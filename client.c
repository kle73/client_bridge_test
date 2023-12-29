#include "connector/src/connector.h"
#include <stdio.h>
#include <unistd.h>

int main(){
  int t = init_conn_nu();
  while (true){
    send_data_nu(100);
    unsigned i = read_next_instr();
    printf("%d\n", i);
    send_data_nu(200);
    send_data_nu(300);
    sleep(1);
  }
  free_conn_nu();
}
