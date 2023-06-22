#include <stdio.h>

void reverseArray(int arr[], int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        
        start++;
        end--;
    }
}

int main() {
    int arr[] = {6, 4, 8, 4, 20, 36, 12, 9, 7, 21, 0, 45, 56};
    int length = sizeof(arr) / sizeof(arr[0]);

    
    reverseArray(arr, length);

    
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
