#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int top_of_range;
    int random_number;
    int guess;
    int attempts = 0;

    // welcome message
    printf("Welcome to the Number Guessing Game!\n");
    printf("Enter the top of the range: ");
    if (scanf("%d", &top_of_range) != 1 || top_of_range <= 0) {
        printf("Please type a number greater than 0 next time.\n");
        return 0;
    }

    // Initialize random seed
    srand(time(0));
    random_number = rand() % (top_of_range + 1);

    // Guessing loop
    while (1) {
        attempts++;
        printf("Guess a number: ");
        if (scanf("%d", &guess) != 1) {
            printf("Please type a number next time.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        if (guess == random_number) {
            printf("You guessed the number!\n");
            break;
        } else if (guess > random_number) {
            printf("Too high.\n");
        } else {
            printf("Too low.\n");
        }
    }

    printf("You guessed the number in %d guesses.\n", attempts);
    return 0;
}
