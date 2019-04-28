#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "helperClasses/RoofTree.h"






int main() {
    int n;
    scanf("%d", &n);
    struct roof *roofPtr;
    struct roofTree *root = NULL;

    for (int j = 0; j < n; j++) {
        roofPtr = malloc(sizeof(struct roof));
        scanf("%d %d %d %d", &(roofPtr->startX), &(roofPtr->startY), &(roofPtr->endX), &(roofPtr->endY));
        roofPtr->waterCollected = -1;


        root = insert(roofPtr, root);
    }

    printf("%s", "enter a number to continue");
    scanf("d");

    printf("%s", "\n\n__________________________________\n");
    printInOrder(root);

    printf("%s", "enter a number to continue");
    scanf("d");

    return 0;

}


