#include <stdio.h>

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    for (int i = 0; i < size; i++) {
        freq[tasks[i] - 'A']++;
    }

    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    int countMax = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq)
            countMax++;
    }

    int part = (maxFreq - 1) * (n + 1) + countMax;

    return (size > part) ? size : part;
}

int main() {
    char tasks[] = {'A','A','A','B','B','B'};
    int n = 2;
    int size = sizeof(tasks)/sizeof(tasks[0]);

    int result = leastInterval(tasks, size, n);
    printf("%d\n", result);

    return 0;
}