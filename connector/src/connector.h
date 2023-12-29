#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "mongoose/mongoose.h"
#include "util/nb_buffer.h"


extern struct mg_mgr mgr;
extern struct mg_connection *send_conn, *rcv_conn;
extern struct nb_buffer instr_buffer;



/*
 * initializes the  connection and runs the event loop.
 * has to be called before the first send or read call
*/
int init_conn_nu(void);

/*
 * closes connections and interrupts handlerthread
 * after call, no more send_data/read_instr calls possible
*/
int free_conn_nu(void);

/*
 * if NavUnit has send an isntruction: retreive it
 * returns NULL otherwise
 */
unsigned read_next_instr(void);

/*
 * sends the data to NavUnit
 * returns 0 on sucess
 * returns -1 on failure
 */
int send_data_nu(int value);

#endif
