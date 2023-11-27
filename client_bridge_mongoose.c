#include "connector/src/read_instr.h"
#include "connector/src/send_data_nu.h"
#include "connector/src/manage_conn.h"
#include "connector/src/data.h"
#include <stdio.h>
#include <unistd.h>

int main(){
  int t = init_conn_nu();
  while (true){
    send_data_nu(100);
    struct data *d1 = read_next_instr();
    send_data_nu(200);
    send_data_nu(300);
    sleep(1);
  }
  free_conn_nu();
}
