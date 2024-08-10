#include <iostream>
#include <vector>
using namespace std;

string n1;
string n2;
int row ; 
int col;
char token ;
vector<vector<char>> board( 3 , vector<char> (3));


void grid ( vector<vector<char>> &board){
    for ( int i=0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++){
            board[i][j]=' ';
        }
    }
}

void displayGrid ( vector<vector<char>> &board ){
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++ ){
            cout << " " << board[i][j]<< "  ";
            if ( j<2 ) cout << "|";
        }
        cout<< endl;
        if(i<2 ) cout << "----|----|----"<<endl;
    }
}


bool checkValidMove( vector<vector<char>> &board , int row , int col){
    
    return row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ' ;
    
}
void playerDetails (){   
  cout << "GAME STARTS !"<< endl;
    cout<<endl;
    cout<< "Enter your move ( row and col ) For example: 0 0 for the top left corner : " << endl;
    cin>>row>>col;

    while ( checkValidMove ( board, row , col)){
        if(token == 'X' && board[row][col]== ' '){
            board[row][col]='X';
            token = '0';
            displayGrid(board);
        }
        
        if(token == '0' && board[row][col]== ' '){
            board[row][col]='0';
            token = 'X';
            displayGrid(board);
        } 
    } 
}

void movePlayer (char token){
    cout << "Enter your move (row and col)  For example: 0 0 for the top left corner : ";
    cin >> row >> col;
    while (!checkValidMove(board, row, col)){
        cout << "Your move is invalid. Enter the move(row and col) again.  ";
        cin >> row >> col;
    }
    cout<<endl;
    board[row][col] = token;
    displayGrid(board);
}

bool checkWin ( vector<vector<char>>& board , char token){
    
    for (int i=0 ; i<3 ; i++){
        if (token == board[i][0] && board[i][0]== board[i][1] && board[i][0]== board[i][2] || token== board[0][i] && board[0][i] == board [1][i] && board[0][i]==board[2][i]){
            return true;
        }
    }
    
    if(token == board[0][0] && board[0][0]==board[2][2] && board[0][0]==board[1][1] || token==board[0][2]  && board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return true;
    }
    
    return false;
    
}


bool checkDraw (vector<vector<char>>&board){
    for(int i=0 ; i<3 ; i++){
        for(int j=0; j<3;j++){
            if(board[i][j] ==' '){
                return false;
            }
        }
    }
    return true ;
}

void switchPlayer (char &token ){
    token = (token=='X') ? '0' : 'X';
}

int main() {
    
    grid(board);
    displayGrid(board);
    
    cout << "Enter first player name : "<< endl;
    getline ( cin , n1);
    cout << "Enter second player name : "<<endl;
    getline(cin, n2);
    cout<<endl;
    
    
    cout << n1 << " will play first. "<< endl ;
    cout << n1 <<" will use X "<< endl;
    token='X' ;  
    cout<< n2 <<" will use 0"<<endl;
    cout<<endl;
    playerDetails();
     
    bool win = false;
    bool draw = false;

    while (!win && !draw) {
        movePlayer(token);
        win = checkWin(board, token);
        if (win) {
            cout << "Player " << (token == 'X' ? n1 : n2) << " wins! Congratulations !! " << endl;
        } else {
            draw = checkDraw(board);
            if (draw) {
                cout << "The game is a Draw " << endl;
            } else {
                switchPlayer(token);
            }
        }
    }
    return 0;
}
