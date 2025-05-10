#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 9
#define password 2025

char seats[SIZE][SIZE];

void init_seats() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            seats[i][j] = '-';
        }
    }
}

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

void seatlist() {
    printf("  123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void clearscreen() {
    system("cls");
    system("clear");
}

void menu() {
    printf("----------[Booking System]----------\n");
    printf("| a.Available seats                |\n");
    printf("| b.Arrange for you                |\n");
    printf("| c.Choose by yourself             |\n");
    printf("| d.Exit                           |\n");
    printf("------------------------------------\n");
}

void wait() {
    printf("\npress any key to return to the main menu");
    fflush(stdin);
    getchar();
}

// 找連續座位
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

// 找兩列各兩個座位
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

// 標示建議座位
void mark_suggestion(int row, int col, int num) {
    for (int i = 0; i < num; i++) {
        seats[row][col + i] = '@';
    }
}

void mark_pair_suggestion(int r1, int c1, int r2, int c2) {
    seats[r1][c1] = seats[r1][c1 + 1] = '@';
    seats[r2][c2] = seats[r2][c2 + 1] = '@';
}

// 接受建議
void accept_suggestion() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (seats[i][j] == '@') seats[i][j] = '*';
        }
    }
}

// 自選座位
void manual_selection() {
    int n;
    char input[10];
    printf("請輸入要選幾個座位 (1~4): ");
    scanf("%d", &n);

    if (n < 1 || n > 4) {
        printf("數量錯誤，請重新選擇\n");
        wait();
        return;
    }

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("請輸入第 %d 個座位 (格式: 列-行，例如 2-5): ", i + 1);
            scanf("%s", input);
            int row, col;
            if (sscanf(input, "%d-%d", &row, &col) == 2 && row >= 1 && row <= 9 && col >= 1 && col <= 9) {
                if (seats[row - 1][col - 1] == '-') {
                    seats[row - 1][col - 1] = '@';
                    break;
                } else {
                    printf("該座位已被選取或預約，請重新輸入\n");
                }
            } else {
                printf("格式錯誤，請重新輸入\n");
            }
        }
    }

    clearscreen();
    seatlist();
    wait(); // 按任意鍵確認
    accept_suggestion(); // 將 @ 轉為 *
}

int main(void) {
    int pwd, wrong = 0;

    for (int i = 0; i < 5; i++)
        printf("* 歡迎使用自動訂位系統 *\n");

    while (wrong < 3) {
        printf("請輸入 4 位數密碼：");
        scanf("%d", &pwd);
        if (pwd == password) {
            break;
        } else {
            printf("密碼錯誤\n");
            wrong++;
        }
    }

    if (wrong == 3) {
        printf("錯誤三次，程式結束\n");
        return 0;
    }

    init_seats();
    reserve_randomseats();

    char option;
    while (1) {
        clearscreen();
        menu();
        printf("請輸入選項: ");
        scanf(" %c", &option);

        if (option == 'a' || option == 'A') {
            clearscreen();
            seatlist();
            wait();
        } else if (option == 'b' || option == 'B') {
            clearscreen();
            int num;
            printf("請問需要幾個座位 (1~4): ");
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
                printf("是否滿意安排？(y/n): ");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    accept_suggestion();
                }
            } else {
                printf("無法安排座位\n");
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
                else printf("輸入錯誤\n");
            }
        } else {
            printf("選項錯誤，請重新輸入\n");
            wait();
        }
    }

    return 0;
}
