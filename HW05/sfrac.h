
/*HEADER FILE*/
extern char *sfrac_add(char * n1, char * n2);
extern char *sfrac_sub(char * n1, char * n2);
extern char *sfrac_mult(char * n1, char * n2);
extern char *sfrac_div(char * n1, char * n2);

extern char *sfrac_fromdouble(double x);
extern double sfrac_todouble(char *x);

extern void sfrac_simplify(char *n);
extern void sfrac_print(char *a1, char *n1, char *a2, char *n2, char *a3, char *n3,
char *a4);

extern void gcd(int *n1, int *n2);
extern void char_to_integer(char *n, int *n1, int *n2);
extern char *integer_to_char(int n1, int n2);

extern int isPrime(int n);
