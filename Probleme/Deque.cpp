	
#include <fstream>
#define MAX 5000010
using namespace std;
ifstream in("deque.in");
ofstream out("deque.out");
int A[MAX], deque[MAX];
long long int N,K,sum=0;
int main()
{
    in>>N>>K;
    int front = 1, back = 0; // Initializam deque
    for(int i=0; i<N; i++)
    {
        in>>A[i];
        while(front<=back && A[i]<= A[deque[back]]) back--; // Cat timp elementul e mai mic decat ce avem in deque
        deque[++back]=i; // Adaugam elementul in deque
        if(deque[front] == i-K) // Daca am trecut de "zona" minimului, il scoatem
            front++;
        if(i>=K-1) // Dupa primele K elemente
            sum+=A[deque[front]]; // Adunam minimul
    }
    out<<sum;
 
}
