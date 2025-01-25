#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void *elem_t;
typedef elem_t (*clone_t)(elem_t e);
typedef void (*destroy_t)(elem_t e);
typedef void (*print_t)(elem_t e);

struct stack {
    size_t size;         // Current size of the stack
    size_t max_size;     //maximal posibble stack size
    elem_t *data;        // pointer to array
    clone_t clone;      // Function pointer
    destroy_t destroy;  // Function pointer
    print_t print;      // Function pointer
};


struct stack* stack_create(size_t max_size, clone_t clone, destroy_t destroy, print_t print);

bool stack_destroy(struct stack* stack);

bool stack_push(struct stack* stack, void *new_elem);

void stack_pop(struct stack* stack);

elem_t* stack_peek(struct stack* stack);

size_t stack_size(struct stack* stack);

bool stack_is_empty(struct stack* stack);

size_t stack_capacity(struct stack* stack);

void stack_print(struct stack* stack);

#endif