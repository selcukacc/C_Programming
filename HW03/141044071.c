/* Homework 3 */
/* Name: Islam Goktan Selcuk */
/* Student No: 141044071 */

#include <stdio.h>
#include <math.h>

#define PI 3.14
#define E 2.71

/*---------------------------------------------*/
/*------Part 1'in fonksiyon prototipleri-------*/
/*---------------------------------------------*/
int part1(void);
/*dereceyi radyana donusturur*/
double degreetoRadian(double angle);
/*parametreler ile sinusu heaplar*/
double sinusCalculator(double radian, int n);
/*herhangi bir sayinin kuvvetini hesaplar*/
double power(double num, int p);
/*faktoriyel hesaplar*/
int factorial(int n);

/*---------------------------------------------*/
/*------Part 2'nin fonksiyon prototipleri------*/
/*---------------------------------------------*/
/*Fonksiyonu olusturmak icin kullaniciyi yonlendirir.*/
int part2(void);
/*Pointer'sız deger dondurerek hesaplama yapan fonksiyonlar*/
double usluSayi(int x, int eleman, int secim);
double trigonometrik(int x, int secim);
double tersTrigonometrik(int x, int secim);
double eSayisi(int x, int kuvvet);
double logaritma(int x, int taban, int secim);
/*Pointer kullanarak hesaplama yapan fonksiyonlar*/
void usluSayiPointer(int *x, int *eleman, double *sonuc, int *secim);
void trigonometrikPointer(int *x, double *sonuc, int *secim);
void tersTrigonometrikPointer(int *x, double *sonuc, int *secim);
void eSayisiPointer(int *x, double *sonuc, int *kuvvet);
void logaritmaPointer(int *x, int *taban, double *sonuc, int *secim);

int main(void) {

	part1();
	printf("\n\n");
	part2();
	
	return 0;
}
/*---------------------------------------------*/
/*-----------Part 1'in fonksiyonları-----------*/
/*---------------------------------------------*/
int part1(void)
{
	double x;/*derece cinsinden alinan aci*/
	double radian;
	int n;	/*terim sayisi*/

	printf("Enter angle->> ");
	scanf("%lf", &x);
	printf("Number of terms->> ");
	scanf("%d", &n);
	
	if(x < 0 || n < 0) {
		printf("Invalid input.\n");
		return (-1);
	}	
	radian = degreetoRadian(x);
	printf("%.4f\n", sinusCalculator(radian, n));
	
	return 0;
}

double degreetoRadian(double angle)
{
	int n;
	
	if(angle > 360) {
		n = angle / 360;
		angle -= n * 360;
	}
	if(angle == 180 || angle == 360)
		return 0;
	return ( (angle * PI) / 180 );
}

double sinusCalculator(double radian, int n)
{
	int i;
	double sum;
	double value;
	int sign = -1;
	
	sum = radian;
	for(i = 3; i < n*2 + 3; i += 2) {
		value = power(radian, i) / factorial(i);
		sum += sign * value;
		sign *= -1;
	}
	
	return (sum);
}

double power(double num, int p)
{
	int i;
	double sum;
	
	if(p == 0)
		return 1;
		
	sum = 1;
	for(i = 0; i < p; i++) 
		sum *= num;
	
	return (sum);	
}

