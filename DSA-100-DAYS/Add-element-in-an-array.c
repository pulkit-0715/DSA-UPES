/*
Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. 
Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right*/
#include <stdio.h>

void inputarr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void printarr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void updatearr(int *arr, int n, int pos, int num) {
    
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = num;
}

int main() {
    int arr[10000];
    int n;

    scanf("%d", &n);
    inputarr(arr, n);

    int pos;
    scanf("%d", &pos);

    int num;
    scanf("%d", &num);

    updatearr(arr, n, pos - 1, num);
    printarr(arr, n + 1);

    return 0;
}
