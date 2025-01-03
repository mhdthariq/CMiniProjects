#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int get_choice_number(char *choice) {
    if (strcmp(choice, "rock") == 0) return 0;
    if (strcmp(choice, "paper") == 0) return 1;
    if (strcmp(choice, "scissors") == 0) return 2;
    return -1;
}

int main() {
    int user_wins = 0;
    int computer_wins = 0;
    char user_input[10];
    char *options[3] = {"rock", "paper", "scissors"};

    // Welcome message
    printf("Welcome to the Rock Paper Scissors Game!\n");

    // Initialize random seed
    srand(time(0));

    while (1) {
        printf("Enter 'rock', 'paper', 'scissors', or 'q' to quit: ");
        scanf("%s", user_input);

        if (strcmp(user_input, "q") == 0) {
            break;
        }

        int user_choice = get_choice_number(user_input);
        if (user_choice == -1) {
            printf("Invalid input. Please enter 'rock', 'paper', or 'scissors'.\n");
            continue;
        }

        // rock: 0, paper: 1, scissors: 2
        int random_number = rand() % 3;
        printf("Computer chose %s.\n", options[random_number]);

        if ((user_choice == 0 && random_number == 2) ||  // rock beats scissors
            (user_choice == 1 && random_number == 0) ||  // paper beats rock
            (user_choice == 2 && random_number == 1)) {  // scissors beat paper
            printf("You win!\n");
            user_wins++;
        } else if (user_choice == random_number) {
            printf("It's a tie!\n");
        } else {
            printf("You lose!\n");
            computer_wins++;
        }
    }

    // Final score
    printf("Thanks for playing! Your final score is:\n");
    printf("You: %d\n", user_wins);
    printf("Computer: %d\n", computer_wins);
    printf("Goodbye!\n");

    return 0;
}
