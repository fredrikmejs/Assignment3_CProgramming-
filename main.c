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
void sortRoofArray(struct roof roofs[], int size);
int compareRoofs (struct roof r1, struct roof r2);

int main() {
    int n;
    scanf("%d", &n);
    struct roof roofs[n];

    struct roof *roofPtr;
    for (int j = 0; j < sizeof(roofs) / sizeof(roofs[0]); j++) {
        roofPtr = malloc(sizeof(roofPtr));
        scanf("%d %d %d %d", &roofPtr->startX, &roofPtr->startY, &roofPtr->endX, &roofPtr->endY);
        roofPtr->waterCollected = -1;
        roofs[j] = *roofPtr;
    }

    for (int j = 0; j < sizeof(roofs) / sizeof(roofs[0]); j++) {
        printRoof(roofs[j]);
    }
    printf("%s", "\n\n__________________________________\n");

    sortRoofArray(roofs, n);

    printf("%s", "\n\n_______________FINAL________________\n");
    for (int j = 0; j < sizeof(roofs) / sizeof(roofs[0]); j++) {
        printRoof(roofs[j]);
    }

    return 0;

}

void printRoof (struct roof roof) {
    printf("(%d, %d), (%d, %d)\n", roof.startX, roof.startY, roof.endX, roof.endY);
}

void sortRoofArray(struct roof roofs[], int size){
    int min;
    int max;
    int middle;

    for (int i = 1; i < size; i++) {
        min = 0;
        max = i;
        middle = ((max - min) / 2) + min;
        while (true) {

            /*if (compareRoofs(roofs[max], roofs[i]) >= 0) {
                struct roof temp = roofs[i];
                for (int j = i; j > max; j--){
                    roofs[j] = roofs[j-1];
                }
                roofs[max + 1] = temp;
                break;
            }*/
            if (min == middle){
                if (compareRoofs(roofs[middle], roofs[i]) > 0)
                    middle++;
                struct roof temp = roofs[i];
                for (int j = i; j > middle; j--){
                    roofs[j] = roofs[j-1];
                }
                roofs[middle] = temp;
                break;
            }
            if (compareRoofs(roofs[middle], roofs[i]) > 0) {
                min = middle;
                middle = ((max - min + 1) / 2) + min;
            } else {
                max = middle;
                middle = ((max - min) / 2) + min;
            }

        }

    }

}

int compareRoofs (struct roof r1, struct roof r2) {
    int r1Max;
    int r2Max;

    if (r1.startY > r1.endY)
        r1Max = r1.startY;
    else
        r1Max = r1.endY;

    if (r2.startY > r2.endY)
        r2Max = r2.startY;
    else
        r2Max = r2.endY;

    return r2Max - r1Max;
}