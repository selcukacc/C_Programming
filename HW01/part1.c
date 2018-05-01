/*****************************************/
/*  Program takes user's numeric grades. */
/*      and converts to letter grades.   */
/*	Author:	Islam Goktan Selcuk    		 */
/*  Student Number: 141044071	   		 */
/*****************************************/
#include <stdio.h>

int main(void) {
    int input;	 /*User's input*/
    int sum;	 /*Total grade*/
    int avarage; /*avarage of all input*/
    int counter; /*counter for avarage*/

    counter = 0; /*initialize*/
    sum = 0;
    avarage = 0;    
/*takes first input*/
    scanf("%d", &input);
/*If input is "-1", loop is stopped.*/
    while(input != -1) {
	    sum += input;
	    counter++;
/*If input is bigger then 90, print "A"*/	    
	    if(input >= 90)
	        printf("A\n");
	    else if(input < 90 && input >= 80)
	        printf("B\n");
	    else if(input < 80 && input >= 70)
	        printf("C\n");
	    else if(input < 70 && input >= 60)
	        printf("D\n");
	    else if(input < 60)
	        printf("F\n");
	    else
	        printf("Invalid input. Try again.");
/*takes input for every loop*/	        
	    scanf("%d", &input);
    }
/*calculation of avarage*/
	if(counter != 0) {
    	avarage = sum / counter;
    }
    printf("%d ", avarage);
    if(avarage >= 90)
	        printf("A\n");
	    else if(avarage < 90 && avarage >= 80)
	        printf("B\n");
	    else if(avarage < 80 && avarage >= 70)
	        printf("C\n");
	    else if(avarage < 70 && avarage >= 60)
	        printf("D\n");
	    else if(avarage < 60)
	        printf("F\n");
    
	return 0;
}


