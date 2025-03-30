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
    /*清除畫面*/
    getchar(); //讀取一個字元
    system("CLS"); //清除畫面
    system("clear");//清除畫面

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
    system("pause");//暫停程式
    system("CLS");//清除螢幕
    system("clear");//清除螢幕
    fflush(stdin);//清除緩衝區

    /*選單*/

    printf("--------------------------\n");
    printf("| 'A'...'Z'  : Uppercase  |\n");
    printf("| 'a'...'z'  : Lowercase  |\n");
    printf("| '0'...'9'  : Digit      |\n");
    printf("|  Otherwise : Your name  |\n");
    printf("--------------------------\n");

    /*輸入字元，並顯示對應回應*/
    char ch;

    printf("請輸入一個字元:");
    ch = getchar();
    while (getchar() != '\n'); //如果輸入一個以上字元，在緩衝區刪除多餘字元並讀取第一個

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
/*心得:
 這次的作業，讓我學到了很多新知識。在寫程式之前，我花了不少時間查詢如何設定vim，讓它更符合我的
 使用習慣，同時也花了一點時間學習並使用vim快捷鍵來增加寫程式的效率，我覺得如果能熟悉快捷鍵並逐
 步設定vimrc，它將會成為一個非常趁手的工具。而準備在git bash上測試程式時，我發現我的電腦沒有安
 裝gcc，只好再花時間搜尋如何下載，花了不少工夫才處理好前置動作，不過設定完非常方便，我很滿意。

 在寫程式時，我更加熟悉getchar()的用法，也更明白getchar和scanf的差異，getchar只能讀取一個字符，
 而scanf能自己調整數量和格式，在簡單的字符輸入方面getchar比scanf更乾淨。而在清除螢幕方面，我發
 現system("CLS")在git bash上測試時會出現無法將介面清除乾淨的問題，我的輸入密碼介面會和bash上打
 的舊指令重疊，在搜尋問題後發現可能是因為git bash模擬linux環境，造成針對Windows的system("CLS")
 指令沒有效果，於是我加入針對linux的清除指令system("clear")，果然成功清除。這次的作業讓我收穫不
 少關於程式、git bash使用，和電腦設定的許多設定和訣竅，希望未來能更熟悉和活用。*/
