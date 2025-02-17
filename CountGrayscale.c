#include <stdio.h>
#include <stdlib.h>

int main() {
    float R, G, B, gray, R1, G1, B1;
    char choice;

    do {
        // Header
        printf("\n====================================\n");
        printf("       RGB to Grayscale Converter\n");
        printf("====================================\n");

        // Input RGB values
        printf("Enter R value (0-255): ");
        if (scanf("%f", &R) != 1) break;
        printf("Enter G value (0-255): ");
        if (scanf("%f", &G) != 1) break;
        printf("Enter B value (0-255): ");
        if (scanf("%f", &B) != 1) break;

        // Clear any leftover newline characters
        while(getchar() != '\n');

        // Calculate grayscale components
        R1 = 0.2989f * R;
        G1 = 0.5870f * G;
        B1 = 0.1140f * B;
        gray = R1 + G1 + B1;

        // Display results in a formatted table
        printf("\n====================================\n");
        printf("              RESULTS\n");
        printf("====================================\n");
        printf("+------------+-----------+\n");
        printf("| Component  |   Value   |\n");
        printf("+------------+-----------+\n");
        printf("|     R      | %9.2f |\n", R1);
        printf("|     G      | %9.2f |\n", G1);
        printf("|     B      | %9.2f |\n", B1);
        printf("+------------+-----------+\n");
        printf("| Grayscale  | %9.2f |\n", gray);
        printf("+------------+-----------+\n");

        // Ask if user wants to continue
        printf("\nPress 'q' to quit or any other key to continue: ");
        scanf(" %c", &choice);
        while(getchar() != '\n'); // Clear the input buffer

    } while (choice != 'q' && choice != 'Q');

    printf("\nProgram exited. Thank you!\n");
    return 0;
}