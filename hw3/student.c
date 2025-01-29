#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


void* student_clone(void* student){
    if (student == NULL) {   
        return NULL;        //failed
    }
    struct student* temp = (struct student*)student;
    struct student* clone = (struct student*)malloc(sizeof(struct student));
    if (clone == NULL) {   
        return NULL;        //failed
    }

    clone->age = temp->age;
    clone->id = temp->id;

    // memory allocation for clone->name
    if (temp->name != NULL) {
        clone->name = (char*)malloc(strlen(temp->name) + 1);  
        if (clone->name != NULL) {
            strcpy(clone->name, temp->name);  // Copy name
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


void student_destroy(void* student){
    struct student* temp = (struct student*)student;
    if(temp->name != NULL) {     // Free the dynamically allocated memory for name (if it was allocated)
        free(temp->name);
    }
    free(temp);                  // Free the memory for the struct itself
    return;
}

void student_print(void* student){
    struct student* temp = (struct student*)student;
    printf("student name: %s, age: %d, id: %d\n", temp->name,temp->age,temp->id);
    return;
}
