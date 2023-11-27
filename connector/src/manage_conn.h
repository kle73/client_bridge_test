#include "mongoose/mongoose.h"
#include "util/nb_buffer.h"

struct mg_mgr mgr;
struct mg_connection *send_conn, *rcv_conn;

struct nb_buffer instr_buffer;

int init_conn_nu();

int free_conn_nu();