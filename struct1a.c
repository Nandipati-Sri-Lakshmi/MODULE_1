#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

void calculateVolumeAndSurfaceArea(struct Box *box) {
    float volume, surfaceArea;

    volume = box->length * box->width * box->height;
    surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box box = {3.0, 4.0, 5.0};
    struct Box *boxPtr = &box;

    calculateVolumeAndSurfaceArea(boxPtr);

    return 0;
}
