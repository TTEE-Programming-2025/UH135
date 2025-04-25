#include <stdio.h>
#include <stdlib.h>
//宣告直線函數
void printLine(char ch) {
    for (int i = 0; i <=100 ; i++) {
        printf("%c", ch);
    }
    printf("\n");
}
int main(){
    //個人風格畫面
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
    printLine('*');
        // 密碼驗證
    const int password = 2025;
    int input;
    int wrong = 0;

    while (wrong < 3) {
        printf("請輸入四字密碼: ");
        scanf("%d", &input);
        if (input == password) {
            printf("密碼正確!\n");

            // 顯示選單
            char choice;
            do {
                printf("\n--------------------------\n");
                printf("| a. 畫出直角三角形       |\n");
                printf("| b. 顯示乘法表           |\n");
                printf("| c. 結束                 |\n");
                printf("--------------------------\n");
                printf("請輸入選項 (a/b/c): ");
                scanf(" %c", &choice);

                switch (choice) {
                    case 'a': {
                        int i, j, h;
                        printf("請輸入三角形的高度: ");
                        scanf("%d", &h);
                        for (i = 1; i <= h; i++) {
                            for (j = 1; j <= i; j++) {
                                printf("*");
                            }
                            printf("\n");
                        }
                        break;
                    }
                    case 'b': {
                        int i, j;
                        for (i = 1; i <= 9; i++) {
                            for (j = 1; j <= 9; j++) {
                                printf("%d×%d = %2d  ", i, j, i * j);
                            }
                            printf("\n");
                        }
                        break;
                    }
                    case 'c':
                        printf("結束選單\n");
                        break;
                    default:
                        printf("無效選項，請重新輸入。\n");
                }
            } while (choice != 'c');

            return 0;
        } else {
            wrong++;
            printf("輸入錯誤，剩餘嘗試次數: %d\n", 3 - wrong);
        }
    }

    printf("錯誤次數過多，系統停止\n");
    system("pause");
    return 0;
}
