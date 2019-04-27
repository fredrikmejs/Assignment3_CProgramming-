//
// Created by Bruger on 26-04-2019.
//

#include "Roof.h"

#ifndef ASSIGNMENT3_C_ROOFTREE_H
#define ASSIGNMENT3_C_ROOFTREE_H





// roofTree struct
struct roofTree {
    struct roof *list;

    int key;
    struct roofTree *parent, *left, *right;
};
typedef struct roofTree roofTree;

//binary search methods
roofTree * predecessor (int key, roofTree *root);
roofTree * successor (int key, roofTree *root);
roofTree * insert (roof *r, roofTree *root);
void delete (struct roof *r, roofTree *root);
void printInOrder (roofTree *root);

#endif //ASSIGNMENT3_C_ROOFTREE_H
