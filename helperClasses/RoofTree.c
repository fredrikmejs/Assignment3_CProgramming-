//
// Created by Bruger on 26-04-2019.
//

#include "RoofTree.h"
#include "Roof.h"
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>




//###############################   Search Tree related    #######################################



/*
 *************    b-tree methods     ****************
 */


/**
 *
 * @param key the key of which one wishes to find the predecessor
 * @param root the root of the search tree
 * @return the element with the greatest key smaller than @param key
 */
roofTree * predecessor (int key, roofTree *root){
    if (root == NULL) return NULL;
    //if (root->key == key) return root;
    if (key <= root->key) return predecessor(key, root->left);
    roofTree *t = predecessor(key, root->right);
    return (t != NULL ? t : root); //return t or root
}


/**
 *
 * @param key the key of which one wishes to find the predecessor
 * @param root the root of the search tree
 * @return the element with the smallest key greater than @param key
 */
roofTree * successor (int key, roofTree *root){
    if (root == NULL) return NULL;
    //if (root->key == key && root->left->key == key) return root;
    if (key >= root->key) return successor(key, root->right);
    struct roofTree *t = successor(key, root->left);
    return (t != NULL ? t : root); //return t or root
}

/**
 * inserts a new roof in the correct place
 * @param r the roof to be inserted
 * @param root the root of the search tree
 * @return void
 */
roofTree * insert (roof *r, roofTree *root) {
    if (root == NULL) {
        root = malloc(sizeof(roofTree));
        root->list = r;
        root->key = getMax(*r);
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;

        return root;
    }

    if (getMax(*r) == root->key) {
        roof *roofPtr = root->list;
        while (roofPtr->next != NULL){
            roofPtr = roofPtr->next;
        }
        roofPtr->next = r;
    } else if (getMax(*r) > root->key) {
        root->right = insert(r, root->right);
        root->right->parent = root;
        return
    } else {
        root->left = insert(r, root->left);
        root->left->parent = root;
    }

}

void delete (struct roof *r, roofTree *root){
    //TODO implement
}

/**
 * Prints all roofs in ascending order of keys
 * @param root the root of the tree or sub-tree being printed
 */
void printInOrder (roofTree *root){
    if (root == NULL) return;
    printInOrder(predecessor(root->key, root));
    struct roof *roofPtr = root->list;
    while (roofPtr != NULL) {
        printRoof(*roofPtr);
    }
    printInOrder(successor(root->key, root));
}