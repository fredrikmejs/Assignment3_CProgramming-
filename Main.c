#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "roofDataStructures/Roof.h"
#include "roofDataStructures/RoofTree.h"
#include "roofDataStructures/waterCalc.h"




int main() {
    int n;
    scanf("%d", &n);
    roof *roofPtr;
    roofTree *root = NULL;
    roof * roofOrder[n];

    for (int j = 0; j < n; j++) {
        roofPtr = malloc(sizeof(struct roof));
        scanf("%d %d %d %d", &(roofPtr->startX), &(roofPtr->startY), &(roofPtr->endX), &(roofPtr->endY));
        roofPtr->streamCaught = false;
        roofPtr->waterCollected = -1;
        roofPtr->next = NULL;

        roofOrder[j] = roofPtr;
        root = insert(roofPtr, root);
    }


    printf("%s", "\n\n__________________________________\n");
    printInOrder(root);
    printf("%s", "\n\n__________________________________\n");
    printInReverse(root);

    int d;
    do {
        printf("\n\n enter '0' to exit: ");
        scanf("%d", &d);
    } while (d != 0);

    return 0;

}


