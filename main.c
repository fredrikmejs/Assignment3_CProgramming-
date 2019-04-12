#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


struct roof {
    int startX;
    int startY;

    int endX;
    int endY;

    int waterCollected;
};

void printRoof(struct roof roof);

int main() {
    int n;
    scanf("%d", &n);
    struct roof arr[n];

    struct roof *roofPtr;
    for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++) {
        roofPtr = malloc(sizeof(roofPtr));
        scanf("%d %d %d %d", &roofPtr->startX, &roofPtr->startY, &roofPtr->endX, &roofPtr->endY);
        roofPtr->waterCollected = -1;
        arr[j] = *roofPtr;
    }

    for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++) {
        printRoof(arr[j]);
    }

    return 0;

}

void printRoof (struct roof roof) {
    printf("(%d, %d), (%d, %d)\n", roof.startX, roof.startY, roof.endX, roof.endY);
}