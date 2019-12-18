#include "PQ.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int getInvCount(int row[],int);
bool isSolvable(int **bArray,int);
bool FileExist(string);
string address = "/Users/ramyelgendi/Desktop/Computer Science/Final/8 Puzzle/8 Puzzle/File.txt";

int main()
{
    int n = 3;
    
    if(FileExist(address))
    {
        
        
        ifstream file;
        file.open (address);
        file >> n;
        int **bArray = new int * [n];
        for (int i = 0; i < n; i++)
            bArray[i] = new int[n];
        
        int **Goal = new int * [n];
        for (int i = 0; i < n; i++)
            Goal[i] = new int[n];
        int i=1;
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++)
            {
                file >> bArray[x][y];
                Goal[x][y]=i;
                i++;
            }
        Goal[n-1][n-1]=0;
        
        file.close();
        
        if(isSolvable(bArray,n))
        {
            PQ H(bArray, n);
            H.Moves(bArray, 0, n,Goal);
        }
        else
            cout << "Not Solvable\n";
        
    }
    else
    {
        cout<<"File Does Not Exist!\n";
        system("pause");
        return 0;
    }
    
   

    
    system("pause");
    return 0;
}
bool FileExist (string ) {
    ifstream file;
    file.open(address);
    if (file.fail())
        return false;
    file.close();
    return true;
}
int getInvCount(int **bArray,int n)
{
    int row[n*n],i=0;
    for(int x = 0;x<3;x++)
        for(int y=0;y<3;y++)
        {
            row[i] = bArray[x][y];
            i++;
        }
    int count = 0;
    for (int i = 0; i < n*n - 1; i++)
        for (int j = i+1; j < n*n; j++)
            if (row[j] && row[i] && row[i] > row[j])
                count++;
    return count;
}

bool isSolvable(int **bArray,int n)
{
    
    int count = getInvCount(bArray,n);
    return (count%2 == 0);
}
