#include <stdio.h>

void bubbleSort(int arry[], int size, int *maxSwaps, int swapCount[]);

int main() {
    int arry[100], counter, maxSwaps = 0;
    int swapCount[100] = {0};

    printf("Enter array length\n");
    scanf("%d", &counter);

    if (counter > 100 || counter <= 0) {
        printf("Invalid array length\n");
        return 1;
    }

    for (int i = 0; i < counter; i++) {
        printf("%d. Enter number: ", i + 1);
        scanf("%d", &arry[i]);
    }

    bubbleSort(arry, counter, swapCount, &maxSwaps);

    printf("\nSort Array:\n");
    for (int i = 0; i < counter; i++) {
        printf("%d ", arry[i]);
    }
    printf("\n");

    for (int i = 0; i < counter; i++) {
        printf("%d : # of times is %d swapped\n", arry[i], swapCount[i]);
    }
    printf("# of swaps: %d\n", maxSwaps);
    return 0;
}

void bubbleSort(int arry[], int size, int *swapCount, int *maxSwaps) {
    int temp, i, j;
    *maxSwaps = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arry[j] > arry[j + 1]) {
                temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
                swapCount[j]++;
                swapCount[j + 1]++;
                (*maxSwaps)++;
            }
        }
    }
}