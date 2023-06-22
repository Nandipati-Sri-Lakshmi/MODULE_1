#include <stdio.h>

int main() {
    int arr[] = {6, 4, 8, 4, 20, 36, 12, 9, 7, 21, 0, 45, 56};

    int length = sizeof(arr) / sizeof(arr[0]);

    int min = arr[0];
    int max = arr[0]; 

    for (int i = 1; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
