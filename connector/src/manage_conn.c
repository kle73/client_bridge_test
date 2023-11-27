#include "manage_conn.h"
#include "mongoose/mongoose.h"
#include "util/jsmn.h"

#include <stdio.h>
#include <string.h>
// TODO 
// change pthreads to freeRTOS tasks
#include <pthread.h>

static const char* s_url = "ws://0.0.0.0:9090";

static const unsigned TIMEOUT = 1000;

static pthread_t poll_handler;
volatile bool end_connections = false;


/**
 * event handler sending for connection (c == send_conn)
*/
static void send_handler(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  if (ev == MG_EV_ERROR) {

    // TODO
    printf("error\n");
    
  } else if (ev == MG_EV_WS_OPEN) {

    // TODO init message
    char message[200];
    snprintf(message, sizeof(message), "{\"op\": \"subscribe\", \"topic\": \"/test_topic\", \"msg\": {\"data\": %d}}", 0);
    mg_ws_send(c, message, strlen(message), WEBSOCKET_OP_TEXT);
    
  } else if (ev == MG_EV_WS_MSG) {
    // TODO
    // (shouldnt happen)
  }
  /*
  if (ev == MG_EV_CLOSE) {
     *(bool *) fn_data = true;  
  }
  */
}

/**
 * event handler for receiving connection (c == rcv_conn)
*/
static void rcv_handler(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  if (ev == MG_EV_ERROR) {
    // TODO
    printf("error\n");
    
  } else if (ev == MG_EV_WS_OPEN) {
    
    char message[200];
    snprintf(message, sizeof(message), "{\"op\": \"subscribe\", \"topic\": \"/test_subscribe_topic\"}");
    mg_ws_send(c, message, strlen(message), WEBSOCKET_OP_TEXT);
    
  } else if (ev == MG_EV_WS_MSG) {

    // TODO
    // extract data
    // place in buffer for rcv_instr
    const int buffer_len = 68;
    struct mg_ws_message *wm = (struct mg_ws_message *) ev_data;
    char data[32];
    snprintf(data, 32, "%.*s", (int) wm->data.len-buffer_len-2, wm->data.ptr+buffer_len);
    int i = atoi(data);
    nb_buffer_enqueue(&instr_buffer, (unsigned)i);
    
  }
  /*
  if (ev == MG_EV_CLOSE) {
     *(bool *) fn_data = true; 
  }
  */
}


/*
* main event loop for mongoose 
*/
void* poll_handle(void* arg){
    while (true){
        mg_mgr_poll(&mgr, TIMEOUT);
        if (end_connections){
          // check that all connections where closed by mongoose
          // -> esnures that all leftover data has been send
          if (mgr.conns == NULL){
            break;
          }
        } 
    }
}


/*
 * initializes the  connection and runs the event loop.
 * has to be called before the first send or read call
*/
int init_conn_nu(){
    mg_mgr_init(&mgr);
    nb_buffer_init(&instr_buffer);
    // bool done1 = false; bool done2 = false;
    send_conn = mg_ws_connect(&mgr, s_url, send_handler, NULL, NULL);
    rcv_conn = mg_ws_connect(&mgr, s_url, rcv_handler, NULL, NULL);
    if (send_conn == NULL || rcv_conn == NULL) return -1;
    int t = pthread_create(&poll_handler, NULL, poll_handle, NULL);
    return t;
}

/*
 * closes connections and interrupts handlerthread
 * after call, no more send_data/read_instr calls possible
*/
int free_conn_nu(){
    end_connections = true;
    send_conn->is_draining = 1;
    rcv_conn->is_draining = 1;
    pthread_join(poll_handler, NULL);
    mg_mgr_free(&mgr);
    return 0;
}
