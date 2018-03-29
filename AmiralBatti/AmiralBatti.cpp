// AmiralBatti v1.0 caner.arifoglu@gmail.com
// 

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <time.h>
#include <Windows.h>

using namespace std;

char oyuncu_tahta[10][10],pc_tahta[10][10],atis_oy_tahta[10][10],atis_pc_tahta[10][10];

struct Gemi
{
	int x[6],y[6];
}A_O,D1_O,D2_O,F1_O,F2_O,F3_O,H1_O,H2_O,H3_O,H4_O,A_P,D1_P,D2_P,F1_P,F2_P,F3_P,H1_P,H2_P,H3_P,H4_P;

void tahtaGoster(char tahta[10][10])
{
	for(int i=9;i>=0;i--){
		if(i==9)
			cout<<i+1<<" ";
		else
			cout<<i+1<<"  ";
		for(int j=0;j<10;j++){
			
			cout<<tahta[j][i]<<"   ";
		}
		cout<<endl<<endl;
	}
	cout<<"   ";
	for(int i=1;i<11;i++)
		cout<<i<<"   ";
	cout<<endl<<endl;

}

void cift_tahta_goster(char tahta_o[10][10],char tahta_p[10][10])
{
		cout<<"\tOyuncunun Tahtas�\t\t\t\tBilgisayar�n Tahtas�\n";

	for(int i=9;i>=0;i--){
		if(i==9)
			cout<<i+1<<" ";
		else
			cout<<i+1<<"  ";
		for(int j=0;j<10;j++){
			
			cout<<tahta_o[j][i]<<"   ";
		}
		cout<<"    ";
		
		if(i==9)
			cout<<i+1<<" ";
		else
			cout<<i+1<<"  ";
		for(int j=0;j<10;j++){
			cout<<tahta_p[j][i]<<"   ";
		}
		cout<<endl<<endl;
	}
	cout<<"   ";
	for(int i=1;i<11;i++)
		cout<<i<<"   ";
	cout<<"      ";
	for(int i=1;i<11;i++)
		cout<<i<<"   ";
	cout<<endl<<endl;
}

int koordinat_kontroly(char tahta[10][10],int x1,int y1,int gemiuzunlugu)

{
	int test=1;
	for(int j=0;j<gemiuzunlugu;j++){
		if(tahta[x1][y1+j]!='.')
			test=0;
	}
	return test;
}

int koordinat_kontrolx(char tahta[10][10],int x1,int y1,int gemiuzunlugu)

{
	int test=1;
	for(int j=0;j<gemiuzunlugu;j++){
		if(tahta[x1+j][y1]!='.')
			test=0;
	}
	return test;
}

