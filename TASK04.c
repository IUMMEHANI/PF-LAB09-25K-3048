#include <stdio.h>
#define MAXR 10
#define MAXC 10
void searchElement(int (*arr)[MAXC], int rows, int cols, int key) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (*(*(arr + i) + j) == key) {   
                printf("Element %d found at Row %d, Column %d\n",
                       key, i, j);
                return;
            }
        }
    }
    printf("Element %d not found in the array.\n", key);
}

int main() {
    int arr[MAXR][MAXC];
    int rows, cols, i, j, key;
    printf("Enter number of rows (max %d): ", MAXR);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAXC);
    scanf("%d", &cols);
    if (rows < 1 || cols < 1 || rows > MAXR || cols > MAXC) {
        printf("Invalid size.\n");
        return 0;
    }
    printf("\nEnter elements of %d x %d array:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", (*(arr + i) + j));        
        }
    }
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    searchElement(arr, rows, cols, key);
    return 0;
}

