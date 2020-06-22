#include <iostream>

using namespace std;

char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
bool drawgame = false;
int row, column;
int choice;


void table();
bool game_over();
void player_turn();

int main()
{
    while(game_over())
    {

        table();

        player_turn();

        game_over();
    }

    if(turn == '0' && drawgame == false)
        cout<<"Player1 [X] WON!!\n\nCONGRATS!!\n";

    else if(turn == 'X' && drawgame == false)
        cout << "Player2 [0] WON!!\n\nCONGRATS!!\n";
    else
        cout << "DRAW GAME!\n";

    return 0;
}

void table()
{
    cout << "\n\n     T i c - T a c - T o e   G a m e \n" << endl ;
    cout << "\tPLAYER1[X]\n\tPLAYER2[O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "\t\t     |     |     \n";
}

bool game_over()
{
    //win
    for (int i=0; i<3; ++i)
        if(((board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) || ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i])))
            return false;

    if (((board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) || ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0])))
        return false;
    //spare
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if(board[i][j] != 'X' && board[i][j] != '0')
                return true;
    //tie
    drawgame = true;
    return false;
}

void player_turn()
{

    if (turn == 'X')
        cout << "\n\t Player1 [X] turn:\n";

    if (turn == '0')
        cout << "\n\t Player2 [0] turn:\n";
    cin >> choice;

    switch(choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout<<"Invalid choice\n";
    }

    if(turn == 'X'&& board[row][column]!='X'&& board[row][column]!='0')
    {
        board[row][column]='X';
        turn='0';
    }
    else if(turn == '0'&& board[row][column]!='X'&& board[row][column]!='0')
    {
        board[row][column]='0';
        turn='X';
    }
    else
    {
        cout<<"Already full!\nTry again!\n\n";
        player_turn();
    }
    table();
}
