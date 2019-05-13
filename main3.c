#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct LinkedChar {
    char ch;
    struct LinkedChar *next;
};

typedef struct LinkedChar LinkedChar;
int changedColor(const char arr[], int size, FILE *fileptr);
int main() {

    //File pointer to input- and outputfile
    FILE *inputFile, *outputFile;


    //Path and name of the files
    char outputFilename[] = "C:\\Users\\fredr\\CLionProjects\\OpgaveC3\\NECKLACE.SOL";
    char inputFilename[] = "C:\\Users\\fredr\\CLionProjects\\OpgaveC3\\NECKLACE.DAT";

    inputFile = fopen(inputFilename, "r");

    //checks if the file is empty
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


    //Writes to the output file
    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Can't open output file %s!\n",
                outputFilename);
        exit(1);
    } else {
        fprintf(outputFile, "NECKLACE.SOL\n");
        fprintf(outputFile, "%s", arr1);
        fprintf(outputFile, "\n");
        changedColor(arr1,sizeArr1,outputFile);
        fprintf(outputFile,"\n");
        fprintf(outputFile,"\n");
        fprintf(outputFile, "%s", arr2);
        fprintf(outputFile, "\n");
        changedColor(arr2,sizeArr2,outputFile);
        fclose(outputFile);
    }

    return 0;
}

/*
 * function to get the longest chain in the necklaces.
 * The function returns the longest chain.
 */
int changedColor(const char arr[], int size, FILE *filePtr) {
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
    //The highest chain writes to the file
    if (maxChainBlue > maxChainRed) {

        return fprintf(filePtr,"%d between %d and %d",maxChainBlue,(indexBlue-1),indexBlue);
    } else {

        return fprintf(filePtr,"%d between %d and %d",maxChainRed,(indexRed-1),indexRed);
    }
}


