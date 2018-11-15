SEUNGHAN BAE (423311) - seunghan.bae@wustl.edu
LAB 0: parse an input text file and check if each string only contains numeric characters

===== File List =============================================================
Lab0.cpp: main application source file
	- int parseInput(vector<string> & v, char * c): parses the input file
	- int usageMsg(char * c): prints out the "usage message"

Lab0.h: main application header file

===== Encountered Errors & Warnings =========================================
(1) C2065('vector': undeclared identifier)
	C2065('string': undeclared identifier)
	C2059(syntax error: ',')
	C3861('parseInput': identifier not found)
	=> added '#include <string>', '#include <vector>', and 'using namespace std;' to Lab0.h
	(SOLVED)

(2) When creating a vector<string>, the last string of the input file is pushed back twice
	=> moved 'string s;' to the inside of 'while (ifs)' loop
	(SOLVED)

===== Sample Cases & Results ================================================
(1) Lab0 (only one command line argument)
	=> usage: Lab0 <input_file_name>
	=> 1
	(CORRECT)

(2) Lab0 input.txt output.txt (too many command line arguments)
	=> usage: Lab0 <input_file_name>
	=> 1
	(CORRECT)

(3) Lab0 none.txt (non-existent input file name)
	=> error: cannot open file 'none.txt'
	=> 2
	(CORRECT)

(4) Lab0 empty.txt (empty input file name)
	=> error: file 'empty.txt' is empty
	=> 3
	(CORRECT)

(5) Lab0 input.txt ("success" case)
	=> arg0
	   not
	   this
	   yay
	   hi7
	   bye30
	   aar
	   ds
	   124f
	   1ki3
	   112
	   34
	   567890
	   1938
	   1
	=> 0
	(CORRECT)

===== Extra Credit ==========================================================
$ mkdir cse332
$ cd cse332
$ mkder lab0
$ cd lab0

(moved all the necessary files)

$ make
g++ -o Lab0.exe -DUNIX   -Wall -W -g -pedantic Lab0.cpp -lnsl

(following are results of running sample cases)

$ ./Lab0.exe
usage: ./Lab0.exe <input_file_name>
$ ./Lab0.exe input.txt output.txt
usage: ./Lab0.exe <input_file_name>
$ ./Lab0.exe none.txt
error: cannot open file 'none.txt'
$ ./Lab0.exe empty.txt
error: file 'empty.txt' is empty
$ ./Lab0.exe input.txt
arg0
not
this
yay
hi7
bye30
aar
ds
124f
1ki3
112
34
567890
1938
1
