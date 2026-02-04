/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/

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

void reverse(int *arr,int n){

    int i=0,j=n-1;
    while (i<=j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    printf("Output array\n");
    printarr(arr,n);
}
int main(){
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Input array\n");
    inputarr(arr,n);
    printf("Array Entered\n");
    printarr(arr,n);

    reverse(arr,n);
    return 0;
}