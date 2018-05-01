/***********************************/
/*     Program is doing simple     */
/*	simple arithmetic calculation. */
/*								   */
/*	Author:	Islam Goktan Selcuk    */
/*  Student Number: 141044071	   */
/***********************************/

#include <stdio.h>

int main(void) {
    int input; 		/*First input*/
    int input2;		/*Second input*/
    int result;		/*Last variable*/
    char op;		/*Operator of calculation*/

    scanf("%d", &input);	
    scanf(" %c", &op);
/* If operator is "=", loop is stopped. */    
    while(op != '=') {  
        scanf("%d", &input2);
        if(op == '+') {
/*First and second input is calculated.*/
            result = input + input2; }
        else if(op == '-') 
            result = input - input2;
        else if(op == '*')
            result = input * input2;
        else if(op == '/')
            result = input / input2;
/*First input is assigned result for calculation order.*/
        input = result;
        scanf(" %c", &op);
    }
    
    printf("%d\n", result);
    
	return 0;
}


