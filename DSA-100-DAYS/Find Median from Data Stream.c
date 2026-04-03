#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < maxSize && maxHeap[left] > maxHeap[largest])
        largest = left;
    if (right < maxSize && maxHeap[right] > maxHeap[largest])
        largest = right;

    if (largest != i) {
        swap(&maxHeap[i], &maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}

void minHeapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minSize && minHeap[left] < minHeap[smallest])
        smallest = left;
    if (right < minSize && minHeap[right] < minHeap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapifyDown(smallest);
    }
}

void insertMax(int x) {
    maxHeap[maxSize] = x;
    maxHeapifyUp(maxSize);
    maxSize++;
}

void insertMin(int x) {
    minHeap[minSize] = x;
    minHeapifyUp(minSize);
    minSize++;
}

int extractMax() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
    return root;
}

int extractMin() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
    return root;
}

void addNum(int num) {
    insertMax(num);
    insertMin(extractMax());

    if (minSize > maxSize) {
        insertMax(extractMin());
    }
}

double findMedian() {
    if (maxSize > minSize)
        return maxHeap[0];
    return (maxHeap[0] + minHeap[0]) / 2.0;
}

int main() {
    addNum(1);
    addNum(2);
    printf("%.1f\n", findMedian());
    addNum(3);
    printf("%.1f\n", findMedian());
    return 0;
}