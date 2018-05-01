/*
 *--------------------------------------------------------------------*
 * Isim: Islam Goktan SELCUK									      *
 * No: 141044071										              *	
 *	 Programin Amaci: token.txt ve emails.txt dosyalarini okuyup      *
 * icindeki hatalari kontrol eder. Hatalara bagli olarak dosyalardaki *
 * verileri gruplara ayirip print eder.                               * 
 *--------------------------------------------------------------------*
 */
 
/* kutuphaneler*/
#include <stdio.h>
#include <string.h>

/* token dosyasi icin structure */
typedef struct {
	char name[50];	  /* token'lerin tamami */
	int repetition;	  /* token'lerin tekrar edilmemesi gereken sayi*/
} token_t;
/* emails dosyasi icin structure */
typedef struct {
	char email_subject[250]; /* emailin subject bolumunu tutar */
	char email_body[1000]; 	 /* emailin body bolumunu tutar */
} emails_t;

/* token dosyasi icin fonksiyon prototipleri */
/* token dosyasini tarayip verileri tokens structure'a kaydeder */
void scan_token(FILE *input, token_t tokens[], int *list_size);
/* structure deki verileri print eder */
void print_token(token_t tokens[], int n);

/* emails dosyasi icin fonksiyon prototipleri */
/* emails dosyasini tarayip verileri emails structure'a kaydeder */
void scan_emails(FILE *inp2, emails_t emails[], int *n);
/* dosyadaki herhangi bir satiri okuyup line dizisine kaydeder */
int read_line(FILE *input, char line[]);
/* emailin subject bolumunu okuyup line dizisine kaydeder */
int read_subject(FILE *input, char line[], int *line_number);
/* emailin body bolumunu okuyup line dizisine kaydeder */
int read_body(FILE *input, char line[], int *line_number);
/* structure deki verileri print eder */
void print_emails(emails_t emails[], int n);

