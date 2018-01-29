#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "morse.h"
using namespace std;

string str, ss = "";
long int i = 0;

void in()
{
	ifstream input;
	input.open("morse-in.txt");
	getline(input, str);
}
void out()
{
	ofstream output;
	output.open("morse-out.txt");
	output << ss;
	cout << "Ciphered successfully." << endl;
	system("pause");
}
void ci()
{
	while (!str.empty())
	{
		for (long long j = 0;j < num;j++)
			if (str[0] == cd[j].ch) ss += cd[j].c + " ";
		str.erase(0, 1);
	}
	ss.erase(ss.length() - 1, 1);
}
int main()
{
	in();
	if (str.empty())
	{
		cout << "Input text not found." << endl;
		cout << "Insert input text to be ciphered and restart this application." << endl;
		system("pause");
		return 0;
	}
	cre();
	ci();
	out();
	return 0;
}
