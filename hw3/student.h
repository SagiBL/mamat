#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void *elem_t;
typedef void* (*clone_t)(elem_t e);
typedef void (*destroy_t)(elem_t e);
typedef void (*print_t)(elem_t e);

struct student {
char *name;
int age;
int id;
};

struct student* student_clone(struct student* student);
void student_destroy(struct student* student);
void student_print(struct student* student);

#endif
