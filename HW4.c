#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i;
// ����w��e���]�ܤ�20��^
void showWelcomeScreen() {
    for ( i = 0; i < 20; i++) {
	
        printf("****************\n");
    }
}

// �K�X�n�J�ˬd�]�w�]�K�X��"2025"�A�̦h�T���^
int login() {
    char input[10];
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter  password: ");
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

int main() {
    showWelcomeScreen();

    if (!login()) {
        return 0; // �Y�n�J���ѡA�����{��
    }

    return 0;
}
