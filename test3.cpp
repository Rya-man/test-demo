#include<iostream>
#include<iomanip>
using namespace std;
class Sudoku
{
    int puz[9][9]={0};
    void input()
    {
        int a=0;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cin>>a;
                puz[i][j] = a;
            }
        }
    }
};