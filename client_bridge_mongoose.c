#include "connector/src/send_data_nu.h"
#include "connector/src/manage_conn.h"
#include <stdio.h>
#include <unistd.h>

int main(){
  int t = init_conn_nu();
  printf("t: %d\n", t);
  while (true){
    send_data_nu(100);
    send_data_nu(200);
    send_data_nu(300);
    sleep(1);
  }
  free_conn_nu();
}
