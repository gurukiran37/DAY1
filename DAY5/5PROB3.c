#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    struct Song *next;
} Song;

Song *head = NULL, *current = NULL;

void addSong(char *title) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    newSong->next = head ? head : newSong; 

    if (!head) {
        head = current = newSong;
    } else {
        Song *temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newSong;
    }
}

void nextSong() {
    if (current) {
        printf("Now Playing: %s\n", current->title);
        current = current->next;
    } else {
        printf("Playlist is empty!\n");
    }
}

int main() {
    int choice;
    char songTitle[100];

    while (1) {
        printf("\n1. Add Song\n2. Next Song\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();  /
        if (choice == 1) {
            printf("Enter Song Name: ");
            fgets(songTitle, sizeof(songTitle), stdin);
            songTitle[strcspn(songTitle, "\n")] = 0;
            addSong(songTitle);
        } else if (choice == 2) {
            nextSong();
        } else {
            break;
        }
    }
    return 0;
}
