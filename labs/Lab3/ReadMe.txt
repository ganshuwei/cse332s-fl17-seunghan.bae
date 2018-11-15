SEUNGHAN BAE (423311) - seunghan.bae@wustl.edu
LAB 3: create tic-tac-toe and gomoku game

===== File List =============================================================
Lab3.cpp: main application source file
	- int usageMsg(char * c1, char * c2, char * c3, char * c4): prints out the usage message

Lab3.h: main application header file

GamePieces.cpp: source file for game pieces
	- string enumToString(piece_color p): converts the color enum into string
	- piece_color stringToEnum(string s): converts the string into color enum
	- game_pieces::game_pieces(piece_color p, string name, string display): declares and defines a game_pieces object

GamePieces.h: header file for game pieces

GameClasses.cpp: source file for game classes
	- GameBase::GameBase(unsigned int width, unsigned int height): constructor for the GameBase class
	- void GameBase::prompt(unsigned int & n1, unsigned int & n2): prompts player to type either 'quit' or 'x,y'
	- int GameBase::play(): plays the game
	- GameBase * GameBase::start(int argc, char * argv[]): initializes the game by checking argc and argv
	- ostream & operator<<(ostream & os, const TicTacToe & ttt): prints out the TicTacToe game
	- TicTacToe::TicTacToe(): default constructor for the TicTacToe class
	- void TicTacToe::print(): prints out the TicTacToe game
	- bool TicTacToe::done(): returns true when either of the players won
	- bool TicTacToe::draw(): returns true when the game ended draw
	- int TicTacToe::turn(): receives input for each player's turn and prints out the board
	- ostream & operator<<(ostream & os, const Gomoku & gmk): prints out the Gomoku game
	- Gomoku::Gomoku(): default constructor for the Gomoku class
	- Gomoku::Gomoku(unsigned int dim, unsigned int connect): extra-credit constructor for the Gomoku class
	- void Gomoku::print(): prints out the Gomoku game
	- bool Gomoku::done(): returns true when either of the players won
	- unsigned int Gomoku::doneCheck(unsigned int x, unsigned int y, int & dir): checks neighboring game_pieces recursively
	- bool Gomoku::draw(): returns true when the game ended draw
	- int Gomoku::turn(): receives input for each player's turn and prints out the board

GameClasses.h: header file for game classes

===== Encountered Errors & Warnings =========================================
(1) C4018: '<': signed/unsigned mismatch (in a few 'for' loops)
	=> changed the variables' types from int to unsigned int
	(SOLVED)

===== Sample Cases & Results ================================================
(1) lab3 (only 1 command line argument)
	=> usage: lab3 <TicTacToe/Gomoku> <board_dimension> <#_connect>
	=> 1
	(CORRECT)

(2) lab3 TicTac (wrong game name)
	=> usage: lab3 <TicTacToe/Gomoku> <board_dimension> <#_connect>
	=> 1
	(CORRECT)

(3) lab3 TicTacToe (TicTacToe: user quit)
	=> 4
	   3
	   2
	   1
	   0
	     0 1 2 3 4
	
	   type 'quit' or 'x,y': 2,2
	   4
	   3
	   2     X
	   1
	   0
	     0 1 2 3 4
	   
	   Player X: 2,2;
	   
	   type 'quit' or 'x,y': 1,1
	   4
	   3
	   2     X
	   1   O
	   0
	     0 1 2 3 4
		
	   Player O: 1,1;
	   
	   type 'quit' or 'x,y': quit
	   user quit: 2 turn(s) played
	=> 2
	(CORRECT)

