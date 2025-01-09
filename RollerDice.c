#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PLAYERS 2
#define MAX_PLAYERS 4

// Function to roll a dice
int roll_dice() {
    return (rand() % 6) + 1;
}

// Get the number of players
int get_num_players() {
    int players;
    while (1) {
        printf("Enter the number of players (%d-%d): ", MIN_PLAYERS, MAX_PLAYERS);
        if (scanf("%d", &players) == 1 && players >= MIN_PLAYERS && players <= MAX_PLAYERS) {
            return players;
        }
        printf("Invalid input. Please enter a number between %d and %d.\n", MIN_PLAYERS, MAX_PLAYERS);
        while (getchar() != '\n'); // Clear buffer
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Dice Rolling Game!\n");

    // Game setup
    int players = get_num_players();
    int max_score = players * 10;
    int player_scores[MAX_PLAYERS] = {0};

    // Main game loop
    while (1) {
        int game_over = 0;

        for (int i = 0; i < players; i++) {
            printf("\nPlayer %d's turn.\n", i + 1);
            printf("Current total score: %d\n", player_scores[i]);

            int current_score = 0;
            char choice;

            // Player turn loop
            while (1) {
                printf("Roll the dice? (y/n): ");
                scanf(" %c", &choice);

                if (choice == 'y' || choice == 'Y') {
                    int value = roll_dice();
                    if (value == 1) {
                        printf("Oops! You rolled a 1. Your turn is over!\n");
                        current_score = 0;
                        break;
                    } else {
                        current_score += value;
                        printf("You rolled a %d. Current turn score: %d.\n", value, current_score);
                    }
                } else if (choice == 'n' || choice == 'N') {
                    printf("Okay, ending your turn.\n");
                    break;
                } else {
                    printf("Invalid input. Please enter 'y' to roll or 'n' to end your turn.\n");
                }
            }

            player_scores[i] += current_score;
            printf("Total score after turn: %d.\n", player_scores[i]);

            if (player_scores[i] >= max_score) {
                game_over = 1;
                break;
            }
        }

        if (game_over) {
            break;
        }
    }

    // Determine the winner
    int winning_score = 0;
    int winner = -1;
    for (int i = 0; i < players; i++) {
        if (player_scores[i] > winning_score) {
            winning_score = player_scores[i];
            winner = i + 1;
        }
    }

    printf("\nCongratulations! Player %d wins with a total score of %d!\n", winner, winning_score);

    return 0;
}
