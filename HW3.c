#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define password 2025
#define rows 9
#define cols 9

int seat[rows][cols] = {0};  // 0: empty, 1: selected, 2: suggested
int initialized = 0;

void availableseat();         // Display seat status
void arrangeforyou();         // Auto-arrange seats
void choosebyyourself();      // Manual seat selection


// Personal style screen + Password login + Menu loop
int main(void){
	printf("====================\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("++++++++++++++++++++\n");
	printf("====================\n");
	printf("\n");
	
	// Password login (max 3 attempts)
	int input,attempt=0;
	
	while (attempt < 3) {
	    printf("Please enter the password! (Hint: This year's year)\n");
	    scanf("%d",&input);
	    if(input==password){
		    printf("Password correct.\n");
		    system("CLS");
		    break; 
	    } 
	    else{
		    attempt++;
            printf("Incorrect password! You have %d attempts left.\n",3-attempt);
	    }
        if(attempt>=3){
	        printf("No attempts left! Access denied.\a\a\a\a\a\a\a\a\n");	
            return 0;
        }
    } 	

    // Main menu loop
    char option,di;
    do{
	    printf("-----[Booking System]-----\n");
        printf("|  a. Available seats     |\n");
        printf("|  b. Auto arrange seats  |\n"); 
        printf("|  c. Manual seat choice  |\n");
        printf("|  d. Exit                |\n"); 
        printf("--------------------------\n");
        
        printf("Please enter a to d:\n");
        scanf(" %c",&option);
        
        switch(option){
        	
        	case 'a' :
        	   availableseat();    // Show seat map
        	   break;
        	   
        	case 'b':
        	   arrangeforyou();    // Auto seat arrangement
        	   break;
        	
        	case 'c':
		       choosebyyourself(); // Manual seat selection
		       break;
			
    	    case 'd':
    	       printf("Continue? (y/n): \n");
    	       scanf(" %c",&di);
    	       if(di=='y'){
    	            break;
		       }
		       else if(di=='n'){
			        printf("Goodbye!\n");
			        return 0;
		       }
		       else{
			        printf("Invalid input, please try again.\n");
		       }
		       break;
			
		    default :
			    printf("Invalid input, please enter a to d.\n");
        }
    }while(1);		
    return 0;
}

// Randomly initialize 10 seats as selected
void initalseat() {
    srand(time(NULL));
    int count = 0;
    while(count < 10) {
        int r=rand()%rows;
        int c=rand()%cols;
        if (seat[r][c]==0){
            seat[r][c]=1;
            count++;
        }
    }
    initialized=1;
}

// Display seat layout: '-' empty, '*' selected, '@' suggested
void availableseat(){
    if (!initialized){
        initalseat();    // Lazy initialization
    }
    printf("\n   ");
    int k;
    for (k=0;k<cols;k++){
        printf("%d ",k+1);
    }
    printf("\n");
    int j,i;
    for(i=0;i<rows;i++){
        printf("%d ",rows-i);
        
        for(j=0;j<cols;j++){
            if(seat[i][j]==0)printf("- ");
            else if(seat[i][j]==1)printf("* ");
            else if(seat[i][j]==2) printf("@ ");
        }
        printf("\n");
    }
    printf("\nPress any key to return to the main menu...\n");
    getch();
    system("CLS");
}

// Automatically suggest seats (linear or 2x2 block)
void arrangeforyou() {
    int num,i,j,k,found=0;
    printf("How many seats do you want to book? (1~4): ");
    scanf("%d",&num);
    if (num<1||num>4) {
        printf("Invalid number. Please enter between 1 to 4.\n");
        return;
    }

    // Clear previous suggestions
    for (i=0;i<rows;i++)
        for (j=0;j<cols;j++)
            if (seat[i][j]==2)seat[i][j]=0;

    // Try to find horizontal seats
    for(i=0;i<rows&&!found;i++){
        for(j=0;j<=cols-num&&!found;j++){
            int ok=1;
            for (k=0;k<num;k++){
                if(seat[i][j + k]!=0){
                    ok=0;
                    break;
                }
            }
            if(ok){
                for(k=0;k<num;k++)seat[i][j+k]=2;
                found=1;
            }
        }
    }

    // Try 2x2 square if 4 seats needed and linear fails
    if (!found&&num==4) {
        for (i=0;i<rows-1&&!found;i++) {
            for (j=0;j<cols-1&&!found;j++) {
                if(seat[i][j]==0&&seat[i+1][j]==0&&
                    seat[i][j+1]==0&&seat[i+1][j+1]==0) {
                    seat[i][j]=seat[i+1][j]=seat[i][j+1]=seat[i+1][j+1]=2;
                    found=1;
                }
            }
        }
    }

    if (!found){
        printf("Sorry, no suitable seats found.\n");
        return;
    }

    availableseat();  // Show suggested seats
    char confirm;
    printf("Do you accept these suggested seats? (y/n): ");
    scanf(" %c",&confirm);

    if(confirm=='y'){
        for(i=0;i<rows;i++)
            for(j=0;j<cols;j++)
                if(seat[i][j]==2)seat[i][j]=1;
        printf("Seats successfully booked!\n");
    }else{
        for(i=0;i<rows;i++)
            for(j=0;j<cols;j++)
                if(seat[i][j]==2)seat[i][j]=0;
        printf("Booking canceled. Returning to main menu.\n");
    }
}

// User manually selects seat by row-column
void choosebyyourself(){
    int r,c;
    printf("Enter seat position (e.g. 1-2 means row 1, column 2): ");
    scanf("%d-%d", &r, &c);
    r=rows-r;
    c=c-1;
    if (r<0||r>=rows||c<0||c>=cols){
        printf("Invalid position. Please try again.\n");
        return;
    }
    if (seat[r][c]!=0) {
        printf("Seat already taken. Please choose another.\n");
        return;
    }
    seat[r][c]=1;
    availableseat();
    char confirm;
    printf("Do you want to confirm this seat? (y/n): ");
    scanf(" %c",&confirm);
    if(confirm=='y'){
        printf("Seat successfully selected!\n");
    } else {
        seat[r][c]=0;
        printf("Seat selection canceled. Returning to menu.\n");
    }
}

