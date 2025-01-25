
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

struct student* student_clone(struct student* student);
void student_destroy(struct student* student);
void student_print(struct student* student);

#endif