(4) lab3 TicTacToe (TicTacToe: game ended draw)
	=> 4
	   3
	   2
	   1
	   0
	     0 1 2 3 4

	   type 'quit' or 'x,y': 1,1
	   4
	   3
	   2
	   1   X
	   0
	     0 1 2 3 4
		
	   Player X: 1,1;

	   type 'quit' or 'x,y': 2,1
	   4
	   3
	   2
	   1   X O
	   0
	     0 1 2 3 4

	   Player O: 2,1;

	   type 'quit' or 'x,y': 3,1
	   4
	   3
	   2
	   1   X O X
	   0
	     0 1 2 3 4

	   Player X: 1,1; 3,1;

	   type 'quit' or 'x,y': 1,3
	   4
	   3   O
	   2
	   1   X O X
	   0
	     0 1 2 3 4

	   Player O: 1,3; 2,1;

	   type 'quit' or 'x,y': 2,3
	   4
	   3   O X
	   2
	   1   X O X
	   0
	     0 1 2 3 4

	   Player X: 1,1; 2,3; 3,1;

	   type 'quit' or 'x,y': 3,3
	   4
	   3   O X O
	   2
	   1   X O X
	   0
	     0 1 2 3 4

	   Player O: 1,3; 2,1; 3,3;

	   type 'quit' or 'x,y': 2,2
	   4
	   3   O X O
	   2     X
	   1   X O X
	   0
	     0 1 2 3 4

	   Player X: 1,1; 2,2; 2,3; 3,1;

	   type 'quit' or 'x,y': 1,2
	   4
	   3   O X O
	   2   O X
	   1   X O X
	   0
	     0 1 2 3 4

	   Player O: 1,2; 1,3; 2,1; 3,3;

	   type 'quit' or 'x,y': 1,1 (intentionally invalid input)
	   type 'quit' or 'x,y': 3,2
	   4
	   3   O X O
	   2   O X X
	   1   X O X
	   0
	     0 1 2 3 4

	   Player X: 1,1; 2,2; 2,3; 3,1; 3,2;

	   game ended draw: 9 turn(s) played
	=> 3
	(CORRECT)

(5) lab3 TicTacToe (TicTacToe: success case)
	=> 4
	   3
	   2
	   1
	   0
	     0 1 2 3 4

	   type 'quit' or 'x,y': 2,2
	   4
	   3
	   2     X
	   1
	   0
	     0 1 2 3 4

	   Player X: 2,2;

	   type 'quit' or 'x,y': 1,1
	   4
	   3
	   2     X
	   1   O
	   0
	     0 1 2 3 4

	   Player O: 1,1;

	   type 'quit' or 'x,y': 2,1
	   4
	   3
	   2     X
	   1   O X
	   0
	     0 1 2 3 4

	   Player X: 2,1; 2,2;

	   type 'quit' or 'x,y': 3,11 (intentionally invalid input)
	   type 'quit' or 'x,y': stop (intentionally invalid input)
	   type 'quit' or 'x,y': 0,0 (intentionally invalid input)
	   type 'quit' or 'x,y': 3,3
	   4
	   3       O
	   2     X
	   1   O X
	   0
	     0 1 2 3 4

	   Player O: 1,1; 3,3;

	   type 'quit' or 'x,y': 2,3
	   4
	   3     X O
	   2     X
	   1   O X
	   0 
	     0 1 2 3 4

	   Player X: 2,1; 2,2; 2,3;

	   Player X wins
	=> 0
	(CORRECT)

(5) lab3 Gomoku (Gomoku: user quit)
    => 19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10
	    9
	    8
	    7
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   type 'quit' or 'x,y': 5,5
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10
	    9
	    8
	    7
	    6
	    5              B
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   Black Stone: 5,5;

	   type 'quit' or 'x,y': 11,7
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10
	    9
	    8
	    7                                W
	    6
	    5              B
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   White Stone: 11,7;

	   type 'quit' or 'x,y': quit
	   user quit: 2 turn(s) played
	=> 2
	(CORRECT)

(6) lab3 Gomoku (Gomoku: game ended draw)
	=> see the last test case of the Extra Credit section

(7) lab3 Gomoku (Gomoku: success case)
	=> 19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10
	    9
	    8
	    7
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   type 'quit' or 'x,y': 9,8
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10
	    9
	    8                          B
	    7
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   Black Stone: 9,8;

	   type 'quit' or 'x,y': 8,8
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10
	    9
	    8                       W  B
	    7
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   White Stone: 8,8;

	   type 'quit' or 'x,y': 10,9
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10
	    9                             B
	    8                       W  B
	    7
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   Black Stone: 9,8; 10,9;

	   type 'quit' or 'x,y': 8,10
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10                       W
	    9                             B
	    8                       W  B
	    7
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   White Stone: 8,8; 8,10;

	   type 'quit' or 'x,y': 8,8 (invalid input)
	   type 'quit' or 'x,y': 8,7
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10                       W
	    9                             B
	    8                       W  B
	    7                       B
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   Black Stone: 8,7; 9,8; 10,9;

	   type 'quit' or 'x,y': 8,9
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10                       W
	    9                       W     B
	    8                       W  B
	    7						B
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   White Stone: 8,8; 8,9; 8,10;

	   type 'quit' or 'x,y': 11,10
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10                       W        B
	    9                       W     B
	    8                       W  B
	    7                       B
	    6
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   Black Stone: 8,7; 9,8; 10,9; 11,10;

	   type 'quit' or 'x,y': 7,6
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11
	   10                       W        B
	    9                       W     B
	    8                       W  B
	    7                       B
	    6                    W
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   White Stone: 7,6; 8,8; 8,9; 8,10;

	   type 'quit' or 'x,y': 12,11
	   19
	   18
	   17
	   16
	   15
	   14
	   13
	   12
	   11                                   B
	   10                       W        B
	    9                       W     B
	    8                       W  B
	    7                       B
	    6                    W
	    5
	    4
	    3
	    2
	    1
	    X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

	   Black Stone: 8,7; 9,8; 10,9; 11,10; 12,11;

	   Black Stone wins
	=> 0
	(CORRECT)

