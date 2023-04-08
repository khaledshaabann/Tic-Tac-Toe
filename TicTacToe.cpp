#include <iostream>
using namespace std;
#include <cstdlib>
#include <Windows.h>

void verifyInput(char current_player, char board[])
{
    ask:
        int position;
        if(current_player == 'X'){
            cout << "Player 1, choose a position:" << endl;
            cin >> position;
        }
        else if(current_player == 'O'){
            cout << "Player 2, choose a position:" << endl;
            cin >> position;
        }
        if(position >9){
            cout << "Number too big, please try again:"<< endl;
            goto ask;
        }
        else if(position < 1)
        {
            cout << "Number too small, please try again:" << endl;
            goto ask;
        }
        else if(board[position -1] == 'X' || board[position-1] == 'O'){
            cout << "This position is already filled, please try again:" << endl;
            goto ask;
        }
        else{
            board[position-1] = current_player;
        }

}
void drawBoard(char board[], int player1_score, int player2_score)
{
    cout << "         Tic Tac Toe Game" << endl;
    cout << " Player 1: X          Player 2: O" << endl;
    cout << " Score: " << player1_score << "             Score: " << player2_score << endl;
    cout << endl;
    cout << "            " << board[0] << " " << "|" << " " << board[1] << " " << "|" << " " << board[2] << " " << endl;
    cout << "           -----------" << endl;
    cout << "            " << board[3] << " " << "|" << " " << board[4] << " " << "|" << " " << board[5] << " " << endl;
    cout << "           -----------" << endl;
    cout << "            " << board[6] << " " << "|" << " " << board[7] << " " << "|" << " " << board[8] << " " << endl;
    cout << endl;
}
int winner(char board[])
{
    //Horizontal check
    if(board[0] == board[1] && board[1] == board[2])
    {
        if(board[0] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(board[3] == board[4] && board[4] == board[5])
    {
        if(board[3] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(board[6] == board[7] && board[7] == board[8])
    {
        if(board[6] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    //Vertical check
    else if(board[0] == board[3] && board[3] == board[6])
    {
        if(board[0] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(board[1] == board[4] && board[4] == board[7])
    {
        if(board[1] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(board[2] == board[5] && board[5] == board[8])
    {
        if(board[2] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    //Diagonal check
    else if(board[0] == board[4] && board[4] == board[8])
    {
        if(board[0] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(board[2] == board[4] && board[4] == board[6])
    {
        if(board[2] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }
}
void refresh()
{
    system("cls");
}



int main()
{
    start:
        cout << endl;
        cout << "Welcome to Tic Tac Toe." << " Player 1's symbol is 'X', and Player 2's is 'O'" << endl;
        cout << endl;
        cout << "Good luck and Have Fun!" << endl;
        cout << endl;
        cout << "************************************************************************************************************************" << endl;
        Sleep(5000);
        refresh();
        cout << endl;
        cout << endl;
        int player1_score = 0;
        int player2_score = 0;
    gameplay:
        char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char current_player = 'X';
        for(int i = 0; i < 9; i++){
            drawBoard(board, player1_score, player2_score);
            verifyInput(current_player, board);
            if(winner(board) == 1){
                player1_score+=1;
                cout << endl;
                cout << endl;
                cout << "********" << "Player 1 Won!" << "********" << endl;
                cout << endl;
                cout << endl;
                Sleep(800);
                refresh();
                goto gameplay;
            }
            else if(winner(board) == 2){
                player2_score+=1;
                cout << endl;
                cout << endl;
                cout << "********" << "Player 2 Won!" << "********" << endl;
                cout << endl;
                cout << endl;
                Sleep(800);
                refresh();
                goto gameplay;
            }
            else{
                if(current_player == 'X'){
            current_player = 'O';
        }
                else{
            current_player = 'X';
        }
            }
        refresh();
    }
        cout << "It is a Tie!" << endl;
        Sleep(800);
        refresh();
        goto gameplay;
}
