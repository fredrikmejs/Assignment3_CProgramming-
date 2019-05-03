//
// Created by Bruger on 27-04-2019.
//
#include <stdbool.h>
#ifndef ASSIGNMENT3_C_ROOF_H
#define ASSIGNMENT3_C_ROOF_H

//#######################    roof related     ##################################
//roof struct
struct roof {
    int startX;
    int startY;

    int endX;
    int endY;

    bool streamCaught;
    int waterCollected;

    struct roof  *next;
};

typedef struct roof roof;

//roof methods
void printRoof(roof roof);
bool hasNext (roof roof);
int getMin(roof r);

#endif //ASSIGNMENT3_C_ROOF_H
