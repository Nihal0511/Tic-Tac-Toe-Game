#include<bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int ch;
int row,column;
char turn = 'X';
bool draw = false;

void board_display(){

    //Rander Game Board LAYOUT
	cout<<endl;
    cout<<"PLAYER - 1 [X]  PLAYER - 2 [O]"<<endl;
    cout<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<endl;
    cout<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<endl;
    cout<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<endl;
}

//Function to get the player input and update the board

void player_turn(){
    if(turn == 'X'){
        cout<<"Player - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"Player - 2 [O] turn : ";
}
    cin>> ch;

    switch(ch){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'X';
        turn = 'O';
    }
	else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'O';
        turn = 'X';
    }
	else
	 {	
        cout<<"Please choose empty box"<<endl;
        player_turn();
    }
   // board_display();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gaming()
{
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    {
    for(int j=0; j<3; j++)
    {
	if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;
	}
	}

    //Checking the if game already drawn
    draw = true;
    return false;
}


int main()
{
    cout<<"T I C -- T A C -- T O E -- G A M E"<<endl;
    cout<<"THE GAME IS DESIGNED FOR 2 PLAYERS"<<endl;
	   while(gaming()){
        board_display();
        player_turn();
        gaming();
    }
    if(turn == 'X' && draw == false){
        cout<<"Congratulations! O has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"Congratulations! X has won the game";
    }
    else
    cout<<"GAME DRAW!!!\n";
    return 0;
} 
