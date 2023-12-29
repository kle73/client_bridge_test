#include "connector.h"
#include "mongoose/mongoose.h"

#include <stdio.h>
#include <string.h>
#include <pthread.h>


struct mg_mgr mgr;
struct mg_connection *send_conn, *rcv_conn;
struct nb_buffer instr_buffer;

static const char* s_url = "ws://10.211.55.11:9090";
static const unsigned TIMEOUT = 1000;
static pthread_t poll_handler;
// TODO 
volatile bool end_connections = false;


/**
 * event handler sending for connection (c == send_conn)
*/
static void send_handler(struct mg_connection *c, int ev, void *ev_data, 
		                     void *fn_data) {
  if (ev == MG_EV_ERROR) {
    // TODO 
  } else if (ev == MG_EV_WS_OPEN) {
    // TODO init message
    char message[200];
    snprintf(message, sizeof(message), 
				     "{\"op\": \"subscribe\","
						 "\"topic\": \"/test_topic\","
						 "\"msg\": {\"data\": %d}}", 
						 0);
    mg_ws_send(c, message, strlen(message), WEBSOCKET_OP_TEXT);
    
  } else if (ev == MG_EV_WS_MSG) {
    // TODO
    // (shouldnt happen)
  }
}

/**
 * event handler for receiving connection (c == rcv_conn)
*/
static void rcv_handler(struct mg_connection *c, int ev, void *ev_data,
												void *fn_data) {
  if (ev == MG_EV_ERROR) {
    // TODO 
  } else if (ev == MG_EV_WS_OPEN) { 
    char message[200];
    snprintf(message, sizeof(message), 
				     "{\"op\": \"subscribe\","
						 "\"topic\": \"/test_subscribe_topic\"}");
    mg_ws_send(c, message, strlen(message), WEBSOCKET_OP_TEXT);
    
  } else if (ev == MG_EV_WS_MSG) {
    const int buffer_len = 68;
    struct mg_ws_message *wm = (struct mg_ws_message *) ev_data;
    char data[32];
    snprintf(data, 32, "%.*s", (int) wm->data.len-buffer_len-2,
				     wm->data.ptr+buffer_len);
    int i = atoi(data);
    nb_buffer_enqueue(&instr_buffer, (unsigned)i);
    
  }
}


/*
* main event loop for mongoose 
* if all connections where closed by mongoose:
* -> esnures that all leftover data has been send 
*/
void* poll_handle(void* arg){
    while (true){
			mg_mgr_poll(&mgr, TIMEOUT);
			if (end_connections){
				if (mgr.conns == NULL){
					break;
				}
			} 
    }
		return NULL;
}


int init_conn_nu(){
    mg_mgr_init(&mgr);
    nb_buffer_init(&instr_buffer);
    send_conn = mg_ws_connect(&mgr, s_url, send_handler, NULL, NULL);
    rcv_conn = mg_ws_connect(&mgr, s_url, rcv_handler, NULL, NULL);
    if (send_conn == NULL || rcv_conn == NULL) return -1;
    int t = pthread_create(&poll_handler, NULL, poll_handle, NULL);
    return t;
}


int free_conn_nu(){
    end_connections = true;
    send_conn->is_draining = 1;
    rcv_conn->is_draining = 1;
    pthread_join(poll_handler, NULL);
    mg_mgr_free(&mgr);
    return 0;
}


unsigned read_next_instr(){
    return nb_buffer_dequeue(&instr_buffer);
}


int send_data_nu(int value) {
  if (send_conn == NULL) return -1;
  char message[200];
  snprintf(message, sizeof(message), 
			     "{\"op\": \"publish\","
					 "\"topic\": \"/test_topic\","
					 "\"msg\": {\"data\": %d}}",
					 value);
  mg_ws_send(send_conn, message, strlen(message), WEBSOCKET_OP_TEXT);
  return 0;
}
