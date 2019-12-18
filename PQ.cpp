#include <iostream>
#include <iomanip>
#include "PQ.h"
using namespace std;
PQ::PQ(int **bArray, int n) //Constructor
{
    a = new E[5];
    N = 0;
    itemMin = -32767; // Minimum Heap
    a[0].sum = itemMin;
    
    E initial;
    initial.arr = new int *[n];
    for (int i = 0; i < n; i++)
        initial.arr[i] = new int[n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            initial.arr[i][j] = bArray[i][j];
    
    initial.g = 0;
    initial.h = findH(initial, n);
    initial.sum = initial.h + initial.g;
    
    
    cout << endl << "   Puzzle ("<<n<<"x"<<n<<")"<< endl;
    cout<<" ---------------  \n";

    insert(initial);
    for(int x = 0;x<n;x++)
    {
        for(int y=0;y<n;y++)
            cout<<"  "<<initial.arr[x][y]<<"   ";
        cout<<endl;
    }
    cout<<" ---------------  \n";
}
void PQ::test(int **bArray,int move)
{
    
    E t;
    t.arr = bArray;
    t.g = move;
    t.h = findH(t, 3);
    t.sum = t.h + t.g;
    insert(t);
    
}
bool PQ::HeapIsEmpty()
{
    if(N==0)
        return true;
    return false;
}
bool PQ::Moves(int **bArray,int move,int n, int **Goal)
{
    bool flag = false;
    while(!flag){
    flag = true;
    int x,y;
    E Board;
    Board.arr = new int *[n];
    for (int i = 0; i < n; i++)
        Board.arr[i] = new int[n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Board.arr[i][j] = bArray[i][j];
    
    findIJ(Board, 0, x, y, n);
    
    if(x!=0)    // Move Up
    {
        swap(Board.arr[x-1][y],Board.arr[x][y]);
        
        E temp;
        temp.arr = new int *[n];
        for (int i = 0; i < n; i++)
            temp.arr[i] = new int[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp.arr[i][j] = Board.arr[i][j];
        temp.g = move;
        temp.h = findH(temp, n);
        temp.sum = temp.h + temp.g;
        insert(temp);
        
        swap(Board.arr[x-1][y],Board.arr[x][y]);
    }
    if(y!=0)    // Move Left
    {
        swap(Board.arr[x][y-1],Board.arr[x][y]);

        E temp;
        temp.arr = new int *[n];
        for (int i = 0; i < n; i++)
            temp.arr[i] = new int[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp.arr[i][j] = Board.arr[i][j];
        temp.g = move;
        temp.h = findH(temp, n);
        temp.sum = temp.h + temp.g;
        insert(temp);
        
        swap(Board.arr[x][y-1],Board.arr[x][y]);
    }
    if(y!=n-1)    // Move Right
    {
        swap(Board.arr[x][y+1],Board.arr[x][y]);
        
        E temp;
        temp.arr = new int *[n];
        for (int i = 0; i < n; i++)
            temp.arr[i] = new int[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp.arr[i][j] = Board.arr[i][j];
        temp.g = move;
        temp.h = findH(temp, n);
        temp.sum = temp.h + temp.g;
        insert(temp);
        
        swap(Board.arr[x][y+1],Board.arr[x][y]);
    }
    if(x!=n-1)    // Move Down
    {
        swap(Board.arr[x+1][y],Board.arr[x][y]);
        
        E temp;
        temp.arr = new int *[n];
        for (int i = 0; i < n; i++)
            temp.arr[i] = new int[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp.arr[i][j] = Board.arr[i][j];
        temp.g = move;
        temp.h = findH(temp, n);
        temp.sum = temp.h + temp.g;
        
        insert(temp);
        
        swap(Board.arr[x+1][y],Board.arr[x][y]);
    }
    
    Board = remove();
    

        for(int x = 0;x<n && flag;x++)
            for(int y=0;y<n && flag;y++)
                if(Board.arr[x][y]!=Goal[x][y])
                {
                    flag = false;
                }
     
        cout<<"    Move: "<<move+1<<endl;
        cout<<" ---------------  \n";

        for(int x = 0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                bArray[x][y]= Board.arr[x][y];
                cout<<"  "<<bArray[x][y]<<"   ";
            }
            cout<<endl;
        }
        cout<<" ---------------  \n";
        
    move++;
        
        if(flag)
            cout<<"Puzzle Completed in "<<move<<" moves.\n\n";
}
return false;
}
    
//
//    bool flag = true;
//
//    while(flag){
//    E board;
//    board.arr = new int *[n];
//    for (int i = 0; i < n; i++)
//        board.arr[i] = new int[n];
//
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            board.arr[i][j] = bArray[i][j];
//
//    int x,y;
//    findIJ(board, 0, x, y, n);
//    cout<<"Index x: "<<x<<" Index y: "<<y<<" n: "<<n<<endl;
//    if(x!=0)
//    {
//        swap(board.arr[x-1][y],board.arr[x][y]);// Move Up
//        board.g=move;
//        board.h = findH(board,n);
//        board.sum = board.h+board.g;
//        insert(board);
//
//        cout<<"UP "<<board.sum<<" = "<<board.g<<" + "<<board.h<<endl;
//        for(int x = 0;x<n;x++)
//        {
//            for(int y=0;y<n;y++)
//                cout<<board.arr[x][y]<<"   ";
//            cout<<endl;
//        }
//
//        cout<<"-----------"<<endl;
//        swap(board.arr[x-1][y],board.arr[x][y]);// Move Up
//    }
//    if(y!=0)
//    {
//        swap(board.arr[x][y-1],board.arr[x][y]);// Move Left
//        board.g=move;
//        board.h = findH(board,n);
//        board.sum = board.h+board.g;
//
//        insert(board);
//
//        cout<<"LEFT "<<board.sum<<" = "<<board.g<<" + "<<board.h<<endl;
//        for(int x = 0;x<n;x++)
//        {
//            for(int y=0;y<n;y++)
//                cout<<board.arr[x][y]<<"   ";
//            cout<<endl;
//        }
//
//        cout<<"-----------"<<endl;
//        swap(board.arr[x][y-1],board.arr[x][y]);// Move Left
//    }
//    if(y!=n-1)
//    {
//        swap(board.arr[x][y+1],board.arr[x][y]);// Move Right
//        board.g=move;
//        board.h = findH(board,n);
//        board.sum = board.h+board.g;
//
//        insert(board);
//
//        cout<<"RIGHT "<<board.sum<<" = "<<board.g<<" + "<<board.h<<endl;
//        for(int x = 0;x<n;x++)
//        {
//            for(int y=0;y<n;y++)
//                cout<<board.arr[x][y]<<"   ";
//            cout<<endl;
//        }
//
//        cout<<"-----------"<<endl;
//        swap(board.arr[x][y+1],board.arr[x][y]);// Move Right
//    }
//    if(x!=n-1)
//    {
//        swap(board.arr[x+1][y],board.arr[x][y]);// Move Down
//        board.g=move;
//        board.h = findH(board,n);
//        board.sum = board.h+board.g;
//
//        insert(board);
//
//        cout<<"DOWN "<<board.sum<<" = "<<board.g<<" + "<<board.h<<endl;
//        for(int x = 0;x<n;x++)
//        {
//            for(int y=0;y<n;y++)
//                cout<<board.arr[x][y]<<"   ";
//            cout<<endl;
//        }
//
//        cout<<"-----------"<<endl;
//        swap(board.arr[x+1][y],board.arr[x][y]);// Move Down
//    }
//    //======
//
//    board = remove();
//
//
//    if(!HeapIsEmpty())
//    {
//
//        for(int x = 0;x<n;x++)
//            for(int y=0;y<n;y++)
//                if(board.arr[x][y]!=Goal[x][y])
//                    flag = false;
//
//
//
//        cout<< "Top Node Sum = "<<board.sum <<endl;
//        for(int x = 0;x<n;x++)
//        {
//            for(int y=0;y<n;y++)
//                cout<<board.arr[x][y]<<"   ";
//            cout<<endl;
//        }
//    }
//    else
//    {
//        cout<<"Heap Is Empty"<<endl;
//            return false;
//    }
//        cout<< " NEW ROUND BITCHES "<<endl;
//        move++;
//    }
//    return false;


// Insert element (v) in the heap and adjust heap
//find index i and index j of value x in the borad b
void PQ::findIJ(E b, int x, int & i, int & j, int n)
{
    i = 0; j = 0;
    int r, c;
    for (r = 0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            if (b.arr[r][c] == x)
            {
                i = r;
                j = c;
            }
        }
    }
}

//find sum of all distances
int PQ::findH(E b, int n)
{
    int difX, difY;
    int s = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            //generating values from 1 up to n*n: 1 2 3 4 5 ...
            int value = j + n*i + 1;
            if (value == n*n) //ignore value n*n
                break;
            
            int iC = 0, jC = 0; //i and j position of current value
            //find index i and index j of current value (its current position)
            findIJ(b, value, iC, jC, n);
            int iG = (value - 1) / n;   //Goal i position
            int jG = (value - 1) % n;   //Goal j position
            //find horizontal distance from its goal position
            difX = abs(iC - iG);
            difY = abs(jC - jG); //find vertical distance
            
            s = s + difX + difY;
        }
    }
    return s;
}
void PQ::insert(E v)
{
    N++;
    a[N] = v;
    upheap(N);
    
}
void PQ::upheap(int k)
{
    E v = a[k];
    while (a[k / 2].sum >= v.sum)
    {
        a[k] = a[k / 2];   k = k / 2;
    }
    a[k] = v;
}
// remove and return top of the heap, then adjust heap
E PQ::remove()
{
    E v = a[1];
    a[1] = a[N--]; downheap(1);
    return v;
}
void PQ::downheap(int k)
{
    int j = 2 * k;     E v = a[k];
    while (j <= N) {
        if ((j < N) && (a[j].sum > a[j + 1].sum)) j++;
        if (v.sum <= a[j].sum) break;
        a[j / 2] = a[j];     j *= 2;
    }
    a[j / 2] = v;
}



