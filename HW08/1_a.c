/*---------------------*
 * HW8 Part 1.a        *
 * Islam Goktan Selcuk *
 * No: 141044071       *
 *---------------------*
*/

#include <stdio.h>

int int_to_binary(int n, int i);
int power(int n, int m);

int main(void)
{
	int n;
	
	printf("Enter positive integer: ");
	scanf("%d", &n);
	
	if(n >= 0)
	{
		printf("Binary number is %d.\n", int_to_binary(n, 0));
	}
	
	return (0);
}

int int_to_binary(int n, int i)
{
	int result;
	
	if(n < 2)
	{
		result = (n % 2) * power(10, i);
	}
	else
	{
		result = ( (n % 2) * power(10, i) ) + int_to_binary(n / 2, i + 1);
	}
	
	return (result);
}

int power(int n, int m)
{
	int ans = 1;
	
	while(m > 0)
	{
		ans *= n;
		m--;
	}
	
	return (ans);
}
