#include <stdio.h>
#include<string.h>
void swap(char*a,char *b)
{
    char z= *a;
    *a=*b;
    *b=z;
}

void reverseString(char* s, int sSize) {
    int i=0,j=sSize-1;
    while(i<=j)
    {
        swap(&s[i++],&s[j--]);
    }
}
int main(){
    char str[1000];

    fgets(str, 1000, stdin);

    int n = strlen(str);

    
    if (str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n--;
    }
    reverseString(str,n);
    printf("%s", str);
    
    return 0;
}