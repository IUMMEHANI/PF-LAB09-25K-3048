#include <stdio.h>

#define WARDS 3
#define BEDS 5

void inputStatus(int (*arr)[BEDS]) {
	int i,j;
    printf("Enter bed status (1=occupied, 0=empty):\n");
    for( i=0;i<WARDS;i++){
        for( j=0;j<BEDS;j++){
            printf("Ward %d Bed %d: ", i+1, j+1);
            scanf("%d", (*(arr+i)+j));      
        }
    }
}

void countBeds(int (*arr)[BEDS], int *occ, int *avail) {
    *occ = *avail = 0;
    int i,j;
    for( i=0;i<WARDS;i++){
        for( j=0;j<BEDS;j++){
            if(*(*(arr+i)+j) == 1) (*occ)++;
            else (*avail)++;
        }
    }
}

void displayStatus(int (*arr)[BEDS]) {
	int i,j;
    printf("\n--- Bed Status ---\n");
    for( i=0;i<WARDS;i++){
        printf("Ward %d: ", i+1);
        for( j=0;j<BEDS;j++){
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

int main() {
    int beds[WARDS][BEDS];
    int occ, avail;

    inputStatus(beds);
    countBeds(beds, &occ, &avail);
    displayStatus(beds);

    printf("\nOccupied: %d\nAvailable: %d\n", occ, avail);
    return 0;
}

