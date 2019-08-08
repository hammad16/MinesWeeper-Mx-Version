//Librarys
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


void print_board(int board[][10], int lose); /*functions to print board*/
void place_bombs(int mines[][10], int exp); /*function to colocate bombs*/
#define ROW 10 /*define the constant row with value 10*/
#define COL 10 /*define the constant col with value 10*/

//main
int main()
{
  	int minesweeper[ROW][COL] = {0}, x, y; /*Declaration of ROW and COL [x], [y]*/
	int level, bombs;	/*Declaration of random bombs*/
	int score, counter = 0, win;	/*Declaration of game control*/
 	int attempts;	/*Declaration of statistic of the game*/
  	char output;  /*Declaration of a character function*/
  	float rate; /*Declaration for the raiting


		/*function to colocate the boms in the board through of a 
		random function of 0-9, mines[row][col] = is the logic value for 
		the bombs in the program */
		void place_bombs(int mines[][10], int exp)
		{
		     int x, row, col; //declarate x, row and col
		     
		     /* colocate the boms in the board through of a 
			random function of 0-9 */
		     for(x = 1; x <= exp; x++)
		     {
		           row = 0 + rand() % 9;
		           col = 0 + rand() % 9;
		           /*logic values*/
		           mines[row][col] = 3;
		     }
		}

		/*function to show board style;  */
		void print_board(int board[][10], int lose)
		{
			 /*declarate variables*/
		     int x, y;
		     /*for header*/
		     for(x = 0; x <= ROW -1; x++)  
		     printf("%d ", x);
		     printf("\n");
		  	
		  	/*for the "lines" around of the colums*/
		     for(x = 0; x <= COL - 1; x++) 
		     
		     printf("-~");
		     printf("\n");
		     

		     /* This for is to print the mines with the * and the 
		     separator | around the rows, the character that will 
		     be selected - */
		     for(x = 0; x <= ROW -1; x++)
		     {
		           for(y = 0; y <= COL - 1; y++){
		             if(board[x][y] == 1)
		               printf("%d ", board[x][y]);
		           /*for the mines*/
		             else if((board[x][y] == 3) && (lose == -1))
		               printf("%c ", '*'); 
		             else
		            /*for the character that will be selected*/
		               printf("%c ", '_');         
		           }
		           
		           /*for the character around the rows*/   
		           printf("| %d", x);  
		           printf("\n");  
		      
		    }    
		}

		do{

			/* The following printf have the function to show
			the tittle of the game, instructions, and ask to user 
			the level of difficult that they want, and the scanf 
			is the scanf to level registred.*/

		    printf("\nMinesweeper\n\n");
		    printf("The game consist in a matrix of 9x9 quadrants with row and columns where you need an enter a coordinates, if you put many attempts you have a good luck!,  .\n\n");
		    printf("Enter the level difficult:\n\n%d.-Baby\n", 1);
		    printf("%d.-Easy\n%d.-Medium\n%d.-Hard\n%d.-Extreme\n", 2, 3, 4, 5);
		    printf("\n");
		    scanf("%d", &level);
		    
		    /*main with switchs, the number of bombs are the mines that will be in the game*/ 
		    switch(level){
		       
		        case 1: bombs = 10; /*If the case 1 is select, the bombs will be 10 in the game*/
		                break;
		        
		        case 2: bombs = 15; /*If the case 2 is select, the bombs will be 15 in the game*/
		                break;
		                   
		        case 3: bombs = 20; /*If the case 3 is select, the bombs will be 20 in the game*/
		                break;
		                   
		        case 4: bombs = 25; /*If the case 4 is select, the bombs will be 25 in the game*/
		                break;
		                   
		        case 5: bombs = 30; /*If the case 5 is select, the bombs will be 30 in the game*/
		                break;	           
				default: printf("Invalid Option.\n");
						break;    
		    }
	
		    /* With srand(time(NULL)); we can generate a random numbers.
		    place_bombs(minesweeper, boms); Is the function to minesweeper and score
		    attempts = 0; is the counter for the number of attempts*/

		    srand(time(NULL));
		       
		    place_bombs(minesweeper, bombs);
		       
		    attempts = 0;

		    do{

		    	/*Clean the screen and show the title*/
		        system("cls");
		        printf("\nMinesweeper\n\n");

		        /* function to minesweeper and score, show the map 
		        of coordinates*/
		        print_board(minesweeper, score);   
		        printf("\n");

		        /*  Ask to user the coordinates x and y (row, column)
		        the coordinate is for use in the matrix*/ 
		        printf("*Enter the row[x]: ");
		        scanf("%d", &x);
		        printf("*Enter the column[y]: ");
		        scanf("%d",&y);
		        

		        /* This "if" is for prove the varible minesweeper
		        if the condition has not cumply  */
		        if(minesweeper[x][y] == 3){                               
		            score = -1;
		            attempts++;
		         /* In this part, the function print_board() has the 
		         function of keep the matrix and*/     
		            system("cls");
		            printf("\nMinesweeper\n\n");
		            print_board(minesweeper, score);
		        /*Print the final note when the player has lost*/    
		            printf("\n\nYou lost :(!, the game has finished");
		            getch();               
		        }

		        /*When the if has not cumply
		        the else this contain the matrix*/ 
		        else
		        {
		            minesweeper[x][y] = 1;
		            counter++;
		            attempts++;
		        }

		        /* This part is for show the message of congratulations
		        when the playes has won
		        if the counter is = 100 - bombs
		        are 100 because is the total of spaces in te matrix
		          */
		        if(counter == (100 - bombs) )
		        {
		            win = 1;
		            system("cls");
		            printf("\nMinesweeper\n\n");
		            /*show the matriz*/
		            print_board(minesweeper, score);

		            printf("You winner!, Congratulations!!");
		       
		            getch();
		        }        
		           
		               
		    }

		    /* This while is for show in the screen the number
		    of attempts that the user has realized and the raiting obtained */

		    while(score != -1 || win == 1);
		    /*the operation is multiplies for 40 to obtain
		    an score for the player*/
		    rate = ((float)counter * 40) / 100;	
		    printf("\n\nYour raiting is %.2f points. \n", rate);   
		    printf("\n*Number of attempts %d.\n\n", attempts);
		       
		    system("pause");
		           
		       	counter = 0; //game counter
		
		 }

		/* The final command to say goodbye to player */ 
		while(output == 's');           
		    
		system("cls");
		printf("\nSee you soon!!-\n\n");
		getch();
		return 0;
}


