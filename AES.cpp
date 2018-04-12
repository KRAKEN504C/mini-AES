#include <iostream>
#include <conio.h>
#include<vector>
#include <string>
#include <bitset>

using namespace std;

string RutynoweWejscie(int liczba)
{
	string ciag;
	cout << "Plesase enter number (do " << liczba << " liczb):";
	cin >> ciag;

	int length = ciag.length();
	if (length < liczba)
	{
		for (int i = length; i < liczba; i++) ciag += '0';
	}
	if (length > liczba)
	{
		for (int i = length; i > liczba; i--) ciag.erase(ciag.begin() + liczba, ciag.end());
	}

	cout << "Entered number is: " << ciag << endl;

	//cout << "Podana liczba po permutacji wstepnej: " << ciag << endl;
	return ciag;
}

string dodawanie16(string &ciag1, string ciag2)
{
	string Ik1 = ciag1;
	string IIk1 = ciag1;
	string IIIk1 = ciag1;
	string IVk1 = ciag1;

	string Ik2 = ciag2;
	string IIk2 = ciag2;
	string IIIk2 = ciag2;
	string IVk2 = ciag2;
	//dzielenie klucza na czworo

	Ik1.erase (4, 12);
	IIk1.erase(8,8);
	IIk1.erase(0, 4);
	IIIk1.erase(12, 4);
	IIIk1.erase(0,8);
	IVk1.erase(0,12);

	//cout << "TEST:";
	//cout << "\nIk1: " << Ik1;
	//cout << "\nIIk1: " << IIk1;
	//cout << "\nIIIk1: " << IIIk1;
	//cout << "\nIVk1: " << IVk1;
	//dziala :3

	Ik2.erase(4, 12);
	IIk2.erase(8, 8);
	IIk2.erase(0, 4);
	IIIk2.erase(12, 4);
	IIIk2.erase(0, 8);
	IVk2.erase(0, 12);
	//dodawanie

	auto Iw = bitset<4>(Ik1)^bitset<4>(Ik2);
	auto IIw = bitset<4>(IIk1) ^ bitset<4>(IIk2);
	auto IIIw = bitset<4>(IIIk1) ^ bitset<4>(IIIk2);
	auto IVw = bitset<4>(IVk1) ^ bitset<4>(IVk2);

	string Idod = Iw.to_string();
	string IIdod = IIw.to_string();
	string IIIdod = IIIw.to_string();
	string IVdod = IVw.to_string();

	Idod += IIdod;
	Idod += IIIdod;
	Idod += IVdod;
	cout << "Wynik dodawania binarnego dwoch ciagow 16 bitowych: " << Idod << endl;
	return Idod;
}

string konwersjamod(int pity4)
{
	int tab7[7];
	int checker;
	string wynik = "";

	for (int i = 6; i >= 0; i--)
	{
		checker = pity4 % 10;
		checker %= 2;
		tab7[i] = checker;
		pity4 /= 10;
	}

	cout << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << tab7[i];
	}


	for (int i = 0; i < 3; ++i)
	{
		if (tab7[i] == 1)
		{
			tab7[i + 0] += 1;
			tab7[i + 1] += 0;
			tab7[i + 2] += 0;
			tab7[i + 3] += 1;
			tab7[i + 4] += 1;
			for (int j = 0; j < 7; ++j)
			{
				tab7[j] %= 2;
			}
			cout << endl;
			for (int i = 0; i < 7; i++)
			{
				cout << tab7[i];
			}
			
		}
	}

	//cout << endl << pity4 << endl;

	for (int i = 3; i < 7; i++)
	{
		wynik += tab7[i];
	}
	cout << endl << "wynik: ";
	for (int i = 3; i < 7; i++)
	{
		cout << tab7[i];
	}

	return wynik;

}

void Wyluskiwanie(string osiemcyfr, string &converter, int ile)
{
	//cout << "TESTY\n";
	for (int i = 0; i < ile; i++)
	{
		//cout<<(int)osiemcyfr[i];
		if (osiemcyfr[i] == 0)
		{
			osiemcyfr[i] = 48;
		}
		else
		{
			osiemcyfr[i] = 49;
		}
		//cout << osiemcyfr[i];
	}
	converter = osiemcyfr;
}

