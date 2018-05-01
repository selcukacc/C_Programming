#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "sfrac.h"

char *sfrac_add(char * n1, char * n2) {
	int x1, x2, x3, x4;
	int numerator;
	int denominator;
	
	char_to_integer(n1, &x1, &x2);
	char_to_integer(n2, &x3, &x4);
	
	numerator = (x4 * x1) + (x2 * x3);
	denominator = x2 * x4;
	
	gcd(&numerator, &denominator);
	
	return(integer_to_char(numerator, denominator));
}

char *sfrac_sub(char * n1, char * n2) {
	int x1, x2, x3, x4;
	int numerator;
	int denominator;
	
	char_to_integer(n1, &x1, &x2);
	char_to_integer(n2, &x3, &x4);

	numerator = (x4 * x1) - (x2 * x3);
	denominator = (x4 * x2);
	gcd(&numerator, &denominator);
	
	return(integer_to_char(numerator, denominator));
}

char *sfrac_mult(char * n1, char * n2) {
	int x1, x2, x3, x4;
	int numerator;
	int denominator;
	
	char_to_integer(n1, &x1, &x2);
	char_to_integer(n2, &x3, &x4);

	numerator = (x1 * x3);
	denominator = (x4 * x2);
	gcd(&numerator, &denominator);
	
	return(integer_to_char(numerator, denominator));
}

char *sfrac_div(char * n1, char * n2) {
	int x1, x2, x3, x4;
	int numerator;
	int denominator;
	
	char_to_integer(n1, &x1, &x2);
	char_to_integer(n2, &x3, &x4);

	numerator = (x1 * x4);
	denominator = (x3 * x2);
	gcd(&numerator, &denominator);
	
	return(integer_to_char(numerator, denominator));
}

char *sfrac_fromdouble(double x) {
	int i = 0;
	int iValue = x;
	int divisor;
	double dValue = x;
	double value = dValue - iValue;

	while(value > 0) {
		dValue *= 10;
		iValue = dValue;
		value =  dValue - iValue;
		i++;
	}
	divisor = pow(10, i);
	
	gcd(&iValue, &divisor);
	
	return (integer_to_char(iValue, divisor));
}

double sfrac_todouble(char *x) {
	int i, j;
	char charOne[50];
	char charTwo[50];
	char ch;
	double doubleOne = 0.0;
	double doubleTwo = 0.0; 
	int digitOne, digitTwo, value;

	i = 0;
	j = 0;
	
	
	while(x[i] != '/') {
			charOne[i] = x[i];
			i++;
	}
	charOne[i] = '\0';
	digitOne = i;

	i++;	
	while(x[i] != '\0') {
		charTwo[j] = x[i];
		i++;
		j++;
	}	
	charTwo[j] = '\0';
	digitTwo = j;

	for(i = 0; i < digitOne; i++) {
		ch = charOne[i];
		value = ch - '0';
		doubleOne += value * pow(10, digitOne - (1+i));
	}
	
	for(i = 0; i < digitTwo; i++) {
		ch = charTwo[i];
		value = ch - '0';
		doubleTwo += value * pow(10, digitTwo - (1+i));
	}
	
	if(doubleTwo == 0) {
		printf("The divisor can not be zero. Error.\n");
		return (-1);
	}	

	return (doubleOne/doubleTwo);
}

void gcd(int *n1, int *n2) {
	int i = 1;
	int gcd = 1;
	
	while(*n1 >= i && *n2 >= i) {
		if(*n1 % i == 0 && *n2 % i == 0)
			gcd = i;
		i++;	
	}

	*n1 /= gcd;
	*n2 /= gcd;	
}

void sfrac_simplify(char *n) {
	int numerator;
	int denominator;
	
	char_to_integer(n, &numerator, &denominator);
	
	gcd(&numerator, &denominator);
	
	strcpy(&n[0], integer_to_char(numerator, denominator));
		
}

void sfrac_print(char *a1, char *n1, char *a2, char *n2, char *a3, char *n3,
char *a4) {
	printf("%s%s%s%s%s%s%s", a1, n1, a2, n2, a3, n3, a4);
}

char *integer_to_char(int n1, int n2) {
	int digits = 0;
	int temp;
	int i, j;
	int num;
	int reduced;
	int x;
	char ch;
	char n[50];
	char *np;
	
	temp = n1;
	while(temp > 0) {
		temp /= 10;
		digits++;
	}	
	
	temp = n1;
	for(i = 0; i < digits; i++) {
		num = temp / pow(10, digits - (i+1));
		ch = num + 48;
		n[i] = ch;
		reduced = num * pow(10, digits - (i+1));
		temp -= reduced;
	}
	n[i++] = '/';
	

	digits = 0;
	temp = n2;
	while(temp > 0) {
		temp /= 10;
		digits++;
	}
	
	temp = n2;
	x = 1;
	for(j = i; j < digits + i; j++) {
		num = temp / pow(10, digits - x);
		ch = num + 48;
		n[j] = ch;
		reduced = num * pow(10, digits - x);
		temp -= reduced;
		x++;
	}
	n[j] = '\0';
	
	np = (char *)malloc(j+1);
	strcpy(np, n);
	 
	return (np);
}

void char_to_integer(char *n, int *n1, int *n2) {
	int i = 0;
	int j = 0;
	char string_n1[50];
	char string_n2[50];
	char ch;
	int value;
	int digits_n1;
	int digits_n2;
	*n1 = 0;
	*n2 = 0;
	
	while(n[i] != '/') {
			string_n1[i] = n[i];
			i++;
	}
	string_n1[i] = '\0';
	digits_n1 = i;

	i++;	
	while(n[i] != '\0') {
		string_n2[j] = n[i];
		i++;
		j++;
	}	
	string_n2[j] = '\0';
	digits_n2 = j;

	for(i = 0; i < digits_n1; i++) {
		ch = string_n1[i];
		value = ch - '0';
		*n1 += value * pow(10, digits_n1 - (1+i));
	}
	
	for(i = 0; i < digits_n2; i++) {
		ch = string_n2[i];
		value = ch - '0';
		*n2 += value * pow(10, digits_n2 - (1+i));
	}
	
	if(*n2 == 0) {
		printf("The divisor can not be zero. Error.\n");
	}		
	
}

int isPrime(int n) {
	int i;
	int status;
	
	status = 1;
	for(i = 2; i <= n/2; i++) {
		if(n % i == 0)
			status = 0;
	}
	
	if(n <= 1)
		status = 0;
		
	return (status);
}
