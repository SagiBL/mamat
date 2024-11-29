#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100

int edit_dist(char word1[], char word2[]);

int main() {
	char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];
	
	fgets(word1, MAX_WORD_LEN, stdin);
	word1[strlen(word1) - 1] = '\0';
	fgets(word2, MAX_WORD_LEN, stdin);
	word2[strlen(word2) - 1] = '\0';

	printf("%d\n", edit_dist(word1, word2));

	return (0);
}

int edit_dist(char word1[], char word2[]) {
	/* YOUR CODE HERE */
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int mat[len1 + 1][len2 + 1]; //dynamic programming matrix
    //mat(i,j) is the distance between first i letters of word1 and first j letters of word2
    
    for (int i = 0; i <= len1; i++) {        //Initialize left column
        mat[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {        //Initialize top row
        mat[0][j] = j;
    }


    // Fill the mat
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i - 1] == word2[j - 1]) {   //words are equal
                mat[i][j] = mat[i - 1][j - 1];  
            } else {                              //else solve for one step less                         
                int add = mat[i][j - 1] + 1;
                int delet = mat[i - 1][j] + 1;
                int swape = mat[i - 1][j - 1] + 1;
                if(add<=delet && add<=swape) mat[i][j] = add;  //mat[i][j] = minimum action
                else if(delet<=swape) mat[i][j] = delet;
                else  mat[i][j] = swape;
            }
        }
    }
    return mat[len1][len2];

}
