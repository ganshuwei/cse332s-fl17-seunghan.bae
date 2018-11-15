SEUNGHAN BAE (423311) - seunghan.bae@wustl.edu
LAB 1: draw a game board and game pieces according to the given input file

===== File List =============================================================
Lab1.cpp: main application source file
	- void toLowerCase(string & s): converts the string into all lower cases
	- int usageMsg(char * c1, char * c2): prints out the usage message

Lab1.h: main application header file

GamePieces.cpp: source file for game pieces
	- string enumToString(piece_color p): converts the color enum into string
	- piece_color stringToEnum(string s): converts the string into color enum
	- game_pieces::game_pieces(piece_color p, string name, string display): declares and defines a game_pieces object

GamePieces.h: header file for game pieces

GameBoard.cpp: source file for game board
	- int readDimension(ifstream & ifs, unsigned int & width, unsigned int & height): reads board dimension from the input file
	- int readPieces(ifstream & ifs, vector<game_pieces>& v, unsigned int width, unsigned int height): reads board pieces from the input file
	- int printPieces(const vector<game_pieces>& v, unsigned int width, unsigned int height): prints the board and its pieces out
	- [Extra Credit] int printNeighbor(const vector<game_pieces>& v, unsigned int width, unsigned int height): prints the neighbors of each game_pieces printed

GameBoard.h: header file for game board

===== Encountered Errors & Warnings =========================================
(1) C4018: '<': signed/unsigned mismatch (in multiple for loops)
	=> changed the variables' types from int to unsigned int and size_t
	(SOLVED)

===== Sample Cases & Results ================================================
(1) lab1 (only 1 command line argument)
	=> usage: lab1 <input_file_name>
	=> 1
	(CORRECT)

(2) lab1 arg1.txt arg2.txt (too many command line arguments)
	=> usage: lab1 <input_file_name>
	=> 1
	(CORRECT)

(3) lab1 no.txt (nonexistent input file)
	=> error: cannot open 'no.txt'
	=> 2
	(CORRECT)

(4) lab1 empty.txt (empty input file)
	=> error: cannot extract board dimensions from 'empty.txt'
	=> 3
	(CORRECT)

(5) lab1 no_dim.txt (input file with no dimension values)
	=> error: cannot extract board dimensions from 'no_dim.txt'
	=> 3
	(CORRECT)

(6) lab1 no_pieces.txt (input file with no valid pieces)
	=> error: cannot find any piece definitions from 'no_pieces.txt'
	=> 5
	(CORRECT)

(7) lab1 gomoku.txt (correct input file #1)
	=>  O O O O
	   O O O O
	    O O O O


	   X X X X
	    X X X X
	   X X X X
	=> 0
	(CORRECT)

(8) lab1 tic-tac-toe.txt (correct input file #2)
	=> XXO
	   OX
	   XOO
	=> 0
	(CORRECT)

(9) lab1 tic-tac-toe_edited.txt (tic-tac-toe.txt with spaces, empty lines, and false lines added)
	=>  XX
	   O
	   XO
	=> 0
	(CORRECT)

(10) lab1 gomoku_edited.txt (gomoku.txt with spaces, empty lines, and false lines added)
	=>  O   O O
	   O O O 
	    O O O O


	   X   X  
	    X X X 
	   X X X X
	=> 0
	(CORRECT)

===== Extra Credit ==========================================================
(1) using 2 "for" loops, iterate through the entire board, cell by cell.
(2) During each iteration, check if there is a piece drawn in the cell.
(3) If TRUE, first print the information of that piece in a new line.
(4) Now, time to check for existing neighbors in the 8 cells surrounding the piece.
(5) First, check if the possible neighbor is within the boundary of the board.
(6) Second, check if there is a piece drawn in the neighboring cell.
(7) If both conditions are met, print the information of the neighbor in the same line.
(8) Repeat steps (2)-(7) for the next cell.
(9) Test results:
	- lab1 tic-tac-toe.txt
	=> XXO
	   OX
	   XOO
	   
	   0,0 red Xs: 1,0 blue Os; 1,1 red Xs; 0,1 blue Os;
	   0,1 blue Os: 1,1 red Xs; 1,2 red Xs; 0,2 red Xs; 0,0 red Xs; 1,0 blue Os;
	   0,2 red Xs: 1,2 red Xs; 0,1 blue Os; 1,1 red Xs;
	   1,0 blue Os: 2,0 blue Os; 1,1 red Xs; 0,1 blue Os; 0,0 red Xs;
	   1,1 red Xs: 2,2 blue Os; 1,2 red Xs; 0,2 red Xs; 0,1 blue Os; 0,0 red Xs; 1,0 blue Os; 2,0 blue Os;
	   1,2 red Xs: 2,2 blue Os; 0,2 red Xs; 0,1 blue Os; 1,1 red Xs;
	   2,0 blue Os: 1,1 red Xs; 1,0 blue Os;
	   2,2 blue Os: 1,2 red Xs; 1,1 red Xs;
	- lab1 gomoku.txt
	=>  O O O O
	   O O O O
	    O O O O
	   
	   
	   X X X X
	    X X X X
	   X X X X
	   
	   0,0 black stone: 1,1 black stone;
	   0,2 black stone: 1,1 black stone;
	   0,6 white stone: 1,7 white stone; 1,5 white stone;
	   1,1 black stone: 2,2 black stone; 0,2 black stone; 0,0 black stone; 2,0 black stone;
	   1,5 white stone: 2,6 white stone; 0,6 white stone;
	   1,7 white stone: 0,6 white stone; 2,6 white stone;
	   2,0 black stone: 3,1 black stone; 1,1 black stone;
	   2,2 black stone: 1,1 black stone; 3,1 black stone;
	   2,6 white stone: 3,7 white stone; 1,7 white stone; 1,5 white stone; 3,5 white stone;
	   3,1 black stone: 4,2 black stone; 2,2 black stone; 2,0 black stone; 4,0 black stone;
	   3,5 white stone: 4,6 white stone; 2,6 white stone;
	   3,7 white stone: 2,6 white stone; 4,6 white stone;
	   4,0 black stone: 5,1 black stone; 3,1 black stone;
	   4,2 black stone: 3,1 black stone; 5,1 black stone;
	   4,6 white stone: 5,7 white stone; 3,7 white stone; 3,5 white stone; 5,5 white stone;
	   5,1 black stone: 6,2 black stone; 4,2 black stone; 4,0 black stone; 6,0 black stone;
	   5,5 white stone: 6,6 white stone; 4,6 white stone;
	   5,7 white stone: 4,6 white stone; 6,6 white stone;
	   6,0 black stone: 7,1 black stone; 5,1 black stone;
	   6,2 black stone: 5,1 black stone; 7,1 black stone;
	   6,6 white stone: 7,7 white stone; 5,7 white stone; 5,5 white stone; 7,5 white stone;
	   7,1 black stone: 6,2 black stone; 6,0 black stone;
	   7,5 white stone: 6,6 white stone;
	   7,7 white stone: 6,6 white stone;
