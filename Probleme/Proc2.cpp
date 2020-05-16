#include <bits/stdc++.h>
using namespace std;
fstream in("proc2.in");
ofstream out("proc2.out");
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> proc_used; // timp, indice
priority_queue<int,vector<int>, greater<>> proc_free;

int N,M,timp,durata,cnt;
int main()
{
    in>>N>>M;
    for(int i=1; i<=N; i++)
        proc_free.emplace(i);
    while(M--)
    {
        in>>timp>>durata;
        while(!proc_used.empty() && timp >= proc_used.top().first)
        {
            proc_free.push(proc_used.top().second);
            proc_used.pop();
        }

        out<<proc_free.top()<<'\n';
        proc_used.push({timp+durata,proc_free.top()});
        proc_free.pop();

    }
    return 0;
}
