#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

string str, key = "", s = "", ss = "", keyp = "";
char ch;
long int i = 0, j, k, int_ch;

void in()
{
	ifstream input;
	input.open("vigenere-in.txt");
	getline(input, str);
	getline(input, key);
}
void de()
{
/* thua, khong dung den
	while (i < str.length())												// loai bo khoang trang trong xau str
		if (str[i] == 32)
			str.erase(i, 1);
		else i++;
*/
	for (i = 0;i < key.length();i++)
		if (key[i] >= 65 && key[i] <= 90) keyp += char(int(key[i]) + 32);	// chuyen tat ca ki tu
		else keyp += key[i];												// cua xau key
/*	khong doi mat ma input sang chu thuong; giu nguyen
	for (i = 0;i < str.length();i++)
		if (str[i] >= 97 && str[i] <= 122) s += char(int(str[i]) - 32);		// va xau str
		else s += str[i];													// sang chu thuong
*/
	s = str;
	k = 0;
/*
	for (i = 0;i < s.length();i++)											// dich mat ma vigenere sang xau thuong
	{
		k = i % keyp.length();
		ch = char(int(s[i]) - int(keyp[k]) + 97);
		if (ch < 97) ch = char(int(ch) + 26);
		ss += ch;
	}
*/
	for (i = 0;i < s.length();i++)											// chuyen sang mat ma vigenere
	{
		if (s[i] >= 65 && s[i] <= 90)	// truong hop ki tu la chu hoa
		{
			if (k >= keyp.length())
				k = 0;
			int_ch = int(s[i]) - (int(keyp[k]) - 97);
			if (int_ch < 65)	// truong hop ma ki tu cua ch vuot qua 90
				ch = char(int_ch + 26);
			else
				ch = char(int_ch);
			ss += ch;
			k++;
		}
		else if (s[i] >= 97 && s[i] <= 122)	// truong hop ki tu la chu thuong
		{
			if (k >= keyp.length())
				k = 0;
			int_ch = int(s[i]) - (int(keyp[k]) - 97);
			
			if (int_ch < 97)	// truong hop ma ki tu cua ch vuot qua 122 (max = 127)
				ch = char(int_ch + 26);
			else
				ch = char(int_ch);
			ss += ch;
			k++;
		}
		else	// truong hop ki tu dac biet
			ss += s[i];
	}
}
void out()
{
	ofstream output;
	output.open("vigenere-out.txt");
	output << ss;
	cout << "Decoded successfully." << endl;
	system("pause");
}
int main()
{
	in();
	if (str.empty())
	{
		cout << "Input text not found." << endl;
		cout << "Insert text to be deciphered and restart this application." << endl;
		system("pause");
		return 0;
	}
	else if (!str.empty() && key.empty())
	{
		cout << "Input text found but keyword is not recognized." << endl;
		cout << "Insert keyword and restart this application." << endl;
		system("pause");
		return 0;
	}
	de();
	out();
	return 0;
}
