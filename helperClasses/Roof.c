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
    printf("[key = %d]\t(%d, %d), (%d, %d)\t\n",  getMax(roof), roof.startX, roof.startY, roof.endX, roof.endY);
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
int getMax(roof r) {
    int rMax;

    if (r.startY > r.endY)
        rMax = r.startY;
    else
        rMax = r.endY;


    return rMax;
}

