#include "manage_conn.h"
#include "read_instr.h"

unsigned read_next_instr(){
    return nb_buffer_dequeue(&instr_buffer);
}