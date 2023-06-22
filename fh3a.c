#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

int readLogEntries(LogEntry logEntries[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int entryCount = 0;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the data file.\n");
        return -1;
    }

    
    while (fgets(line, sizeof(line), file) != NULL) {
        
        char *token = strtok(line, ",");
        
        
        logEntries[entryCount].entryNo = atoi(token);
        
        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].sensorNo, token);
        
        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);
        
        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);
        
        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);
        
        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].time, token);
        
        entryCount++;
    }

    fclose(file);

    return entryCount;
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount, i;

    entryCount = readLogEntries(logEntries);

    if (entryCount == -1) {
        printf("Error occurred while reading the log entries.\n");
        return 1;
    }

    
    printf("Log Entries:\n");
    printf("------------------------------------\n");
    printf("EntryNo  SensorNo  Temperature  Humidity  Light  Time\n");
    printf("------------------------------------\n");

    for (i = 0; i < entryCount; i++) {
        printf("%-8d %-9s %-12.1f %-9d %-6d %-8s\n",
               logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature,
               logEntries[i].humidity, logEntries[i].light, logEntries[i].time);
    }

    return 0;
}
