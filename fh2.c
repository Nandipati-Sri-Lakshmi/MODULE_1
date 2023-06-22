#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024


void convertToUpper(char *buffer) {
    while (*buffer) {
        *buffer = toupper(*buffer);
        buffer++;
    }
}

void convertToLower(char *buffer) {
    while (*buffer) {
        *buffer = tolower(*buffer);
        buffer++;
    }
}

void convertToSentenceCase(char *buffer) {
    int capitalizeNext = 1;
    while (*buffer) {
        if (capitalizeNext && isalpha(*buffer)) {
            *buffer = toupper(*buffer);
            capitalizeNext = 0;
        } else {
            *buffer = tolower(*buffer);
        }

        if (*buffer == '.' || *buffer == '?' || *buffer == '!') {
            capitalizeNext = 1;
        }

        buffer++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./cp [-u/-l/-s] source_file target_file\n");
        return 1;
    }

    FILE *sourceFile, *targetFile;
    char *option = argv[1];
    char *sourceFileName = argv[2];
    char *targetFileName = argv[3];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    targetFile = fopen(targetFileName, "w");
    if (targetFile == NULL) {
        printf("Failed to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (strcmp(option, "-u") == 0) {
            convertToUpper(buffer);
        } else if (strcmp(option, "-l") == 0) {
            convertToLower(buffer);
        } else if (strcmp(option, "-s") == 0) {
            convertToSentenceCase(buffer);
        }

        fwrite(buffer, 1, bytesRead, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");

    return 0;
}
