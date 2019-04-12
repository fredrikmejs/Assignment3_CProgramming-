#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = scanf("%d");
    int arr[n*4];
    for (int j = 0; j < sizeof(arr); j++) {
        printf("Please enter a number: ");
        scanf("%d", &arr[j]);
        if (arr[j] == 0) {
            break;
        }
    }


    return 0;

}