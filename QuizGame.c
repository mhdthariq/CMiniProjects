#include <stdio.h>
#include <string.h>

int main() {
    char playing[10];
    char answer[100];
    int score = 0;

    // Welcome message
    printf("Welcome to the Computer Quiz Game!\n");
    printf("Are you ready to play? (yes/no): ");
    scanf("%s", playing);
    getchar(); // Clear buffer

    // Check if user wants to play
    if (strcmp(playing, "yes") != 0) {
        printf("Goodbye!\n");
        return 0;
    }

    printf("\nLet's start the quiz!\n\n");

    // Array of questions and answers
    char *questions[5] = {
        "What does CPU stand for?",
        "What does GPU stand for?",
        "What does RAM stand for?",
        "What does PSU stand for?",
        "What does Motherboard stand for?"
    };

    char *answers[5] = {
        "central processing unit",
        "graphics processing unit",
        "random access memory",
        "power supply",
        "main board"
    };

    // Loop through questions
    for (int i = 0; i < 5; i++) {
        printf("%s ", questions[i]);
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0; // Remove newline

        if (strcmp(answer, answers[i]) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is: %s\n\n", answers[i]);
        }
    }

    // Display final score
    printf("You got %d out of 5 correct!\n", score);
    printf("Your final score is %.2f%%.\n", (score / 5.0) * 100);

    return 0;
}
