#include <stdio.h>

int main() {
    int arr[] = {6, 4, 8, 4, 20, 36, 12, 9, 7, 21, 0, 45, 56, 48, 13};
    int length = sizeof(arr) / sizeof(arr[0]);

    int sumEven = 0;
    int sumOdd = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
        } else {
            sumOdd += arr[i];
        }
    }

    int difference = sumEven - sumOdd;

    printf("Difference: %d\n", difference);

    return 0;
}
