#ifndef NB_BUFFER_H
#define NB_BUFFER_H

typedef struct nb_buffer{
    struct buffer_node *head;
    struct buffer_node *tail;
    unsigned len;
}nb_buffer;

typedef struct buffer_node{
    struct buffer_node *next;
    struct buffer_node *prev;
    unsigned data;
}buffer_node;

unsigned nb_buffer_dequeue(nb_buffer *buf);

int nb_buffer_enqueue(nb_buffer *buf, unsigned u);

int nb_buffer_init(nb_buffer *buf);

void nb_buffer_clean(nb_buffer *buf);

#endif
