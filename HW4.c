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

Student students[MAX_STUDENTS];
int student_count = 0;

// 顯示歡迎畫面
void showWelcomeScreen() {
	int i ;
    for (i = 0; i < 20; i++) {
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

// 清除螢幕
void clearScreen() {
	int i;
    for ( i = 0; i < 30; i++) printf("\n");
}

// 主選單
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
    for (i = 0; i < n; i++) {
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
        students[i].avg = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
    printf("Student data entry complete! Press Enter to return to menu...\n");
    getchar(); getchar();
}

// 功能 b：顯示所有學生資料
void displayStudentGrades() {
    clearScreen();
    if (student_count == 0) {
        printf("No student data available.\n");
    } else {
        printf("Name       ID       Math  Physics  English  Average\n");
        printf("----------------------------------------------------\n");
        int i;
        for (i = 0; i < student_count; i++) {
            printf("%-10s %-7d %-5d %-7d %-7d %.1f\n",
                   students[i].name, students[i].id,
                   students[i].math, students[i].physics,
                   students[i].english, students[i].avg);
        }
    }
    printf("Press Enter to return to menu...\n");
    getchar(); getchar();
}

// 功能 c：搜尋學生
void searchStudent() {
    char target[20];
    int found = 0;
    clearScreen();
    if (student_count == 0) {
        printf("No student data available.\n");
    } else {
        printf("Enter the name of student to search: ");
        scanf("%s", target);
        int i;
        for (i = 0; i < student_count; i++) {
            if (strcmp(students[i].name, target) == 0) {
                printf("Found student:\n");
                printf("Name: %s\n", students[i].name);
                printf("ID: %d\n", students[i].id);
                printf("Math: %d\n", students[i].math);
                printf("Physics: %d\n", students[i].physics);
                printf("English: %d\n", students[i].english);
                printf("Average: %.1f\n", students[i].avg);
                found = 1;
                break;
            }
        }
        if (!found) printf("Student not found.\n");
    }
    printf("Press Enter to return to menu...\n");
    getchar(); getchar();
}

// 功能 d：成績排序
void gradeRanking() {
    clearScreen();
    if (student_count == 0) {
        printf("No student data available.\n");
    } else {
        Student sorted[MAX_STUDENTS];
        int i;
        for ( i = 0; i < student_count; i++) {
            sorted[i] = students[i];
        }
        for (i = 0; i < student_count - 1; i++) {
        	int j;
            for (j = 0; j < student_count - 1 - i; j++) {
                if (sorted[j].avg < sorted[j + 1].avg) {
                    Student temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }
        printf("Ranking: (by average grade)\n");
        printf("Name       ID       Average\n");
        printf("------------------------------\n");
        for (i = 0; i < student_count; i++) {
            printf("%-10s %-7d %.1f\n", sorted[i].name, sorted[i].id, sorted[i].avg);
        }
    }
    printf("Press Enter to return to menu...\n");
    getchar(); getchar();
}

// 功能 e：確認離開
int confirmExit() {
    char ans;
    while (1) {
        printf("確定離開？(y/n): ");
        scanf(" %c", &ans);
        if (ans == 'y' || ans == 'Y') return 1;
        else if (ans == 'n' || ans == 'N') return 0;
        else printf("請輸入 y 或 n。\n");
    }
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
            case 'a': enterStudentGrades(); break;
            case 'b': displayStudentGrades(); break;
            case 'c': searchStudent(); break;
            case 'd': gradeRanking(); break;
            case 'e': if (confirmExit()) return 0; break;
            default: printf("Invalid choice. Please enter a~e.\n");
        }
    }
    return 0;
}

