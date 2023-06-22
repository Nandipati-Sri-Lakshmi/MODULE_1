#include <stdio.h>

int main() {
    int arr[] = {12, 84, 20, 36, 64, 56, 72, 10, 45, 90};
    int length = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = sum + arr[i];
    }

    float avg = (float) sum / length;

    printf("Average: %.2f\n", avg);

    return 0;
}