#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define FAIL 1
#define SUCCESS 0

// Function to create a stack
struct stack* stack_create(size_t max_size, clone_t clone, destroy_t destroy, print_t print) {
    struct stack* new_stack = (struct stack*)malloc(sizeof(struct stack));
    if (!new_stack) {
        return NULL;  // failed
    }

    new_stack->size = 0;
    new_stack->max_size = max_size;
    new_stack->data = (elem_t*)malloc(max_size * sizeof(elem_t));
    if (!new_stack->data) {
        free(new_stack);  // failed for data, free the stack struct
        return NULL;
    }

    new_stack->clone = clone;
    new_stack->destroy = destroy;
    new_stack->print = print;

    return new_stack;
}

// Function to destroy a stack
bool stack_destroy(struct stack* stack) {
    if (!stack) return FAIL ;   //invalid arguments - empty

    // Call the destroy function for each element
    for (size_t i = 0; i < stack->size; i++) {
        stack->destroy(stack->data + i);
    }
        
    free(stack->data);  // Free the array holding the elements
    free(stack);  // Free the stack structure
    return SUCCESS;
}


// Function to push an element onto the stack
bool stack_push(struct stack* stack, void *new_elem) {
    if (!stack || !new_elem) return FAIL ;  //invalid arguments - empty
    if(stack->size+1 > stack->max_size) return FAIL ;  //stack is full

    stack->data = (elem_t*)realloc(stack->data, ( (stack->size+1)*sizeof(elem_t) ) );
    if (!stack->data) {
        return FAIL;  // failed
    }
    
    stack->data[stack->size] = stack->clone(new_elem);  // Clone the new_elem
    stack->size++;
    return SUCCESS;
}

// Function to pop an element from the stack
void stack_pop(struct stack* stack) {
    if (!stack || stack->size == 0) return;  //invalid arguments - empty
    stack->destroy(stack->data + (stack->size-1));  // Destroy the element
    stack->size--;  // Decrease the size of the stack
    return;
}

// Function to peek at the top element of the stack
elem_t* stack_peek(struct stack* stack) {
    if (!stack || stack->size == 0) return NULL;  //invalid arguments - empty
    return stack->data[stack->size - 1];  // Return pointer
}

// Function to get the size of the stack
size_t stack_size(struct stack* stack) {
    if (!stack) return 0;  //invalid arguments - empty
    return stack->size;
}

// Function to check if the stack is empty
bool stack_is_empty(struct stack* stack) {
    if (!stack) return false;  //invalid arguments - empty
    return stack->size == 0;
}

// Function to get the capacity of the stack
size_t stack_capacity(struct stack* stack) {
    if (!stack) return 0;  //invalid arguments - empty
    return stack->max_size - stack->size;
}

// Function to print all elements in the stack
void stack_print(struct stack* stack) {
    if (!stack || stack->print == NULL) return;  //invalid arguments - empty

    for (size_t i = stack->size; i > 0; i--) {
        stack->print(stack->data[i-1]);  // Call the print function for each element
    }
    return;
}