void Oto_TahtaDoldur(char tahta[10][10])
{
	int x,y,z,test=1;
	int gemiuzunluk[10] ={6,4,4,3,3,3,2,2,2,2};
	char gemisembol[10] ={'A','D','D','F','F','F','H','H','H','H'};
	int *gemi_x[10] ={A_P.x,D1_P.x,D2_P.x,F1_P.x,F2_P.x,F3_P.x,H1_P.x,H2_P.x,H3_P.x,H4_P.x};
	int *gemi_y[10] ={A_P.y,D1_P.y,D2_P.y,F1_P.y,F2_P.y,F3_P.y,H1_P.y,H2_P.y,H3_P.y,H4_P.y};

	//Oyun Tahtas�n� S�f�rlamak i�in
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			tahta[i][j]='.';
	// Gemilerin Yerle�tirilmesi
	for(int i=0;i<10;i++){		//Gemiyi Yatay yada Dikey Yerle�imini rastgele belirler...
		z=rand()%2;
	if(z==0)					//Yatay Yerle�im
		{
			while(true){
			x=rand()%(11-gemiuzunluk[i]);
			y=rand()%10;
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlar�n Bo� oldu�unu kontrol eder
				if(tahta[x+j][y]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){   	//Gemiyi Yerle�tirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				x++;
			}
		}
		if(z==1)			//Dikey Yerle�im...
		{
			while(true){
			x=rand()%10;
			y=rand()%(11-gemiuzunluk[i]);
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlar�n Bo� oldu�unu kontrol eder
				if(tahta[x][y+j]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){		//Gemiyi Yerle�tirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				y++;
			}
		}


	}

}

void Oto_TahtaDoldur2(char tahta[10][10])
{
	int x,y,z,test=1;
	int gemiuzunluk[10] ={6,4,4,3,3,3,2,2,2,2};
	char gemisembol[10] ={'A','D','D','F','F','F','H','H','H','H'};
	int *gemi_x[10] ={A_O.x,D1_O.x,D2_O.x,F1_O.x,F2_O.x,F3_O.x,H1_O.x,H2_O.x,H3_O.x,H4_O.x};
	int *gemi_y[10] ={A_O.y,D1_O.y,D2_O.y,F1_O.y,F2_O.y,F3_O.y,H1_O.y,H2_O.y,H3_O.y,H4_O.y};

	//Oyun Tahtas�n� S�f�rlamak i�in
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			tahta[i][j]='.';
	// Gemilerin Yerle�tirilmesi
	for(int i=0;i<10;i++){		//Gemiyi Yatay yada Dikey Yerle�imini rastgele belirler...
		z=rand()%2;
	if(z==0)					//Yatay Yerle�im
		{
			while(true){
			x=rand()%(11-gemiuzunluk[i]);
			y=rand()%10;
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlar�n Bo� oldu�unu kontrol eder
				if(tahta[x+j][y]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){   	//Gemiyi Yerle�tirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				x++;
			}
		}
		if(z==1)			//Dikey Yerle�im...
		{
			while(true){
			x=rand()%10;
			y=rand()%(11-gemiuzunluk[i]);
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlar�n Bo� oldu�unu kontrol eder
				if(tahta[x][y+j]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){		//Gemiyi Yerle�tirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				y++;
			}
		}


	}

}

int koordinat_ayikla(char koordinatChar[],int *sayiDizisi){
	int j=0,ciftsayi,uzunluk;
	char gecici[4];
	uzunluk=strlen(koordinatChar);
	koordinatChar[uzunluk]='!';		//Taramay� Durdurma komutu(Koordinat giri�inin sonuna ekler)
	for(int i=0; i<uzunluk ; i++){
		
		bool kontrol=true;
		int k=0;
		do { 
			
			gecici[k]=koordinatChar[i];
			if(koordinatChar[i+1]=='!')
				break;
			if(koordinatChar[i+1]==',' || koordinatChar[i+1]=='-' ){
				kontrol=false;
			}
			else{
				i++;
				k++;
			}
		}while(kontrol);
		if(k==0){		//Tek basamakl�ysa koordinat� ptr arac�l���yla diziye atar..
			*(sayiDizisi+j)=gecici[0]-49;
			j++;
			i++; // virg�l atlatma
			}
		else if(k==1){		//�ift basamakl�ysa koordinat� ptr arac�l���yla diziye atar..
			ciftsayi=(gecici[0]-48)*10+(gecici[1]-48)*10;
			if(ciftsayi==10){
				*(sayiDizisi+j)=ciftsayi-1;
				j++;
				i++; // virg�l atlatma
			}
			else{	 //say�n�n 10'dan buyuk olmas� durumunda fonksiyonu durdurur..
				return 0;
				}
			}
			
		else		//3 veya daha fazla basamak giri�inde fonksiyonu durdurur..
			return 0;
		
			
	}
	if(j!=4)
		return 2;
	if(*sayiDizisi!=*(sayiDizisi+2) && *(sayiDizisi+1)!=*(sayiDizisi+3))
		return 2;
	koordinatChar[uzunluk]=NULL;
	return 1;
}

int karakter_engelle(int girisuzunlugu,char koordinat_giris[])
{
	int test=0;
	for(int b=0;b<girisuzunlugu;b++){
			if(koordinat_giris[b]>47 && koordinat_giris[b]<58 || koordinat_giris[b]==',' || koordinat_giris[b]=='-')
				test=1;
			else 
				test=0;
		}
	return test;
}

void Manuel_TahtaDoldur(char oyuncu_tahta[10][10])
{
	int *gemi_x[10] ={A_O.x,D1_O.x,D2_O.x,F1_O.x,F2_O.x,F3_O.x,H1_O.x,H2_O.x,H3_O.x,H4_O.x};
	int *gemi_y[10] ={A_O.y,D1_O.y,D2_O.y,F1_O.y,F2_O.y,F3_O.y,H1_O.y,H2_O.y,H3_O.y,H4_O.y};
	//Oyun Tahtas�n� S�f�rlamak i�in
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			oyuncu_tahta[i][j]='.';

	char koordinat_giris[15]={};
	int test,girisuzunlugu,koordinatlar[4];
	int *koordinatPtr=koordinatlar;

	//Gemileri yerle�tirme...

	//Amiral Gemisi
	while(true){
		test=1;
			system("cls");
			tahtaGoster(oyuncu_tahta);
			int gemiuzunlugu=6;
			cout<<"Gemileri Yerle�tiriniz..."<<endl;
			cout<<"�rnek : 1,1-1,"<<gemiuzunlugu<<" (�lk ve Son Noktalar�n� Giriniz)"<<endl;
			cout<<"\n-------------------------------------------------------\n";
			cout<<"Amiral Gemisini Yerle�tiriniz:";
			gets_s(koordinat_giris);
			if(koordinat_giris[0]=='\0')
				continue;
			girisuzunlugu=strlen(koordinat_giris);
		
			//Say�lar ',' ve '-' d���nda karakter giri�ini engeller...
			test=karakter_engelle(girisuzunlugu,koordinat_giris);
			if(test==0){
				system("cls");
				cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
				continue;
			}
			test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinat� ',' ve '-' ay�klay�p diziye par�alar..
																		//koordinatlar[] dizisindeki de�erler s�ras�yla --> x1,y1,x2,y2 �eklinde ay�klan�r ;)
			if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0  || test==2 ){    //Koordinatlar�n 1-10 aras�nda giri�ini sa�lar..
				system("CLS");
				cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
				continue;
			}												

			//Geminin Dikey yerle�me durumu
			if(koordinatlar[0]==koordinatlar[2]){
				if(koordinatlar[3]-koordinatlar[1]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
					test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);		//Girilen Koordinatlar�n bo� olup olmad���na bakar..
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
				}
				//Tahtaya gemiyi yerle�tirir.
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]='A';
					A_O.x[i]=koordinatlar[0];A_O.y[i]=koordinatlar[1]+i;
				}
				system("CLS");break;
			}

			//Geminin Yatay Yerle�me Durumu
			if(koordinatlar[1]==koordinatlar[3]){
				if(koordinatlar[2]-koordinatlar[0]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);			//Girilen Koordinatlar�n bo� olup olmad���na bakar..
				if(test==0){
					system("CLS");
					cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
					continue;
				}
				//Tahtaya Gemiyi Yerle�tirir..
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]+i][koordinatlar[1]]='A';
					A_O.x[i]=koordinatlar[0]+i;A_O.y[i]=koordinatlar[1];
				}
			}
					system("cls");break;
		
	}

	for(int dest=0;dest<2;dest++){
		//Destroyer Gemisi
		while(true){
			test=1;
			tahtaGoster(oyuncu_tahta);
			int gemiuzunlugu=4;
			cout<<"Gemileri Yerle�tiriniz..."<<endl;
			cout<<"�rnek : 1,1-1,"<<gemiuzunlugu<<" (�lk ve Son Noktalar�n� Giriniz)"<<endl;
			cout<<"\n-------------------------------------------------------\n";
			cout<<"Destroyer Gemisini Yerle�tiriniz:";gets_s(koordinat_giris);
			girisuzunlugu=strlen(koordinat_giris);
		
			//Say�lar ',' ve '-' d���nda karakter giri�ini engeller...
			test=karakter_engelle(girisuzunlugu,koordinat_giris);
			if(test==0){
				system("cls");
				cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
				continue;
			}
			test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinat� ',' ve '-' ay�klay�p diziye par�alar..
																		//koordinatlar[] dizisindeki de�erler s�ras�yla --> x1,y1,x2,y2 �eklinde ay�klan�r ;)
			if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0  || test==2){    //Koordinatlar�n 1-10 aras�nda giri�ini sa�lar..
				system("CLS");
				cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
				continue;
			}

			//Geminin Dikey yerle�me durumu
			if(koordinatlar[0]==koordinatlar[2]){
				if(koordinatlar[3]-koordinatlar[1]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
					test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);		//Girilen Koordinatlar�n bo� olup olmad���na bakar..
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
				}
				//Tahtaya gemiyi yerle�tirir.
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]='D';
					*(gemi_x[dest+1]+i)=koordinatlar[0];*(gemi_y[dest+1]+i)=koordinatlar[1]+i;
				}
				system("CLS");break;
			}

			//Geminin Yatay Yerle�me Durumu
			if(koordinatlar[1]==koordinatlar[3]){
				if(koordinatlar[2]-koordinatlar[0]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);			//Girilen Koordinatlar�n bo� olup olmad���na bakar..
				if(test==0){
					system("CLS");
					cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
					continue;
				}
				//Tahtaya Gemiyi Yerle�tirir..
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]+i][koordinatlar[1]]='D';
					*(gemi_x[dest+1]+i)=koordinatlar[0]+i;*(gemi_y[dest+1]+i)=koordinatlar[1];
				}
			}
					system("cls");break;
		
		}
	}


	for(int fir=0;fir<3;fir++){
		//Firkateyn Gemisi
		while(true){
			test=1;
			tahtaGoster(oyuncu_tahta);
			int gemiuzunlugu=3;
			cout<<"Gemileri Yerle�tiriniz..."<<endl;
			cout<<"�rnek : 1,1-1,"<<gemiuzunlugu<<" (�lk ve Son Noktalar�n� Giriniz)"<<endl;
			cout<<"\n-------------------------------------------------------\n";
			cout<<"Firkateyn Gemisini Yerle�tiriniz:";gets_s(koordinat_giris);
			girisuzunlugu=strlen(koordinat_giris);
		
			//Say�lar ',' ve '-' d���nda karakter giri�ini engeller...
			test=karakter_engelle(girisuzunlugu,koordinat_giris);
			if(test==0){
				system("cls");
				cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
				continue;
			}
			test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinat� ',' ve '-' ay�klay�p diziye par�alar..
																		//koordinatlar[] dizisindeki de�erler s�ras�yla --> x1,y1,x2,y2 �eklinde ay�klan�r ;)
			if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0  || test==2){    //Koordinatlar�n 1-10 aras�nda giri�ini sa�lar..
				system("CLS");
				cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
				continue;
			}
			//Geminin Dikey yerle�me durumu
			if(koordinatlar[0]==koordinatlar[2]){
				if(koordinatlar[3]-koordinatlar[1]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
					test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);		//Girilen Koordinatlar�n bo� olup olmad���na bakar..
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
				}
				//Tahtaya gemiyi yerle�tirir.
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]='F';
					*(gemi_x[fir+3]+i)=koordinatlar[0];*(gemi_y[fir+3]+i)=koordinatlar[1]+i;
				}
				system("CLS");break;
			}

			//Geminin Yatay Yerle�me Durumu
			if(koordinatlar[1]==koordinatlar[3]){
				if(koordinatlar[2]-koordinatlar[0]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);			//Girilen Koordinatlar�n bo� olup olmad���na bakar..
				if(test==0){
					system("CLS");
					cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
					continue;
				}
				//Tahtaya Gemiyi Yerle�tirir..
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]+i][koordinatlar[1]]='F';
					*(gemi_x[fir+3]+i)=koordinatlar[0]+i;*(gemi_y[fir+3]+i)=koordinatlar[1];
				}
			}
					system("cls");break;
		
		}
	}

	for(int hucum=0;hucum<4;hucum++){
		//H�c�m Bot Gemisi
		while(true){
			test=1;
			tahtaGoster(oyuncu_tahta);
			int gemiuzunlugu=2;
			cout<<"Gemileri Yerle�tiriniz..."<<endl;
			cout<<"�rnek : 1,1-1,"<<gemiuzunlugu<<" (�lk ve Son Noktalar�n� Giriniz)"<<endl;
			cout<<"\n-------------------------------------------------------\n";
			cout<<"H�cum Botlar� Yerle�tiriniz:";gets_s(koordinat_giris);
			girisuzunlugu=strlen(koordinat_giris);
		
			//Say�lar ',' ve '-' d���nda karakter giri�ini engeller...
			test=karakter_engelle(girisuzunlugu,koordinat_giris);
			if(test==0){
				system("cls");
				cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
				continue;
			}
			test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinat� ',' ve '-' ay�klay�p diziye par�alar..
																		//koordinatlar[] dizisindeki de�erler s�ras�yla --> x1,y1,x2,y2 �eklinde ay�klan�r ;)
			if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0 || test==2 ){    //Koordinatlar�n 1-10 aras�nda giri�ini sa�lar..
				system("CLS");
				cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
				continue;
			}
			//Geminin Dikey yerle�me durumu
			if(koordinatlar[0]==koordinatlar[2]){
				if(koordinatlar[3]-koordinatlar[1]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
					test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);		//Girilen Koordinatlar�n bo� olup olmad���na bakar..
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
				}
				//Tahtaya gemiyi yerle�tirir.
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]='H';
					*(gemi_x[hucum+6]+i)=koordinatlar[0];*(gemi_y[hucum+6]+i)=koordinatlar[1]+i;
				}
				system("CLS");break;
			}

			//Geminin Yatay Yerle�me Durumu
			if(koordinatlar[1]==koordinatlar[3]){
				if(koordinatlar[2]-koordinatlar[0]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);			//Girilen Koordinatlar�n bo� olup olmad���na bakar..
				if(test==0){
					system("CLS");
					cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
					continue;
				}
				//Tahtaya Gemiyi Yerle�tirir..
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]+i][koordinatlar[1]]='H';
					*(gemi_x[hucum+6]+i)=koordinatlar[0]+i;*(gemi_y[hucum+6]+i)=koordinatlar[1];
				}
			}
					system("cls");break;
		
		}
	}
}

