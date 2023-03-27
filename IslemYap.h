#ifndef ISLEMYAP_H
#define ISLEMYAP_H
#include "Kisi.h"
#include "Soru.h"


class IslemYap
{
	public:
		Kisi k1;
		Soru s1;
		
		void kisiEkle();
		void soruEkle();
		void kisiler();
		void sorular();
		void sinavBaslat();
		void sinavYap();
		void sonuclar();
		int menu();
		void giris();
		
		
		
	
	
};

#endif