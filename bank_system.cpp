#include "bankClass.h"
#include <locale.h>


// Melih Yıldız
// 13.05.2021
// 
// 

int main() {
	setlocale(LC_ALL, "Turkish");
	int key, askForNext=1;
	bankAccount acc1("", "", "", 0.0F);
	
	while (askForNext == 1) {
		cout << "-------ANASAYFA-------" << endl <<
		"HESABIM (1)---->" << endl << "PARA ÇEKME (2)---->" 
		<< endl << "PARA YATIRMA (3)---->" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
			acc1.controlMyAccount();
			break;
		case 2:
			acc1.withDraw();
			acc1.controlMyAccount();
			break;
		case 3:
			acc1.deposit();
			acc1.controlMyAccount();
			break;
		default:
			break;
		}
		cout << "Çıkış ---> 0" << endl << "Anasayfa ---> 1" << endl;
		cin >> askForNext;
	}
	
}