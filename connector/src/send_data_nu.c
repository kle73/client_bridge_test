#include "mongoose/mongoose.h"
#include "send_data_nu.h"
#include "manage_conn.h"
#include <stdio.h>

#include <string.h>

int send_data_nu(int value) {
  if (send_conn == NULL) return -1;
  char message[200];
  snprintf(message, sizeof(message), "{\"op\": \"publish\", \"topic\": \"/test_topic\", \"msg\": {\"data\": %d}}", value);
  mg_ws_send(send_conn, message, strlen(message), WEBSOCKET_OP_TEXT);
  return 0;
}