#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct LinkedChar {
    char ch;
    struct LinkedChar *next;
};
typedef struct LinkedChar LinkedChar;
int indexC(const char arr[], int size);
int changedColor(const char arr[], int size);
int main() {

    FILE *inputFile, *outputFile;
    char *mode = "r";
    char outputFilename[] = "C:\\Users\\fredr\\CLionProjects\\OpgaveC3\\NECKLACE.SOL";
    char inputFilename[] = "C:\\Users\\fredr\\CLionProjects\\OpgaveC3\\NECKLACE.DAT";

    inputFile = fopen(inputFilename, mode);

    if (inputFile == NULL) {
        fprintf(stderr, "Can't open input file in.list!\n");
        exit(EXIT_FAILURE);
    }

    //Reads from file and saves it in two linked lists
    LinkedChar list1, list2;
    list1.next = NULL;
    list2.next = NULL;
    int sizeArr1 = 0, sizeArr2 = 0, newline = 0;
    LinkedChar *pChar1 = &list1, *pChar2 = &list2;
    char ch;
    do {
        ch = fgetc(inputFile);

        if (ch == '\n') {
            newline++;
            continue;
        }
        if (ch == EOF)
            break;

        //adds one to array size of the line it is reading on.
        if (newline == 1) {
            sizeArr1++;
            pChar1->ch = ch;
            pChar1 = (pChar1->next = malloc(sizeof(LinkedChar)));
        } else if (newline == 2) {
            sizeArr2++;
            pChar2->ch = ch;
            pChar2 = (pChar2->next = malloc(sizeof(LinkedChar)));
        }
    } while (true);
    pChar1->ch = '/';
    pChar2->ch = '/';
    fclose(inputFile);


    //copy the lists to arrays
    char arr1[sizeArr1+1];
    char arr2[sizeArr2+1];
    pChar1 = &list1;
    pChar2 = &list2;
    for (int i = 0; i < (sizeArr1 > sizeArr2 ? sizeArr1 : sizeArr2); i++) {
        if (i < sizeArr1) {
            arr1[i] = pChar1->ch;
            pChar1 = pChar1->next;
        }
        if (i < sizeArr2) {
            arr2[i] = pChar2->ch;
            pChar2 = pChar2->next;
        }
    }


    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Can't open output file %s!\n",
                outputFilename);
        exit(1);
    } else {
        fprintf(outputFile, "NECKLACE.SOL\n");
        fprintf(outputFile, "%s", arr1);
        fprintf(outputFile, "\n");
        int a = indexC(arr1,sizeArr1);
        fprintf(outputFile,"%d",changedColor(arr1,sizeArr1));
        fprintf(outputFile," between ");
        fprintf(outputFile,"%d",a);
        fprintf(outputFile," and ");
        fprintf(outputFile,"%d",(a-1));
        fprintf(outputFile,"\n");
        fprintf(outputFile,"\n");
        fprintf(outputFile, "%s", arr2);
        fprintf(outputFile, "\n");
        int b = indexC(arr2,sizeArr2);
        fprintf(outputFile,"%d",changedColor(arr2,sizeArr2));
        fprintf(outputFile," between ");
        fprintf(outputFile,"%d",b);
        fprintf(outputFile," and ");
        fprintf(outputFile,"%d",(b-1));
        fclose(outputFile);
    }

    return 0;
}

int indexC(const char arr[], int size){
    int blue = 0, red = 0, maxChainBlue = 0,
            maxChainRed = 0, indexBlue = -1, indexRed = -1;
    char currentColor = arr[0];


    for (int i = 0; i < size; ++i) {

        if (currentColor == 'r') {
            if (arr[i] == 'b' || arr[i] == '@') {
                blue++;
            }
            if (arr[i] == 'r' && blue > 0) {
                if (maxChainRed < (blue + red)) {
                    maxChainRed = blue + red;
                    indexRed = i - blue;
                }
                red = 0;
                currentColor = 'b';
            }if (arr[i] == 'r') {
                red++;
            }
        } else if (currentColor == 'b') {
            if (arr[i] == 'r' || arr[i] == '@') {
                red++;
            }
            if (arr[i] == 'b' && red > 0) {
                if (maxChainBlue < (blue + red)) {
                    maxChainBlue = blue + red;
                    indexBlue = i - red;
                }
                blue = 0;
                currentColor = 'r';
            }
            if (arr[i] == 'b') {
                blue++;
            }
        }
    }

    if (maxChainBlue > maxChainRed) {
        return indexBlue;
    } else {
        return indexRed;
    }
}


int changedColor(const char arr[], int size) {
    int blue = 0, red = 0, maxChainBlue = 0,
            maxChainRed = 0, indexBlue = -1, indexRed = -1;
    char currentColor = arr[0];


    for (int i = 0; i < size; ++i) {

        if (currentColor == 'r') {
            if (arr[i] == 'b' || arr[i] == '@') {
                blue++;
            }
            if (arr[i] == 'r' && blue > 0) {
                if (maxChainRed < (blue + red)) {
                    maxChainRed = blue + red;
                    indexRed = i - blue;
                }
                red = 0;
                currentColor = 'b';
            }if (arr[i] == 'r') {
                red++;
            }
        } else if (currentColor == 'b') {
            if (arr[i] == 'r' || arr[i] == '@') {
                red++;
            }
            if (arr[i] == 'b' && red > 0) {
                if (maxChainBlue < (blue + red)) {
                    maxChainBlue = blue + red;
                    indexBlue = i - red;
                }
                blue = 0;
                currentColor = 'r';
            }
            if (arr[i] == 'b') {
                blue++;
            }
        }
    }

    if (maxChainBlue > maxChainRed) {
        return maxChainBlue;
    } else {

        return maxChainRed;
    }
}


