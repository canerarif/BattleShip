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
		cout<<"\tOyuncunun Tahtasý\t\t\t\tBilgisayarýn Tahtasý\n";

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

	//Oyun Tahtasýný Sýfýrlamak için
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			tahta[i][j]='.';
	// Gemilerin Yerleþtirilmesi
	for(int i=0;i<10;i++){		//Gemiyi Yatay yada Dikey Yerleþimini rastgele belirler...
		z=rand()%2;
	if(z==0)					//Yatay Yerleþim
		{
			while(true){
			x=rand()%(11-gemiuzunluk[i]);
			y=rand()%10;
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlarýn Boþ olduðunu kontrol eder
				if(tahta[x+j][y]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){   	//Gemiyi Yerleþtirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				x++;
			}
		}
		if(z==1)			//Dikey Yerleþim...
		{
			while(true){
			x=rand()%10;
			y=rand()%(11-gemiuzunluk[i]);
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlarýn Boþ olduðunu kontrol eder
				if(tahta[x][y+j]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){		//Gemiyi Yerleþtirir..
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

	//Oyun Tahtasýný Sýfýrlamak için
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			tahta[i][j]='.';
	// Gemilerin Yerleþtirilmesi
	for(int i=0;i<10;i++){		//Gemiyi Yatay yada Dikey Yerleþimini rastgele belirler...
		z=rand()%2;
	if(z==0)					//Yatay Yerleþim
		{
			while(true){
			x=rand()%(11-gemiuzunluk[i]);
			y=rand()%10;
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlarýn Boþ olduðunu kontrol eder
				if(tahta[x+j][y]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){   	//Gemiyi Yerleþtirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				x++;
			}
		}
		if(z==1)			//Dikey Yerleþim...
		{
			while(true){
			x=rand()%10;
			y=rand()%(11-gemiuzunluk[i]);
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlarýn Boþ olduðunu kontrol eder
				if(tahta[x][y+j]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){		//Gemiyi Yerleþtirir..
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
	koordinatChar[uzunluk]='!';		//Taramayý Durdurma komutu(Koordinat giriþinin sonuna ekler)
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
		if(k==0){		//Tek basamaklýysa koordinatý ptr aracýlýðýyla diziye atar..
			*(sayiDizisi+j)=gecici[0]-49;
			j++;
			i++; // virgül atlatma
			}
		else if(k==1){		//Çift basamaklýysa koordinatý ptr aracýlýðýyla diziye atar..
			ciftsayi=(gecici[0]-48)*10+(gecici[1]-48)*10;
			if(ciftsayi==10){
				*(sayiDizisi+j)=ciftsayi-1;
				j++;
				i++; // virgül atlatma
			}
			else{	 //sayýnýn 10'dan buyuk olmasý durumunda fonksiyonu durdurur..
				return 0;
				}
			}
			
		else		//3 veya daha fazla basamak giriþinde fonksiyonu durdurur..
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
	//Oyun Tahtasýný Sýfýrlamak için
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			oyuncu_tahta[i][j]='.';

	char koordinat_giris[15]={};
	int test,girisuzunlugu,koordinatlar[4];
	int *koordinatPtr=koordinatlar;

	//Gemileri yerleþtirme...

	//Amiral Gemisi
	while(true){
		test=1;
			system("cls");
			tahtaGoster(oyuncu_tahta);
			int gemiuzunlugu=6;
			cout<<"Gemileri Yerleþtiriniz..."<<endl;
			cout<<"Örnek : 1,1-1,"<<gemiuzunlugu<<" (Ýlk ve Son Noktalarýný Giriniz)"<<endl;
			cout<<"\n-------------------------------------------------------\n";
			cout<<"Amiral Gemisini Yerleþtiriniz:";
			gets_s(koordinat_giris);
			if(koordinat_giris[0]=='\0')
				continue;
			girisuzunlugu=strlen(koordinat_giris);
		
			//Sayýlar ',' ve '-' dýþýnda karakter giriþini engeller...
			test=karakter_engelle(girisuzunlugu,koordinat_giris);
			if(test==0){
				system("cls");
				cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
				continue;
			}
			test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinatý ',' ve '-' ayýklayýp diziye parçalar..
																		//koordinatlar[] dizisindeki deðerler sýrasýyla --> x1,y1,x2,y2 þeklinde ayýklanýr ;)
			if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0  || test==2 ){    //Koordinatlarýn 1-10 arasýnda giriþini saðlar..
				system("CLS");
				cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
				continue;
			}												

			//Geminin Dikey yerleþme durumu
			if(koordinatlar[0]==koordinatlar[2]){
				if(koordinatlar[3]-koordinatlar[1]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
					test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);		//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
				}
				//Tahtaya gemiyi yerleþtirir.
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]='A';
					A_O.x[i]=koordinatlar[0];A_O.y[i]=koordinatlar[1]+i;
				}
				system("CLS");break;
			}

			//Geminin Yatay Yerleþme Durumu
			if(koordinatlar[1]==koordinatlar[3]){
				if(koordinatlar[2]-koordinatlar[0]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);			//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
				if(test==0){
					system("CLS");
					cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
					continue;
				}
				//Tahtaya Gemiyi Yerleþtirir..
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
			cout<<"Gemileri Yerleþtiriniz..."<<endl;
			cout<<"Örnek : 1,1-1,"<<gemiuzunlugu<<" (Ýlk ve Son Noktalarýný Giriniz)"<<endl;
			cout<<"\n-------------------------------------------------------\n";
			cout<<"Destroyer Gemisini Yerleþtiriniz:";gets_s(koordinat_giris);
			girisuzunlugu=strlen(koordinat_giris);
		
			//Sayýlar ',' ve '-' dýþýnda karakter giriþini engeller...
			test=karakter_engelle(girisuzunlugu,koordinat_giris);
			if(test==0){
				system("cls");
				cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
				continue;
			}
			test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinatý ',' ve '-' ayýklayýp diziye parçalar..
																		//koordinatlar[] dizisindeki deðerler sýrasýyla --> x1,y1,x2,y2 þeklinde ayýklanýr ;)
			if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0  || test==2){    //Koordinatlarýn 1-10 arasýnda giriþini saðlar..
				system("CLS");
				cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
				continue;
			}

			//Geminin Dikey yerleþme durumu
			if(koordinatlar[0]==koordinatlar[2]){
				if(koordinatlar[3]-koordinatlar[1]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
					test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);		//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
				}
				//Tahtaya gemiyi yerleþtirir.
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]='D';
					*(gemi_x[dest+1]+i)=koordinatlar[0];*(gemi_y[dest+1]+i)=koordinatlar[1]+i;
				}
				system("CLS");break;
			}

			//Geminin Yatay Yerleþme Durumu
			if(koordinatlar[1]==koordinatlar[3]){
				if(koordinatlar[2]-koordinatlar[0]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);			//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
				if(test==0){
					system("CLS");
					cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
					continue;
				}
				//Tahtaya Gemiyi Yerleþtirir..
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
			cout<<"Gemileri Yerleþtiriniz..."<<endl;
			cout<<"Örnek : 1,1-1,"<<gemiuzunlugu<<" (Ýlk ve Son Noktalarýný Giriniz)"<<endl;
			cout<<"\n-------------------------------------------------------\n";
			cout<<"Firkateyn Gemisini Yerleþtiriniz:";gets_s(koordinat_giris);
			girisuzunlugu=strlen(koordinat_giris);
		
			//Sayýlar ',' ve '-' dýþýnda karakter giriþini engeller...
			test=karakter_engelle(girisuzunlugu,koordinat_giris);
			if(test==0){
				system("cls");
				cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
				continue;
			}
			test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinatý ',' ve '-' ayýklayýp diziye parçalar..
																		//koordinatlar[] dizisindeki deðerler sýrasýyla --> x1,y1,x2,y2 þeklinde ayýklanýr ;)
			if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0  || test==2){    //Koordinatlarýn 1-10 arasýnda giriþini saðlar..
				system("CLS");
				cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
				continue;
			}
			//Geminin Dikey yerleþme durumu
			if(koordinatlar[0]==koordinatlar[2]){
				if(koordinatlar[3]-koordinatlar[1]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
					test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);		//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
				}
				//Tahtaya gemiyi yerleþtirir.
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]='F';
					*(gemi_x[fir+3]+i)=koordinatlar[0];*(gemi_y[fir+3]+i)=koordinatlar[1]+i;
				}
				system("CLS");break;
			}

			//Geminin Yatay Yerleþme Durumu
			if(koordinatlar[1]==koordinatlar[3]){
				if(koordinatlar[2]-koordinatlar[0]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);			//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
				if(test==0){
					system("CLS");
					cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
					continue;
				}
				//Tahtaya Gemiyi Yerleþtirir..
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]+i][koordinatlar[1]]='F';
					*(gemi_x[fir+3]+i)=koordinatlar[0]+i;*(gemi_y[fir+3]+i)=koordinatlar[1];
				}
			}
					system("cls");break;
		
		}
	}

	for(int hucum=0;hucum<4;hucum++){
		//Hücüm Bot Gemisi
		while(true){
			test=1;
			tahtaGoster(oyuncu_tahta);
			int gemiuzunlugu=2;
			cout<<"Gemileri Yerleþtiriniz..."<<endl;
			cout<<"Örnek : 1,1-1,"<<gemiuzunlugu<<" (Ýlk ve Son Noktalarýný Giriniz)"<<endl;
			cout<<"\n-------------------------------------------------------\n";
			cout<<"Hücum Botlarý Yerleþtiriniz:";gets_s(koordinat_giris);
			girisuzunlugu=strlen(koordinat_giris);
		
			//Sayýlar ',' ve '-' dýþýnda karakter giriþini engeller...
			test=karakter_engelle(girisuzunlugu,koordinat_giris);
			if(test==0){
				system("cls");
				cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
				continue;
			}
			test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinatý ',' ve '-' ayýklayýp diziye parçalar..
																		//koordinatlar[] dizisindeki deðerler sýrasýyla --> x1,y1,x2,y2 þeklinde ayýklanýr ;)
			if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0 || test==2 ){    //Koordinatlarýn 1-10 arasýnda giriþini saðlar..
				system("CLS");
				cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
				continue;
			}
			//Geminin Dikey yerleþme durumu
			if(koordinatlar[0]==koordinatlar[2]){
				if(koordinatlar[3]-koordinatlar[1]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
					test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);		//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
				}
				//Tahtaya gemiyi yerleþtirir.
				for(int i=0;i<gemiuzunlugu;i++){
					oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]='H';
					*(gemi_x[hucum+6]+i)=koordinatlar[0];*(gemi_y[hucum+6]+i)=koordinatlar[1]+i;
				}
				system("CLS");break;
			}

			//Geminin Yatay Yerleþme Durumu
			if(koordinatlar[1]==koordinatlar[3]){
				if(koordinatlar[2]-koordinatlar[0]!=(gemiuzunlugu-1)){
					system("CLS");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemiuzunlugu);			//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
				if(test==0){
					system("CLS");
					cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
					continue;
				}
				//Tahtaya Gemiyi Yerleþtirir..
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
		if((atisgiris[i]<=47 || atisgiris[i]>=58) && atisgiris[i]!=',')  //Sayý ve virgül dýþýndaki karakterleri engeller
			return 0;
		if(atisgiris[i]==',')  //Virgül adetini Sayar
			sayac++;
		
	}
	if(sayac!=1) //1'den Fazla virgülde hata verdirir..
		return 0;
	if(atisgiris[0]<'0' || atisgiris[0]>'9' || atisgiris[uzunluk-1]<'0' || atisgiris[uzunluk-1]>'9')    //Ýlk ve Son Karakterin Sayý Olmasýný saðlar
		return 0;

	return 1;
}

