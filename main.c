#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


struct roof {
    int startX;
    int startY;

    int endX;
    int endY;

    int waterCollected;

    int key;
    struct roof *parent, *left, *right;
};

//roof methods
void printRoof(struct roof roof);
int getMax(struct roof r);

//binary search methods
void setKey(struct roof *r);
struct roof * predecessor (int key, struct roof *root);
struct roof * successor (int key, struct roof *root);
struct roof * insert (struct roof *r, struct roof *root);
void delete (struct roof *r, struct roof *root);
void printInOrder (struct roof *root);

int main() {
    int n;
    scanf("%d", &n);
    struct roof *roofPtr, *root;
    root = NULL;

    for (int j = 0; j < n; j++) {
        roofPtr = malloc(sizeof(struct roof));
        scanf("%d %d %d %d", &(roofPtr->startX), &(roofPtr->startY), &(roofPtr->endX), &(roofPtr->endY));
        roofPtr->waterCollected = -1;

        roofPtr->parent = NULL;
        roofPtr->left = NULL;
        roofPtr->right = NULL;
        setKey(roofPtr);
        root = insert(roofPtr, root);
    }

    printInOrder(root);
    printf("%s", "\n\n__________________________________\n");


    return 0;

}


/*
 **************    roof methods    **************
 */
/**
 * print the data of a roof in an easy to read way
 * @param roof  the roof being printed
 */
void printRoof (struct roof roof) {
    printf("[key = %d]\t(%d, %d), (%d, %d)\n", roof.key, roof.startX, roof.startY, roof.endX, roof.endY);
}

/**
 * Returns the greatest height of the roof
 */
int getMax(struct roof r) {
    int rMax;

    if (r.startY > r.endY)
        rMax = r.startY;
    else
        rMax = r.endY;


    return rMax;
}



/*
 *************    b-tree methods     ****************
 */

/**
 * Automatically sets the key according to our convention
 * @param r the roof getting it's key set
 */
void setKey(struct roof *r){
    r->key = getMax(*r);
}

/**
 *
 * @param key the key of which one wishes to find the predecessor
 * @param root the root of the search tree
 * @return the element with the greatest key smaller than @param key
 */
struct roof * predecessor (int key, struct roof *root){
    if (root == NULL) return NULL;
    //if (root->key == key) return root->left;
    if (key <= root->key) return predecessor(key, root->left);
    struct roof *t = predecessor(key, root->right);
    return (t != NULL ? t : root); //return t or root
}


/**
 *
 * @param key the key of which one wishes to find the predecessor
 * @param root the root of the search tree
 * @return the element with the smallest key greater than @param key
 */
struct roof * successor (int key, struct roof *root){
    if (root == NULL) return NULL;
    if (root->key == key && root->left->key == key) return root->left;
    if (key >= root->key) return successor(key, root->right);
    struct roof *t = successor(key, root->left);
    return (t != NULL ? t : root); //return t or root
}

/**
 * inserts a new roof in the correct place
 * @param r the roof to be inserted
 * @param root the root of the search tree
 * @return void
 */
struct roof * insert (struct roof *r, struct roof *root) {
    if (root == NULL) {
        root = r;
        return r;
    }
    if (r->key > root->key)
        root->right = insert(r, root->right);
    else
        root->left = insert(r, root->left);

}

void delete (struct roof *r, struct roof *root){
    //TODO implement
}

/**
 * Prints all roofs in ascending order of keys
 * @param root the root of the tree or sub-tree being printed
 */
void printInOrder (struct roof *root){
    if (root == NULL) return;
    printInOrder(predecessor(root->key, root));
    printRoof(*root);
    printInOrder(successor(root->key, root));
}