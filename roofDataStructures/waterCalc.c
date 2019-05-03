//
// Created by Bruger on 30-04-2019.
//

#include <stdbool.h>
#include <stdio.h>
#include "Roof.h"
#include "RoofTree.h"
#include "waterCalc.h"


/**
 * calculates the water dripping from each roof.
 * @param root the root of the tree being searched
 * @param current the current roof being processed
 */
void calcWaterForTree(roofTree *root, roofTree *current) {
    if (root == NULL) return;
    calcWaterForTree(root, successor(root->key, root));
    //Functionality of calculating water goes here
    roof *roofPtr = current->list;
    while (roofPtr != NULL) {
        calcWaterForRoof(roofPtr, root);
        roofPtr = roofPtr->next;
    }

    calcWaterForTree(root, predecessor(root->key, root));
}


int checkStream (roof *pHighRoof, roof *r);
roof checkCover (roof pHighRoof, roof waterArea);
int calcWaterForRoof(roof *r, roofTree *root) {
    int waterSum = 0;

    roof waterArea;
    waterArea.startX = r->startX;
    waterArea.endX = r->endX;

    roofTree *pTree;
    roof *pHighRoof;

    while ((pTree = successor(getMin(*r), root)) != NULL) {
        pHighRoof = pTree->list;
        do {
            //this is where we check all the roofs above the one currently being calculated
            waterSum = checkStream(pHighRoof, r);
            waterArea = checkCover(*pHighRoof, waterArea);
        } while ((pHighRoof = pHighRoof->next) != NULL);
    }
}

int checkStream (roof *pHighRoof, roof *r){
    if (pHighRoof->streamCaught) return 0;
    bool lowStart;
    lowStart = pHighRoof->startY > pHighRoof->endY;
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

roof checkCover (roof pHighRoof, roof waterArea) {

}