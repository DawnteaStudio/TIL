#include "minesweeper.h"

void minesweeper( string mines, string command, string output )
{	
	int count, crack_x = 0, crack_y = 0;
	char board[SIZE][SIZE];
	initBoard(board,mines);
	initTouched(board,  command, count, crack_x, crack_y);

	cout << "Spaces touched: " << count << endl;
}

void initBoard( char board[SIZE][SIZE], string file )
{	
	ifstream files;
	string line;
	files.open (file);
	char board[SIZE][SIZE]{};
        for(int i = 0; i < SIZE; i++){
            getline(files, line);
            for(int j = 0; j < 8; j++){
                board[i][j] = line[j];
                }
        }
	files.close();

}

void displayBoard( string output, char board[SIZE][SIZE], int& count, int& cx, int& cy )
{
		ofstream out;
		out.open(output);
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

void initTouched( char touchedBoard[SIZE][SIZE], string command, int& count, int& cx , int& cy){
	ifstream files;
	files.open(command);
	string touch;
	getline(files, touch);
	cout<<"Command: " << touch<<endl;
	count = 0;

	while(files){
		getline(files, touch);
		cout<<"Command: " << touch<<endl;
		if(touch != "display"){
			count++;
			int x = (int)touch[6];
			int y = (int)touch[8];
			if(touchedBoard[x][y] == '*'){
				cx = x;
				cy = y;
				cout<<"Game Over"<<endl;
				cout<<"~~~~~~~~~"<<endl;
				cout<<"Final Board"<<endl;
				break;
			}
			else{
				touchBoard(touchedBoard, x, y);
			}

		}
	}
	files.close();
}

void touchBoard( char board[][SIZE], int w, int h)
{
	{
    int x = w - 1;
    int y = h - 1;
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

    board[w][h] = char(sum + 48);

    // for (int row = 0; row < SIZE; row++) 
    // {
    //     for (int col = 0; col < SIZE; col++) 
    //     {
    //         cout << board[row][col];
    //     }

    //     cout << endl;
    // }
}
}


// char **_load_(string file){
// 	ifstream files;
// 	string line;
// 	files.open (file);
// 	char board[SIZE][SIZE]{};
//             for(int i = 0; i < SIZE; i++){
//                 getline(files, line);
//                 for(int j = 0; j < 8; j++){
//                     board[i][j] = line[j];
//                     cout << board[i][j];
//                     }
//                 cout << endl;
//         }
//     return (char**)board;

// }

int main() {
	cout << "Testing minesweeper" << endl;
	minesweeper(".\\test1board.txt",".\\MS_Commands\\test1commands.txt", "test1_output_mine.txt");
	// minesweeper(".\\test1board.txt","\\MS_Commands\\test2commands.txt", "test2_output_mine.txt");
	// minesweeper(".\\test1board.txt",".\\MS_Commands\\test3commands.txt", "test3_output_mine.txt");
	// minesweeper(".\\test1board.txt",".\\MS_Commands\\test4commands.txt", "test4_output_mine.txt");
	// minesweeper(".\\test1board.txt",".\\MS_Commands\\test5commands.txt", "test5_output_mine.txt");
	// minesweeper(".\\test1board.txt",".\\MS_Commands\\test6commands.txt", "test6_output_mine.txt");
	// minesweeper(".\\test1board.txt",".\\MS_Commands\\test7commands.txt", "test7_output_mine.txt");
	// minesweeper(".\\test1board.txt",".\\MS_Commands\\test8commands.txt", "test8_output_mine.txt");
	// minesweeper(".\\test1board.txt",".\\MS_Commands\\test9commands.txt", "test9_output_mine.txt");
	// minesweeper(".\\test1board.txt",".\\MS_Commands\\test10commands.txt", "test10_output_mine.txt");

	return 0;
}
	