/*
Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
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

void search(int *arr, int n, int k) {
    int ct=0;
    for(int i=0;i<n;i++){
        ct++;
          if(arr[i]==k)
          {
            printf("Found at index  %d \nComparisons %d",i,ct);
          }  
    }
  

}

int main() {
    int arr[10000];
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    inputarr(arr, n);

    int k;
    printf("Enter Element to search\n");
    scanf("%d",&k);

    search(arr,n,k);
   
    return 0;
}
