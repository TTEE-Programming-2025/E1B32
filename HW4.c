#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i;
// 顯示歡迎畫面（至少20行）
void showWelcomeScreen() {
    for ( i = 0; i < 20; i++) {
	
        printf("****************\n");
    }
}

// 密碼登入檢查（預設密碼為"2025"，最多三次）
int login() {
    char input[10];
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter  password: ");
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

int main() {
    showWelcomeScreen();

    if (!login()) {
        return 0; // 若登入失敗，結束程式
    }

    return 0;
}
