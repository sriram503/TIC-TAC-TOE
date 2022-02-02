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
        if(A[i][0] == 'O' && A[i][1] == 'O' && A[i][2] == 'O') return -1;
        if(A[i][0] == 'X' && A[i][1] == 'X' && A[i][2] == 'X') return 1;
    }

    for(int i = 0 ; i < 3 ; ++i)
    {
        if(A[0][i] == 'O' && A[1][i] == 'O' && A[2][i] == 'O') return -1;
        if(A[0][i] == 'X' && A[1][i] == 'X' && A[2][i] == 'X') return 1;
    }

    if(A[0][0] == 'O' && A[1][1] == 'O' && A[2][2] == 'O') return -1;
    if(A[0][0] == 'X' && A[1][1] == 'X' && A[2][2] == 'X') return 1;
    if(A[0][2] == 'O' && A[1][1] == 'O' && A[2][0] == 'O') return -1;
    if(A[0][2] == 'X' && A[1][1] == 'X' && A[2][0] == 'X') return 1;

    if(moves == 9) return 0;

    return 3;

}

int minimax(char A[3][3] , int valid[3][3] , bool flag , int moves)
{
    int result = check(A , moves);
    if(result == 1) return 1;
    if(result == -1) return -1;
    if(result == 0 || result == 3) return 0;

    if(flag == false)
    {
        int score;
        int bestscore = 10000000; 
        for(int i = 0 ; i < 3 ; ++i)
        {
            for(int j = 0 ; j < 3; ++j)
            {
                if(valid[i][j] == 0)
                {
                    A[i][j] = 'O';
                    valid[i][j] = 1;
                    score = minimax(A , valid , true , moves+1);
                    A[i][j]= ' ';
                    valid[i][j] = 0;
                    if(bestscore > score)
                    {
                        bestscore = score;
                    }
                }
            }
        }
        return bestscore;
    }
    else
    {
        int score;
        int bestscore = -10000000; 
        for(int i = 0 ; i < 3 ; ++i)
        {
            for(int j = 0 ; j < 3; ++j)
            {
                if(valid[i][j] == 0)
                {
                    A[i][j] = 'X';
                    valid[i][j] = 1;
                    score = minimax(A , valid , false , moves+1);
                    A[i][j]= ' ';
                    valid[i][j] = 0;
                    if(bestscore < score)
                    {
                        bestscore = score;
                    }
                }
            }
        }
        return bestscore;
    }
}

void Bestmove(int *a , int *b , char A[3][3] , int valid[3][3] , int moves)
{
    int score = 0;
    int bestscore = -10000000;
    for(int i = 0 ; i < 3 ; ++i)
    {
        for(int j = 0 ; j < 3 ; ++j)
        {
            if(valid[i][j] == 0)
            {
                A[i][j] = 'X';
                valid[i][j] = 1;
                score = minimax(A , valid , false , moves+1);
                A[i][j]= ' ';
                valid[i][j] = 0;
                if(bestscore < score)
                {
                    *a = i;
                    *b = j;
                    bestscore = score;
                }
            }
        }
    }
}