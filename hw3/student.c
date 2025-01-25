#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"



struct student {
char *name;
int age;
int id;
};

struct student* student_clone(struct student* student){
    struct student* clone = (struct student*)malloc(sizeof(struct student));
    if (clone == NULL) {   
        return NULL;        //failed
    }

    clone->age = student->age;
    clone->id = student->id;

    // memory allocation for clone->name
    if (student->name != NULL) {
        clone->name = (char*)malloc(strlen(student->name) + 1);  
        if (clone->name != NULL) {
            strcpy(clone->name, student->name);  // Copy name
        } 
        else {
            free(clone);  // free the struct
            return NULL;   //failed
        }
    } 
    else {
        clone->name = NULL;  // original name is NULL => clone name is NULL
    }

    return clone;
}


void student_destroy(struct student* student){
    if(student->name != NULL) {     // Free the dynamically allocated memory for name (if it was allocated)
        free(student->name);
    }
    free(student);                  // Free the memory for the struct itself
    return;
}

void student_print(struct student* student){
    printf("student name: %s, age: %d, id: %d\n", student->name,student->age,student->id);
    return;
}
