#ifndef PQ_H
#define PQ_H
struct E {
    int g;
    int h;
    int sum;
    int **arr;
};
class PQ
{
public:
    PQ(int **bArray, int n);
    void insert(E);    // insert element into heap
    E remove();    // remove & return the top of the heap
    void test(int **bArray,int move);
    bool Moves(int **bArray,int,int,int **Goal);
    bool HeapIsEmpty();
private: //find index i and index j of value x in the borad b
    void findIJ(E b, int x, int & iC, int & jC, int n);
    int findH(E b, int n); //find sum of all distances
    
    E *a;         //Heap array
    int N;          //index of last element in the array
    int itemMin;  //Very small value at index 0
    
    void upheap(int k);
    void downheap(int k);
};
#endif // PQ_H
