
#include <stdio.h>
#include <string.h>
// #include <math.h>
#include <stdlib.h>

int median(FILE *f);
int compare(const void *a, const void *b);
void append_int(int **arr, int size, int value);

int main(int argc, char **argv){
    FILE *f;
    if(argc==1 || 0 == strcmp(argv[1],"-")){
        f=stdin;
    }
    else{
        f=fopen(argv[1], "r");
    }

    if(!f){
        fprintf(stderr,"Error occurred\n");
        return 1;
    }
    fprintf(stdout,"%d\n",median(f));
    if (f != stdin) fclose(f);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void append_int(int **arr, int size, int value) {
    // Reallocate memory to add one more element
    *arr = realloc(*arr, (size + 1) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
     // Add the value at the correct position
    (*arr)[size] = value;
}

int median(FILE *f){
    int grade;
    int ret;
    int length=0;
    int *arr = NULL;
    int median;

    while(1){
        ret = fscanf(f, "%d" , &grade);
        if(ret==EOF) break;
        if(ret != 1){
            fprintf(stderr, "Error at line %d: invalid input %d\n",length+1,grade);
            exit(1);
        }
        else{
            length+=1;
            append_int(&arr, length, grade);
        }
    }

    qsort(arr, length, sizeof(int), compare);
    median = arr[length / 2];
    free(arr);
    return median;
}
