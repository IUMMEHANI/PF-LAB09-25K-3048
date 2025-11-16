#include <stdio.h>

void printData(void *ptr, char type) {
    if (type == 'i') {
        printf("Integer value: %d\n", *(int*)ptr);
    }
    else if (type == 'f') {
        printf("Float value: %.2f\n", *(float*)ptr);
    }
    else if (type == 'c') {
        printf("Character value: %c\n", *(char*)ptr);
    }
    else {
        printf("Invalid type code.\n");
    }
}
int main() {
    char type;
    int iValue;
    float fValue;
    char cValue;
    printf("Enter type code (i = int, f = float, c = char): ");
    scanf(" %c", &type);  
    if (type == 'i') {
        printf("Enter an integer: ");
        scanf("%d", &iValue);
        printData(&iValue, 'i');
    }
    else if (type == 'f') {
        printf("Enter a float: ");
        scanf("%f", &fValue);
        printData(&fValue, 'f');
    }
    else if (type == 'c') {
        printf("Enter a character: ");
        scanf(" %c", &cValue);
        printData(&cValue, 'c');
    }
    else {
        printf("Invalid type code entered.\n");
    }
    return 0;
}

