#include"check.cpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
    cout<<"------ TIC TAC TOE ------"<<endl;
    cout<<"\nPress 1 start game (player vs player)\n";
    cout<<"\nPress 2 start game with computer\n";
    int p;
    cin>>p;
    if(p == 2)
    {
        char A[3][3];
        char turn='X';
        int moves = 0;
        initalizeBoard(A);
        DisplayBoard(A);
        int valid[3][3] = {0};
        while(1)
        {
            if(turn == 'X')
            {
                int a , b;
                if(moves == 0)
                {
                    a = rand()%3;
                    b = rand()%3;
                }
                else
                {
                    Bestmove(&a , &b , A , valid , moves);
                }
                A[a][b] = 'X';
                valid[a][b] = 1;
                turn = 'O';
                moves++;
            }
            else
            {
                cout<<"Enter your move"<<endl;
                
                int a,b;
                cin>>a>>b;
                while(valid[a][b] !=0)
                {
                    cout<<"Invalid Move!! Enter your move again"<<endl;
                    cin>>a>>b;
                }
                A[a][b] = 'O';
                valid[a][b] = 1;
                turn = 'X';
                moves++;
            } 
            system("clear");
            DisplayBoard(A);
            int result = check(A , moves);
            if(result == 1)
            {
                cout<<"X wins\n";
                break;
            }
            else if(result == -1)
            {
                cout<<"O wins\n";
                break;
            }
            else if(result == 0)
            {
                cout<<"Match Drawn\n";
                break;
            }
        }
    }
    else
    {
        char A[3][3];
        //char B[3][3];
        char turn='X';
        int moves = 0;
        initalizeBoard(A);
        DisplayBoard(A);
        int valid[3][3] = {0};
        while(1)
        {
            if(turn == 'X')
            {
                cout<<"Enter your move"<<endl;
                
                int a,b;
                cin>>a>>b;
                while(valid[a][b] !=0)
                {
                    cout<<"Invalid Move!! Enter your move again"<<endl;
                    cin>>a>>b;
                }
                A[a][b] = 'X';
                valid[a][b] = 1;
                turn = 'O';
                moves++;
            }
            else
            {
                cout<<"Enter your move"<<endl;
                
                int a,b;
                cin>>a>>b;
                while(valid[a][b] !=0)
                {
                    cout<<"Invalid Move!! Enter your move again"<<endl;
                    cin>>a>>b;
                }
                A[a][b] = 'O';
                valid[a][b] = 1;
                turn = 'X';
                moves++;
            }
            system("clear");
            DisplayBoard(A);
            int result = check(A , moves);
            if(result == 1)
            {
                cout<<"X wins\n";
                break;
            }
            else if(result == -1)
            {
                cout<<"O wins\n";
                break;
            }
            else if(result == 0)
            {
                cout<<"Match Drawn\n";
                break;
            }

        }
    }

}
