#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// Function to clone a student
void* student_clone(void* student_void) {
    struct student* student = (struct student*)student_void;
    struct student* clone = (struct student*)malloc(sizeof(struct student));
    if (clone == NULL) {   
        return NULL;        // failed
    }

    clone->age = student->age;
    clone->id = student->id;

    // Memory allocation for clone->name
    if (student->name != NULL) {
        clone->name = (char*)malloc(strlen(student->name) + 1);  
        if (clone->name != NULL) {
            strcpy(clone->name, student->name);  // Copy name
        } 
        else {
            free(clone);  // Free the struct
            return NULL;   // failed
        }
    } 
    else {
        clone->name = NULL;  // Original name is NULL => clone name is NULL
    }

    return clone;
}

// Function to destroy a student
void student_destroy(void* student_void) {
    struct student* student = (struct student*)student_void;
    if(student->name != NULL) {     // Free dynamically allocated memory for name (if allocated)
        free(student->name);
    }
    free(student);                  // Free the memory for the struct itself
    return;
}

// Function to print a student
void student_print(void* student_void) {
    struct student* student = (struct student*)student_void;
    printf("student name: %s, age: %d, id: %d\n", student->name, student->age, student->id);
    return;
}
