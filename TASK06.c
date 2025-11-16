#include <stdio.h>

#define STU 4
#define CLS 5

void inputAttendance(int (*a)[CLS]) {
	int i,j;
    for( i=0;i<STU;i++){
        printf("Student %d: ", i + 1);
        for( j=0;j<CLS;j++){
            scanf("%d", (*(a+i)+j));
        }
    }
}

void checkPercentage(int (*a)[CLS]) {
	int i,j;
    for( i=0;i<STU;i++){
        int sum = 0;
        for( j=0;j<CLS;j++)
            sum += *(*(a+i)+j);
        float per = (sum / (float)CLS) * 100;
        printf("Student %d = %.2f%%", i + 1, per);
        if(per < 75) printf(" ---> WARNING!");
        printf("\n");
    }
}
int main() {
    int att[STU][CLS];
    inputAttendance(att);
    printf("\nAttendance Report:\n");
    checkPercentage(att);

    return 0;
}

