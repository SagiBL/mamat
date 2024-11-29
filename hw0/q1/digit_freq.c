#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 1000

/*Read input from STDIN. Print output to STDOUT */ 

int main() {
    int hist[10] = {0};
    char inpt[MAX_LEN] = {0}; 
    int n = fread(inpt, 1, MAX_LEN, stdin);
    for(int i=0; i<n; i++){
        int tmp = (int)inpt[i]-(int)'0';
        if(tmp>=0 && tmp<=9){
            hist[tmp]++;
        }
    }
    for(int j=0; j<10; j++){
        printf("%d%s",hist[j], j<9 ? " " : "");
    }
    printf("\n");
    return 0;
}
