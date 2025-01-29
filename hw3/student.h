#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct student {
char *name;
int age;
int id;
};

void* student_clone(void* student);
void student_destroy(void* student);
void student_print(void* student);

#endif
