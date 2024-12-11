#include <stdio.h>
#include <string.h>
// #include <math.h>
#include <stdlib.h>

void my_copy(FILE *f, FILE *out);

int main(int argc, char **argv){
    FILE *f;
    FILE *out = stdout;
    if(0 == strcmp(argv[1],"-")){
        f=stdin;
    }
    else{
        f=fopen(argv[1], "r");
        if(!f){
            fprintf(stderr,"Error occurred\n");
            return 1;
        }
    }
    
    if(0 == strcmp(argv[2],"-")){
        out = fopen(argv[2], "w");
        if(!out){
            fprintf(stderr,"Error occurred\n");
            fclose(f);
            return 1;
        }
    }
    
    my_copy(f,out);
    if (f != stdin) fclose(f);
    if (out != stdout) fclose(out);
    return 0;
}


void my_copy(FILE *f, FILE *out) {
    char line[1024];  // Buffer to hold each line

    // Read each line from the file (or stdin) and print it to stdout
    while (fgets(line, sizeof(line), f)) {
        // Output the line read
        fputs(line, out);
    }
}
