#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 10

// 結構定義：學生資料
typedef struct {
    char name[20];
    int id;
    int math, physics, english;
    float avg;
} Student;

Student students[MAX_STUDENTS]; // 學生陣列
int student_count = 0;          // 實際人數

// 顯示歡迎畫面
void showWelcomeScreen() {
	int i;
    for ( i = 0; i < 20; i++) {
        printf("== Welcome to My Grade System ==\n");
    }
}

// 密碼登入（最多三次）
int login() {
    char input[10];
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter 4-digit password: ");
        scanf("%s", input);

        if (strcmp(input, "2025") == 0) {
            printf("Login successful! Welcome!\n");
            return 1;
        } else {
            attempts++;
            printf("Wrong password. Try again. (%d/3)\n", attempts);
        }
    }

    printf("Too many incorrect attempts. Program exiting.\n");
    return 0;
}

// 清除螢幕（簡易版）
void clearScreen() {
	int i;
    for ( i = 0; i < 30; i++) printf("\n");
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

// 功能 a：輸入學生資料
void enterStudentGrades() {
    int n;

    clearScreen();
    printf("Enter number of students (5 ~ 10): ");
    scanf("%d", &n);

    while (n < 5 || n > 10) {
        printf("Invalid number! Please enter 5~10: ");
        scanf("%d", &n);
    }

    student_count = n;
    int i;
    for ( i = 0; i < n; i++) {
        printf("Student #%d:\n", i + 1);

        printf("  Name: ");
        scanf("%s", students[i].name);

        printf("  ID (6 digits): ");
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("  Invalid ID! Re-enter (6 digits): ");
            scanf("%d", &students[i].id);
        }

        printf("  Math score (0~100): ");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("  Invalid score! Re-enter: ");
            scanf("%d", &students[i].math);
        }

        printf("  Physics score (0~100): ");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("  Invalid score! Re-enter: ");
            scanf("%d", &students[i].physics);
        }

        printf("  English score (0~100): ");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("  Invalid score! Re-enter: ");
            scanf("%d", &students[i].english);
        }

        // 計算平均
        students[i].avg = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }

    printf("Student data entry complete! Returning to menu...\n");
    printf("Press Enter to continue...\n");
    getchar(); // 吃掉前一個換行
    getchar(); // 等待使用者按鍵
}

// 主程式
int main() {
    char choice;

    showWelcomeScreen();
    if (!login()) return 0;

    while (1) {
        clearScreen();
        showMainMenu();

        printf("Choose an option (a~e): ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                enterStudentGrades();
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
        getchar(); // 吃掉換行
        getchar();
    }

    return 0;
}

