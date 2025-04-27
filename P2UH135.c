#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*宣告直線函數*/
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
    printLine('=');
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
                printf("--------------------------\n");
                printf("| a. 畫出直角三角形       |\n");
                printf("| b. 顯示乘法表           |\n");
                printf("| c. 結束                 |\n");
                printf("--------------------------\n");
                printf("請輸入選項 (a/b/c): ");
                scanf(" %c", &choice);
                //選項abc
                switch (choice) {
                    case 'A':
                    case 'a': {
                        system("cls");
                        system("clear");
                        char ch;
                        do {
                            printf("請輸入字元a-n: ");
                            scanf(" %c", &ch);
                            //清除緩衝內換行符號
                            while (getchar()!= '\n');

                            if (ch >= 'a' && ch <= 'n') {
                                int h = ch - 'a' + 1;
                                for (int i = 0; i < h; i++) {
                                    // 印出空格
                                    for (int j = 0; j < h - i - 1; j++) {
                                        printf(" ");
                                    }
                                    // 印出字元
                                    for (int j = h - i - 1; j < h; j++) {
                                        printf("%c", 'a' + j);
                                    }
                                    printf("\n");
                                }
                                break;
                            } else {
                                printf("錯誤!請輸入字元a-n\n");
                            }
                        } while (ch < 'a' || ch > 'n');
                        printf("按任意鍵回到主選單\n");
                        getch();
                        system("cls");
                        system("clear");
                        break;
                    }

                    case 'B':
                    case 'b': {
                        system("cls");
                        system("clear");
                        int n;
                        do {
                            printf("輸入1-9的整數\n");
                            scanf("%d", &n);
                            if (n >= 1 && n <= 9) {
                                for (int i = 1; i <= n; i++) {
                                    for (int j = 1; j <= n; j++) {
                                        printf("%dx%d=%2d ", i, j, i * j);
                                    }
                                    printf("\n");
                                }
                                break;
                            } else {
                                printf("輸入錯誤!請輸入一個1-9的整數\n");
                            }
                        } while (1);
                        printf("按任意鍵回到主選單\n");
                        getch();
                        system("cls");
                        system("clear");
                        break;
                    }

                    case 'C':
                    case 'c': {
                        char yn;
                        do {
                            printf("Continue? (y/n): ");
                            scanf(" %c", &yn);
                            //清除緩衝內換行符號
                            while (getchar()!= '\n');

                            if (yn == 'y' || yn == 'Y') {
                                system("cls");
                                system("clear");
                                break;
                            } else if (yn == 'n' || yn == 'N') {
                                printf("程式結束，回到作業系統\n");
                                return 0;
                            } else {
                                printf("輸入錯誤!請輸入y或n\n");
                            }
                        } while (1);
                        break;
                    }

                    default:
                        printf("無效選項，請重新輸入。\n");
                }
            } while (1);
        } 


        else {
            wrong++;
            printf("輸入錯誤，剩餘嘗試次數: %d\n", 3 - wrong);
        }
    }

    printf("錯誤次數過多，系統停止\n");
    system("pause");
    return 0;
}


/*心得:
這次作業我一開始沒看好作業要求，導致後面花了很多時間重寫選單功能。下次會更加注意作業要求，避免
像這次一樣內容需要大改。此外，這次在撰寫個人風格畫面時，設置函數讓顯示直線更加簡潔，不必再看到
複雜的for迴圈，而是使用自己設定的printLine，還能快速地更改需要顯示100個的符號。同時，這次撰寫因
為需要大改的關係，讓我更加熟悉vim的快捷鍵使用，在更快速的修改程式方面幫了大忙。

選單功能需要不斷重複輸入，這次嘗試使用while(1)，而不是使用以前慣用的do-while，我覺得while(1)在使
用上更加有彈性，do-while比較適合輸入驗證，while(1)則更方便在各部分保證選單出現，適合像這次這種無
限選單，但while(1)的可讀性較差，在檢查程式時給我帶來一些困擾。不過之後應該也會常常使用這兩種迴圈
，希望能夠更加熟悉如何用好while(1)迴圈。*/
