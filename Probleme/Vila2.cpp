#include <fstream>
#include <iostream>
#define MAX 100010
using namespace std;
ifstream in("vila2.in");
ofstream out("vila2.out");
long long int A[MAX], deque1[MAX], deque2[MAX]; // deque1 pt minime, deque1 2 pt maxime
long long int N,K,sum=0;
int main()
{
    in>>N>>K;
    int front = 1, back = 0; // Initializam deque1 si 2
    int front2 = 1, back2 = 0;
    for(int i=0; i<N; i++)
    {
        in>>A[i];
        while(front<=back && A[i]<= A[deque1[back]]) back--;
        deque1[++back]=i;
        if(deque1[front] == i-K-1)
            front++;
 
        while(front2<=back2 && A[i]>=A[deque2[back2]]) back2--;
        deque2[++back2]=i;
        if(deque2[front2] == i-K-1)
            front2++;
 
        if(i>=K-1)
            sum = max(sum, A[deque2[front2]]-A[deque1[front]]);
    }
    out<<sum;
 }
