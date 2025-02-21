#include <stdio.h>
#include <string.h>

#define MAX 100  

char stock[MAX][100];  
int top = -1;  


void addStock(char *item) {
    if (top < MAX - 1) {
        strcpy(stock[++top], item);
        printf("Stock Added: %s\n", item);
    } else {
        printf("Warehouse is full!\n");
    }
}

void dispatchStock() {
    if (top >= 0) {
        printf("Dispatching Item: %s\n", stock[top--]);
    } else {
        printf("No stock to dispatch!\n");
    }
}

void viewStock() {
    if (top >= 0) {
        printf("Remaining Stock: ");
        for (int i = 0; i <= top; i++) {
            printf("%s", stock[i]);
            if (i < top) printf(", ");
        }
        printf("\n");
    } else {
        printf("No stock available.\n");
    }
}

int main() {
    int choice;
    char item[100];

    while (1) {
        printf("\n1. Add Stock\n2. Dispatch Stock\n3. View Stock\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter Item Name: ");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = 0;  
                addStock(item);
                break;
            case 2:
                dispatchStock();
                break;
            case 3:
                viewStock();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
