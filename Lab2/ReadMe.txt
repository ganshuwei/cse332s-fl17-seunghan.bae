SEUNGHAN BAE (423311) - seunghan.bae@wustl.edu
LAB 2: create a tic-tac-toe game

===== File List =============================================================
Lab2.cpp: main application source file
	- int usageMsg(char * c1, char * c2, char * c3): prints out the usage message

Lab2.h: main application header file

GamePieces.cpp: source file for game pieces
	- string enumToString(piece_color p): converts the color enum into string
	- piece_color stringToEnum(string s): converts the string into color enum
	- game_pieces::game_pieces(piece_color p, string name, string display): declares and defines a game_pieces object

GamePieces.h: header file for game pieces

TicTacToe.cpp: source file for TicTacToeGame class
	- ostream & operator<<(ostream & os, const TicTacToeGame & game): prints out the board and game pieces
	- TicTacToeGame::TicTacToeGame(): default constructor for the TicTacToeGame class
	- TicTacToeGame::TicTacToeGame(const TicTacToeGame & game): copy constructor for the TicTacToeGame class
	- TicTacToeGame::TicTacToeGame(bool autoP): constructor made for extra credit portion
	- bool TicTacToeGame::done(): returns true when either of the players won
	- bool TicTacToeGame::draw(): returns true when the game ended draw
	- int TicTacToeGame::prompt(unsigned int & n1, unsigned int & n2): prompts player to type either 'quit' or 'x,y'
	- int TicTacToeGame::turn(): receives input for each player's turn and prints out the board
	- int TicTacToeGame::play(): plays the game
	- [Extra Credit] unsigned int TicTacToeGame::auto_player(): determines auto_player's next move and returns the vector index of the selection

TicTacToe.h: header file for TicTacToeGame class

===== Encountered Errors & Warnings =========================================
(1) C4018: '<': signed/unsigned mismatch (in some 'for' loops)
	=> changed the variables' types from int to unsigned int
	(SOLVED)

(2) C4715: 'TicTacToeGame::prompt': not all control paths return a value
	=> declare an int variable to save the return value and return at the end of the method
	(SOLVED)

(3) address of the board, instead of the board itself, is printed
	=> 'cout << *this << endl;' instead of 'cout << this << endl;'
	(SOLVED)

===== Sample Cases & Results ================================================
(1) lab2 (only 1 command line argument)
	=> usage: lab2 TicTacToe
	=> 1
	(CORRECT)

(2) lab2 Tic Tac Toe (too many command line arguments)
	=> usage: lab2 TicTacToe
	=> 1
	(CORRECT)

(3) lab2 TicTac (wrong game name)
	=> usage: lab2 TicTacToe
	=> 1
	(CORRECT)

(4) lab2 TicTacToe (user quit)
	=> 4
	   3
	   2
	   1
	   0
	    0 1 2 3 4
	
	   type 'quit' or 'x,y': 2,2
	   4
	   3
	   2    X
	   1
	   0
	    0 1 2 3 4
	   
	   Player X: 2,2
	   
	   type 'quit' or 'x,y': 1,1
	   4
	   3
	   2    X
	   1  O
	   0
	    0 1 2 3 4
		
	   Player O: 1,1
	   
	   type 'quit' or 'x,y': quit
	   user quit: 2 turn(s) played
	=> 2
	(CORRECT)

(5) lab2 TicTacToe (game ended draw)
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
	   1  X
	   0
	    0 1 2 3 4
		
	   Player X: 1,1

	   type 'quit' or 'x,y': 2,1
	   4
	   3
	   2
	   1  X O
	   0
	    0 1 2 3 4

	   Player O: 2,1

	   type 'quit' or 'x,y': 3,1
	   4
	   3
	   2
	   1  X O X
	   0
	    0 1 2 3 4

	   Player X: 3,1

	   type 'quit' or 'x,y': 1,3
	   4
	   3  O
	   2
	   1  X O X
	   0
	    0 1 2 3 4

	   Player O: 1,3

	   type 'quit' or 'x,y': 2,3
	   4
	   3  O X
	   2
	   1  X O X
	   0
	    0 1 2 3 4

	   Player X: 2,3

	   type 'quit' or 'x,y': 3,3
	   4
	   3  O X O
	   2
	   1  X O X
	   0
	    0 1 2 3 4

	   Player O: 3,3

	   type 'quit' or 'x,y': 2,2
	   4
	   3  O X O
	   2    X
	   1  X O X
	   0
	    0 1 2 3 4

	   Player X: 2,2

	   type 'quit' or 'x,y': 1,2
	   4
	   3  O X O
	   2  O X
	   1  X O X
	   0
	    0 1 2 3 4

	   Player O: 1,2

	   type 'quit' or 'x,y': 1,1 (intentionally invalid input)
	   type 'quit' or 'x,y': 3,2
	   4
	   3  O X O
	   2  O X X
	   1  X O X
	   0
	    0 1 2 3 4

	   Player X: 3,2

	   game ended draw: 9 turn(s) played
	=> 3
	(CORRECT)