string Mnozenie(string ciag1, string ciag2)
{
	string Ik1 = ciag1;
	string IIk1 = ciag1;
	string IIIk1 = ciag1;
	string IVk1 = ciag1;

	string Ik2 = ciag2;
	string IIk2 = ciag2;
	string IIIk2 = ciag2;
	string IVk2 = ciag2;
	//dzielenie klucza na czworo

	Ik1.erase(4, 12);
	IIk1.erase(8, 8);
	IIk1.erase(0, 4);
	IIIk1.erase(12, 4);
	IIIk1.erase(0, 8);
	IVk1.erase(0, 12);

	Ik2.erase(4, 12);
	IIk2.erase(8, 8);
	IIk2.erase(0, 4);
	IIIk2.erase(12, 4);
	IIIk2.erase(0, 8);
	IVk2.erase(0, 12);

	unsigned int Il1 = stoi(Ik1);
	unsigned int IIl1 = stoi(IIk1);
	unsigned int IIIl1 = stoi(IIIk1);
	unsigned int IVl1 = stoi(IVk1);

	unsigned int Il2 = stoi(Ik2);
	unsigned int IIl2 = stoi(IIk2);
	unsigned int IIIl2 = stoi(IIIk2);
	unsigned int IVl2 = stoi(IVk2);

	unsigned int Iw;
	unsigned int IIw;
	unsigned int IIIw;
	unsigned int IVw;
	//mnozonko

	unsigned int Im1 = Il1 * Il2;
	string sIm1 = konwersjamod(Im1);
	unsigned int Im2 = IIl1 * Il2;
	string sIm2 = konwersjamod(Im2);
	unsigned int Im3 = IIIl1 * IIIl2;
	string sIm3 = konwersjamod(Im3);
	unsigned int Im4 = IVl1 * IIIl2;
	string sIm4 = konwersjamod(Im4);

	unsigned int IIm1 = Il1 * IIl2;
	string sIIm1 = konwersjamod(IIm1);
	unsigned int IIm2 = IIl1 * IIl2;
	string sIIm2 = konwersjamod(IIm2);
	unsigned int IIm3 = IIIl1 * IVl2;
	string sIIm3 = konwersjamod(IIm3);
	unsigned int IIm4 = IVl1 * IVl2;
	string sIIm4 = konwersjamod(IIm4);
	
	string dododania1 = "";
	string dododania2 = "";

	dododania1 = sIm1 + sIm2 + sIm3 + sIm4;
	dododania2 = sIIm1 + sIIm2 + sIIm3 + sIIm4;

	Wyluskiwanie(dododania1, dododania1, 16);
	Wyluskiwanie(dododania2, dododania2, 16);

	cout << "dodawanie:" << dododania1 << "\n" << dododania2 << endl;

	string wynik = dodawanie16(dododania1, dododania2);

	return wynik;
}

void operacjaZK(string &ciag1)
{
	string Ik1 = ciag1;
	string IIk1 = ciag1;
	string IIIk1 = ciag1;
	string IVk1 = ciag1;

	Ik1.erase(4, 12);
	IIk1.erase(8, 8);
	IIk1.erase(0, 4);
	IIIk1.erase(12, 4);
	IIIk1.erase(0, 8);
	IVk1.erase(0, 12);

	ciag1 = "";
	ciag1 = Ik1 + IIk1 + IVk1 + IIIk1;
}

void SBoxE(string &ciag1)
{
	int tab[4];
	for (int i = 0; i < 4; i++)
	{
		tab[i] = ciag1[i] - '0';
	}

	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0) ciag1 = "1110";
	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 1) ciag1 = "0100";
	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 1 && tab[3] == 0) ciag1 = "1101";
	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 1 && tab[3] == 1) ciag1 = "0001";

	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 0 && tab[3] == 0) ciag1 = "0010";
	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 0 && tab[3] == 1) ciag1 = "1111";
	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 1 && tab[3] == 0) ciag1 = "1011";
	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 1 && tab[3] == 1) ciag1 = "1000";

	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0) ciag1 = "0011";
	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 0 && tab[3] == 1) ciag1 = "1010";
	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 1 && tab[3] == 0) ciag1 = "0110";
	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 1 && tab[3] == 1) ciag1 = "1100";

	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 0 && tab[3] == 0) ciag1 = "0101";
	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 0 && tab[3] == 1) ciag1 = "1001";
	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 1 && tab[3] == 0) ciag1 = "0000";
	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 1 && tab[3] == 1) ciag1 = "0111";


}

