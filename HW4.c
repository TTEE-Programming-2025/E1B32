// Homework4.c - ��1�D + ��2�D�G�n�J�e�� + �D���

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ����w��e���]�ܤ�20��^
void showWelcomeScreen() {
	int i;
    for (i = 0; i < 20; i++) {
        printf("== Welcome to My Grade System ==\n");
    }
}

// �K�X�n�J�ˬd�]�w�]�K�X��"2025"�A�̦h�T���^
int login() {
    char input[10];
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter 4-digit password: ");
        scanf("%s", input);

        if (strcmp(input, "2025") == 0) {
            printf("Login successful! Welcome!\n");
            return 1;  // �n�J���\
        } else {
            attempts++;
            printf("Wrong password. Try again. (%d/3)\n", attempts);
        }
    }

    printf("Too many incorrect attempts. Program exiting.\n");
    return 0;  // �n�J����
}

// �M���ù��]²�ƪ��G�C�L�h��^
void clearScreen() {
	int i;
    for ( i = 0; i < 30; i++) {
        printf("\n");
    }
}

// ��ܥD���
void showMainMenu() {
    printf("------------[Grade System]------------\n");
    printf("|  a. Enter student grades           |\n");
    printf("|  b. Display student grades         |\n");
    printf("|  c. Search for student grades      |\n");
    printf("|  d. Grade ranking                  |\n");
    printf("|  e. Exit system                    |\n");
    printf("--------------------------------------\n");
}

// �D�{���J�f
int main() {
    char choice;

    showWelcomeScreen();

    if (!login()) {
        return 0; // �n�J���ѫh���}
    }

    while (1) {
        clearScreen();         // �M���ù�
        showMainMenu();        // ��ܥD���

        printf("Choose an option (a~e): ");
        scanf(" %c", &choice); // �`�N�e���Ů�A�קK�e�@��J�v�T

        switch (choice) {
            case 'a':
                // �U�@�D�\��N�g�b�o��
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
        getchar(); // �M���e�@�ӿ�J�������
        getchar(); // ���ݨϥΪ̫���
    }

    return 0;
}

