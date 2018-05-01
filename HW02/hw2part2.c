/******************************************/
/*    Program takes value of the file and */
/*  calculate polynomials with them.      */
/*	Author:	Islam Goktan Selcuk    		  */
/*  Student Number: 141044071	   		  */
/******************************************/
#include <stdio.h>

int polynomial(FILE *inp, int x);
int lastValue(FILE *inp);
int power(int number, int degree);
int numberofLines(FILE *inp);

int main(void) {
	FILE *inp; 	/* file for polynomial result*/
	FILE *inp2; /* file for x value */
	FILE *inp3; /* file for EOF */
	
	int x;		/* x for polynomial */
	int value;  /* polynomial result */
	int min;    /* min result */
	int max;    /* maximum result */
	int n;		/* number of lines */
	int i;		/* counter */
	
	inp = fopen("a.txt", "r");
	inp2 = fopen("a.txt", "r");
	inp3 = fopen("a.txt", "r");
	

	x = lastValue(inp);
	value = polynomial(inp2, x);
	n = numberofLines(inp3);	

	min = value;
	max = value;	
	/* continues until end of file */
	for(i = 0; i < n; i++) { 
	/* finding max and min value */
		if(value > max)
			max = value;
		if(value < min)
			min = value;
		x = lastValue(inp);
		value = polynomial(inp2, x);
	}
	
	printf("Maximum value: %d\nMinimum Value: %d\n", max, min);

	return 0;
}

int polynomial(FILE *inp, int x)
{
	int i;   		/*counter*/
	int num;		/*value in the choosen line*/
	int degree;
	int sum;		/*calculation result*/
	int status;     /*file status for loop control*/
	int temp;		/*temporary value*/
	
	status = fscanf(inp, "%d", &degree);
	temp = degree;
	sum = 0;
	for(i = 0; i < degree + 1 && status != EOF && status == 1; i++) {
		status = fscanf(inp, "%d", &num);
		sum += num * power(x, temp);
		temp--;
	}
	status = fscanf(inp, "%d", &temp);
	return (sum);
}
/* finding x value */
int lastValue(FILE *inp)
{
	int num; /* numbers */
	int degree; /* degree for loop control */
	int i; /*counter*/
	int status;
	
	/* taking first value */
	status = fscanf(inp, "%d", &degree);
	for(i = 0; i < degree + 2 && status != EOF; i++)
		status = fscanf(inp, "%d", &num);
	/* returns every value of file*/	
	return (num);
}
/* it finds end of file and return number of lines */
int numberofLines(FILE *inp) {
	int status;
	int temp;
	int degree;
	int i;
	int counter = 0;
	
	while(status != EOF) {
		status = fscanf(inp, "%d", &degree);
		counter++;
		for(i = 0; i < degree + 2 && status != EOF; i++)
			status = fscanf(inp, "%d", &temp);
	}
	
	return (counter - 1);
}

/* calculates power of number */
int power(int number, int degree)
{
	int i;
	int result = 1;
	
	if(number == 0)
		result = 0;
	else if(degree == 0)
		result = 1;
	else	
		for(i = 0; i < degree; i++) {
			result *= number;
		}	
	return (result);
}