int main(void) 
{
	token_t tokens[30]; 	/* token dosyasi icin structure */
	emails_t emails[30];	/* emails dosyasi icin structure */
	FILE *inp;				/* token.txt dosyasi icin pointer */
	FILE *inp2;				/* emails.txt dosyasi icin pointer */
	int n;					/* structure'lardaki dolu index sayisi */
		
	inp = fopen("token.txt", "r");
	
	scan_token(inp, tokens, &n);
	print_token(tokens, n);			
	/* token.txt dosyasini kapatir */		
	fclose(inp);
	
	inp2 = fopen("emails.txt", "r");
	
	printf("\n\n");
	scan_emails(inp2, emails, &n);
	print_emails(emails, n);
	/* emails.txt dosyasini kapatir */
	fclose(inp2);
	
	return (0);
}
/* token dosyasini tarayip verileri tokens structure'a kaydeder */
void scan_token(FILE *inp, token_t tokens[], int *list_size) 
{
	
	char ch;		 	/* gecici dosyadan okunan karakter */
	char line[50];	 	/* dosyada okunan satir */
	int status;	     	/* donguyu bitirebilmek icin dosyanin sonunu gosterir*/
	int i, a, j;        /* sayaclar */
	int found;		    /* '=' isaretinin oldugunu belirtir */
	int found2;			/* sayinin oldugunu belirtir */
	j = 0;	
	a = 0;
	found = 0;
	found2 = 0;
	
	status = fscanf(inp, "%c", &ch);
	/* dosyanin basindaki bos satirlari atlar */
	while(ch == '\n') 
	{
		status = fscanf(inp, "%c", &ch);
	}		
	/* okunan ilk karakteri diziye kaydeder */
	line[a] = ch;
	a++;
	/* dosyanin sonuna kadar okumaya devam et */
	for(i = 0; status != EOF; ) 
	{
	/* '=' isaretini gordugunde diziyi bitir */
		if(ch == '=') 
		{
			line[a] = '\0';
			/* token'in ismini structure'a kaydet */
			strncpy(tokens[i].name, line, a);
			/* esittir isaretini sil */
			tokens[i].name[a-2] = '\0';			
			a = 0;
			found = 1;
			i++;
		}	
		/* essittir bulunduysa, satir bitene kadar okumaya devam et*/
		while(ch != '\n' && found) 
		{
			status = fscanf(inp, "%c", &ch);
			/* herhangi bir sayi bulursan bunu structure'a kaydet */
			if(ch >= '0' && ch <= '9') 
			{
			/* char karakteri integer sayiya donustur */
				tokens[j].repetition = ch - 48;
				j++;
				found2 = 1;
			}
		}
		/* eger essittir bulunmadiysa hata mesaji ver */
		if(ch == '\n' && found == 0) 
		{
				printf("There is an error on the %d. line of token file.\n", 
					   i+1);
				a = 0;
		}	
		/* eger sayi bulunmadiysa hata mesaji ver */
		else if(ch == '\n' && found2 == 0) 
		{
			printf("There is an error on the %d. line of token file.\n", 
					   i+1);
			a = 0;			
		}		 
		/* eger hata yoksa degiskenleri sifirla */
		else if(ch == '\n') 
		{
				found = 0;	
				found2 = 0;
		}		
		/* sonraki satiri okumaya basla */
		status = fscanf(inp, "%c", &ch);
		if(ch != '\n') 
		{
			line[a] = ch;
			a++;	
		}	
	}
	/* tokens dizisinin dolduruldugu yere kadar olan indexi verir */
	*list_size = i;
}
/* structure daki verileri print eder */
void print_token(token_t tokens[], int n)
{
	int i;
	
	printf("-----------------------------------------------------\n");
	printf("|%2s| %-35s | %9s|\n", "#", "Token", "Frequency");
	printf("-----------------------------------------------------\n");
	for(i = 0; i < n; i++) {
		printf("|%2d| %-35s | %9d| \n", i+1, tokens[i].name, 
									   tokens[i].repetition);
	}
	printf("-----------------------------------------------------\n");
}
/* emails.txt dosyasini okuyup structure'a kaydeder */
void scan_emails(FILE *inp2, emails_t emails[], int *n)
{
	char line[1000]; 	 /* structure'a kopyalamak icin olusturulan dizi */
	int i = 0;			 /* structure'daki maximum index */
	char ch;			 /* dosyadan okunan gecici karakter */
	int line_number = 0; /* satir numarasi */
	int status;			/* donguyu bitirebilmek icin dosyanin sonunu gosterir*/	
	int error;			/* emails dosyasindaki hatayi isaretler */
	
	
	status = fscanf(inp2, "%c", &ch);
	/* bos satirlari atlayip, satir sayisini artirir */
	while(ch == '\n') 
	{
		status = fscanf(inp2, "%c", &ch);
		line_number++;
	}
	line[0] = ch;
	/* dosyanin sonuna kadar dongu surer */
	while(status != EOF) 
	{
		/* satiri okuyup, line dizisine kaydeder */
		read_line(inp2, line);
		line_number++;
		/* okunan satirda hata bulursa, bulundugu satiri print eder */
		if( strncmp("<email>", line, 7) ) {
			printf("There is an error on %d. line of emails file.\n",
				    line_number);
			/* okunan emailde hata oldugunu belirtir */	    
			error = 1;
		}
		/* bos satirlari atlar */
		status = fscanf(inp2, "%c", &ch);
		while(ch == '\n') 
		{
			status = fscanf(inp2, "%c", &ch);
			line_number++;
		}
		line[0] = ch;
		read_line(inp2, line);
		line_number++;		
/* eger hata yoksa emailin subject bolumunu okur ve structure'a kaydeder*/
		if( error == 0 ) 
		{
			error = read_subject(inp2, line, &line_number);
			strcpy(emails[i].email_subject, line);
		}
		/* bos satirlari atlar */
		status = fscanf(inp2, "%c", &ch);
		while(ch == '\n') 
		{
			status = fscanf(inp2, "%c", &ch);
			line_number++;
		}
		line[0] = ch;
		/* eger body de bir hata varsa bunu belirtir */
		if( read_body(inp2, line, &line_number) == 1) 
		{
			error = 1;
		}
		strcpy(emails[i].email_body, line);
		/* bos satirlari atlar */
		status = fscanf(inp2, "%c", &ch);
		while(ch == '\n') 
		{
			status = fscanf(inp2, "%c", &ch);
			line_number++;
		}
		line[0] = ch;
		read_line(inp2, line);
		line_number++;
		/* emailin son satirinda hata varsa, bulundugu satiri belirtir */
		if( strncmp("</email>", line, 7) && error == 0) 
		{
			printf("There is an error on %d. line of emails file.\n",
				    line_number);
			error = 1;
		}
/* eger emailde hata varsa structure dizisini ilerletmez ve structure'in 
bulundugu indexdeki subject'i ve body'i yok sayar */
		if(error == 0) 
		{
			i++;
		}
		else if(error == 1)
		{
			emails[i].email_body[0] = '\0';
			emails[i].email_subject[0] = '\0';
			error = 0;
		}
		/* bos satirlari atlar */
		status = fscanf(inp2, "%c", &ch);
		while(ch == '\n' && status != EOF) 
		{
			status = fscanf(inp2, "%c", &ch);
			line_number++;
		}
		line[0] = ch;
	}
	/* emails structure dizisinin, dolduruldugu yere kadar olan indexi */
	*n = i;
}
/* dosyadaki herhangi bir satiri okuyup line dizisine kaydeder */
int read_line(FILE *input, char line[]) 
{
	int i;	   /* line dizisinin indexi */
	char ch;
	int status;
	
	status = fscanf(input, "%c", &ch);
	i = 1;
	/* satir sonuna kadar karakterleri kopyalar*/
	while(ch != '\n' && status != EOF) 
	{
		line[i++] = ch;
		status = fscanf(input, "%c", &ch);
	}
	line[i] = '\0';
	
	return (status);
}
/* emaillerin subject bolumlerini line dizisine kaydeder */
int read_subject(FILE *input, char line[], int *line_number) 
{
	char subject[100]; /* gecici subject'n tutuldugu dizi*/ 
	int i = 0;		   /* dizi indexi */
	int error = 0;	   /* dosyadaki hatayi isaretler */
	/* subject'in print edilecek kismi kopylanir */
	for(i = 0; line[i+9] != '<'; i++) 
	{
		subject[i] = line[i+9];	
	}	
	subject[i] = '\0';
	/* line dizisinin </Subject> kismina kadar olan indexi hesaplanir */
	while(line[i] != '<')
		i++;
	
	/* hata bulunursa print edilip, error degiskeniyle belirtilir */
	if(strncmp("<Subject>", line, 9) != 0) 
	{
		printf("There is an error on %d. line of emails file.\n",
			   *line_number);
		error = 1;	   
	}		   
	else if(strncmp("</Subject>", &line[i], 10) != 0) 
	{
		printf("There is an error on %d. line of emails file.\n",
			   *line_number);
		error = 1;
	}
	
	/* subject dizisi line dizisine kopyalanarak diger fonksiyona gonderilir */
	strcpy(line, subject);
	/* hata varsa return edilir */
	return (error);
}
/* emailin body bolumunu okuyup line dizisine kaydeder */
int read_body(FILE *input, char line[], int *line_number) 
{
	char body[1000];			/* body bolumunun gecici kaydedildigi dizi */
	char ch;					/* gecici karakterler*/
	char error_control[8];	    /* body nin son kismini tutar*/
	int i;						/* dizi indexi */
	int status;		
	int error = 0;				/* olasi bir hatayi belirtir */
	
/* satirin ilk karakteri fonksiyon disinda okundugu icin body dizisine
kaydedilir */
	body[0] = line[0];
	read_line(input, body);
	*line_number += 1;
	/* <Body> atlanarak line dizisine body bolumu kaydedilir */
	for(i = 0; body[i + 6] != '\0'; i++) 
	{
		line[i] = body[i + 6];
	}
	/* hata bulunursa, hatanin bulundugu satir print edilir */
	if(strncmp("<Body>", &body[0], 6) != 0) 
	{
		printf("There is an error on %d. line of email file.\n",
			    *line_number);
		error = 1;	
	}
	/* body' nin ic kismi line dizisine kopyalanir */
	status = fscanf(input, "%c", &ch);
	while(ch != '<' && status != EOF) 
	{
		line[i++] = ch;
		status = fscanf(input, "%c", &ch);
		/* olasi bos satirlar icin satir sayisi hesaplanir */
		if(ch == '\n')
			*line_number += 1;
	}	
	/* line dizisi tamamlanir */
	line[i] = '\0';
	*line_number += 1;
	
	/* body'nin </Body> diziye kaydedilir */
	for(i = 0; ch != '\n' && status != EOF; i++) 
	{
		error_control[i] = ch;
		status = fscanf(input, "%c", &ch);
	}	
	error_control[i] = '\0';
	/* hata bulunursa print edilir */
	if(strncmp("</Body>", error_control, 7) != 0) 
	{
		printf("There is an error on %d. line of email file.\n", 
				*line_number);
		error = 1;;
	}	
	/* dizinin icinde hata varsa return edilir */
	return (error);		
}
/* emails.txt dosyasinin icerigini structure uzerinden print eder */
void print_emails(emails_t emails[], int n)
{
	int a;		/* dongu icin sayac*/
	int j;	    /* dongu icin sayac*/
	int k;		/* dongu icin sayac*/
	int end_of_body = 0;       /* body bolumunun bittigini belirtir */
	int end_of_subject = 0;	   /* subject bolumunun bittigini belirtir */
	int counter; /* sayac */
	/* cerceve */
	for(j = 0; j < 73; j++) 
	{
		printf("-");
	}
	printf("\n");
	/* emailin bolumlerini yazar */
	printf("|%2s| %-15s| %-50s|\n", "#", "  Subject",
	"                     Body"); 
	/* structure'in dolduruldugu indexe kadar devam eder */
	for(k = 0; k < n; k++) {
		/* yeni emaili okumaya baslarken degiskenler sifirlanir */
		end_of_body = 0;
		end_of_subject = 0;
		/* cerceve */
		for(j = 0; j < 73; j++) 
		{
			printf("-");
		}
		printf("\n");
		/* emailin numarasini print eder */
		printf("|%2d| ", k+1);
		/* body bolumu bitene kadar dongu surer */
		for(a = 0; end_of_body == 0; a++) 
		{
			
			counter = 0;
			/* subject icin bir satirda 15 karakter ayirilir */
			/* subjectin sonuna kadar print edilir*/
			for(j = a * 15; 
				emails[k].email_subject[j] != '\0' && counter < 15 
				&& end_of_subject == 0;
				j++) 
			{ 
				/* eger satir atlama varsa bosluk karakteriyle degistirilip, */
				/* oyle print edilir */
				if(emails[k].email_subject[j] == '\n')
					emails[k].email_subject[j] = ' ';
				printf("%c", emails[k].email_subject[j]); 
				counter++;
			}
			/* subject icin ayirilan bolum karakterle dolmadiysa, */
			/* kalan kisimda bosluk print edilir */
			for(j = counter; j < 15; j++)
				printf(" ");
		
			/* eger subjectin tamami print edildiyse, */
			/* degisken ile belirtilir */
			if( emails[k].email_subject[j] == '\0' ) 
				end_of_subject = 1;
			printf("| ");
		
		
			counter = 0;
			/* body bolumu icin bir satirda 50 karakter ayirilir */
			/* bolumun sonuna kadar print edilir*/
			for(j = a * 50;
				emails[k].email_body[j] != '\0' && counter < 50	
				&& end_of_body == 0; 
				j++)
			{
				/* eger satir atlama varsa bosluk karakteriyle degistirilip, */
				/* oyle print edilir */
				if(emails[k].email_body[j] == '\n')
					emails[k].email_body[j] = ' ';
			
				printf("%c", emails[k].email_body[j]); 
				counter++;
			}
			/* eger subjectin tamami print edildiyse, */
			/* degisken ile belirtilir */
			if( emails[k].email_body[j] == '\0' ) 
			{
				end_of_body = 1;
			}
			/* body bolumu icin ayirilan bolum karakterle dolmadiysa, */
			/* kalan kisimda bosluk print edilir */
			for(j = counter; j < 50; j++)
				printf(" ");
			
		
		
			printf("|\n");
			/* eger body bitmediyse, ayni email icin yeni satira baslanir */
			if(end_of_body == 0)
				printf("|  | ");
		}
	}	
	for(j = 0; j < 73; j++) 
	{
		printf("-");
	}
	printf("\n");
}
