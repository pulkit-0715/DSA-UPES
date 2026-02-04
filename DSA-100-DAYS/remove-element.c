#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    int i=0,j;
    for(j=0;j<numsSize;j++)
    {
        if(nums[j]!=val)
        nums[i++]=nums[j];
    }
    return i;
}


void inputarr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void printarr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
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
    int k ;
    printf("Enter value of element to delete\n");
    scanf("%d",&k);
    
    printf("%d",removeElement(arr,n,k));

    
    return 0;
}