int atis_hata_ayiklama(char atisgiris[])
{
	int uzunluk,sayac=0;
	uzunluk=strlen(atisgiris);
	for(int i=0;i<uzunluk;i++){
		if((atisgiris[i]<=47 || atisgiris[i]>=58) && atisgiris[i]!=',')  //Say� ve virg�l d���ndaki karakterleri engeller
			return 0;
		if(atisgiris[i]==',')  //Virg�l adetini Sayar
			sayac++;
		
	}
	if(sayac!=1) //1'den Fazla virg�lde hata verdirir..
		return 0;
	if(atisgiris[0]<'0' || atisgiris[0]>'9' || atisgiris[uzunluk-1]<'0' || atisgiris[uzunluk-1]>'9')    //�lk ve Son Karakterin Say� Olmas�n� sa�lar
		return 0;

	return 1;
}

void Game_Start()
{
	int amiral_sayac_o=0,amiral_sayac_pc=0,koor_tut[2];
	bool sag=false,sol=false,ust=false,alt=false,ctrlkont;
	for(int i=0;i<10;i++){			//At�� Tahtalar�n� S�f�rlar...
		for(int j=0;j<10;j++){
			atis_oy_tahta[i][j]='.';
			atis_pc_tahta[i][j]='.';
		}
	}
	while(true){
		
		char atis_giris[10]={NULL};
		int atis_xy[2],kontrol=1;
		int *atisPtr=atis_xy;
		if(amiral_sayac_pc==6){		//Bilgisayar�n amiral� bat�rmas� �art�...
			cout<<"\n-----  Amiral Gemisi Vuruldu Oyunu Bilgisayar Kazand�!!!  ----\n\n";
			break;
		}

		cout<<endl;
		cift_tahta_goster(atis_oy_tahta,atis_pc_tahta);
		cout<<"Rakip gemileri g�rmek i�in CTRL+F5 kombinasyonunu kullan�n�z \nAt��lar x,y koordinat giri�i girilerek yap�l�r.\n�rn:3,5\n----------------------------------------\nKoordinat Giriniz:";	
		while(1){
			 if ((GetAsyncKeyState(VK_CONTROL)) && (GetAsyncKeyState(VK_F5)))	//CTRL+F5 Bas�l�rsa Bilgisayar Tahtas�n� g�sterir..
			 {
				system("cls");
				cout<<"\tRakip Oyun Tahtas�\n";
				tahtaGoster(pc_tahta);
				system("pause");
				system("cls");
				ctrlkont=true;
				break;
				
			 }
			 else if(_kbhit())	//Ctrl+F5 d���nda bir tu�a bas�l�rsa at�� giri�i al�n�r..
			 {
				 gets_s(atis_giris);
				 ctrlkont=false;
				 break;
			 }
		
		}
		if(ctrlkont){		//Ctrl+F5 kombinasyonu yap�ld�ysa ba�a al�r ekranda tahta g�r�nt�s� sa�lar..
			continue;
		}

		kontrol=atis_hata_ayiklama(atis_giris);		//At�� Koordinatlar�n�n hatalar�n� kontrol eder..
		if(kontrol==0){
			system("CLS");
			cout<<"Hatal� Koordinat Giri�i Yeniden At�� Yap�n�z..\n";
			continue;
		}

		kontrol=koordinat_ayikla(atis_giris,atisPtr);	//At�� Koordinatlar�n� Ay�klay�p say�lar�n 1-10 aras� girilmesini sa�lar..
		if(atis_xy[0]<0 || atis_xy[1]<0 || kontrol==0 ){
			system("CLS");
			cout<<"1-10 Aras� Say� Giriniz..\n";
			continue;
		}
		if(atis_pc_tahta[atis_xy[0]][atis_xy[1]]=='X' || atis_pc_tahta[atis_xy[0]][atis_xy[1]]=='O'){	//Koordinata daha �nce at�� yap�lm��m� kontrol� yapar..
			system("cls");
			cout<<"Bu koordinatlara daha �nce at�� yap�ld�!!\n";
			continue;
		}
		system("cls");
		if(pc_tahta[atis_xy[0]][atis_xy[1]]!='.'){		//At�� yap�lan yerde gemi varm�?
			if(pc_tahta[atis_xy[0]][atis_xy[1]]=='A')	//Varsa Amiral mi? Amiralse sayac� art�r�p oyunu sonland�r�r..
				amiral_sayac_o++;
			atis_pc_tahta[atis_xy[0]][atis_xy[1]]='O';	//Di�er gemilerse at�� tahtas�n� i�aretler...
			cout<<"�sabetli At��..\n";
		}
		else{
			atis_pc_tahta[atis_xy[0]][atis_xy[1]]='X';	//At�� karavana ise i�aretleme yap�l�r..
			cout<<"Karavana..\n";
		}
		if(amiral_sayac_o==6){							//Amiral sayac� t�m kareleri vurdurdugunda �art� sa�lar ve oyunu durdurur..
			cout<<"\n-----  Amiral Gemisi Vuruldu Oyunu Kazand�n�z!!!  ----\n\n";
			break;
		}
		while(true){				//Bilgisayar�n At��� 
			atis_xy[0]=rand()%10;			//Rastgele Koordinat se�imi yapar..
			atis_xy[1]=rand()%10;
			if(atis_oy_tahta[atis_xy[0]][atis_xy[1]]!='X' && atis_oy_tahta[atis_xy[0]][atis_xy[1]]!='O')
				break;
		}


		if(sag){		//�sabet olmas� durumunda s�ras�yla sa� sol �st ve alt taraflara bakar..
			koor_tut[0]++;
			if(koor_tut[0]>9)
				sag=false;
			if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]!='.'){
				if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]=='A')
						amiral_sayac_pc++;
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='O';
				alt=false;ust=false;
			}
			else{
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='X';
				sag=false;
			}
			continue;
		}


		if(sol){
			if(koor_tut[0]<0)
				sol=false;
			while(true){
				if(atis_oy_tahta[koor_tut[0]][koor_tut[1]]=='X' || atis_oy_tahta[koor_tut[0]][koor_tut[1]]=='O'){
					koor_tut[0]--;
					continue;
				}
				break;
			}
			if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]!='.'){
				if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]=='A')
						amiral_sayac_pc++;
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='O';
				koor_tut[0]--;
				alt=false;ust=false;
			}
			else{
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='X';
				sol=false;
				koor_tut[0]++;
			}
			continue;
		}


		if(ust){
			if(koor_tut[1]>9)
				ust=false;
			koor_tut[1]++;
			if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]!='.'){
				if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]=='A')
						amiral_sayac_pc++;
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='O';
			}
			else{
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='X';
				ust=false;
			}
			continue;
		}


		if(alt){
			if(koor_tut[1]<0)
				alt=false;
			while(true){
				if(atis_oy_tahta[koor_tut[0]][koor_tut[1]]=='X' || atis_oy_tahta[koor_tut[0]][koor_tut[1]]=='O'){
					koor_tut[1]--;
					continue;
				}
				break;
			}
			if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]!='.'){
				if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]=='A')
						amiral_sayac_pc++;
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='O';
				koor_tut[1]--;
			}
			else{
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='X';
				alt=false;
			}
			continue;
		}

		if(oyuncu_tahta[atis_xy[0]][atis_xy[1]]!='.'){
			if(oyuncu_tahta[atis_xy[0]][atis_xy[1]]=='A')
					amiral_sayac_pc++;
			atis_oy_tahta[atis_xy[0]][atis_xy[1]]='O';
			sag=true;sol=true;ust=true;alt=true;
			koor_tut[0]=atis_xy[0];koor_tut[1]=atis_xy[1];
		}
		else
			atis_oy_tahta[atis_xy[0]][atis_xy[1]]='X';

		

	}
}

