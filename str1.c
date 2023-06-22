#include <stdio.h>
#include <ctype.h>

void toggleCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char str1[] = "Hello World";
    toggleCase(str1);
    printf("Output String: %s\n", str1);

    char str2[] = "hELLO wORLD";
    toggleCase(str2);
    printf("Output String: %s\n", str2);

    char str3[] = "A+B";
    toggleCase(str3);
    printf("Output String: %s\n", str3);

    char str4[] = "a+b";
    toggleCase(str4);
    printf("Output String: %s\n", str4);

    return 0;
}
