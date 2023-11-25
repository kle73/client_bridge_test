#include "mongoose/mongoose.h"

struct mg_mgr mgr;
struct mg_connection *send_conn, *rcv_conn;

int init_conn_nu();

int free_conn_nu();