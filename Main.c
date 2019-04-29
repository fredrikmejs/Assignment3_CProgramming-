#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "helperClasses/Roof.h"
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
        roofPtr->next = NULL;

        root = insert(roofPtr, root);
    }


    printf("%s", "\n\n__________________________________\n");
    printInOrder(root);


    return 0;

}


