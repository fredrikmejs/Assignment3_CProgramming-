//
// Created by Bruger on 27-04-2019.
//

#include <stdio.h>
#include "Roof.h"

/*
**************    roof methods    **************
*/
/**
 * print the data of a roof in an easy to read way
 * @param roof  the roof being printed
 */
void printRoof (roof roof) {
    printf("[key = %d]\t(%d, %d), (%d, %d) water collected: %d\n", getMin(roof), roof.startX, roof.startY, roof.endX, roof.endY, roof.waterCollected);
}

/**
 *
 * @param roof
 * @return true if next element exists, false otherwise
 */
bool hasNext (roof roof) {
    return  roof.next != NULL;
};


/**
 * Returns the greatest height of the roof
 */
int getMin(roof r) {
    int rMin;

    if (r.startY > r.endY)
        rMin = r.endY;
    else
        rMin = r.startY;


    return rMin;
}

