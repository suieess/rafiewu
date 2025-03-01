#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_title() {
    printf("==========================================\n");
    printf("\t  EAST WEST UNIVERSITY\n");
    printf("==========================================\n");
    printf("\t Rock Paper Scissors Game\n");
    printf("------------------------------------------\n");
}

int get_computer_choice() {
    return (rand() % 3) + 1; // Generates a number between 1 and 3
}

void display_choices() {
    printf("\nChoose an option:\n");
    printf("1 = Rock\n");
    printf("2 = Paper\n");
    printf("3 = Scissors\n");
    printf("Enter your choice: ");
}

void determine_winner(int player, int computer) {
    printf("Computer chose: %s\n", (computer == 1) ? "Rock" : (computer == 2) ? "Paper" : "Scissors");

    if (player == computer) {
        printf("It's a tie!\n");
    } else if ((player == 1 && computer == 3) ||
               (player == 2 && computer == 1) ||
               (player == 3 && computer == 2)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    int player_choice, computer_choice;
    srand(time(NULL));

    display_title();

    while (1) {
        display_choices();
        scanf("%d", &player_choice);

        if (player_choice < 1 || player_choice > 3) {
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
            continue;
        }

        computer_choice = get_computer_choice();
        determine_winner(player_choice, computer_choice);

        char play_again;
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        if (play_again != 'y' && play_again != 'Y') {
            printf("Thanks for playing!\n");
            break;
        }
    }
    return 0;
}

