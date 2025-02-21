#include <stdio.h>
#include <string.h>
#define MAX 100

char backStack[MAX][100];
char forwardStack[MAX][100];
char currentURL[100];
int backTop = -1, forwardTop = -1;

void push(char stack[MAX][100], int *top, char *url) {
    if (*top < MAX - 1) {
        strcpy(stack[++(*top)], url);
    }
}

char* pop(char stack[MAX][100], int *top) {
    return (*top >= 0) ? stack[(*top)--] : NULL;
}

void visit(char *url) {
    if (strlen(currentURL) > 0) {
        push(backStack, &backTop, currentURL);
    }
    strcpy(currentURL, url);
    forwardTop = -1; 
    printf("Visited: %s\n", currentURL);
}

void goBack() {
    if (backTop >= 0) {
        push(forwardStack, &forwardTop, currentURL);
        strcpy(currentURL, pop(backStack, &backTop));
        printf("Current Page: %s\n", currentURL);
    } else {
        printf("No backward history.\n");
    }
}

void goForward() {
    if (forwardTop >= 0) {
        push(backStack, &backTop, currentURL);
        strcpy(currentURL, pop(forwardStack, &forwardTop));
        printf("Current Page: %s\n", currentURL);
    } else {
        printf("No forward history.\n");
    }
}
int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n1. Visit URL\n2. Go Back\n3. Go Forward\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0; 
                visit(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                printf("Exiting browser...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
