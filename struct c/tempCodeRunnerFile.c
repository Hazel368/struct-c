#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    char size;
    char sizeName[10];
    int price;
} Clothing;

typedef struct {
    Clothing item;
    int discount, quantity;
} Transaction;

int main() {
    int i, numTransactions, dataSize;
    double totalAmount = 0, tax, totalPayment;

    Transaction receipt[MAX];
    Clothing inventory[] = { {'S', "Small", 36000}, {'M', "Medium", 43000}, {'L', "Large", 62000} };

    printf("\t\tLARIS Store\n");
    printf("\t\tPrice List\n");
    printf("-----------------------------------------------------\n");
    printf("Clothing Size\tSize Name\tPrice Per Piece\n");
    for (i = 0; i < 3; i++) {
        printf("%c\t\t%s\t\t%d\n", inventory[i].size, inventory[i].sizeName, inventory[i].price);
    }
    printf("-----------------------------------------------------\n");
    printf("Get a 20%% discount for purchases over 10 pieces...\n");
    printf("Don't forget the tax... (10%% x (price - discount))\n");
    printf("How many transactions (max 3)? ");
    scanf("%d", &dataSize);
    if (dataSize < 1 || dataSize > 3) {
        printf("Invalid Input");
        exit(0);
    }

    for (i = 0; i <= dataSize - 1; i++) {
        printf("\nTransaction %d\n", i + 1);
        printf("Size [S/M/L]: ");
        receipt[i].item.size = getchar(); // using getchar to consume the newline character
        receipt[i].item.size = getchar(); // read the actual character

        if (receipt[i].item.size == 'S' || receipt[i].item.size == 's') {
            strcpy(receipt[i].item.sizeName, "Small");
            receipt[i].item.price = 36000;
        } else if (receipt[i].item.size == 'M' || receipt[i].item.size == 'm') {
            strcpy(receipt[i].item.sizeName, "Medium");
            receipt[i].item.price = 43000;
        } else if (receipt[i].item.size == 'L' || receipt[i].item.size == 'l') {
            strcpy(receipt[i].item.sizeName, "Large");
            receipt[i].item.price = 62000;
        }

        printf("\nQuantity = ");
        scanf("%d", &receipt[i].quantity);

        if (receipt[i].quantity >= 10) {
            receipt[i].discount = receipt[i].quantity * receipt[i].item.price * 0.2;
        } else {
            receipt[i].discount = 0.00;
        }
    }

    numTransactions = i;

    printf("\nYour Shopping Receipt: \n");
    printf("\t\t\tLARIS Store\n\n");
    printf("======================================================================\n");
    printf("No\tSize Name\tPrice Per Unit\tQty\tDiscount\tTotal Price\n");
    printf("======================================================================\n");

    for (i = 0; i < numTransactions; i++) {
        printf("%d\t%s\t\t%d\t\t%d\t%d\t%d\n", i + 1, receipt[i].item.sizeName, receipt[i].item.price,
               receipt[i].quantity, receipt[i].discount, (receipt[i].item.price * receipt[i].quantity) - receipt[i].discount);

        totalAmount = totalAmount + ((receipt[i].item.price * receipt[i].quantity) - receipt[i].discount);
    }

    printf("======================================================================\n");
    printf("\t\t\t\tTotal Amount \t\t= %.2lf\n", totalAmount);

    tax = totalAmount * 0.1;
    printf("\t\t\t\tTax on your total amount = %.2lf\n", tax);
    totalPayment = totalAmount + tax;
    printf("\t\t\t\tYour Total Payment \t= %.2lf\n", totalPayment);
    printf("\t\tTHANK YOU FOR VISITING LARIS Store\n");

    return 0;
}
