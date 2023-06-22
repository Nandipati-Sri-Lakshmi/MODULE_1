#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(const char* timeString) {
    char* token;
    char* delimiter = ":";
    char* timeCopy = strdup(timeString);  

    unsigned long hours, minutes, seconds;

    token = strtok(timeCopy, delimiter);
    hours = strtoul(token, NULL, 10);

    token = strtok(NULL, delimiter);
    minutes = strtoul(token, NULL, 10);

    token = strtok(NULL, delimiter);
    seconds = strtoul(token, NULL, 10);

    free(timeCopy); 

    unsigned long totalSeconds = hours * 3600 + minutes * 60 + seconds;
    return totalSeconds;
}

int main() {
    const char* timeString1 = "10:12:50";
    unsigned long totalSeconds1 = computeTotalSeconds(timeString1);
    printf("Total seconds: %lu\n", totalSeconds1);

    const char* timeString2 = "13:10:40";
    unsigned long totalSeconds2 = computeTotalSeconds(timeString2);
    printf("Total seconds: %lu\n", totalSeconds2);

    return 0;
}