int factorial(int n)
{
	int i;
	int result;
	
	if(n == 0)
		return 1;
	result = 1;
	for(i = 2; i <= n; i++) 
		result *= i;
	
	return (result);
}
/*---------------------------------------------*/
/*----------Part 2'nin fonksiyonlari-----------*/
/*---------------------------------------------*/
int part2(void)
{
	int n; 	   /*sayac*/
	int i;	  
	int giris; /*islem turunu belirleyen degisken*/ 
	double sonuc; /*pointer kullanan fonksiyonlarin sonucu*/
	double sonuc2;/*pointer kullanmayan fonksiyonlarin sonucu*/
	double toplam = 0;/*pointer kullanilan tum islemlerin toplami*/
	double toplam2 = 0;/*pointer kullanilmayan tum islemlerin toplami*/
	int katsayi; /*secilen islemin kaysayisi*/
	int x;  /*fonksiyondaki x bilinmeyeni*/
	/*fonksiyonlarin parametreleri*/
	int kuvvet; 
	int taban;
	int secim;
	
	printf("*************************************************\n");
	printf("x degiskeni ne olsun ->> ");
	scanf("%d", &x);
	printf("*************************************************\n");
	printf("* Fonksiyonunuz kaç parcadan olusuyor?          *\n");
	printf("* Ornek: (23.e^x + 3x^2) fonksiyonu 2 parcadir. *\n");
	printf("->> ");
	scanf("%d", &n);
	printf("*************************************************\n");
	/*n parca sayisi(islem sayisi) kadar donguyu surdurur*/
	for(i = 0; i < n; i++) {
		printf("%d. parcada kullanılacak islemi secin.\n", i+1);
		printf("* 1-)Uslu sayi(x^2 veya 2^x gibi)\n");
		printf("* 2-)Trigonometrik Fonksiyonlar(cos(x), sin(x), tan(x))\n");
		printf("* 3-)Ters Trigonometrik Fonksiyonlar\n");
		printf("* 4-)e sayisi ve ussu\n");
		printf("* 5-)Logaritma veya ln fonksiyonu\n");
		printf("* 1'den 5'e kadar bir sayi girin->> ");
		scanf("%d", &giris);
		printf("*************************************************\n");
		printf("Gireceginiz ifadenin katsayisini girin ->> ");
		scanf("%d", &katsayi);
		sonuc = katsayi;
		sonuc2 = katsayi;
		
		if(giris == 1) {
			printf("1-)x^a gibi bir ifade icin 1'i gir.\n");
			printf("2-)a^x gibi bir ifade icin 2'yi gir.\n");
			printf("->> ");
			scanf("%d", &secim);
			if(secim == 1) {
				printf("x'in kuvvetini girin a: ");
				scanf("%d", &kuvvet);
				/*girilen ifadenin turevli ve turevsiz halinin yazimi*/
				printf("y = %d.x^%d\n", katsayi, kuvvet);
				printf("dy/dx = %d.x^%d\n", katsayi * kuvvet, kuvvet-1);	
				/*hesaplama fonksiyonlari*/
				usluSayiPointer(&x, &kuvvet, &sonuc, &secim);
				sonuc2 *= usluSayi(x, kuvvet, secim); 
			}
			else if(secim == 2) {
				printf("a^x ifadesinin tabanını girin a: ");
				scanf("%d", &taban);
				/*girilen ifadenin turevli ve turevsiz halinin yazimi*/
				printf("y = %d.%d^x\n", katsayi, taban);
				printf("dy/dx = %d.ln(%d).%d^x", katsayi, taban, taban);
				/*hesaplama fonksiyonlari*/
				usluSayiPointer(&x, &taban, &sonuc, &secim);
				sonuc2 *= usluSayi(x, taban, secim);
			}
			else 
				printf("Gecersiz giris! Bu islem yok sayilacak.\n");
		}
			
		else if(giris == 2) {
			printf("Hangi trigonometrik fonksiyonu kullanmak istiyorsun?\n");
			printf("1-)cos(x)\n");
			printf("2-)sin(x)\n");
			printf("3-)tan(x)\n");
			printf("->> ");
			scanf("%d", &secim);
			if(secim == 1) {
			/*girilen ifadenin turevli ve turevsiz halinin yazimi*/
				printf("y = %d.cos(x)\n", katsayi);
				printf("dy/dx = -%d.sin(x)\n", katsayi);
			}
			else if(secim == 2) {
				printf("y = %d.sin(x)\n", katsayi);
				printf("dy/dx = %d.cos(x)\n", katsayi);	
			}
			else if(secim == 3) {
				printf("y = %d.tan(x)\n", katsayi);
				printf("dy/dx = %d.sec^2(x)\n", katsayi);
			}	
			/*hesaplama fonksiyonlari*/
			trigonometrikPointer(&x, &sonuc, &secim);
			sonuc2 *= trigonometrik(x, secim);
		}
		
		else if(giris == 3) {
			printf("Hangi trigonometrik fonksiyonu kullanmak istiyorsun?\n");
			printf("1-)cos^-1(x)\n");
			printf("2-)sin^-1(x)\n");
			printf("3-)tan^-1(x)\n");
			printf("->> ");
			scanf("%d", &secim);
			if(secim == 1) {
			/*girilen ifadenin turevli ve turevsiz halinin yazimi*/
				printf("y = %d.cos^-1(x)\n", katsayi);
				printf("dy/dx = %d.-1/(1-x^2)^(1/2)\n", katsayi);
			}
			else if(secim == 2) {
				printf("y = %d.sin^-1(x)\n", katsayi);
				printf("dy/dx = %d.1/(1-x^2)^(1/2)\n", katsayi);
			}
			else if(secim == 3) {
				printf("y = %d.tan^-1(x)\n", katsayi);
				printf("dy/dx = %d.1/(1+x^2)\n", katsayi);
			}
			/*hesaplama fonksiyonlari*/
			tersTrigonometrikPointer(&x, &sonuc, &secim);
			sonuc2 *= tersTrigonometrik(x, secim);
		}
		else if(giris == 4) {
			printf("e^ax icin a ne olsun ->> ");
			scanf("%d", &kuvvet);
			/*girilen ifadenin turevli ve turevsiz halinin yazimi*/
			printf("y = %d.e^(%dx)\n", katsayi, kuvvet);
			printf("dy/dx = %d.e^(%dx)\n", katsayi * kuvvet, kuvvet);
			/*hesaplama fonksiyonlari*/
			eSayisiPointer(&x, &sonuc, &kuvvet);
			sonuc2 *= eSayisi(x, kuvvet);
		}
		else if(giris == 5) {
			printf("Logaritmanın tabanı ne olsun?\n");
			printf("1-)e sayisi olsun.(ln(x))\n");
			printf("2-)Farklı bir sayi olsun.\n");
			printf("->> ");
			scanf("%d", &secim);
			if(secim == 1) {
			/*girilen ifadenin turevli ve turevsiz halinin yazimi*/
				printf("y = %d.ln(x)\n", katsayi);
				printf("dy/dx = %d.1/x\n", katsayi);
			}
			else if(secim == 2) {
				printf("Sayi ->> ");
				scanf("%d", &taban);
				/*girilen ifadenin turevli ve turevsiz halinin yazimi*/
				printf("y = %d.log%d(x)\n", katsayi, taban);
				printf("dy/dx = %d.1/(x.ln(%d))\n", katsayi, taban);
			}	
			/*hesaplama fonksiyonlari*/
			logaritmaPointer(&x, &taban, &sonuc, &secim);
			sonuc2 *= logaritma(x, taban, secim);
		}
	
	printf("\nGecerli islemin sonucu(call by reference): %.2f\n", sonuc);
	printf("Gecerli islemin sonucu(call by value): %.2f\n", sonuc2);
	/*her secilen islemin hesap sonucu toplama eklenir*/
	toplam += sonuc;
	toplam2 += sonuc2;
	}
	
	printf("\nx = %d icin tum islemlerin sonucu(call by reference): %.2f\n", x,
	toplam);
	printf("x = %d icin tum islemlerin sonucu(call by value): %.2f\n", x,
	toplam2);

	return 0;
}
/*-----Pointer'sız deger dondurerek hesaplama yapan fonksiyonlar-----*/
/*-------------------------------------------------------------------*/
double usluSayi(int x, int eleman, int secim)
{
	double sonuc = 1;
/*kullanicinin secimine gore islem secilir*/
	if(secim == 1) {
		sonuc = eleman * pow(x, eleman - 1);
			
	}
	else if(secim == 2 && eleman > 0) {
		sonuc = pow(eleman, x) * log(eleman);
	}
/*eger hatali bir islem istenirse sonucu sıfıra esitleyip hata mesaji verir*/
	else {
		printf("Hata. Gecersiz islem.\n");			
		sonuc = 0;
	}
	
	return (sonuc);
}

