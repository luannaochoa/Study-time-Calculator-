#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


typedef struct Course{
    char *name;
    int credits;
    int hrsWeekly;
    int difficulty;
} Course;


/* Called: in main */
/*Function creates struct*/
 Course *Course_create(char *name, int credits, int hrsWeekly, int difficulty)
{
    Course *class = malloc(sizeof(struct Course));
    assert(class != NULL);

    class->name = strdup(name);
    class->credits = credits;
    class->hrsWeekly = hrsWeekly;
    class->difficulty = difficulty;

    return class;
}

/*Called: in main*/
/*Function Prints out struct*/
void Course_print(Course *class)
{
    printf("\nCOURSE NAME: %s\n", class->name);
    printf("-------------------------------------\n");
    printf("\tCREDITS: %d\n", class->credits);
    printf("\tHOURS WEEKLY: %d\n", class->hrsWeekly);
    printf("\tDIFFICULTY: %d\n", class->difficulty);
    printf("\tSUGGESTED MINIMUM HOURS SPENT STUDYING: %d \n", class->difficulty * class->hrsWeekly);
 
}


/* Function that will delete structure so we "clean up" */
void Course_destroy(Course *class)
{
    assert(class != NULL);

    free(class->name);
    free(class);
}



int main( ) {


   /*Ask user how many classes they are taking*/
   /*We need this info to loop the program the correct number of times*/
		   int courseLoad;

		   printf("Enter the number of courses you are taking this semester:");
		   scanf("%d", &courseLoad);
		   



   /*Create structs based on user provided info*/
		   int count;
		   char userProvidedClassName[6];
		   int  userProvidedCreditNumber;
		   int 	userProvidedHrsWeekly;
		   int  userProvidedDifficulty;
		   char *nameClassinForLoop;

		   
		  

/*To do: Will use while loop to make this repeat*/ 
		    /*We create 1 struct at a time*/
		   for( count = 0; count < courseLoad; ++count )
		   {
		   

		   /* Collecting all struct information from user*/
		   /*Printing struct info that was collected*/
		   printf("\nPlease provide the course name:");

/*To do: Need to make this prog. error proof for the user. */

		   printf("\n-------------------------------------\n");
		   scanf("%s", userProvidedClassName);
	

		   printf("\nPlease provide the course credit value, weekly hrs and difficulty:");
		   scanf("%d %d %d", &userProvidedCreditNumber, 
		   					 &userProvidedHrsWeekly,
		   					 &userProvidedDifficulty);



		   /* Creating struct with user provided info*/
		   /*Printing struct that was created*/
	
		   nameClassinForLoop = userProvidedClassName;
		   Course *userProvidedClassName = Course_create( nameClassinForLoop, 
		   														 userProvidedCreditNumber, 
												   				 userProvidedHrsWeekly, 
												   				 userProvidedDifficulty);

		   
   		   Course_print(userProvidedClassName);

		   


		   }


   return 0;
}