int Puanlama()
{

	int sayac=0,p1=0,p2=0;
	int gemiuzunluk[9] ={4,4,3,3,3,2,2,2,2};
	int *gemi_x_pc[9] ={D1_P.x,D2_P.x,F1_P.x,F2_P.x,F3_P.x,H1_P.x,H2_P.x,H3_P.x,H4_P.x};
	int *gemi_y_pc[9] ={D1_P.y,D2_P.y,F1_P.y,F2_P.y,F3_P.y,H1_P.y,H2_P.y,H3_P.y,H4_P.y};
	int *gemi_x_oy[9] ={D1_O.x,D2_O.x,F1_O.x,F2_O.x,F3_O.x,H1_O.x,H2_O.x,H3_O.x,H4_O.x};
	int *gemi_y_oy[9] ={D1_O.y,D2_O.y,F1_O.y,F2_O.y,F3_O.y,H1_O.y,H2_O.y,H3_O.y,H4_O.y};
	
	for(int i=0;i<9;i++){
		sayac=0;
		for(int j=0;j<gemiuzunluk[i];j++){
			if(atis_pc_tahta[*(gemi_x_pc[i]+j)][*(gemi_y_pc[i]+j)]=='O')
				sayac++;
		}
		if(sayac==gemiuzunluk[i])
			p1 = p1 + sayac;
	}

	for(int i=0;i<9;i++){
		sayac=0;
		for(int j=0;j<gemiuzunluk[i];j++){
			if(atis_oy_tahta[*(gemi_x_oy[i]+j)][*(gemi_y_oy[i]+j)]=='O')
				sayac++;
		}
		if(sayac==gemiuzunluk[i])
			p2 = p2 + sayac;
	}
	cout<<"----------------------------------------------\n\n";
	cout<<"Oyuncu Puan�\t :"<<p1<<endl;
	cout<<"Rakibin Puan�\t :"<<p2<<endl<<endl;

	return p1;

}

