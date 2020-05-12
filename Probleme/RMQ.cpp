#include <iostream>
#include <fstream>
#include <math.h>
#define MAX 100002
using namespace std;
ifstream in("rmq.in");
ofstream out("rmq.out");
int LOG[18]; // log2(MAX)+1
int RMQ[MAX][18];
int N,M,L,R;
int main()
{
    in>>N>>M;
    for (int i = 0; i < N; i++) // Pe bucatile de lungime 1, cel mai mic element e chiar el
        in>> RMQ[i][0];

    for (int j = 1; (1<<j) <= N; j++) // Pt fiecare putere a lui 2
        for (int i = 0; i + (1 << j) <= N; i++) // Pt fiecare "offset" din interval
            RMQ[i][j] = min(RMQ[i][j-1], RMQ[i + (1 << (j - 1))][j - 1]); // Minimul e minimul celor 2 intervale calculate anterior
    while(M--)
    {
        in>>L>>R;
        L--; //Avem array-ul indexat de la 0, intrebarile sunt de la 1
        R--;
        int j = (int)log2(R - L + 1); // Nu i-a placut cu log precalculat
        int minimum = min(RMQ[L][j], RMQ[R - (1 << j)+1 ][j]); // Impart intervalul dupa cea mai apropiata putere a lui 2 si apoi compar minimele
        out<<minimum<<'\n';
    }

    return 0;
}
