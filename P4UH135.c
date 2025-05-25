#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define password 2025
#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 50
#define LINE_LENGTH 70

// Student data structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id; // 6-digit number
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int num_students = 0;

// Function declarations
void display_personal_screen();
void clear_screen();
void consume_input_buffer();
void robust_wait_for_key_press();
void display_main_menu();
void calculate_all_averages();
void enter_student_grades();
void display_all_student_grades();
void search_student_grades();
void rank_grades_by_average();
void printLine(char ch);

// Print a line of characters
void printLine(char ch) {
    for (int i = 0; i < LINE_LENGTH; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

// Clear screen
void clear_screen() {
    system("cls");
    system("clear");
}

// Clear input buffer
void consume_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Wait for Enter key
void robust_wait_for_key_press() {
    printf("\nPress Enter to return to the main menu...");
    consume_input_buffer();
}

// Display main menu
void display_main_menu() {
    printLine('-');
    printf("------------[Grade System]------------\n");
    printf("| a. Enter student grades             |\n");
    printf("| b. Display student grades           |\n");
    printf("| c. Search for student grades        |\n");
    printf("| d. Grade ranking                    |\n");
    printf("| e. Exit system                      |\n");
    printLine('-');
}

// Calculate average grades
void calculate_all_averages() {
    for (int i = 0; i < num_students; i++) {
        students[i].average = (float)(students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
}

// Input student grades
void enter_student_grades() {
    clear_screen();
    printf("--- Enter Student Grades ---\n");

    int n_input;
    do {
        printf("Enter number of students (5-10): ");
        if (scanf("%d", &n_input) != 1) {
            printf("Invalid input. Please enter a number.\n");
            consume_input_buffer();
            n_input = 0;
            continue;
        }
        consume_input_buffer();
        if (n_input < 5 || n_input > 10) {
            printf("Number must be between 5 and 10. Please try again.\n");
        }
    } while (n_input < 5 || n_input > 10);

    num_students = n_input;

    for (int i = 0; i < num_students; i++) {
        printf("\nEnter data for student %d:\n", i + 1);

        do {
            printf("Name: ");
            fgets(students[i].name, MAX_NAME_LENGTH, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            if (strlen(students[i].name) == 0) {
                printf("Name cannot be empty. Please re-enter.\n");
            }
        } while (strlen(students[i].name) == 0);

        int id_temp;
        do {
            printf("ID (6-digit): ");
            if (scanf("%d", &id_temp) != 1) {
                printf("Invalid input. Please enter a number.\n");
                consume_input_buffer();
                id_temp = -1;
                continue;
            }
            consume_input_buffer();
            if (id_temp < 100000 || id_temp > 999999) {
                printf("ID must be a 6-digit number. Please try again.\n");
            }
        } while (id_temp < 100000 || id_temp > 999999);
        students[i].id = id_temp;

        do {
            printf("Math (0-100): ");
            if (scanf("%d", &students[i].math) != 1) {
                printf("Invalid input. Please enter a number.\n");
                consume_input_buffer(); students[i].math = -1; continue;
            }
            consume_input_buffer();
            if (students[i].math < 0 || students[i].math > 100) {
                printf("Score must be between 0 and 100. Please try again.\n");
            }
        } while (students[i].math < 0 || students[i].math > 100);

        do {
            printf("Physics (0-100): ");
            if (scanf("%d", &students[i].physics) != 1) {
                printf("Invalid input. Please enter a number.\n");
                consume_input_buffer(); students[i].physics = -1; continue;
            }
            consume_input_buffer();
            if (students[i].physics < 0 || students[i].physics > 100) {
                printf("Score must be between 0 and 100. Please try again.\n");
            }
        } while (students[i].physics < 0 || students[i].physics > 100);

        do {
            printf("English (0-100): ");
            if (scanf("%d", &students[i].english) != 1) {
                printf("Invalid input. Please enter a number.\n");
                consume_input_buffer(); students[i].english = -1; continue;
            }
            consume_input_buffer();
            if (students[i].english < 0 || students[i].english > 100) {
                printf("Score must be between 0 and 100. Please try again.\n");
            }
        } while (students[i].english < 0 || students[i].english > 100);
    }
    calculate_all_averages();
    printf("\nStudent grades entered successfully.\n");
    robust_wait_for_key_press();
}

// Display all student grades
void display_all_student_grades() {
    clear_screen();
    printf("--- Display All Student Grades ---\n");
    if (num_students == 0) {
        printf("No student data. Please enter grades using option 'a'.\n");
    } else {
        printf("%-20s | %-10s | %6s | %6s | %6s | %6s\n",
               "Name", "ID", "Math", "Physics", "English", "Average");
        printLine('-');
        for (int i = 0; i < num_students; i++) {
            printf("%-20s | %-10d | %6d | %6d | %6d | %6.1f\n",
                   students[i].name, students[i].id, students[i].math,
                   students[i].physics, students[i].english, students[i].average);
        }
        printLine('-');
    }
    robust_wait_for_key_press();
}

// Search for student grades
void search_student_grades() {
    clear_screen();
    printf("--- Search Student Grades ---\n");
    if (num_students == 0) {
        printf("No student data to search.\n");
        robust_wait_for_key_press();
        return;
    }

    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0;

    int found = 0;
    printf("\nSearch Result:\n");
    printf("%-20s | %-10s | %6s | %6s | %6s | %6s\n",
           "Name", "ID", "Math", "Physics", "English", "Average");
    printLine('-');

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("%-20s | %-10d | %6d | %6d | %6d | %6.1f\n",
                   students[i].name, students[i].id, students[i].math,
                   students[i].physics, students[i].english, students[i].average);
            found = 1;
        }
    }

    if (!found) {
        printf("No student found with name '%s'.\n", search_name);
    }
    printLine('-');
    robust_wait_for_key_press();
}

// Compare by average
int compare_students_by_average(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    if (s1->average < s2->average) return 1;
    if (s1->average > s2->average) return -1;
    return 0;
}

// Rank by average
void rank_grades_by_average() {
    clear_screen();
    printf("--- Grade Ranking (By Average Descending) ---\n");
    if (num_students == 0) {
        printf("No student data for ranking.\n");
    } else {
        qsort(students, num_students, sizeof(Student), compare_students_by_average);

        printf("%-20s | %-10s | %6s\n", "Name", "ID", "Average");
        printLine('-');
        for (int i = 0; i < num_students; i++) {
            printf("%-20s | %-10d | %6.1f\n",
                   students[i].name, students[i].id, students[i].average);
        }
        printLine('-');
    }
    robust_wait_for_key_press();
}

// Display login screen
void display_personal_screen() {
    printLine('=');
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣶⠋⠁⠈⠙⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠁⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⢠⡾⠀⠀⠀⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⣀⣤⠶⠶⠶⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠻⠶⠶⠶⢤⣄⠀\n");
    printf("⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧\n");
    printf("⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿\n");
    printf("⠀⠙⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⠋⠀\n");
    printf("⠀⠀⠀⠙⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠋⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⢸⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⡾⠈⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⢻⣄⠀⠀⠀⣀⣠⠴⠛⠉⠉⠓⠦⣄⣀⠀⠀⠀⣠⡟⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠙⠛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠛⠋⠀⠀⠀⠀⠀\n");

    printf("               ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀          ⠀⠀⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀          ⠀     ⠀⠀⠀⠀⠀⠀     ⠀     ⢀⣶⠋⠁⠈⠙⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀               ⠀⠀          ⢀⡾⠁⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("     ⠀⠀⠀⠀⠀                    ⠀⠀⠀⢠⡾⠀⠀⠀⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("                         ⠀⣀⣤⠶⠶⠶⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠻⠶⠶⠶⢤⣄⠀\n");
    printf("                         ⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧\n");
    printf("                         ⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿\n");
    printf("⠀                         ⠙⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⠋⠀\n");
    printf("⠀⠀                         ⠀⠙⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠋⠀⠀⠀\n");
    printf("⠀⠀⠀⠀                         ⢀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀                         ⠀⢸⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⠀⠀⠀⠀\n");
    printf("⠀⠀⠀               ⠀          ⡾⠈⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀\n");
    printf("⠀⠀⠀                         ⠀⢻⣄⠀⠀⠀⣀⣠⠴⠛⠉⠉⠓⠦⣄⣀⠀⠀⠀⣠⡟⠀⠀⠀⠀\n");
    printf("     ⠀⠀⠀     ⠀               ⠀⠙⠛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠛⠋⠀⠀⠀⠀⠀\n");
    printf("      Welcome to the Student Grade System!      \n");
    printf("             Please verify to continue.         \n");
    printLine('=');
}

// Main function
int main(void) {
    printLine('=');
    display_personal_screen();

    int pwd, wrong = 0;

    while (wrong < 3) {
        printf("Enter 4-digit password: ");
        if (scanf("%d", &pwd) != 1) {
            printf("Invalid input. Please enter a number.\n");
            consume_input_buffer();
            pwd = -1;
        } else {
            consume_input_buffer();
        }

        if (pwd == password) {
            printf("Password correct! Welcome!\n");
            robust_wait_for_key_press();
            break;
        } else {
            printf("Incorrect password!\n");
            wrong++;
        }
    }

    if (wrong == 3) {
        printf("Password incorrect 3 times. Exiting system.\n");
        return 0;
    }

    char choice;
    while (1) {
        clear_screen();
        display_main_menu();
        printf("Enter your choice: ");
        if (scanf(" %c", &choice) != 1) {
            consume_input_buffer();
            choice = ' ';
        } else {
            consume_input_buffer();
        }

        switch (choice) {
            case 'a':
                enter_student_grades();
                break;
            case 'b':
                display_all_student_grades();
                break;
            case 'c':
                search_student_grades();
                break;
            case 'd':
                rank_grades_by_average();
                break;
            case 'e': {
                char confirm_exit;
                do {
                    clear_screen();
                    printf("Are you sure you want to exit? (y/n): ");
                    if (scanf(" %c", &confirm_exit) != 1) {
                        consume_input_buffer();
                        confirm_exit = ' ';
                    } else {
                        consume_input_buffer();
                    }
                } while (confirm_exit != 'y' && confirm_exit != 'Y' &&
                         confirm_exit != 'n' && confirm_exit != 'N');

                if (confirm_exit == 'y' || confirm_exit == 'Y') {
                    printf("System exiting!\n");
                    return 0;
                }
                break;
            }
            default:
                printf("Invalid option. Please try again.\n");
                robust_wait_for_key_press();
        }
    }

    return 0;
}

