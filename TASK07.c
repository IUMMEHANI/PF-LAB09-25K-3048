#include <stdio.h>

#define P 11

void inputRuns(int *arr) {
	int i;
    printf("Enter runs of 11 players:\n");
    for( i=0;i<P;i++)
        scanf("%d", arr+i);
}
int totalRuns(int *arr) {
    int t = 0;
    int i;
    for( i=0;i<P;i++)
        t += *(arr+i);
    return t;
}
float averageRuns(int *arr) {
    return totalRuns(arr) / (float)P;
}
void highest(int *arr) {
    int max = *arr, idx = 0;
    int i;
    for( i=1;i<P;i++){
        if(*(arr+i) > max){
            max = *(arr+i);
            idx = i;
        }
    }
    printf("Highest scorer = %d (Player %d)\n", max, idx);
}
int main() {
    int runs[P];
    inputRuns(runs);
    printf("Total runs = %d\n", totalRuns(runs));
    printf("Average runs = %.2f\n", averageRuns(runs));
    highest(runs);
    return 0;
}

