#include <bits/stdc++.h>
using namespace std;
ifstream in("pikachu.in");
ofstream out("pikachu.out");
long long int N,K,x,A[100011];
long long int solve(long long int val) // Aflam minimul pt o valoare data
{
    long long int mini = 1e18;
    long long int sum=0;
    for(long long int i=1; i<=N; i++)
    {
        sum+=abs(A[i]-val);
        if(i>=K)
        {
            mini = min(mini,sum);
            sum-=abs(A[i-K+1]-val);
        }
    }
    return mini;
}
int main()
{
    in>>N>>K;
    for(long long int i=1; i<=N; i++)
        in>>A[i];

    long long int st =0, dr = 2e9;
    while(st<=dr) //Caut binar valoarea optima
    {
        long long int mid = (st+dr)>>1;
        if(solve(mid-1)>solve(mid+1))
            st = mid +1;
        else
            dr = mid-1;
    }
    out << solve(st);
    return 0;
}
