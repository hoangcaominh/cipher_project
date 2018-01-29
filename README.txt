(Any mistake in grammar or anything else is due to my poor English, sorry about that)

Created by Hoang Cao Minh.

This contains programs which convert normal texts into ciphered texts, vice versa.
Each program encodes texts via different methods.
Currently there are ciphers based on Caesar, Vigenere, Morse.

Just install all stuffs in the same folder. However, txt files MUST be in the same folder with its application (which is already done).

Input texts: Contain only 1 line, insert only your texts there, nothing else.
 *Special case:	- For Vigenere-ci, the first line is your texts, the second line is your keyword.
		- For Vigenere-de, the first line is your ciphered texts, the second line is your keyword.
 *Specific notes:
 - Morse: Text in the input file MUST be lower-cased, ANY capital character can cause an error to the program
	(because upper-cased letters are NOT supported yet, will be fixed in the next version).
 - Vigenere: This will not change special characters like !, @, etc.

Output texts:
 - Caesar: 26 lines of each encoded/decoded texts (text in each line is increased by 1 character value).
 - Morse: 1 line only, contain encoded texts.
 - Vigenere: 1 line only, contain encoded texts.

Where to type in your inputs? In (cipher type)-in.txt
Where to receive your outputs? In (cipher type)-out.txt

Program type;
(cipher type)-ci.exe: Encodes your input texts.
(cipher type)-de.exe: Decodes your input ciphers.

How to run the program:
Just double-click the program you want to run, there will be instructions in the console window.