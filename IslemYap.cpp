#include "IslemYap.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;


void IslemYap::kisiEkle()
{
   
    system("cls");
	cout<<"Kisi Ekleme..."<<endl;
	cout<<"Ad Soyad:";
	cin.getline(k1.adSoyad, 50 , '\n');
	k1.puan=0.0;

	ofstream file("kisiler.txt", ios::app);
	file.write((char*)&k1, sizeof(Kisi));
	file.close();

	cout<<"\nKisi Kaydi tamam..."<<endl;

	system("pause");
	
}
void IslemYap::soruEkle()
{
	system("cls");
	cout<<"Soru Ekleme..."<<endl;
	cout<<"Soru Metni:";
	cin.getline(s1.SoruMetni , 200 ,'\n');
	cout<<"A Secenegi:";
	cin.getline(s1.aSec,30, '\n');
	cout<<"B Secenegi:";
	cin.getline(s1.bSec,30, '\n');
	cout<<"C Secenegi:";
	cin.getline(s1.cSec,30, '\n');
	cout<<"D Secenegi:";
	cin.getline(s1.dSec,30, '\n');
	cout<<"Dogru Cevap:";
	cin.getline(s1.dogruCevap , 2 , '\n');
	
	
	ofstream file("sorular.txt", ios::app);
	file.write((char*)&s1, sizeof(Soru));
	file.close();

	cout<<"\nSoru kaydi tamam..."<<endl;

	system("pause");
	
	
}
void IslemYap::kisiler()
{
	
	system("cls");
	cout<<"Kisiler..."<<endl;
	

	ifstream file("kisiler.txt");
	while(file.read((char*)&k1, sizeof(Kisi)) !=NULL )
	{
		
		cout<<k1.adSoyad<<endl;
	}

	file.close();
	cout<<"Kisiler listelendi..."<<endl;
	system("pause");
	
	
}
void IslemYap::sorular()
{
	
	system("cls");
	cout<<"Sorular..."<<endl;
	int i;
	i=0;
	ifstream file("sorular.txt");
	while(file.read((char*)&s1, sizeof(Soru)) !=NULL )
	{
		i++;
		cout<<endl<< i<< ". soru : "<<s1.SoruMetni<< endl;
		cout<<"A) " << s1.aSec << endl;
		cout<<"B) " << s1.bSec << endl;
		cout<<"C) " << s1.cSec << endl;
		cout<<"D) " << s1.dSec << endl;
		cout<<"Dogru Cevap : " << s1.dogruCevap << endl;
		
		
	}

	file.close();
	cout<<"Sorular Listelendi ..."<<endl;
	system("pause");
	
	
}
void IslemYap::sinavBaslat()
{
	system("cls");
	
	cout<<k1.adSoyad<<"Sınavınız Baslıyor"<<endl;
	cout<<"Sorular..."<<endl;
	int i;
	i=0;
	int dogru;
	int yanlis;
	dogru=0;
	yanlis=0;
	char cevap[2];
	ifstream file("sorular.txt");
	while(file.read((char*)&s1, sizeof(Soru)) !=NULL )
	{
		i++;
		cout<<endl<< i<< ". soru : "<<s1.SoruMetni<< endl;
		cout<<"A) " << s1.aSec << endl;
		cout<<"B) " << s1.bSec << endl;
		cout<<"C) " << s1.cSec << endl;
		cout<<"D) " << s1.dSec << endl;
		cout<<"Cevabınız ? : "; 
		cin.getline(cevap , 2 , '\n');
		
		if(strcmp ( cevap , s1.dogruCevap) ==0)
		dogru++;
		else
		yanlis++;
			
	}

	file.close();
	k1.puan =  (float) (dogru) / (dogru  + yanlis ) *100;
	
	system("cls");
	cout<<"Sinav Basariyla tamamlandi ..."<<endl;
	
	cout<<"Dogru Sayisi:"<< dogru<< endl;
	cout<<"Yanlis Sayisi:"<< yanlis<< endl;
	cout<<"Puaniniz:"<< k1.puan<< endl;
	
	
	ofstream sfile("sinavOlanKisiler.txt", ios::app);
	sfile.write((char*)&k1, sizeof(Kisi));
	sfile.close();

	
	system("pause");
	
	
	
}
void IslemYap::sinavYap()
{
	Kisi k2;
	bool sonuc = false;
	system("cls");
	cout<<"Sinav Baslatma Ekrani..."<<endl;
	cout<<"Ad SoyadÇ:";
	cin.getline(k2.adSoyad, 50 , '\n');
	
	
	
	ifstream file("kisiler.txt");
	while(file.read((char*)&k1, sizeof(Kisi)) !=NULL )
	{
		
		if(strcmp(k1.adSoyad , k2.adSoyad) ==0)
		{
			sonuc=true;
			cout<<k1.adSoyad<<endl;
			break;
		}
		
	}

	file.close();
	
	if(sonuc)
	{
		sinavBaslat();
		
	}
	else
	{
		cout<<k2.adSoyad<<"Once lutfen Kayıt Olunuz ! "<<endl;
		system("pause");
	}
	
	
	
}

void IslemYap::sonuclar  ()
{
	
	system("cls");
	cout<<"\nSinav Olan Kisiler..."<<endl;
	

	ifstream file("sinavOlanKisiler.txt");
	while(file.read((char*)&k1, sizeof(Kisi)) !=NULL )
	{
		
		cout<<k1.adSoyad<<"\t"<<k1.puan<<endl;
	}

	file.close();
	cout<<"\nSinav Olan Kisiler listelendi..."<<endl;
	
	system("pause");
	
	
}


int IslemYap::menu()
{
	system("cls");
	int secim;
	char tercih[2];
	cout<<"\n\tSORU CEVAP UYGULAMASI"<<endl<<endl;
	cout<<"[1]-Sinav Yap"<< endl;
	cout<<"[2]-Kisi Ekle"<< endl;
	cout<<"[3]-Soru Ekle"<< endl;
	cout<<"[4]-Kisiler"<< endl;
	cout<<"[5]-Sorular"<< endl;
	cout<<"[6]-Sonuclar"<< endl;
	cout<<"[0]-Cikis"<< endl;
	cout<<"seciminiz:";
	cin.getline(tercih , 2);
	secim=atoi(tercih);  // atoi ile integera ceviriyoruz tercihi (tam sayıya)
   
	
}
void IslemYap::giris()

{
	
	
	int secim = menu();
	
	while(secim != 0)
	{
		 
		switch (secim)
		{
			case 1:
			sinavYap();
			break;
			
			case 2:
			kisiEkle();
			break;
			
			case 3:
			soruEkle();
			break;
			
			case 4:
		    kisiler();
			break;
			
			case 5:
			sorular();
			break;
			
			case 6:
			sonuclar();
						
	
		}
		
		secim=menu();
		
	}
	
	
}












































