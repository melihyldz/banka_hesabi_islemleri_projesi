#include <iostream>
using namespace std;

class bankAccount {
private:
	string _name, _sname, _contactInfo;
	float _balance;
public:
	bankAccount(string name, string surname,string phoneNum,float balance);
	//Constrnuctors
	void setName(string name) {
		while (!isNameSurname(name)) {
			cout << "Lütfen geçerli bir ad girin. Adınız A-Z, a-z arasındaki harflerinden oluşmalıdır." << endl;
			cin >> name;
		}
		_name = name;
	}
	void setSName(string surname) {
		while (!isNameSurname(surname)) {
			cout << "Lütfen geçerli bir soyad girin. Soydınız A-Z, a-z arasındaki harflerinden oluşmalıdır." << endl;
			cin >> surname;
		}
		_sname = surname;
	}
	void setContactInfo(string phoneNum) {
		while (!isPhoneNum(phoneNum)) {
			cout << "Lütfen geçerli bir numara girin." << endl << "Numaranız 0-9 arasındaki sayılardan oluşmalı ve başına 0 koymadan 10 haneli olmalıdır." << endl;
			cin >> phoneNum;
		}
		_contactInfo = phoneNum;
	}
	void setBalance(float balance) {
		while (!isMoney(balance)) {
			cout << "Lütfen geçerli bir para miktarı giriniz." << endl;
			cin >> balance;
		}
		_balance = balance;
	}
	string getName() {
		return _name; 
	}
	string getSName() {
		return _sname; 
	}
	string getContactInfo() {
		return _contactInfo; 
	}
	float getBalance() {
		return _balance; 
	}
	//set and get functions
	bool isNameSurname(string name_surname);
	bool isPhoneNum(string phoneNum);
	bool isMoney(float money);
	void controlMyAccount();
	bool canWithDraw();
	void withDraw();
	void deposit();
	//another functions
};

bankAccount::bankAccount(string name, string surname, string phoneNum, float balance) {
	cout << endl << "AD: "; cin >> name; setName(name);
	cout << endl << "SOYAD: "; cin >> surname; setSName(surname);
	cout << endl << "TELEFON: "; cin >> phoneNum; setContactInfo(phoneNum);
	cout << endl << "HESABA EKLENİLCEK PARA: "; cin >> balance; setBalance(balance);
}


bool bankAccount::isNameSurname(string name_surname) {
	for (int i = 0; i < name_surname.length(); i++) {
		if (!((name_surname.at(i) >= 'A' && name_surname.at(i) <='Z') || (name_surname.at(i) >= 'a' && name_surname.at(i) <= 'z'))){
			return false;
		}
	}
	return true;
	
}

bool bankAccount::isPhoneNum(string phoneNum) {
	for (int i = 0; i < phoneNum.length(); i++) {
		if (!((phoneNum.at(i) >= '1' || phoneNum.at(i) <= '9') && phoneNum.length() == 10)) {
			return false;
		}
	}
	return true;
}


bool bankAccount::isMoney(float balance) {
	if (!(balance >= 0 )) { 
		return false;
	}
	return true;
}


void bankAccount::controlMyAccount() {
	cout << endl << "----------------------" << endl;
	cout << "AD: " << _name << endl;
	cout << "SOYAD: " << _sname << endl;
	cout << "TELEFON: " << _contactInfo << endl;
	cout << "HESABINIZDAKİ PARA: " << _balance << endl;
	cout << "----------------------" << endl;
}

void bankAccount::deposit() {
	float add_money;
	cout << "Hesabınıza eklenecek miktarı girin: ";
	cin >> add_money;
	_balance += add_money;
}

bool bankAccount::canWithDraw() {
	if (_balance == 0) {
		return false;
	}
	return true;
}

void bankAccount :: withDraw() {
	float withDraw;
	cout << "Çekmek istedğiniz miktarı girin: ";
	cin >> withDraw;
	if (!canWithDraw()) {
		cout << endl << "Hesabınızda para bulunmamaktadır." << endl;
	}
	else {
		if (_balance - withDraw < 0) {
			cout << endl << "Yetersiz Bakiye!" << endl;
		}
		else {
			_balance -= withDraw;
		}
	}
}