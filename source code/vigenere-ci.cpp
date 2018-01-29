#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

string str, key = "", s = "", ss = "", keyp = "";
char ch;
long int i, j, k, int_ch;

void in()
{
	ifstream input;
	input.open("vigenere-in.txt");
	getline(input, str);
	getline(input, key);
}
void ci()
{
	for (i = 0;i < key.length();i++)
		if (key[i] >= 97 && key[i] <= 122) keyp += char(int(key[i]) - 32);	// chuyen tat ca ki tu
		else keyp += key[i];												// cua xau keyp
/*	khong doi xau input sang chu hoa; giu nguyen
	for (i = 0;i < str.length();i++)
		if (str[i] >= 97 && str[i] <= 122) s += char(int(str[i]) - 32);		// va xau str
		else s += str[i];													// sang chu hoa
*/
	s = str;	// phuong an du phong cho truong hop tren
	k = 0;
	
	for (i = 0;i < s.length();i++)											// chuyen sang mat ma vigenere
	{
		if (s[i] >= 65 && s[i] <= 90)	// truong hop ki tu la chu hoa
		{
			if (k >= keyp.length())
				k = 0;
			int_ch = int(s[i]) + (int(keyp[k]) - 65);
			
			if (int_ch > 90)	// truong hop ma ki tu cua ch vuot qua 90
				ch = char(int_ch - 26);
			else
				ch = char(int_ch);
			ss += ch;
			k++;
		}
		else if (s[i] >= 97 && s[i] <= 122)	// truong hop ki tu la chu thuong
		{
			if (k >= keyp.length())
				k = 0;
			int_ch = int(s[i]) + (int(keyp[k]) - 65);
			
			if (int_ch > 122)	// truong hop ma ki tu cua ch vuot qua 122 (max = 127)
				ch = char(int_ch - 26);
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
	cout << "Encoded successfully." << endl;
	system("pause");
}
int main()
{
	in();
	if (str.empty())
	{
		cout << "Input text not found." << endl;
		cout << "Insert text to be ciphered and restart this application." << endl;
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
	ci();
	out();
	return 0;
}
