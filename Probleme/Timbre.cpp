#include <bits/stdc++.h>

using namespace std;
ifstream in("timbre.in");
ofstream out("timbre.out");
int N,M,K,cost;
bool WayToSort( const pair<int,int>&first, const pair<int,int> &second)
{
    return (first.first>second.first);
}
struct Comp
{
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
    const noexcept
    {
        return a.second > b.second;
    }
};
vector<pair<int,int>> A;
priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> heap;
pair<int,int> temp;
int main()
{
    in>>N>>M>>K;
    for(int i=0; i<M; i++)
    {
        in>>temp.first>>temp.second;
        A.push_back(temp);
    }
    int i=0;
    sort(A.begin(),A.end(),WayToSort);
    while(N>0) // Cat timp ne mai trebuie timbre
    {
        while(i<M && A[i].first>=N) // Cat timp mai avem de unde cumpara si ne sunt folositoare
        {
            heap.push(A[i]); // Punem in heap pt a afla minimul
            i++;
        }
        cost+=heap.top().second; // Actualizam costul
        N-=K; // Vrem mereu sa cumparam K timbre dintr-o serie
        heap.pop(); // Actualizam heap-ul
    }
    out<<cost;
    return 0;
}
