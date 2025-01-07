#include <stdio.h>
#include <string.h>

int main() {
    char play[10];
    char name[50];
    char answer[100];

    printf("Welcome to the Adventure Game!\n");

    printf("Do you want to play? (yes/no): ");
    scanf("%s", play);

    if (strcmp(play, "yes") == 0) {
        printf("What is your name? ");
        scanf("%s", name);
        printf("Hello, %s! Let's start your adventure!\n", name);

        printf("You're on a dirt road, and it has come to an end. You can go left or right. Which way will you go? (left/right): ");
        scanf("%s", answer);

        if (strcmp(answer, "left") == 0) {
            printf("You come to a lake. There is a boat and path around the lake. You can take the boat or walk around. Which way will you do? (boat/walk): ");
            scanf("%s", answer);

            if (strcmp(answer, "boat") == 0) {
                printf("You row accross the lake but encounter a storm. The boat capsizes and you drown. Game Over!\n");
            } else if (strcmp(answer, "walk") == 0) {
                printf("You walk for a while and find a house. Do you enter the house or keep walking? (enter/walk): ");
                scanf("%s", answer);

                if (strcmp(answer, "enter") == 0) {
                    printf("You enter the house and find a treasure chest. You open it and find a golden coin! You win!\n");
                } else if (strcmp(answer, "walk") == 0) {
                    printf("You keep walking and find a monster. It eats you. Game Over!\n");
                } else {
                    printf("Not a valid option. Game Over!\n");
                }
            } else {
                printf("Not a valid option. Game Over!\n");
            }
        } else if (strcmp(answer, "right") == 0) {
            printf("You come to a bridge, but it looks weak. Do you cross the bridge or head back? (cross/back): ");
            scanf("%s", answer);

            if (strcmp(answer, "cross") == 0) {
                printf("You carefully cross the bridge and see a treasure chest. Do you open it or leave it? (open/leave): ");
                scanf("%s", answer);

                if (strcmp(answer, "open") == 0) {
                    printf("You open the chest. The chest is full of gold and jewels. You win!\n");
                } else if (strcmp(answer, "leave") == 0) {
                    printf("You leave the treasure and walk away safely but miss out on riches. You survive, but no treasure for you. Game Over!\n");
                } else {
                    printf("Not a valid option. Game Over!\n");
                }
            } else if (strcmp(answer, "back") == 0) {
                printf("You turn back and run into monster. It eats you. Game Over!\n");
            } else {
                printf("Not a valid option. Game Over!\n");
            }
        } else {
            printf("Not a valid option. Game Over!\n");
        }

        printf("Thanks for playing %s!\n", name);
    } else {
        printf("Okay, goodbye!\n");
    }

    return 0;
}
