#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "sfrac.h"

int main(void) {
	char n1[100];
	char n2[100];
	char islem;
	char ch;
	int i = 0;
	
	
	printf("Input your operation: ");
	scanf("%c", &ch);
	while(ch != '+' && ch != '-' && ch != ':' && ch != '*') {
		n1[i] = ch;
		scanf("%c", &ch);
		i++;
	} 
	n1[i] = '\0';
	islem = ch;
	
	i = 0;
	scanf("%c", &ch);
	while(ch != '\n' && ch != '\0') {
		n2[i++] = ch;
		scanf("%c", &ch);
	}	
	n2[i] = '\0';
	
	printf("Result is: ");
	if(islem == '+') 
		printf("%s\n", sfrac_add(n1, n2));
	else if(islem == '-') 
		printf("%s\n", sfrac_sub(n1, n2));
	else if(islem == '*')
		printf("%s\n", sfrac_mult(n1, n2));
	else if(islem == '/')
		printf("%s\n", sfrac_div(n1, n2));
	else
		printf("Error.\n");
	
	
	return (0);
}
