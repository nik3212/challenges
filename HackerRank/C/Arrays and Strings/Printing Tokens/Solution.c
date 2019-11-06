/*

Given a sentence, s, print each word of the sentence in a new line.

Input Format

The first and only line contains a sentence, s.

Constraints

1 <= len(s) <= 1000

Output Format

Print each word of the sentence in a new line.

Sample Input 0

This is C 

Sample Output 0

This
is
C

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    for (char *c = s; *c != NULL; c++) {
        if (*c == ' ') {
            *c = '\n';
        }
    }
    printf("%s", s);

    return 0;
}