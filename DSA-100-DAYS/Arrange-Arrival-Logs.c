/*
Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed
*/

#include <stdio.h>
void printarr(int *arr, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void inputarr(int *arr, int n) {
    printf("Array:");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void merge(int *arr1, int n1, int *arr2, int n2) {
    int arr3[n1 + n2];
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while(i < n1)
        arr3[k++] = arr1[i++];

    while(j < n2)
        arr3[k++] = arr2[j++];

    printarr(arr3, n1 + n2);
}

int main(){

    int n1, n2;

    printf("Enter size of array 1\n");
    scanf("%d", &n1);
    int arr1[n1];
    inputarr(arr1, n1);
    printarr(arr1, n1);

    printf("Enter size of array 2\n");
    scanf("%d", &n2);
    int arr2[n2];
    inputarr(arr2, n2);
    printarr(arr2, n2);

    merge(arr1, n1, arr2, n2);
    return 0;
}
