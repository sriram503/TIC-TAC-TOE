#include<bits/stdc++.h>
using namespace std;

void initalizeBoard(char A[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {

           A[i][j]=' ';

        }
    }
}


void DisplayBoard(char A[3][3])
{

    cout<<"   0     1    2"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<i;
        for(int j=0;j<3;j++)
        {
            if(j!=2)
            printf("  %c  |",A[i][j]);

            if(j==2)
            {
              printf("  %c  ",A[i][j]);

            }
        }

        printf("\n");


        if(i<2)
        {
            cout<<"  ";
            for(int t=0;t<4;t++)
            {
               printf("----");
            }

            printf("\n");
        }
    }

}


//----- CHECK -----//
// Checks the game status
// The function will return 1 if X wins
// The function will return 2 if O wins
// The function will return 3 if draw
// The function will return 4 if game has to be continued

int check(char A[3][3] , int moves)
{
    for(int i = 0 ; i < 3 ; ++i)
    {
        if(A[i][0] == 'O' && A[i][1] == 'O' && A[i][2] == 'O') return 2;
        if(A[i][0] == 'X' && A[i][1] == 'X' && A[i][2] == 'X') return 1;
    }

    for(int i = 0 ; i < 3 ; ++i)
    {
        if(A[0][i] == 'O' && A[1][i] == 'O' && A[2][i] == 'O') return 2;
        if(A[0][i] == 'X' && A[1][i] == 'X' && A[2][i] == 'X') return 1;
    }

    if(A[0][0] == 'O' && A[1][1] == 'O' && A[2][2] == 'O') return 2;
    if(A[0][0] == 'X' && A[1][1] == 'X' && A[2][2] == 'X') return 1;
    if(A[0][2] == 'O' && A[1][1] == 'O' && A[2][0] == 'O') return 2;
    if(A[0][2] == 'X' && A[1][1] == 'X' && A[2][0] == 'X') return 1;

    if(moves == 9) return 3;

    return 4;

}