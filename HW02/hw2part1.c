/******************************************/
/*    Program draws geometric shapes with */
/*  their specifications.                 */
/*	Author:	Islam Goktan Selcuk    		  */
/*  Student Number: 141044071	   		  */
/******************************************/
#include <stdio.h>

void Draw_Triangle(int starting_point, int length, int layer_type);

void Draw_Rectangle(int starting_point, int length, int width, int layer_type);

void Draw_Circle(int center, int radius, int layer_type);
/* it is funtion for a lot of loop */
void writer(char character, int repetition);

int main(void) {
/* variables for functions */
	int choice;         /* shape choice */
/* shape specifications */
	int starting_point; 
	int length;
	int width;
	int layer_type;		
	int center;
	int radius;
	
/* scaning choice */	
	printf("Which shape do you want to draw? (Enter 1, 2 or 3.)\n");
	printf("1- Rectangle\n2- Triangle\n3- Circle\nChoice->> ");
	scanf("%d", &choice);
	
	printf("\nSpecifications of Shape\n");
	if(choice == 1) {
		printf("Starting point->> ");
		scanf("%d", &starting_point);
		printf("Length->> ");
		scanf("%d", &length);
		printf("Width->> ");
		scanf("%d", &width);
		printf("Layer type->> ");
		scanf("%d", &layer_type);
		Draw_Rectangle(starting_point, length, width, layer_type);
	}	
	else if(choice == 2) {
		printf("Starting point->> ");
		scanf("%d", &starting_point);
		printf("Length->> ");
		scanf("%d", &length);
		if(length % 2 == 0) {
			while( length % 2 == 0 ) {
			printf("Please enter odd number for length->> ");
			scanf("%d", &length);
			}
		}
		printf("Layer type->> ");
		scanf("%d", &layer_type);
		Draw_Triangle(starting_point, length, layer_type);
	}
	else if(choice == 3) {
		printf("Center->> ");
		scanf("%d", &center);
		printf("Radius->> ");
		scanf("%d", &radius);
		printf("Layer type->> ");
		scanf("%d", &layer_type);
		Draw_Circle(center, radius, layer_type);
		return 0;
	}
	else
		printf("Invalid input!\n");
	
	return 0;
}

void writer(char character, int repetition)
{
	int i;
	
	for(i = 0; i < repetition; i++) 
		printf("%c", character);
}

void Draw_Triangle(int starting_point, int length, int layer_type)
{
	int i, j; 				/* counter for loops */
	int space;				/* inside of triangle */
	int blankPart;			/* spaces outside the triangle(left side) */
	int middlePart;			/* length's middle of triangle */
	
	middlePart = (length - 3) / 2; 
	blankPart = (length / 2) * layer_type;
	space = 1; /* space in the second line*/
	
	/* top part of triangle*/
	for(i = 0; i < layer_type; i++) {
		writer(' ', starting_point + blankPart);	
		writer('*', layer_type);	
		printf("\n");
	}	
	blankPart -= layer_type;
	/* middle part*/		
	for(i = 0; i < middlePart; i++) {
		/* loop for each line */
 		for(j = 0; j < layer_type; j++) {
 			/* it starts spaces*/
	 		writer(' ', starting_point + blankPart);
			/* first character of the line */
			writer('*', layer_type);		
			/* spaces between characters */	
			writer(' ', space * layer_type);
			/* last character of the line */
			writer('*', layer_type);
			/* next line */
			printf("\n");
		}	
		/* blanks of the left side */
		blankPart -= layer_type;
		/* blanks between two character */
		space += 2;
	}
	/* last part of triangle */
	for(i = 0; i < layer_type; i++) {
		writer(' ', starting_point);
		writer('*', length * layer_type);
		printf("\n");
	}	
}

void Draw_Rectangle(int starting_point, int length, int width, int layer_type) 
{
	int i;
	/* first line */
	/* loops for shape's layer */
	for(i = 0; i < layer_type; i++) {
		writer(' ', starting_point);
		/* characters */
		writer('*', width * layer_type);
		/* next line */
		printf("\n");
	}	
	/* middle part without first and last line of the rectangle */
	for(i = 0; i < (length - 2) * layer_type; i++) {	
		writer(' ', starting_point);
		/* first characters of the line */
		writer('*', layer_type);
		/* blanks between characters */
		writer(' ', (width - 2) * layer_type);
		/* last characters of the line*/
		writer('*', layer_type);
		/* next line */
		printf("\n");
	}	
	
	/* last line */
	for(i = 0; i < layer_type; i++) {
		writer(' ', starting_point);
		writer('*', width * layer_type);
		printf("\n");
	}	
}

void Draw_Circle(int center, int radius, int layer_type)
{
	int i;
	int space; /* blanks for center value */
	int space2; /* spaces left side of the circle */
	int space3; /* spaces inside of the circle */

	space = 0;
	space3 = radius * layer_type;
	space2 = (radius - 3) * layer_type;
/* if center is bigger then radius, creates blanks */
	if(center > radius)
		space = (center - radius - 1) * layer_type;
/* create blanks for radius of circle(middle part) */	
	if(radius > 5)
		space3 = (radius - 1) * layer_type;
	else if(radius < 5)
		space3 = (radius + 1) * layer_type;
	/* first line */
	writer(' ', radius * layer_type + space);
	writer('*', layer_type);
	printf("\n");
/* top part of the circle */	
	for(i = 0; i < radius - 3; i ++) {
		writer(' ', space2 + space);
		writer('*', layer_type);
		writer(' ', space3);
		writer('*', layer_type);
		printf("\n");
		space2 -= layer_type;
		space3 += 2 * layer_type;
	}	
/* different condition for space of the middle part */
	if(radius <= 3) 
		space3 = (2 * radius - 1) * layer_type;
/* middle part of the circle*/	
	if(radius > 1) 
		writer('\n', 2);
	writer(' ', space);
	writer('*', layer_type);
	writer(' ', space3);
	writer('*', layer_type);
	printf("\n");
	space3 -= 2 * layer_type;;
	space2 += layer_type;
	if(radius > 1) 
		writer('\n', 2);
/* last part of the circle */	
	for(i = 0; i < radius - 3; i++) {
		writer(' ', space2 + space);
		writer('*', layer_type);
		writer(' ', space3);
		writer('*', layer_type);
		printf("\n");
		space3 -= 2 * layer_type;;
		space2 += layer_type;
	}	
	/* last line */
	writer(' ', radius * layer_type + space);
	writer('*', layer_type);
	printf("\n");
}

