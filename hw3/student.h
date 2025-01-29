#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Generic function pointers
typedef void* (*clone_t)(void*);
typedef void (*destroy_t)(void*);
typedef void (*print_t)(void*);

// Student struct
struct student {
    char *name;
    int age;
    int id;
};

// Function declarations matching function pointer types
void* student_clone(void* student);  // Changed return type to void*
void student_destroy(void* student);
void student_print(void* student);

#endif
