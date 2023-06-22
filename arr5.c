#include <stdio.h>

int main() {
    int arr[] = {6, 4, 8, 4, 20, 36, 12, 9, 7, 21, 0, 45, 56, 48, 13};
    int length = sizeof(arr) / sizeof(arr[0]);

    int sumEvenIndexed = 0;
    int sumOddIndexed = 0;

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            sumEvenIndexed += arr[i];
        } else {
            sumOddIndexed += arr[i];
        }
    }

    int difference = sumEvenIndexed - sumOddIndexed;

    printf("Difference: %d\n", difference);

    return 0;
}