void Game_Start()
{
	int amiral_sayac_o=0,amiral_sayac_pc=0,koor_tut[2];
	bool sag=false,sol=false,ust=false,alt=false,ctrlkont;
	for(int i=0;i<10;i++){			//Atýþ Tahtalarýný Sýfýrlar...
		for(int j=0;j<10;j++){
			atis_oy_tahta[i][j]='.';
			atis_pc_tahta[i][j]='.';
		}
	}
	while(true){
		
		char atis_giris[10]={NULL};
		int atis_xy[2],kontrol=1;
		int *atisPtr=atis_xy;
		if(amiral_sayac_pc==6){		//Bilgisayarýn amiralý batýrmasý þartý...
			cout<<"\n-----  Amiral Gemisi Vuruldu Oyunu Bilgisayar Kazandý!!!  ----\n\n";
			break;
		}

		cout<<endl;
		cift_tahta_goster(atis_oy_tahta,atis_pc_tahta);
		cout<<"Rakip gemileri görmek için CTRL+F5 kombinasyonunu kullanýnýz \nAtýþlar x,y koordinat giriþi girilerek yapýlýr.\nÖrn:3,5\n----------------------------------------\nKoordinat Giriniz:";	
		while(1){
			 if ((GetAsyncKeyState(VK_CONTROL)) && (GetAsyncKeyState(VK_F5)))	//CTRL+F5 Basýlýrsa Bilgisayar Tahtasýný gösterir..
			 {
				system("cls");
				cout<<"\tRakip Oyun Tahtasý\n";
				tahtaGoster(pc_tahta);
				system("pause");
				system("cls");
				ctrlkont=true;
				break;
				
			 }
			 else if(_kbhit())	//Ctrl+F5 dýþýnda bir tuþa basýlýrsa atýþ giriþi alýnýr..
			 {
				 gets_s(atis_giris);
				 ctrlkont=false;
				 break;
			 }
		
		}
		if(ctrlkont){		//Ctrl+F5 kombinasyonu yapýldýysa baþa alýr ekranda tahta görüntüsü saðlar..
			continue;
		}

		kontrol=atis_hata_ayiklama(atis_giris);		//Atýþ Koordinatlarýnýn hatalarýný kontrol eder..
		if(kontrol==0){
			system("CLS");
			cout<<"Hatalý Koordinat Giriþi Yeniden Atýþ Yapýnýz..\n";
			continue;
		}

		kontrol=koordinat_ayikla(atis_giris,atisPtr);	//Atýþ Koordinatlarýný Ayýklayýp sayýlarýn 1-10 arasý girilmesini saðlar..
		if(atis_xy[0]<0 || atis_xy[1]<0 || kontrol==0 ){
			system("CLS");
			cout<<"1-10 Arasý Sayý Giriniz..\n";
			continue;
		}
		if(atis_pc_tahta[atis_xy[0]][atis_xy[1]]=='X' || atis_pc_tahta[atis_xy[0]][atis_xy[1]]=='O'){	//Koordinata daha önce atýþ yapýlmýþmý kontrolü yapar..
			system("cls");
			cout<<"Bu koordinatlara daha önce atýþ yapýldý!!\n";
			continue;
		}
		system("cls");
		if(pc_tahta[atis_xy[0]][atis_xy[1]]!='.'){		//Atýþ yapýlan yerde gemi varmý?
			if(pc_tahta[atis_xy[0]][atis_xy[1]]=='A')	//Varsa Amiral mi? Amiralse sayacý artýrýp oyunu sonlandýrýr..
				amiral_sayac_o++;
			atis_pc_tahta[atis_xy[0]][atis_xy[1]]='O';	//Diðer gemilerse atýþ tahtasýný iþaretler...
			cout<<"Ýsabetli Atýþ..\n";
		}
		else{
			atis_pc_tahta[atis_xy[0]][atis_xy[1]]='X';	//Atýþ karavana ise iþaretleme yapýlýr..
			cout<<"Karavana..\n";
		}
		if(amiral_sayac_o==6){							//Amiral sayacý tüm kareleri vurdurdugunda þartý saðlar ve oyunu durdurur..
			cout<<"\n-----  Amiral Gemisi Vuruldu Oyunu Kazandýnýz!!!  ----\n\n";
			break;
		}
		while(true){				//Bilgisayarýn Atýþý 
			atis_xy[0]=rand()%10;			//Rastgele Koordinat seçimi yapar..
			atis_xy[1]=rand()%10;
			if(atis_oy_tahta[atis_xy[0]][atis_xy[1]]!='X' && atis_oy_tahta[atis_xy[0]][atis_xy[1]]!='O')
				break;
		}


		if(sag){		//Ýsabet olmasý durumunda sýrasýyla sað sol üst ve alt taraflara bakar..
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
	cout<<"Oyuncu Puaný\t :"<<p1<<endl;
	cout<<"Rakibin Puaný\t :"<<p2<<endl<<endl;

	return p1;

}

void menu()
{
	char secim=NULL;
	while(secim!='1' && secim !='2'){
		cout<<"Amiral Battý v1.0\n"<<endl<<endl;
		cout<<"--------Menü-------\n"<<endl;
		cout<<"1-)Gemileri Manuel Yerleþtir"<<endl;
		cout<<"2-)Gemileri Otomatik Yerleþtir"<<endl;
		secim=_getch();
		system("cls");
		if(secim!='1' && secim!='2')
			cout<<"Menü giriþini hatalý yaptýnýz. Lütfen seçenek numarasýný tekrar giriniz"<<endl;
		_flushall();
	}
	if(secim=='1'){
		Manuel_TahtaDoldur(oyuncu_tahta);
		cout<<"Gemiler Baþarýyla Yerleþtirildi. Oyuna Baþlayabiliriz Artýk...\n";
	}
	if(secim=='2'){
		Oto_TahtaDoldur2(oyuncu_tahta);
		cout<<"Gemiler Bilgisayar Tarafýndan Rastgele Yerleþtirildi.. Oyun Baþlasýn...\n";
	}

}

int main()
{
	
	srand(time(NULL));
	setlocale(0,"tr");
	system("mode con cols=100 lines=100 ");		//Konsol boyutunu sabitlemek için...
	system("color 1F");
	char tekrar_secim,secim;
	int puan;
	while(true){
		menu();
		_flushall();
		Oto_TahtaDoldur(pc_tahta);
		Game_Start();
		puan=Puanlama();
		cout<<"Çýkýþ için 'h' tuþuna basýnýz..\nTekrar oynamak için bir tuþa basýnýz..";
		tekrar_secim=_getch();
		if(tekrar_secim=='h')
			break;
		system("cls");
		_flushall();
	}
	return 0;
}
