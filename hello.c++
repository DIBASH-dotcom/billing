#include <stdio.h>

int main() {
    char name[10][100];
    int bills[10][6];  
    int total[10] = {0};
    float discount[10], vat[10], final_amount[10];
    float maxAmount = -1, minAmount = 999999;
    int i, j;
    int maxIndex = -1, minIndex = -1;

    for(i = 0; i < 10; i++) {
        printf("\nEnter the name of customer %d: ", i+1);
        scanf("%s", name[i]);

        total[i] = 0;

        for(j = 0; j < 6; j++) {
            printf("Enter the bill for month %d: ", j+1);
            scanf("%d", &bills[i][j]);

            if(bills[i][j] < 0) {
                printf("Invalid bill! Please enter again.\n");
                j--; 
                continue;
            }

            total[i] += bills[i][j];
        }

        
        if(total[i] >= 2000)
            discount[i] = 0.15 * total[i];
        else if(total[i] >= 1000)
            discount[i] = 0.10 * total[i];
        else if(total[i] >= 500)
            discount[i] = 0.05 * total[i];
        else
            discount[i] = 0;

        float priceAfterDiscount = total[i] - discount[i];
        vat[i] = priceAfterDiscount * 0.13;
        final_amount[i] = priceAfterDiscount + vat[i];

        if(final_amount[i] > maxAmount) {
            maxAmount = final_amount[i];
            maxIndex = i;
        }

        if(final_amount[i] < minAmount) {
            minAmount = final_amount[i];
            minIndex = i;
        }
    }


    for(i = 0; i < 10; i++) {
        printf("\nCustomer: %s", name[i]);
        printf("\nTotal Bill: %d", total[i]);
        printf("\nDiscount: %.2f", discount[i]);
        printf("\nVAT: %.2f", vat[i]);
        printf("\nFinal Amount: %.2f\n", final_amount[i]);
    }

    printf("\nHighest Final Amount: %s = %.2f", name[maxIndex], maxAmount);
    printf("\nLowest Final Amount: %s = %.2f\n", name[minIndex], minAmount);

    return 0;
}