double trigonometrik(int x, int secim)
{
	double sonuc;
	
	if(secim == 1)
		sonuc = -sin(x);
	else if(secim == 2)
		sonuc = cos(x);
	else if(secim == 3 && cos(x) != 0)
		sonuc = pow(1 / cos(x), 2);
	else {
		printf("Hata. Gecersiz islem.\n");			
		sonuc = 0;
	}
	
	return (sonuc);
}

double tersTrigonometrik(int x, int secim)
{
	double sonuc;
	
	if(secim == 1 && (1 - pow(x, 2) > 0))
		sonuc = -1 / sqrt(1 - x * x);
	else if(secim == 2 && (1 - pow(x, 2) > 0))
		sonuc = 1 / ( sqrt(1 - x * x) );	
	else if(secim == 3)
		sonuc = 1 / (1 + pow(x, 2));
	else {
		sonuc = 0;
		printf("Hata. Gecersiz islem.\n");
	}	
	
	return (sonuc);
}

double eSayisi(int x, int kuvvet)
{
	double sonuc;
	
	sonuc = kuvvet * pow(E, kuvvet * x);
	
	return (sonuc);
}

double logaritma(int x, int taban, int secim)
{	
	double sonuc;
	
	if(secim == 1 && x != 0) {
		sonuc = 1 / x;
	}
	else if(secim == 2 && x * log(taban) != 0 && taban > 0)
		sonuc = 1 / (x * log(taban));
	else {
		sonuc = 0;
		printf("Hata. Gecersiz islem.\n");
	}
	
	return (sonuc);
}
/*----------Pointer kullanarak hesaplama yapan fonksiyonlar----------*/
/*-------------------------------------------------------------------*/
void usluSayiPointer(int *x, int *eleman, double *sonuc, int *secim)
{

/*kullanicinin secimine gore islem secilir*/
	if(*secim == 1) {
		*sonuc *= *eleman * pow(*x, *eleman - 1);
			
	}
	else if(*secim == 2 && *eleman > 0) {
		*sonuc *= pow(*eleman, *x) * log(*eleman);
	}
/*eger hatali bir islem istenirse sonucu sıfıra esitleyip hata mesaji verir*/
	else {
		printf("Hata. Gecersiz islem.\n");		
		*sonuc *= 0;
	}
}

