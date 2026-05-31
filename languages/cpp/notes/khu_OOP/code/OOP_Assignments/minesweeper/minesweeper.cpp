#include "minesweeper.h"


void minesweeper(string command, string output )
{	
	int count = 0, crack_x = 0, crack_y = 0;
	char board[SIZE][SIZE];
	initBoard(board,command);
	// initTouched(board,  command, count, crack_x, crack_y);
	displayBoard(command, output, board, count, crack_x, crack_y );

}

// touch
void touchBoard( char board[SIZE][SIZE], int x, int y)
{
	{

    int sum = 0;

    if (board[x][y] == '.') 
    {
        for (int a = (x - 1); a <= (x + 1); a++) 
        {
            if (a < 0 || a >= SIZE)
            {
                continue;
            }

            for (int g = (y - 1); g <= (y + 1); g++) 
            {
                if (g < 0 || g >= SIZE)
                {
                    continue;
                }

                if (board[a][g] == '*')
                {
                    sum++;
                }
            }
        }
    }

    board[x][y] = char(sum + 48);
}
}

// load
void initBoard( char board[SIZE][SIZE], string file )
{	
	ifstream files;
	ifstream board_file;
	string line, filename, boardname;
	files.open (file);
	getline(files, filename);
			if (!files){
			cout << "Error1" << endl;
			exit(100);
		}
	if(file.length() == 17){
		boardname = filename.substr(5, 14);
	}
	else if(file.length() == 18){
		boardname = filename.substr(5, 15);
	}

	board_file.open(boardname);
		if (!board_file){
			cout << "Error2" << endl;
			exit(100);
		}

        for(int i = 0; i < SIZE; i++){
            getline(board_file, line);
            for(int j = 0; j < 8; j++){
                board[i][j] = line[j];
                }
        }
	files.close();
	board_file.close();

}

//display
void displayBoard(string command, string output, char board[SIZE][SIZE], int& count, int& cx, int& cy )
{		
		// initBoard(board,command );
		bool over = true;
		int x, y, firstx,firsty;
		ofstream out;
		out.open(output);
		ifstream files;
		ifstream file2;
		files.open(command);
		string touch;
		getline(files, touch);
			if (!files){
			cout << "Error3" << endl;
			exit(100);
		}
			if (!out){
			cout << "Error4" << endl;
			exit(100);
		}


		out << "Command: " << touch << endl;


			getline(files, touch);
			out<<"Command: " << touch<<endl;
				firstx = touch[6] - '0';
				firsty = touch[8] - '0';
			if(touch[0] == 't' && board[firstx-1][firsty-1] == '*'){
				count++;
				cx = firstx-1;
				cy = firsty-1;
				out<<"Game Over"<<endl;
				out<<"~~~~~~~~~"<<endl;
				out<<"Final Board"<<endl;
				for(int i = 0; i < SIZE; i++){
					for(int j=0; j < SIZE; j++){
						if(board[i][j]=='*'){
							board[i][j]='@';
								if(count < 54){
									board[cx][cy] = '*';
								}

						}		
					}
				}
				for(int i = 0; i < SIZE; i++){
					for(int j = 0; j<SIZE; j++){
						out << board[i][j];
					}
					out << endl;
				}
				out << endl;
			}

			else if(touch[0] == 't'){
				count++;
					while(getline(files, touch)){
					out<<"Command: " << touch <<endl;
					count++;
						x = touch[6] - '0';
						y = touch[8] - '0';
					if(board[x-1][y-1] == '*'){
						over = false;
						break;
					}

					}
					if(over == true ){
						out<<"Game Over"<<endl;
						out<<"~~~~~~~~~"<<endl;
						out<<"Final Board"<<endl;
					}
					file2.open(command);
					getline(file2, touch);

					for(int i = 0; i < count ; i++){
						getline(file2, touch);

					int x = touch[6] - '0';
					int y = touch[8] - '0';
					if(board[x-1][y-1] == '*'){
						cx = x-1;
						cy = y-1;
						out<<"Game Over"<<endl;
						out<<"~~~~~~~~~"<<endl;
						out<<"Final Board"<<endl;
					}
					else{
					touchBoard(board, x-1, y-1);
					}
				}
				for(int i = 0; i < SIZE; i++){
					for(int j=0; j < SIZE; j++){
						if(board[i][j]=='*'){
						board[i][j]='@';
							if(over == false){
								board[cx][cy] = '*';
							}

						}		
					}
				}
			for(int i = 0; i < SIZE; i++){
				for(int j = 0; j<SIZE; j++){
					out << board[i][j];
				}
				out << endl;
			}
			out << endl;
		}
			if (touch[0] == 'd'){
				for(int i = 0; i < SIZE; i++){
					for(int j = 0 ; j < SIZE; j++){
						out <<'.';
					}
					out << '\n';
				}
				out << '\n';
				out<<"Game Over"<<endl;
				out<<"~~~~~~~~~"<<endl;
				out<<"Final Board"<<endl;
				for(int i = 0; i < SIZE; i++){
					for(int j=0; j < SIZE; j++){
						if(board[i][j]=='*'){
						board[i][j]='@';
						}
					}		
				}
				for(int i = 0; i < SIZE; i++){
					for(int j = 0; j<SIZE; j++){
						out << board[i][j];
					}
					out << endl;
				}
				out << endl;
			}
	

		out << "Spaces touched: " << count << endl;
		out.close();
		files.close();
		file2.close();
}

//here

int main() {
	cout << "Testing minesweeper" << endl;
	minesweeper("test1commands.txt", "test1_output_mine.txt");
	minesweeper("test2commands.txt", "test2_output_mine.txt");
	minesweeper("test3commands.txt", "test3_output_mine.txt");
	minesweeper("test4commands.txt", "test4_output_mine.txt");
	minesweeper("test5commands.txt", "test5_output_mine.txt");
	minesweeper("test6commands.txt", "test6_output_mine.txt");
	minesweeper("test7commands.txt", "test7_output_mine.txt");
	minesweeper("test8commands.txt", "test8_output_mine.txt");
	minesweeper("test9commands.txt", "test9_output_mine.txt");
	minesweeper("test10commands.txt", "test10_output_mine.txt");

	return 0;
}
	