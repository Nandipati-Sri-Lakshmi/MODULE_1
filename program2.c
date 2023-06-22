#include <stdio.h>

void printBits(int num) {
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    int num;

    
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);

    
    printf("Bits representation: ");
    printBits(num);
    printf("\n");

    return 0;
}
