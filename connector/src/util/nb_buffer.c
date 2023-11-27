#include "nb_buffer.h"
#include <stdlib.h>
#include <pthread.h>

/*
 * simple queue, just for testing purposes!
 * probably slow, not lock free
*/

static pthread_mutex_t lock;


unsigned nb_buffer_dequeue(nb_buffer *buf){
    pthread_mutex_lock(&lock);
    if (buf->head != NULL && buf->len > 0){
        buffer_node *first = buf->tail->next;
        if (first == NULL){
            pthread_mutex_unlock(&lock);
            return 0;
        }
        unsigned data = first->data;
        buf->tail->next = first->next;
        if (first->next != NULL){
            first->next->prev = buf->tail;
        }
        free(first);
        buf->len--;
        pthread_mutex_unlock(&lock);
        return data;
    }
    pthread_mutex_unlock(&lock);
    return 0;
}

int nb_buffer_enqueue(nb_buffer *buf, unsigned u){
    pthread_mutex_lock(&lock);
    buffer_node *node = (buffer_node*)calloc(1, sizeof(buffer_node));
    if (node == NULL){
        pthread_mutex_unlock(&lock);
        return 1;
    }
    node->data = u;
    node->next = NULL;
    node->prev = buf->head;
    buf->head->next = node;
    buf->head = node;
    buf->len++;
    pthread_mutex_unlock(&lock);
    return 0;
};


int nb_buffer_init(nb_buffer *buf){
    if (pthread_mutex_init(&lock, NULL) != 0) return -1;
    buffer_node *sentinal_node = (buffer_node*)calloc(1, sizeof(buffer_node));
    if (sentinal_node == NULL){
        return -1;
    }
    sentinal_node->next = NULL;
    sentinal_node->prev = NULL;
    buf->head = sentinal_node;
    buf->tail = sentinal_node;
    buf->len = 0;
    return 0;
}

void nb_buffer_clean(nb_buffer *buf){
    while (buf->len > 0){
        nb_buffer_dequeue(buf);
    }
    free(buf->tail);
}