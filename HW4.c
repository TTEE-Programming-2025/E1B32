// Homework4.c - 第1題 + 第2題：登入畫面 + 主選單

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 顯示歡迎畫面（至少20行）
void showWelcomeScreen() {
	int i;
    for (i = 0; i < 20; i++) {
        printf("== Welcome to My Grade System ==\n");
    }
}

// 密碼登入檢查（預設密碼為"2025"，最多三次）
int login() {
    char input[10];
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter 4-digit password: ");
        scanf("%s", input);

        if (strcmp(input, "2025") == 0) {
            printf("Login successful! Welcome!\n");
            return 1;  // 登入成功
        } else {
            attempts++;
            printf("Wrong password. Try again. (%d/3)\n", attempts);
        }
    }

    printf("Too many incorrect attempts. Program exiting.\n");
    return 0;  // 登入失敗
}

// 清除螢幕（簡化版：列印多行）
void clearScreen() {
	int i;
    for ( i = 0; i < 30; i++) {
        printf("\n");
    }
}

// 顯示主選單
void showMainMenu() {
    printf("------------[Grade System]------------\n");
    printf("|  a. Enter student grades           |\n");
    printf("|  b. Display student grades         |\n");
    printf("|  c. Search for student grades      |\n");
    printf("|  d. Grade ranking                  |\n");
    printf("|  e. Exit system                    |\n");
    printf("--------------------------------------\n");
}

// 主程式入口
int main() {
    char choice;

    showWelcomeScreen();

    if (!login()) {
        return 0; // 登入失敗則離開
    }

    while (1) {
        clearScreen();         // 清除螢幕
        showMainMenu();        // 顯示主選單

        printf("Choose an option (a~e): ");
        scanf(" %c", &choice); // 注意前面空格，避免前一輸入影響

        switch (choice) {
            case 'a':
                // 下一題功能將寫在這裡
                printf("You chose: Enter student grades\n");
                break;
            case 'b':
                printf("You chose: Display student grades\n");
                break;
            case 'c':
                printf("You chose: Search student grades\n");
                break;
            case 'd':
                printf("You chose: Grade ranking\n");
                break;
            case 'e':
                printf("You chose: Exit system\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a~e.\n");
        }

        printf("Press Enter to continue...\n");
        getchar(); // 清除前一個輸入的換行符
        getchar(); // 等待使用者按鍵
    }

    return 0;
}

