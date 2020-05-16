#include <bits/stdc++.h>
using namespace std;
ifstream in("data.in");
vector<pair<int,int>> A;
int N,D,x,y;
int main()
{
    cin>>N>>D;
    A.reserve(N);
    for(int i=0; i<N; i++)
    {
        cin>>x>>y;
        A.push_back({x,y});
    }
    sort(A.begin(),A.end());
    int dr=0;
    long long int sum=0;
    long long int maxi = 0;
    for(int st=0; st<N; st++) // Two pointer technique
    {
        while(dr<N && abs(A[st].first-A[dr].first)<D) // Cat timp respectam conditia problemei si avem unde sa inaintam
        {
            sum+=A[dr].second; // Adunam factorul
            dr++;
        } // Trecem la urmatorul prieten
        maxi=max(maxi,sum); // Update maximum
        sum -=A[st].second; // Pregatim urmatoarea iteratie
    }
    cout<<maxi;
    return 0;
}
