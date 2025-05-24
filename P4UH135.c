#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define password 2025
#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 50
#define LINE_LENGTH 70

// 學生資料結構
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id; // 6位整數
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS]; // 全域學生陣列
int num_students = 0;          // 目前已輸入的學生數量

// 宣告的函數
void display_personal_screen();//顯示登入畫面
void clear_screen();//清除畫面
void consume_input_buffer();//清除輸入緩衝區
void robust_wait_for_key_press();//暫停程式，等待使用者按Enter
void display_main_menu();//顯示主選單
void calculate_all_averages();//計算所有學生的平均成績
void enter_student_grades();//輸入學生姓名、學號與三科成績
void display_all_student_grades();//顯示所有學生的成績與平均
void search_student_grades();//根據姓名查詢學生成績
void rank_grades_by_average();//根據平均成績進行排名顯示
void printLine(char ch);//輸出指定字元一行

//輸出指定字元一行
void printLine(char ch) {
    for (int i = 0; i < LINE_LENGTH; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

//清除畫面
void clear_screen() {
    system("cls");
    system("clear");
}

//清除輸入謊衝區
void consume_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//暫停程式，等待使用者按Enter
void robust_wait_for_key_press() {
    printf("\n按 Enter 鍵返回主選單...");
    consume_input_buffer();
}

//顯示主選單
void display_main_menu() {
    printLine('-');
    printf("------------[Grade System]----------\n");
    printf("| \"a. Enter student grades\"      |\n");
    printf("| \"b. Display student grades\"    |\n");
    printf("| \"c. Search for student grades\" |\n");
    printf("| \"d. Grade ranking\"             |\n");
    printf("| \"e. Exit system\"               |\n");
    printLine('-');
}

//計算所有學生的平均成績
void calculate_all_averages() {
    for (int i = 0; i < num_students; i++) {
        students[i].average = (float)(students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
}

//輸入學生姓名、學號與三科成績
void enter_student_grades() {
    clear_screen();
    printf("--- 輸入學生成績 ---\n");

    int n_input;
    do {
        printf("請輸入學生人數 (5-10): ");
        if (scanf("%d", &n_input) != 1) {
            printf("輸入無效，請輸入數字。\n");
            consume_input_buffer();
            n_input = 0;
            continue;
        }
        consume_input_buffer();
        if (n_input < 5 || n_input > 10) {
            printf("人數必須介於5到10之間，請重新輸入。\n");
        }
    } while (n_input < 5 || n_input > 10);

    num_students = n_input;

    for (int i = 0; i < num_students; i++) {
        printf("\n輸入第 %d 位學生的資料:\n", i + 1);

        do {
            printf("姓名: ");
            fgets(students[i].name, MAX_NAME_LENGTH, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            if (strlen(students[i].name) == 0) {
                printf("姓名不可為空，請重新輸入。\n");
            }
        } while (strlen(students[i].name) == 0);

        int id_temp;
        do {
            printf("學號 (6位數字): ");
            if (scanf("%d", &id_temp) != 1) {
                printf("輸入無效，請為學號輸入數字。\n");
                consume_input_buffer();
                id_temp = -1;
                continue;
            }
            consume_input_buffer();
            if (id_temp < 100000 || id_temp > 999999) {
                printf("學號必須是6位數字，請重新輸入。\n");
            }
        } while (id_temp < 100000 || id_temp > 999999);
        students[i].id = id_temp;

        do {
            printf("數學成績 (0-100): ");
            if (scanf("%d", &students[i].math) != 1) {
                printf("輸入無效，請輸入數字。\n");
                consume_input_buffer(); students[i].math = -1; continue;
            }
            consume_input_buffer();
            if (students[i].math < 0 || students[i].math > 100) {
                printf("成績必須介於0到100之間，請重新輸入。\n");
            }
        } while (students[i].math < 0 || students[i].math > 100);

        do {
            printf("物理成績 (0-100): ");
            if (scanf("%d", &students[i].physics) != 1) {
                printf("輸入無效，請輸入數字。\n");
                consume_input_buffer(); students[i].physics = -1; continue;
            }
            consume_input_buffer();
            if (students[i].physics < 0 || students[i].physics > 100) {
                printf("成績必須介於0到100之間，請重新輸入。\n");
            }
        } while (students[i].physics < 0 || students[i].physics > 100);

        do {
            printf("英文成績 (0-100): ");
            if (scanf("%d", &students[i].english) != 1) {
                printf("輸入無效，請輸入數字。\n");
                consume_input_buffer(); students[i].english = -1; continue;
            }
            consume_input_buffer();
            if (students[i].english < 0 || students[i].english > 100) {
                printf("成績必須介於0到100之間，請重新輸入。\n");
            }
        } while (students[i].english < 0 || students[i].english > 100);
    }
    calculate_all_averages();
    printf("\n所有學生成績已成功輸入。\n");
    robust_wait_for_key_press();
}

//顯示所有學生的姓名和平均
void display_all_student_grades() {
    clear_screen();
    printf("--- 顯示所有學生成績 ---\n");
    if (num_students == 0) {
        printf("尚無學生資料。請先使用選項 'a' 輸入成績。\n");
    } else {
        printf("%-20s | %-10s | %-5s | %-7s | %-7s | %-7s\n",
               "姓名", "學號", "數學", "物理", "英文", "平均");
        printLine('-');
        for (int i = 0; i < num_students; i++) {
            printf("%-20s | %-10d | %-5d | %-7d | %-7d | %-7.1f\n",
                   students[i].name, students[i].id, students[i].math,
                   students[i].physics, students[i].english, students[i].average);
        }
        printLine('-');
    }
    robust_wait_for_key_press();
}

//根據姓名查詢學生成績
void search_student_grades() {
    clear_screen();
    printf("--- 查詢學生成績 ---\n");
    if (num_students == 0) {
        printf("尚無學生資料可供查詢。\n");
        robust_wait_for_key_press();
        return;
    }

    char search_name[MAX_NAME_LENGTH];
    printf("請輸入要查詢的姓名: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0;

    int found = 0;
    printf("\n查詢結果:\n");
    printf("%-20s | %-10s | %-5s | %-7s | %-7s | %-7s\n",
           "姓名", "學號", "數學", "物理", "英文", "平均");
    printLine('-');

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("%-20s | %-10d | %-5d | %-7d | %-7d | %-7.1f\n",
                   students[i].name, students[i].id, students[i].math,
                   students[i].physics, students[i].english, students[i].average);
            found = 1;
        }
    }

    if (!found) {
        printf("找不到姓名為 '%s' 的學生。\n", search_name);
    }
    printLine('-');
    robust_wait_for_key_press();
}

//根據平均成績比較學生排名
int compare_students_by_average(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    if (s1->average < s2->average) return 1;
    if (s1->average > s2->average) return -1;
    return 0;
}

//根據平均成績顯示排名
void rank_grades_by_average() {
    clear_screen();
    printf("--- 成績排名 (依平均成績由高至低) ---\n");
    if (num_students == 0) {
        printf("尚無學生資料可供排名。\n");
    } else {
        qsort(students, num_students, sizeof(Student), compare_students_by_average);

        printf("%-20s | %-10s | %-7s\n", "姓名", "學號", "平均");
        printLine('-');
        for (int i = 0; i < num_students; i++) {
            printf("%-20s | %-10d | %-7.1f\n",
                   students[i].name, students[i].id, students[i].average);
        }
        printLine('-');
    }
    robust_wait_for_key_press();
}

//顯示登入畫面
void display_personal_screen() {
    printLine('=');
    printf("        歡迎使用學生成績管理系統!        \n");
    printf("              請先進行驗證以繼續。   \n");
    printLine('=');
}

//主程式
int main(void) {
    printLine('=');
    display_personal_screen();

    int pwd, wrong = 0;

    // 密碼檢查(最多3次)
    while (wrong < 3) {
        printf("請輸入4位數字密碼：");
        if (scanf("%d", &pwd) != 1) {
            printf("輸入無效，請輸入數字。\n");
            consume_input_buffer();
            pwd = -1;
        } else {
            consume_input_buffer();
        }

        if (pwd == password) {
            printf("密碼正確！歡迎使用！\n");
            robust_wait_for_key_press();
            break;
        } else {
            printf("密碼錯誤！\n");
            wrong++;
        }
    }

    if (wrong == 3) {
        printf("密碼錯誤3次，系統結束。\n");
        return 0;
    }
//選單功能按鈕
    char choice;
    while (1) {
        clear_screen();
        display_main_menu();
        printf("請輸入選項: ");
        if (scanf(" %c", &choice) != 1) {
            consume_input_buffer();
            choice = ' ';
        } else {
            consume_input_buffer();
        }

        switch (choice) {
            case 'a': case 'A':
                enter_student_grades();
                break;
            case 'b': case 'B':
                display_all_student_grades();
                break;
            case 'c': case 'C':
                search_student_grades();
                break;
            case 'd': case 'D':
                rank_grades_by_average();
                break;
            case 'e': case 'E': {
                char confirm_exit;
                do {
                    clear_screen();
                    printf("確定離開？ (y/n): ");
                    if (scanf(" %c", &confirm_exit) != 1) {
                        consume_input_buffer();
                        confirm_exit = ' ';
                    } else {
                        consume_input_buffer();
                    }
                } while (confirm_exit != 'y' && confirm_exit != 'Y' &&
                         confirm_exit != 'n' && confirm_exit != 'N');

                if (confirm_exit == 'y' || confirm_exit == 'Y') {
                    printf("系統結束！\n");
                    return 0;
                }
                break;
            }
            default:
                printf("無效的選項，請重新輸入。\n");
                robust_wait_for_key_press();
        }
    }

    return 0;
}
