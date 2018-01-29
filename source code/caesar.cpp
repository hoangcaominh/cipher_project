#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

string str, ss = "";

void in()
{
	ifstream input;
	input.open("caesar-in.txt");
	getline(input, str);
}
void de_ci_out()
{
	ofstream output;
	output.open("caesar-out.txt");
	for (int i = 0;i < 26;i++)
	{
		for (int j = 0;j < str.length();j++)
			if (str[j] >= 65 && str[j] <= 90)
				if (str[j] + i > 90)	ss += char(int(str[j]) + i - 26);
				else ss += char(int(str[j]) + i);
			else if (str[j] >= 97 && str[j] <= 122)	
				if (str[j] + i > 122)	ss += char(int(str[j]) + i - 26);
				else ss += char(int(str[j]) + i);
			else
				ss += str[j];
		output << "+" << i << " char: " << ss << endl << endl;
		ss = "";
	}
}
int main()
{
	in();
	if (str.empty())
	{
		cout << "Input text not found." << endl;
		cout << "Insert input text to be (de)ciphered and restart this application." << endl;
		system("pause");
		return 0;
	}
	de_ci_out();
	cout << "(de)ciphered successfully." << endl;
	system("pause");
	return 0;
}