void trigonometrikPointer(int *x, double *sonuc, int *secim)
{

	if(*secim == 1)
		*sonuc *= -sin(*x);
	else if(*secim == 2)
		*sonuc *= cos(*x);
	else if(*secim == 3 && cos(*x) != 0)
		*sonuc *= pow(1 / cos(*x), 2);
	else {
		printf("Hata. Gecersiz islem.\n");	
		*sonuc *= 0;
	}
}


void tersTrigonometrikPointer(int *x, double *sonuc, int *secim)
{

	if(*secim == 1 && (1 - pow(*x, 2) > 0))
		*sonuc *= -1 / sqrt(1 - *x * *x);
	else if(*secim == 2 && (1 - pow(*x, 2) > 0))
		*sonuc *= 1 / ( sqrt(1 - *x * *x) );	
	else if(*secim == 3)
		*sonuc *= 1 / (1 + pow(*x, 2));
	else {
		*sonuc *= 0;
		printf("Hata. Gecersiz islem.\n");	
	}	
}


void eSayisiPointer(int *x, double *sonuc, int *kuvvet)
{
	*sonuc *= *kuvvet * pow(E, *kuvvet * *x);
}

void logaritmaPointer(int *x, int *taban, double *sonuc, int *secim)
{	
	if(*secim == 1 && *x != 0) {
		*sonuc *= 1 / *x;
	}
	else if(*secim == 2 && *x * log(*taban) != 0 && *taban > 0)
		*sonuc *= 1 / (*x * log(*taban));
	else {
		*sonuc *= 0;
		printf("Hata. Gecersiz islem.\n");
	}
}

