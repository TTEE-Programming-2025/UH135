#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 9
#define password 2025

char seats[SIZE][SIZE];

// Initialize all seats to available ('-')
void init_seats() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            seats[i][j] = '-';
        }
    }
}

// Randomly reserve 10 seats with '*'
void reserve_randomseats() {
    int count = 0;
    srand(time(NULL));
    while (count < 10) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            count++;
        }
    }
}

// Print the current seating chart
void seatlist() {
    printf("\\\\123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// Clear the screen (cross-platform)
void clearscreen() {
    system("cls");
    system("clear");
}

// Display the main menu
void menu() {
    printf("----------[Booking System]----------\n");
    printf("| a.Available seats                |\n");
    printf("| b.Arrange for you                |\n");
    printf("| c.Choose by yourself             |\n");
    printf("| d.Exit                           |\n");
    printf("------------------------------------\n");
}

// Wait for key press to return to menu
void wait() {
    printf("\npress any key to return to the main menu");
    fflush(stdin);
    getchar();
}

// Search for a continuous block of available seats
int find_continuous_seats(int num, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= SIZE - num; j++) {
            int available = 1;
            for (int k = 0; k < num; k++) {
                if (seats[i][j + k] != '-') {
                    available = 0;
                    break;
                }
            }
            if (available) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

// Search for two rows with two seats available each
int find_two_rows_pair(int *r1, int *c1, int *r2, int *c2) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j <= SIZE - 2; j++) {
            if (seats[i][j] == '-' && seats[i][j + 1] == '-' &&
                seats[i + 1][j] == '-' && seats[i + 1][j + 1] == '-') {
                *r1 = i; *c1 = j;
                *r2 = i + 1; *c2 = j;
                return 1;
            }
        }
    }
    return 0;
}

// Mark suggested seats with '@'
void mark_suggestion(int row, int col, int num) {
    for (int i = 0; i < num; i++) {
        seats[row][col + i] = '@';
    }
}

// Mark pair suggestion across two rows with '@'
void mark_pair_suggestion(int r1, int c1, int r2, int c2) {
    seats[r1][c1] = seats[r1][c1 + 1] = '@';
    seats[r2][c2] = seats[r2][c2 + 1] = '@';
}

// Confirm suggested seats and convert '@' to '*'
void accept_suggestion() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (seats[i][j] == '@') seats[i][j] = '*';
        }
    }
}

// Manual seat selection by user
void manual_selection() {
    int n;
    char input[10];
    printf("Enter number of seats to select (1~4): ");
    scanf("%d", &n);

    if (n < 1 || n > 4) {
        printf("Invalid number, please try again\n");
        wait();
        return;
    }

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Enter seat %d (format: row-col, e.g., 2-5): ", i + 1);
            scanf("%s", input);
            int row, col;
            if (sscanf(input, "%d-%d", &row, &col) == 2 && row >= 1 && row <= 9 && col >= 1 && col <= 9) {
                if (seats[row - 1][col - 1] == '-') {
                    seats[row - 1][col - 1] = '@';
                    break;
                } else {
                    printf("Seat already reserved or taken, please try again\n");
                }
            } else {
                printf("Invalid format, please try again\n");
            }
        }
    }

    clearscreen();
    seatlist();
    wait(); // Confirm before finalizing
    accept_suggestion(); // Convert '@' to '*'
}

// revert suggestions
void revert_suggestions(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(seats[i][j] == '@')
                seats[i][j] ='-';
        }
    }
}

int main(void) {
    int pwd, wrong = 0;

    for (int i = 0; i < 5; i++)
        printf("* Welcome to the Auto Booking System *\n");

    // Password check (3 attempts max)
    while (wrong < 3) {
        printf("Please enter 4-digit password: ");
        scanf("%d", &pwd);
        if (pwd == password) {
            break;
        } else {
            printf("Incorrect password\n");
            wrong++;
        }
    }

    if (wrong == 3) {
        printf("3 failed attempts. Exiting program.\n");
        return 0;
    }

    init_seats();
    reserve_randomseats();

    char option;
    while (1) {
        clearscreen();
        menu();
        printf("Enter your option: ");
        scanf(" %c", &option);

        if (option == 'a' || option == 'A') {
            clearscreen();
            seatlist();
            wait();
        } else if (option == 'b' || option == 'B') {
            clearscreen();
            int num;
            printf("How many seats do you need (1~4): ");
            scanf("%d", &num);
            int row, col, r1, c1, r2, c2;
            int found = 0;
            if (num >= 1 && num <= 3) {
                if (find_continuous_seats(num, &row, &col)) {
                    mark_suggestion(row, col, num);
                    found = 1;
                }
            } else if (num == 4) {
                if (find_continuous_seats(4, &row, &col)) {
                    mark_suggestion(row, col, 4);
                    found = 1;
                } else if (find_two_rows_pair(&r1, &c1, &r2, &c2)) {
                    mark_pair_suggestion(r1, c1, r2, c2);
                    found = 1;
                }
            }
            if (found) {
                clearscreen();
                seatlist();
                char confirm;
                printf("Are you satisfied with the arrangement? (y/n): ");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    accept_suggestion();
                } else {
                    revert_suggestions();
                    printf("Arrangement canceled.\n");
                    wait();
                }
            } else {
                printf("Unable to arrange seats\n");
                wait();
            }
        } else if (option == 'c' || option == 'C') {
            clearscreen();
            manual_selection();
        } else if (option == 'd' || option == 'D') {
            char confirm;
            while (1) {
                printf("Continue? (y/n): ");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') break;
                else if (confirm == 'n' || confirm == 'N') return 0;
                else printf("Invalid input\n");
            }
        } else {
            printf("Invalid option, please try again\n");
            wait();
        }
    }

    return 0;
}
