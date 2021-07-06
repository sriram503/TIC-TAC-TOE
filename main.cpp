#include"check.cpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"------ TIC TAC TOE ------"<<endl;
    cout<<"\nPress 1 start game (player vs player)\n";
    int p;
    cin>>p;
    if(p != 1) exit(0);
    else
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
            else if(result == 2)
            {
                cout<<"O wins\n";
                break;
            }
            else if(result == 3)
            {
                cout<<"Match Drawn\n";
                break;
            }

        }
    }

}
