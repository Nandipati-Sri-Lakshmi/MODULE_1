




#include <stdio.h>

int findLargestAfterDigitDeletion(int num) {
    int max = -1;  
    for (int i = 0; i < 4; i++) {
        int temp = num / 10;  
        int power = 1;        

       
        for (int j = 0; j < 3; j++) {
            if (j != i) {
                temp += (num % 10) * power;
                power *= 10;
            }
            num /= 10;
        }

       
        if (temp > max) {
            max = temp;
        }

        num = temp; 
    }

    return max;
}

int main() {
    int num;

 
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);


    int largest = findLargestAfterDigitDeletion(num);

    printf("Largest number after deleting a single digit: %d\n", largest);

    return 0;
}