void menu()
{
	char secim=NULL;
	while(secim!='1' && secim !='2'){
		cout<<"Amiral Batt� v1.0\n"<<endl<<endl;
		cout<<"--------Men�-------\n"<<endl;
		cout<<"1-)Gemileri Manuel Yerle�tir"<<endl;
		cout<<"2-)Gemileri Otomatik Yerle�tir"<<endl;
		secim=_getch();
		system("cls");
		if(secim!='1' && secim!='2')
			cout<<"Men� giri�ini hatal� yapt�n�z. L�tfen se�enek numaras�n� tekrar giriniz"<<endl;
		_flushall();
	}
	if(secim=='1'){
		Manuel_TahtaDoldur(oyuncu_tahta);
		cout<<"Gemiler Ba�ar�yla Yerle�tirildi. Oyuna Ba�layabiliriz Art�k...\n";
	}
	if(secim=='2'){
		Oto_TahtaDoldur2(oyuncu_tahta);
		cout<<"Gemiler Bilgisayar Taraf�ndan Rastgele Yerle�tirildi.. Oyun Ba�las�n...\n";
	}

}

int main()
{
	
	srand(time(NULL));
	setlocale(0,"tr");
	system("mode con cols=100 lines=100 ");		//Konsol boyutunu sabitlemek i�in...
	system("color 1F");
	char tekrar_secim,secim;
	int puan;
	while(true){
		menu();
		_flushall();
		Oto_TahtaDoldur(pc_tahta);
		Game_Start();
		puan=Puanlama();
		cout<<"��k�� i�in 'h' tu�una bas�n�z..\nTekrar oynamak i�in bir tu�a bas�n�z..";
		tekrar_secim=_getch();
		if(tekrar_secim=='h')
			break;
		system("cls");
		_flushall();
	}
	return 0;
}
