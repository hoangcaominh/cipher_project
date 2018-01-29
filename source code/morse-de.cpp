#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "morse.h"
using namespace std;

string str, sm = "", ss = "";
long int i = 0;

void in()
{
	ifstream input;
	input.open("morse-in.txt");
	getline(input, str);
}
void de()
{
	while (i <= str.length())
		if (str[i] == 32)
		{
			for (long long j = 0;j < num;j++)
				if (sm == cd[j].c) ss += cd[j].ch;
			
			str.erase(0, i + 1);
			i = 0;
			sm = "";
		}
		else
		{
			sm += str[i];
			i++;
		}
}
void out()
{
	ofstream output;
	output.open("morse-out.txt");
	output << ss;
	cout << "Deciphered successfully." << endl;
	system("pause");
}
int main()
{
	cre();
	in();
	if (str.empty())
	{
		cout << "Input text not found." << endl;
		cout << "Insert input text to be deciphered and restart this application." << endl;
		system("pause");
		return 0;
	}
	str += " ";
	de();
	out();
	return 0;
}
