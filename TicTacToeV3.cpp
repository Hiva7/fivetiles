#include<iostream>
#include<limits>
using namespace std;
//check for correct inputs
void CheckInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//tutorial
void HowToPlay(){
    cout<<"\nEach player(O for player one and X for player two) takes turn placing tile."<<endl;
    cout<<"Tile position is determined by two inputs, horizontal(left and right) and vertical(up and down) position."<<endl;
    cout<<"Whoever gets 5 in a row(horizontal, vertical and diagonal) first wins.\n"<<endl;
}

//the game
void TicTacToe(){
    int column=16; //change this value to change the number of columns
    int row=12; //chnage this value to change the number of rows
    int boardSize=(column*row)+column;
    bool checkO[69420]={0};
    bool checkX[69420]={0};
    int vertical;
    int horizontal;
    int turn=0;
    bool finish=0;
    //player input
    while(true){
        if(turn%2==0){
            while(true){
                cout<<"Enter horizontal position(O): ";
                cin>>horizontal;
                CheckInput();
                cout<<"Enter vertical position(O): ";
                cin>>vertical;
                CheckInput();
                if((horizontal>0&&horizontal<=column)&&(vertical>0&&vertical<=row)){//can't place tile with position lower than 0 or higher than column/row
                    if(horizontal+(vertical*column)>0&&horizontal+(vertical*column)<=boardSize){//can't place tile with position lower than 0 or higher than boardsize 
                        if(checkO[horizontal+(vertical*column)]==0&&checkX[horizontal+(vertical*column)]==0){//check if position has already been taken
                            checkO[horizontal+(vertical*column)]=1;
                            break;
                        }
                        else{
                            cout<<"Tile already taken, please try again."<<endl;
                        }
                    }
                    else{
                        cout<<"Out of board!"<<endl;
                    }
                }
                else{
                    cout<<"Out of board!"<<endl;
                }
            }
        }
        else if(turn%2==1){
            while(true){
                cout<<"Enter horizontal position(X): ";
                cin>>horizontal;
                CheckInput();
                cout<<"Enter vertical position(X): ";
                cin>>vertical;
                CheckInput();
                if((horizontal>0&&horizontal<=column)&&(vertical>0&&vertical<=row)){
                    if(horizontal+(vertical*column)>0&&horizontal+(vertical*column)<=boardSize){
                        if(checkO[horizontal+(vertical*column)]==0&&checkX[horizontal+(vertical*column)]==0){
                            checkX[horizontal+(vertical*column)]=1;
                            break;
                        }
                        else{
                            cout<<"Tile already taken, please try again."<<endl;
                        }
                    }
                    else{
                        cout<<"Out of board!"<<endl;
                    }
                }
                else{
                    cout<<"Out of board!"<<endl;
                }
            }
        }
        system("cls");
        //draw the board
        for(int i=1; i<=boardSize; i++){
            if(checkO[i]==1||checkX[i]==1){
                if(checkO[i]==1){
                    cout<<" O |";
                }
                else if(checkX[i]==1){
                    cout<<" X |";
                }
            }
            else{
                if(i>column){
                    cout<<"   |";
                }
            }
            //draw the first row
            if(i==1){
                cout<<"  ";
                for(int k=1; k<=column; k++){
                    cout<<" |";
                    if(k<10){
                        cout<<" ";
                    }
                    cout<<k;
                    if(k==column){
                        cout<<" |";
                    }
                }
            }
            if(i%column==0){
                cout<<endl;
                for(int m=0; m<=column; m++){
                    cout<<"----";
                }
                cout<<endl;
                //draw the first column
                if(i/column<=row){
                    cout<<(i/column);
                    if(i/column<10){
                        cout<<" ";
                    }
                    cout<<" |";
                }
            }
        }
        turn++;
        //win conditions
        vertical=0;
        for(int i=0; i<=row; i++){
            vertical++;
            horizontal=0;
            if(finish==1){
                break;
            }
            for(int j=0; j<column; j++){
                horizontal++;
                //check if O won
                if((checkO[(horizontal)+(vertical*column)]==1)&&(checkO[(horizontal)+((vertical+1)*column)]==1)&&(checkO[(horizontal)+((vertical+2)*column)]==1)&&(checkO[(horizontal)+((vertical+3)*column)]==1)&&(checkO[horizontal+((vertical+4)*column)]==1)
                )//down
                {
                    cout<<"O wins."<<endl;
                    finish=1;
                    break;
                }
                if(horizontal+4<=column){//check if fifth tile is off the board to the right
                    if(((checkO[(horizontal)+(vertical*column)]==1)&&(checkO[(horizontal+1)+(vertical*column)]==1)&&(checkO[(horizontal+2)+(vertical*column)]==1)&&(checkO[(horizontal+3)+(vertical*column)]==1)&&(checkO[(horizontal+4)+(vertical*column)]==1)
                    )||//right
                    ((checkO[(horizontal)+(vertical*column)]==1)&&(checkO[(horizontal+1)+((vertical+1)*column)]==1)&&(checkO[(horizontal+2)+((vertical+2)*column)]==1)&&(checkO[(horizontal+3)+((vertical+3)*column)]==1)&&(checkO[(horizontal+4)+((vertical+4)*column)]==1)
                    ))//down right
                    {
                        cout<<"O wins."<<endl;
                        finish=1;
                        break;
                    }
                    if((horizontal+4)+((vertical-4)*column)>column){//check if fifth tile is off the board to the top
                        if((checkO[(horizontal)+(vertical*column)]==1)&&(checkO[(horizontal+1)+((vertical-1)*column)]==1)&&(checkO[(horizontal+2)+((vertical-2)*column)]==1)&&(checkO[(horizontal+3)+((vertical-3)*column)]==1)&&(checkO[(horizontal+4)+((vertical-4)*column)]==1))
                        {//up right
                            cout<<"O wins."<<endl;
                            finish=1;
                            break;
                        }
                    }
                }
                
                
                //check if X won
                if((checkX[(horizontal)+(vertical*column)]==1)&&(checkX[(horizontal)+((vertical+1)*column)]==1)&&(checkX[(horizontal)+((vertical+2)*column)]==1)&&(checkX[(horizontal)+((vertical+3)*column)]==1)&&(checkX[horizontal+((vertical+4)*column)]==1)
                )//down
                {
                    cout<<"X wins."<<endl;
                    finish=1;
                    break;
                }
                if(horizontal+4<=column){//check if fifth tile is off the board to the right
                    if(((checkX[(horizontal)+(vertical*column)]==1)&&(checkX[(horizontal+1)+(vertical*column)]==1)&&(checkX[(horizontal+2)+(vertical*column)]==1)&&(checkX[(horizontal+3)+(vertical*column)]==1)&&(checkX[(horizontal+4)+(vertical*column)]==1)
                    )||//right
                    ((checkX[(horizontal)+(vertical*column)]==1)&&(checkX[(horizontal+1)+((vertical+1)*column)]==1)&&(checkX[(horizontal+2)+((vertical+2)*column)]==1)&&(checkX[(horizontal+3)+((vertical+3)*column)]==1)&&(checkX[(horizontal+4)+((vertical+4)*column)]==1)
                    ))//down right
                    {
                        cout<<"X wins."<<endl;
                        finish=1;
                        break;
                    }
                    if((horizontal+4)+((vertical-4)*column)>column){//check if fifth tile is off the board to the top
                        if((checkX[(horizontal)+(vertical*column)]==1)&&(checkX[(horizontal+1)+((vertical-1)*column)]==1)&&(checkX[(horizontal+2)+((vertical-2)*column)]==1)&&(checkX[(horizontal+3)+((vertical-3)*column)]==1)&&(checkX[(horizontal+4)+((vertical-4)*column)]==1))
                        {//up right
                            cout<<"X wins."<<endl;
                            finish=1;
                            break;
                        }
                    }
                }
            }
        }
        if(finish==1){
            break;
        }
        if(turn==boardSize-column){
            cout<<"It's a draw."<<endl;
            break;
        }
    }
}

//credit
void Credits(){
    cout<<"\nMade by Norng Sovannara aka Hiva."<<endl;
    cout<<"Also I like cats.\n"<<endl;
}

//menu
void MenuTicTacToe(){
    int option;
    while(true){
        cout<<"1. Start game"<<endl;
        cout<<"2. How to play"<<endl;
        cout<<"3. Credit"<<endl;
        cout<<"4. Quit Game"<<endl;
        cout<<"Enter option: ";
        cin>>option;
        CheckInput();
        if(option==1){
            TicTacToe();
        }
        else if(option==2){
            HowToPlay();
        }
        else if(option==3){
            Credits();
        }
        else if(option==4){
            cout<<"Bye.";
            break;
        }
        else{
            cout<<"Invalid input, please try again."<<endl;
        }
    }
}

int main(){

    MenuTicTacToe();

    return 0;
}