void SBoxD(string &ciag1)
{
	int tab[4];
	for (int i = 0; i < 4; i++)
	{
		tab[i] = ciag1[i] - '0';
	}

	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0) ciag1 = "1110";
	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 1) ciag1 = "0011";
	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 1 && tab[3] == 0) ciag1 = "0100";
	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 1 && tab[3] == 1) ciag1 = "1000";

	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 0 && tab[3] == 0) ciag1 = "0001";
	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 0 && tab[3] == 1) ciag1 = "1100";
	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 1 && tab[3] == 0) ciag1 = "1010";
	if (tab[0] == 0 && tab[1] == 1 && tab[2] == 1 && tab[3] == 1) ciag1 = "1111";

	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0) ciag1 = "0111";
	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 0 && tab[3] == 1) ciag1 = "1101";
	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 1 && tab[3] == 0) ciag1 = "1001";
	if (tab[0] == 1 && tab[1] == 0 && tab[2] == 1 && tab[3] == 1) ciag1 = "0110";

	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 0 && tab[3] == 0) ciag1 = "1011";
	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 0 && tab[3] == 1) ciag1 = "0010";
	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 1 && tab[3] == 0) ciag1 = "0000";
	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 1 && tab[3] == 1) ciag1 = "0101";


}

int main()
{

	//unsigned long long int klucz = 1100000011;

	string ciag = "0100100101001";
	string klucz1 = "1100000011";
	string klucz2;

	string test1 = "1011";
	string test2 = "1111";

	int tab_ciag[8];


	//cout << "\n TEST: liczba wydrukowana ze stringa: " << klucz1 << "\t Ta sama liczba tylko ze wydrukowana w systemie dwojkowym: " << bitset<10>(klucz1) << "\n";

	//auto wyniktest = bitset<4>(test1) ^ bitset<4>(test2);

	//cout << "\n TEST: Dodawanie binarne: " << wyniktest<<"\n\n";

	//Werdykt...................Dodawanie binarne dzia³a :3 // Nie nazwalbym tego nawet dodawaniem. To jest po prostu operacja XoR.

	string ciag1 = RutynoweWejscie(4);
	string ciag2 = RutynoweWejscie(4);
	string ciag3 = RutynoweWejscie(16);
	string ciag4 = RutynoweWejscie(16);

	string Pododawaniu = dodawanie16(ciag3, ciag4);

	string wynik = Mnozenie(ciag3,ciag4);

	string backupKlucz = klucz1;
	string backupKlucz2 = klucz2;
	string deszyfrowanie;


	cout << "\n\n\nProsze podac klucz deszyfrujacy" << deszyfrowanie;
	cin >> deszyfrowanie;

	int length2 = deszyfrowanie.length();
	if (length2 < 8)
	{
		for (int i = length2; i < 8; i++) deszyfrowanie += '0';
	}
	if (length2 > 8)
	{
		for (int i = length2; i > 8; i--) deszyfrowanie.erase(deszyfrowanie.begin() + 8, deszyfrowanie.end());
	}


	_getch();

	return 0;
}








//Mnozonko
/*
string mnozenie(string a, string b)
{
	int x;
	int tab7[7] = { 0 };
	string iloczyn = "";

	for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				tab7[i + j] += val(a[3 - i])*val(b[3 - j]);
			}
		}
	for (int i = 6; i >= 0; --i)
		{
			tab7[i] %= 2;
		}
	/**//*
	for (int i = 6; i >= 4; --i)
	{
		if (tab7[i] == 1)
		{
			tab7[i - 0] += 1;
			tab7[i - 1] += 0;
			tab7[i - 2] += 0;
			tab7[i - 3] += 1;
			tab7[i - 4] += 1;
			for (int j = 0; j < 7; ++j)
			{
				tab7[j] %= 2;
			}
		}
	}

	for (int i = 3; i >= 0; --i)
	{
		x = tab7[i] + '0';
		iloczyn += x;
	}
	return iloczyn;
}

/*
string** pomnoz(string** a, string** b)
{
	string **iloczyn = new string *[2];
	for (int i = 0; i < 2; i++) iloczyn[i] = new string[2];

	iloczyn[0][0] = dodawanie(mnozenie(a[0][0], b[0][0]), mnozenie(a[0][1], b[1][0]));
	iloczyn[0][1] = dodawanie(mnozenie(a[0][0], b[0][1]), mnozenie(a[0][1], b[1][1]));
	iloczyn[1][0] = dodawanie(mnozenie(a[1][0], b[0][0]), mnozenie(a[1][1], b[1][0]));
	iloczyn[1][1] = dodawanie(mnozenie(a[1][0], b[0][1]), mnozenie(a[1][1], b[1][1]));

	return iloczyn;
}
*/






/*for (int i = 6; i >= 0; --i)
{
cout << tab7[i];
}
cout << endl;*/




