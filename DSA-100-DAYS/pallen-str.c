/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/

#include <stdio.h>
#include <string.h>
int main(){
    char str[1000];
    fgets(str,sizeof(str),stdin);
    int n = strlen(str);
    if (str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n--;
    }

    int i=0,j=n-1;

    while(i<j){

        if(str[i++]!=str[j--]){
            printf("Not Pallen");
            return 1;
        }
        
    }
   printf("Pallen");
    return 0;
}