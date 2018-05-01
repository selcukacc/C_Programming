/*---------------------*
 * HW8 Part 1.b        *
 * Islam Goktan Selcuk *
 * No: 141044071       *
 *---------------------*
*/

#include <stdio.h>

int function(int x, int y);

int main(void)
{
	int x, y;
	
	printf("Enter x and y: ");
	scanf("%d%d", &x, &y);
	
	printf("Result is %d.\n", function(x, y));
	
	return (0);
}

int function(int x, int y)
{
	int ans;
	
	if(x <= 0 || y <= 0)
	{
		ans = 0;
	}
	else
	{
		ans = x + y + function(x - 1, y) + function(x, y - 1);
	}
	
	return (ans);
}
