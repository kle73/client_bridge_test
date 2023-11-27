#include "nb_buffer.h"
#include <stdio.h>

int main(){
    printf("hallo\n");
    struct nb_buffer buf;
    int a = nb_buffer_init(&buf);
    printf("hallo, %d\n", a);
    unsigned res;
    res = nb_buffer_dequeue(&buf);
    if (res == 0) printf("null\n");
    unsigned i = 11;
    nb_buffer_enqueue(&buf, i);
    printf("first: %d\n", nb_buffer_dequeue(&buf));
    unsigned j = 22;
    nb_buffer_enqueue(&buf, j);
    unsigned k = 33;
    nb_buffer_enqueue(&buf, k);

    printf("second: %d\n", nb_buffer_dequeue(&buf));
    printf("third: %d\n", nb_buffer_dequeue(&buf));

    int n = nb_buffer_dequeue(&buf);
    nb_buffer_clean(&buf);
}