(6) lab2 TicTacToe (success case)
	=> 4
	   3
	   2
	   1
	   0
	    0 1 2 3 4

	   type 'quit' or 'x,y': 2,2
	   4
	   3
	   2    X
	   1
	   0
	    0 1 2 3 4

	   Player X: 2,2

	   type 'quit' or 'x,y': 1,1
	   4
	   3
	   2    X
	   1  O
	   0
	    0 1 2 3 4

	   Player O: 1,1

	   type 'quit' or 'x,y': 2,1
	   4
	   3
	   2    X
	   1  O X
	   0
	    0 1 2 3 4

	   Player X: 2,1

	   type 'quit' or 'x,y': 3,11 (intentionally invalid input)
	   type 'quit' or 'x,y': stop (intentionally invalid input)
	   type 'quit' or 'x,y': 0,0 (intentionally invalid input)
	   type 'quit' or 'x,y': 3,3
	   4
	   3      O
	   2    X
	   1  O X
	   0
	    0 1 2 3 4

	   Player O: 3,3

	   type 'quit' or 'x,y': 2,3
	   4
	   3    X O
	   2    X
	   1  O X
	   0
	    0 1 2 3 4

	   Player X: 2,3

	   Player X wins
	=> 0
	(CORRECT)

===== Extra Credit ==========================================================
(1) Due to the way TicTacToeGame is programmed, auto_player will always be 'Player O'.
(2) We will calculate the "priority score" of each of the 9 cells in the TicTacToeGame board.
(3) When auto_player() is called, all the scores begin with 0.
(3) Evaluate each of the 8 possible 3-piece lines within the board. (three vertical, three horizontal, two diagonal)
(4) Identify each line's current situation, which would be one of the following:
	- Two 'O's and one empty (highest priority)
	- Two 'X's and one empty
	- One 'O', one 'X', and one empty
	- One 'O' and two empty
	- One 'X' and two empty
	- Three empty (lowest priority).
(5) Based on the line's situation and its priority, certain amount of score is added to all 3 cells in the line.
	(higher priority means higher score added)
(6) After going through all 8 lines, reduce the scores of already filled cells back to 0, so that they are not selected.
(7) Select the cell with the highest "priority score".
(8) auto_player() returns the index of the corresponding cell within the game_pieces vector.
(9) turn() receives the returned index and fills the matching cell with 'O'.
(10) Additional minor modifications were made to accommodate the extra credit features within the program.
(11) Test results:
	- lab2 TicTacToe auto_player
	=> 4
	   3
	   2
	   1
	   0
	    0 1 2 3 4

	   type 'quit' or 'x,y': 2,2
	   4
	   3
	   2    X
	   1
	   0
	    0 1 2 3 4

	   Player X: 2,2

	   auto_player's turn:
	   4
	   3      O
	   2    X
	   1
	   0
	    0 1 2 3 4

	   Player O: 3,3
	   
	   type 'quit' or 'x,y': 2,1
	   4
	   3      O
	   2    X
	   1    X
	   0
	    0 1 2 3 4

	   Player X: 2,1
	   
	   auto_player's turn:
	   4
	   3    O O
	   2    X
	   1    X
	   0
	    0 1 2 3 4

	   Player O: 2,3

	   type 'quit' or 'x,y': 1,3
	   4
	   3  X O O
	   2    X
	   1    X
	   0
	    0 1 2 3 4

	   Player X: 1,3
	   
	   auto_player's turn:
	   4
	   3  X O O
	   2    X
	   1    X O
	   0
	    0 1 2 3 4

	   Player O: 3,1

	   type 'quit' or 'x,y': 3,2
	   4
	   3  X O O
	   2    X X
	   1    X O
	   0
	    0 1 2 3 4

	   Player X: 3,2

	   auto_player's turn:
	   4
	   3  X O O
	   2  O X X
	   1    X O
	   0
	    0 1 2 3 4

	   Player O: 1,2

	   type 'quit' or 'x,y': 1,1
	   4
	   3  X O O
	   2  O X X
	   1  X X O
	   0
	    0 1 2 3 4

	   Player X: 1,1

	   game ended draw: 9 turn(s) played
