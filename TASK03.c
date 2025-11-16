#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 50

int isVowel(char c) {
    char v[] = "aeiouAEIOU";
    int i;
    for (i = 0; v[i] != '\0'; i++) {
        if (c == v[i])
            return 1;
    }
    return 0;
}
void replaceVowels(char (*arr)[MAX_COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        j = 0;
        while (*(*(arr + i) + j) != '\0') {       
            if (isVowel(*(*(arr + i) + j))) {
                *(*(arr + i) + j) = '*';          
            }
            j++;
        }
    }
}

int main() {
    int rows, i;
    char data[MAX_ROWS][MAX_COLS];
    printf("How many strings do you want to enter (max %d)? ", MAX_ROWS);
    scanf("%d", &rows);
    if (rows < 1 || rows > MAX_ROWS) {
        printf("Invalid number of rows.\n");
        return 0;
    }
    printf("\nEnter %d strings:\n", rows);
    for (i = 0; i < rows; i++) {
        printf("String %d: ", i + 1);
        scanf("%s", data[i]);     
    }
    replaceVowels(data, rows);
    printf("\n--- Updated Strings ---\n");
    for (i = 0; i < rows; i++) {
        printf("%s\n", data[i]);
    }
    return 0;
}

