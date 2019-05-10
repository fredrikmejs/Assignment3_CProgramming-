#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct LinkedChar {
    char ch;
    struct LinkedChar *next;
};
typedef struct LinkedChar LinkedChar;

char changedColor(const char arr[],int size);
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
        fprintf(outputFile, "NECLACE.SOL\n");
        fprintf(outputFile, arr1);
        fprintf(outputFile, "\n");
        fprintf(outputFile, arr2);
        fprintf(outputFile, "\n");
        fprintf(outputFile, "%c", changedColor(arr1, sizeArr1));
        fprintf(outputFile, "\n");
        fprintf(outputFile, "%c", changedColor(arr2, sizeArr2));
        fclose(outputFile);
    }
    return 0;

}

char changedColor(const char arr[], int size) {
    int blue = 0, red = 0, maxChainBlue = 0,
            maxChainRed = 0, indexBlue = -1, indexRed = -1;
    char currentColor = arr[0];

    for (int i = 0; i < size; ++i) {
        if (currentColor == 'r') {
            if (arr[i] == 'r' && blue > 0) {
                if (maxChainRed < (blue + red)) {
                    maxChainRed = blue + red;
                    indexRed = i - blue;
                    red = 0;
                    currentColor = 'b';
                }
            } else if (arr[i] == 'r') {
                red++;
            } else if (arr[i] == 'b' || arr[i] == '@') {
                blue++;
            }
        }
        if (currentColor == 'b') {
            if (arr[i] == 'b' && red > 0) {
                if (maxChainBlue < (blue + red)) {
                    maxChainBlue = blue + red;
                    indexBlue = i - red;
                    blue = 0;
                    currentColor = 'r';
                }
            } else if (arr[i] == 'b') {
                blue++;
            } else if (arr[i] == 'r' || arr[i] == '@') {
                red++;
            }
        }
    }
    int blueMinus = indexBlue - 1;
    int redMinus = indexRed - 1;

    if (maxChainBlue > maxChainRed) {
        char String = printf("%d between %d and %d\n", maxChainBlue, blueMinus, indexBlue);
        return String;
    } else {
        char String = printf("%d between %d and %d\n", maxChainRed, redMinus, indexRed);
        return String;
    }
}


