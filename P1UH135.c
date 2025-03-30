#include<stdio.h>
#include<stdlib.h>
int main()
{
    /*第一部分，個人風格畫面*/
    for(int i=0;i<=100;i++)
    {
      printf("=");
    }
    printf("\n");
    printf("～～～＼\n");
    printf("｜你好！＼\n");
    printf("～～～～～＼\n");
    printf("　　　　　　＼\n");
    printf("　　　　\"∧＿＿∧∩\n");
    printf("　　　　(*　>ω•́ )ﾉ＼\n");
    printf("ｰ=≡t―ｰ/ヽ＿つ）_s)\n");
    printf("≡(〓〓(　)／＼＼ｰ＼\n");
    printf("=≡( (〓:(／　|（Ｏ)T\n");
    printf("=≡ヽ､＿ノ￣￣ヽ＿／\n");
    printf("                              ～～～～～～～～～＼\n");
    printf("                              ｜請按按鍵清除螢幕! ＼\n");
    printf("                              ～～～～～～～～～～～＼\n");
    printf("　　　　　                                          　＼\n");
    printf("　　　　                                         \"∧＿＿∧∩\n");
    printf("　　　                                         　(*　>ω< )ﾉ＼\n");
    printf("                                         ｰ=≡t―ｰ/ヽ＿つ）_s)\n");
    printf("                            ≡≡≡≡≡≡≡≡     ≡(〓〓(　)／＼＼ｰ＼\n");
    printf("            ==≡≡≡≡≡≡≡≡      ====≡≡≡      =≡( (〓:(／　|（Ｏ)T\n");
    printf("===≡≡≡≡     ====≡≡≡≡≡≡≡≡    ====≡≡         =≡ヽ､＿ノ￣￣ヽ＿／\n");
    for(int i=0;i<=100;i++)
    {
      printf("=");
    }
    printf("\n");
    getchar();
    system("CLS");

    /*第二部分，輸入密碼*/
    int password=2024;
    printf("請輸入4字密碼\n");
    scanf("%d",&password);
    if(password == 2024)
    {
        printf("歡迎\n");
    }
    else
    {
        printf("輸入錯誤!\n");
        return 0;
    }

    /*第三部分，清除螢幕並顯示主選單*/
    system("pause");
    system("CLS");
    fflush(stdin);

    /*選單*/

    printf("--------------------------\n");
    printf("| 'A'...'Z'  : Uppercase  |\n");
    printf("| 'a'...'z'  : Lowercase  |\n");
    printf("| '0'...'9'  : Digit      |\n");
    printf("|  Otherwise : Your name  |\n");
    printf("--------------------------\n");

    char ch;

    printf("請輸入一個字元:");
    ch = getchar();
    while (getchar() != '\n');

    if(ch >= '0' && ch <='9')
    {
    printf("Digit\n");
    }
    else if(ch >= 'A' && ch <= 'Z')
    {
    printf("Uppercase\n");
    }
    else if(ch >= 'a' && ch <= 'z')
    {
    printf("Lowercase\n");
    }
    else
    {
        printf("UH1.粘荏淳\n");
    }
    return 0;

system("pause");
return 0;
}
