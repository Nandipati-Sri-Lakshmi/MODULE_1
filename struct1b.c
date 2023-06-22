#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

void calculateVolumeAndSurfaceArea(struct Box *boxPtr) {
    float volume, surfaceArea;

    volume = boxPtr->length * boxPtr->width * boxPtr->height;
    surfaceArea = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box box = {3.0, 4.0, 5.0};
    struct Box *boxPtr = &box;

    calculateVolumeAndSurfaceArea(boxPtr);

    return 0;
}
