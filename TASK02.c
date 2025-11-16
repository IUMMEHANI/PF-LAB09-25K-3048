#include <stdio.h>

#define N 5

void deposit(float *arr, int index, float amount) {
    *(arr + index) += amount;  
}
void withdraw(float *arr, int index, float amount) {
    *(arr + index) -= amount;
}
float average(float *arr) {
    int i;
    float sum = 0;
    for (i = 0; i < N; i++)
        sum += *(arr + i);
    return sum / N;
}
int main() {
    float balance[N];
    int choice, index, i;
    float amount;
    printf("Enter initial balances of %d customers:\n", N);
    for (i = 0; i < N; i++) {
        printf("Customer %d: ", i + 1);
        scanf("%f", balance + i);  
    }
    do {
        printf("\n--- BANK MENU ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Show Average Balance\n");
        printf("4. Show All Balances\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { 
            printf("Invalid input. Exiting.\n");
            return 0;
        }
        switch (choice) {
            case 1:
                printf("Enter customer index (1 - %d): ", N);
                scanf("%d", &index);
                if (index < 1 || index > N) {
                    printf("Invalid customer index.\n");
                    break;
                }
                index = index - 1; 
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                if (amount < 0) {
                    printf("Invalid amount.\n");
                    break;
                }
                deposit(balance, index, amount);
                printf("Deposit successful. New balance: %.2f\n", *(balance + index));
                break;
            case 2:
                printf("Enter customer index (1 - %d): ", N);
                scanf("%d", &index);
                if (index < 1 || index > N) {
                    printf("Invalid customer index.\n");
                    break;
                }
                index = index - 1; 
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                if (amount < 0) {
                    printf("Invalid amount.\n");
                    break;
                }
                if (amount > *(balance + index)) {
                    printf("Insufficient funds. Current balance: %.2f\n", *(balance + index));
                    break;
                }
                withdraw(balance, index, amount);
                printf("Withdrawal successful. New balance: %.2f\n", *(balance + index));
                break;
            case 3:
                printf("Average balance: %.2f\n", average(balance));
                break;
            case 4:
                printf("\n--- ACCOUNT BALANCES ---\n");
                for (i = 0; i < N; i++)
                    printf("Customer %d: %.2f\n", i + 1, *(balance + i)); 
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}

