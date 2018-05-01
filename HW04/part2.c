/* Homework 4 */
/* Name: Islam Goktan Selcuk */
/* Student No: 141044071 */

#include <stdio.h>
/* dizinin sutun sayisi */
#define Max_N 8

/* fonksiyon prototipi*/
int find(char Puzzle[][Max_N], int row, int column, char orientation,
char *word);

int main(void) {
	int i, j;             /* donguler icin sayaclar */
	int row, column;      /* kullanıcıdan alinan lokasyon */
	char word[8];		  /* aranacak kelime */
	char orientation;     /* aranacak kelimenin bulmacadaki yazilis yonu */
	int result;           /* find fonksiyonunun sonucu */
	char decision = 'c';  /* programin kapanip, kapanmayacagini belirler */
/* bulmaca */
	char MyPuzzle[][Max_N] = {
	{'T', 'N', 'E', 'U', 'E', 'L', 'G', 'C'},
	{'T', 'L', 'E', 'M', 'O', 'N', 'E', 'O'},
	{'S', 'C', 'H', 'E', 'R', 'R', 'Y', 'T'}};

/* kullanici istemedigi surece programi surdur */
	while( (decision != 'q' && decision != 'Q') ||
		   (decision == 'c' && decision == 'C') ) 
	{
	/* bulmacanin tamamini yazdir */
		printf("    PUZZLE\n");
		for(i = 0; i < 3; i++) {
			for(j = 0; j < Max_N; j++) {
				printf("%c ", MyPuzzle[i][j]);
			}
			printf("\n");
		}
	/* kullanicidan alinan veriler */	
		printf("Enter a word: ");
		scanf("%s", word);
		printf("Enter row and column (They start 1, not 0.) : ");
		scanf("%d%d", &row, &column);
		printf("Enter orientation: ");
		scanf(" %c", &orientation); 
	/* dizi uzerinden islem yapabilmek icin satir ve sutun 1 azaltilir */
		row--;
		column--;
	/* fonksiyonun sonucu result a esitlenir */	
		result = find(MyPuzzle, row, column, orientation, word);
	/* eger kelime bulunursa "found", bulunmazsa "not found" yazdir */
		if(result == 1)
			printf("Found!\n");
		else
			printf("Not found!\n");
	/* dongunun devam etmesi icin veri istenir */	
		printf("If you want to quit, enter 'q' or 'Q'.\n");	
		printf("If you want to continue enter 'c' or 'C'.\n");
		scanf(" %c", &decision);
	
	} 
	
	return (0);
}

int find(char Puzzle[][Max_N], int row, int column, char orientation,
char *word) {
	int i;          /* donguler icin sayac */
	int status = 1; /* fonksiyonun sonucunu belirler */

/* orientationa gore kontrol edilecek yon secilir */
	if(orientation == 'r' || orientation == 'R') {
	/* kelime bitene kadar dizide kelimeyi kontrol et */
		for(i = 0; word[i] != '\0'; i++) {
			/* eger kelime ve dizide uyusmazlik varsa status' u sifira esitle*/
			/* satir sabit, sutun surekli bir azaltilir */
			if(Puzzle[row][column - i] != word[i]) {
				status = 0;
			}
		}		
	}
	else if(orientation == 'l' || orientation == 'L') {
		for(i = 0; word[i] != '\0'; i++) {
			/* satir sabit, sutun surekli bir artirilir */
			if(Puzzle[row][column + i] != word[i]) {
				status = 0;	
			}
		}
	}
	else if(orientation == 't' || orientation == 'T') {
		for(i = 0; word[i] != '\0'; i++) {
		/* sutun sabit, satir surekli bir artirilir */
			if(Puzzle[row + i][column] != word[i]) {
				status = 0;
			}
		}
	}			
	else if(orientation == 'b' || orientation == 'B') {
		for(i = 0; word[i] != '\0'; i++) {
		/* sutun sabit, satir surekli bir azaltilir */
			if(Puzzle[row - i][column] != word[i]) {
				status = 0;
			}	
		}	
	}
	else {
	/* eger orientation farkli girilirse status 0 olur */
		status = 0;
	}
	/* fonksiyonun sonucu status return edilir */	
	return (status);
}