===== Extra Credit ==========================================================
(1) Create another constructor for the Gomoku class so that it receives command line arguments during initialization.
(2) Modify "GameBase::start()" so that it receives and processes additional command line arguments.
(3) Modify member functions of the Gomoku class so that it runs flexibly with varying board sizes and rules. 
(4) Test Results
	- lab3 Gomoku size (wrong command line arguments)
	=> usage: lab3 <TicTacToe/Gomoku> <board_dimension> <#_connect>
	=> 1
	(CORRECT)

	- lab3 Gomoku size conn (wrong command line arguments)
	=> usage: lab3 <TicTacToe/Gomoku> <board_dimension> <#_connect>
	=> 1
	(CORRECT)

	- lab3 Gomoku 7 conn (wrong command line arguments)
	=> usage: lab3 <TicTacToe/Gomoku> <board_dimension> <#_connect>
	=> 1
	(CORRECT)

	- lab3 Gomoku 7 (one additional argument, success case)
	=> 7
	   6
	   5
	   4
	   3
	   2
	   1
	   X 1 2 3 4 5 6 7

	   type 'quit' or 'x,y': 2,2
	   7
	   6
	   5
	   4
	   3
	   2   B
	   1
	   X 1 2 3 4 5 6 7

	   Black Stone: 2,2;

	   type 'quit' or 'x,y': 3,3
	   7
	   6
	   5
	   4
	   3     W
	   2   B
	   1
	   X 1 2 3 4 5 6 7

	   White Stone: 3,3;

	   type 'quit' or 'x,y': 3,2
	   7
	   6
	   5
	   4
	   3     W
	   2   B B
	   1
	   X 1 2 3 4 5 6 7

	   Black Stone: 2,2; 3,2;

	   type 'quit' or 'x,y': 2,4
	   7
	   6
	   5
	   4   W
	   3     W
	   2   B B
	   1
	   X 1 2 3 4 5 6 7

	   White Stone: 2,4; 3,3;

	   type 'quit' or 'x,y': 6,2
	   7
	   6
	   5
	   4   W
	   3     W
	   2   B B     B
	   1
	   X 1 2 3 4 5 6 7

	   Black Stone: 2,2; 3,2; 6,2;

	   type 'quit' or 'x,y': 4,2
	   7
	   6
	   5
	   4   W
	   3     W
	   2   B B W   B
	   1
	   X 1 2 3 4 5 6 7

	   White Stone: 2,4; 3,3; 4,2;

	   type 'quit' or 'x,y': 5,2
	   7
	   6
	   5
	   4   W
	   3     W
	   2   B B W B B
	   1
	   X 1 2 3 4 5 6 7

	   Black Stone: 2,2; 3,2; 5,2; 6,2;

	   type 'quit' or 'x,y': 1,5
	   7
	   6
	   5 W
	   4   W
	   3     W
	   2   B B W B B
	   1
	   X 1 2 3 4 5 6 7

	   White Stone: 1,5; 2,4; 3,3; 4,2;

	   type 'quit' or 'x,y': 7,7
	   7             B
	   6
	   5 W
	   4   W
	   3     W
	   2   B B W B B
	   1
	   X 1 2 3 4 5 6 7

	   Black Stone: 2,2; 3,2; 5,2; 6,2; 7,7;

	   type 'quit' or 'x,y': 5,1
	   7             B
	   6
	   5 W
	   4   W
	   3     W
	   2   B B W B B
	   1         W
	   X 1 2 3 4 5 6 7

	   White Stone: 1,5; 2,4; 3,3; 4,2; 5,1;

	   White Stone wins
	=> 0
	(CORRECT)
	
	- lab3 Gomoku 5 4 (two additional arguments, game ended draw)
	=> 5
	   4
	   3
	   2
	   1
	   X 1 2 3 4 5

	   type 'quit' or 'x,y': 3,3
	   5
	   4
	   3     B
	   2
	   1
	   X 1 2 3 4 5

	   Black Stone: 3,3;

	   type 'quit' or 'x,y': 1,1
	   5
	   4
	   3     B
	   2
	   1 W
	   X 1 2 3 4 5

	   White Stone: 1,1;

	   type 'quit' or 'x,y': 3,1
	   5
	   4
	   3     B
	   2
	   1 W   B
	   X 1 2 3 4 5

	   Black Stone: 3,1; 3,3;

	   type 'quit' or 'x,y': 3,2
	   5
	   4
	   3     B
	   2     W
	   1 W   B
	   X 1 2 3 4 5

	   White Stone: 1,1; 3,2;

	   type 'quit' or 'x,y': 5,1
	   5
	   4
	   3     B
	   2     W
	   1 W   B   B
	   X 1 2 3 4 5

	   Black Stone: 3,1; 3,3; 5,1;

	   type 'quit' or 'x,y': 1,5
	   5 W
	   4
	   3     B
	   2     W
	   1 W   B   B
	   X 1 2 3 4 5

	   White Stone: 1,1; 1,5; 3,2;

	   type 'quit' or 'x,y': 1,3
	   5 W
	   4
	   3 B   B
	   2     W
	   1 W   B   B
	   X 1 2 3 4 5

       Black Stone: 1,3; 3,1; 3,3; 5,1;

	   type 'quit' or 'x,y': 4,3
	   5 W
	   4
	   3 B   B W
	   2     W
	   1 W   B   B
	   X 1 2 3 4 5

	   White Stone: 1,1; 1,5; 3,2; 4,3;

	   type 'quit' or 'x,y': 2,1
	   5 W
	   4
	   3 B   B W
	   2     W
	   1 W B B   B
	   X 1 2 3 4 5

	   Black Stone: 1,3; 2,1; 3,1; 3,3; 5,1;

	   type 'quit' or 'x,y': 4,1
	   5 W
	   4
	   3 B   B W
	   2     W
	   1 W B B W B
	   X 1 2 3 4 5

	   White Stone: 1,1; 1,5; 3,2; 4,1; 4,3;

	   type 'quit' or 'x,y': 5,4
	   5 W
	   4         B
	   3 B   B W
	   2     W
	   1 W B B W B
	   X 1 2 3 4 5

	   Black Stone: 1,3; 2,1; 3,1; 3,3; 5,1; 5,4;

	   type 'quit' or 'x,y': 5,2
	   5 W
	   4         B
	   3 B   B W
	   2     W   W
	   1 W B B W B
	   X 1 2 3 4 5

	   White Stone: 1,1; 1,5; 3,2; 4,1; 4,3; 5,2;

	   type 'quit' or 'x,y': 4,2
	   5 W
	   4         B
	   3 B   B W
	   2     W B W
	   1 W B B W B
	   X 1 2 3 4 5

	   Black Stone: 1,3; 2,1; 3,1; 3,3; 4,2; 5,1; 5,4;

	   type 'quit' or 'x,y': 4,5
	   5 W     W
	   4         B
	   3 B   B W
	   2     W B W
	   1 W B B W B
	   X 1 2 3 4 5

	   White Stone: 1,1; 1,5; 3,2; 4,1; 4,3; 4,5; 5,2;

	   type 'quit' or 'x,y': 3,5
	   5 W   B W
	   4         B
	   3 B   B W
	   2     W B W
	   1 W B B W B
	   X 1 2 3 4 5

	   Black Stone: 1,3; 2,1; 3,1; 3,3; 3,5; 4,2; 5,1; 5,4;

	   type 'quit' or 'x,y': 2,4
	   5 W   B W
	   4   W     B
	   3 B   B W
	   2     W B W
	   1 W B B W B
	   X 1 2 3 4 5

	   White Stone: 1,1; 1,5; 2,4; 3,2; 4,1; 4,3; 4,5; 5,2;

	   type 'quit' or 'x,y': 2,3
	   5 W   B W
	   4   W     B
	   3 B B B W
	   2     W B W
	   1 W B B W B
	   X 1 2 3 4 5

	   Black Stone: 1,3; 2,1; 2,3; 3,1; 3,3; 3,5; 4,2; 5,1; 5,4;

	   game ended draw: 17 turn(s) played
	=> 3
	(CORRECT)
