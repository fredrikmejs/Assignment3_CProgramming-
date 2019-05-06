//
// Created by Bruger on 30-04-2019.
//

#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include "Roof.h"
#include "RoofTree.h"
#include "waterCalc.h"


/**
 * calculates the water dripping from each roof.
 * @param root the root of the tree being searched
 * @param current the current roof being processed
 */
void calcWaterForTree(roofTree *root, roofTree *current) {
    if (current == NULL) return;
    calcWaterForTree(root, successor(current->key, current));
    //Functionality of calculating water goes here
    roof *roofPtr = current->list;
    while (roofPtr != NULL) {
        calcWaterForRoof(roofPtr, root);
        roofPtr = roofPtr->next;
    }

    calcWaterForTree(root, predecessor(current->key, current)); //TODO maybe replace current with root
}


int checkStream (roof *pHighRoof, roof *r);
roof * checkCover (roof pHighRoof, roof *waterArea);
int calcWaterForRoof(roof *r, roofTree *root) {
    int waterSum = 0;

    roof *waterArea = malloc(sizeof(roof));
    waterArea->startX = r->startX;
    waterArea->endX = r->endX;
    waterArea->next = NULL;

    roofTree *pTree;
    roof *pHighRoof;

    pTree = successor(getMin(*r) -1, root);
    while ((pTree = successor(pTree->key, root)) != NULL) {
        pHighRoof = pTree->list;
        do {
            //this is where we check all the roofs above the one currently being calculated
            waterSum += checkStream(pHighRoof, r);
            if (waterArea != NULL)
                waterArea = checkCover(*pHighRoof, waterArea);
        } while ((pHighRoof = pHighRoof->next) != NULL);
    }

    if (waterArea != NULL) {
        do {
            waterSum += waterArea->endX - waterArea->startX;
        } while ((waterArea = waterArea->next) != NULL);
    }

    return (r->waterCollected = waterSum);
}

int checkStream (roof *pHighRoof, roof *r){
    if (pHighRoof->streamCaught) return 0;
    bool lowStart = pHighRoof->startY < pHighRoof->endY;
    if (lowStart) {
        if (pHighRoof->startX >= r->startX && pHighRoof->startX <= r->endX) {
            pHighRoof->streamCaught = true;
            return  pHighRoof->waterCollected;
        } else return 0;
    } else {
        if (pHighRoof->endX >= r->startX && pHighRoof->endX <= r->endX) {
            pHighRoof->streamCaught = true;
            return  pHighRoof->waterCollected;
        } else return 0;
    }
}

roof * checkCover (roof pHighRoof, roof *waterArea) {
    roof *pLowRoof = waterArea;
    roof *pPrevRoof = NULL;
    do {
        //Check if pHighRoof covers any of the line segment of pLowRoof
        if (pHighRoof.startX <= pLowRoof->startX && pHighRoof.endX >= pLowRoof->endX) { //check if the roof covers all of the line segment
            //Deletes a segment
            if (pPrevRoof != NULL) {
                pPrevRoof->next = pLowRoof->next;
                realloc(pLowRoof, sizeof(roof));
                pLowRoof = pPrevRoof;
            } else {
                waterArea = pLowRoof->next;
                realloc(pLowRoof, sizeof(roof));
                pLowRoof = pPrevRoof;
            }
            continue;
        } else if (pHighRoof.startX >= pLowRoof->startX && pHighRoof.startX <= pLowRoof->endX){ //check if the roofs right side is within the line segment
            if (pHighRoof.endX <= pLowRoof->endX){ //  check if the roof extends to the edge
                // Splits segment
                roof *tempRoof = malloc(sizeof(roof));
                tempRoof->startX = pHighRoof.endX;
                tempRoof->endX = pLowRoof->endX;
                pLowRoof->endX = pHighRoof.startX;
                tempRoof->next = pLowRoof->next;
                pLowRoof->next = tempRoof;
            } else { //in this case the upper roof splits the line segment
                // Cuts right side off
                pLowRoof->endX = pHighRoof.startX;
            }
        } else if (pHighRoof.endX >= pLowRoof->startX && pHighRoof.endX <= pLowRoof->endX) { //check if the roofs left side is within the line segment
            // Cuts left side off
            pLowRoof->startX = pHighRoof.endX;
        }
        pPrevRoof = pLowRoof;
    } while ((pLowRoof = (pPrevRoof == NULL ? NULL : pPrevRoof->next)) != NULL); //moves both pointers one step further along the list and checks for NULL

    return waterArea;
}