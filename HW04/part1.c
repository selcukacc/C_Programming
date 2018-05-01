/* Homework 4 */
/* Name: Islam Goktan Selcuk */
/* Student No: 141044071 */

#include <stdio.h> 
/*Fonksiyon prototipleri*/
void init(int s[][9]);
void read_from_file(FILE *file_pointer, int s[][9]);
int is_legal(int s[][9], int r, int c, int x);
void place(int s[][9], int r, int c, int x);
void write_to_the_file(FILE *file_pointer, int s[][9]);

int main(void) {
	int sudoku[9][9];
	FILE *inp;
	
/*Eger dosya acilamiyorsa kullaniciya bildir*/	
	inp = fopen("sudoku.txt", "r");
	if(inp == NULL) {
		printf("Cannot open file.\n");
	}

/*Sudokuyu sifirla*/	
	init(sudoku);
/*Sudokuyu dosyadan okuyup, hata yoksa dosyaya tekrar yazdir*/	
	read_from_file(inp, sudoku);

	return (0);
}

void init(int s[][9]) {
	int i, j;
/*Tum diziye ulasarak diziyi sifirla*/	
	for(i = 0;i < 9; i++)
		for(j = 0; j < 9; j++)
			s[i][j] = 0;
}

void read_from_file(FILE *file_pointer, int s[][9]) {
	int i, j;		 /* donguler icin sayaclar */
	int temp;		 /* dosyadan okunan sayiyi gecici olarak tutar */
	int status = 1;  /* sudokunda hata varsa 0' a esitleir, yoksa 1 kalir */

/* Dosyadaki her karakteri sırayla okuyarak diziye kopyalar */
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			fscanf(file_pointer, "%d", &temp);
/* Eger karakter sudokuya uymuyorsa, hata mesaji verip donguleri sonlandırır */
			if(is_legal(s, i, j, temp) == 0) {
				printf("There is an error in the sudoku.\n");
				/* donguler devam etmemeleri icin sayaclar 9'a esitlenir */
				j = 9;
				i = 9;
				/* Sudokunda hata oldugu icin 0' a esitlenir*/
				status = 0;
			}
/* Eger karakter sudokuya uyuyorsa, karakter diziye kopyalanir */			
			else
				place(s, i, j, temp);
		}						
	}
/* Eger sudokunda hata yoksa sudoku print edilir ve dosyaya yazdirilir */	
	if(status == 1) {
		for(i = 0; i < 9; i++) {
			for(j = 0; j < 9; j++) {
				printf("%d ", s[i][j]);
			}
			printf("\n");	
		}
		
		write_to_the_file(file_pointer, s);
	}	
	
}

int is_legal(int s[][9], int r, int c, int x) {
	int i, j;         /* donguler icin sayaclar */
	int status = 1;   /* fonksiyonun sonunda return edilir */
	int row, column;  /* dongulerde limiti belirlerler */
	
	/* kontrol edilen lokasyonda satirin tamamina bakilir */
	for(i = 0;i < 9; i++) {
/* eger satirda kontrol edilen sayiyla ayni sayi varsa ve bu sayi sifir degilse
status 0' a esitlenir */
		if(s[r][i] == x && s[r][i] != 0) {
			status = 0;
		}	
	}
/* kontrol edilmek sayinin, sudokunun hangi 
parcasinda oldugu bulunur */	
	row  = (r / 3) * 3;
	column = (c / 3) * 3;
	
/* 9 sayinin bulundugu o parca kontrol edilir */
	for(i = row; i < row + 3; i++)
		for(j = column; j < column + 3; j++) 
			if(s[i][j] == x && s[i][j] != 0)
				status = 0;
/* verilen lokasyon sifir degilse status sifira esitlenir */
	if(s[r][c] != 0)
		status = 0;
	
	return (status);
} 

void place(int s[][9], int r, int c, int x) {

	s[r][c] = x;
}

void write_to_the_file(FILE *file_pointer, int s[][9]) {

	int i, j;
	
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
		/* sirayla dizideki tum sayilar dosyaya yazilir*/
			fprintf(file_pointer, "%d ", s[i][j]);
		}
		/* her 9 sayidan sonra satir degistirilir */
		fprintf(file_pointer, " %c", '\n');
	}		
	
}
