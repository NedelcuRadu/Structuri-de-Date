#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string word;
    unordered_map<string,long long int> dictionar;
    long long int rez = 1;
    cin>>N;
    while(N--)
    {
        cin>>word;
        sort(word.begin(),word.end());
        dictionar[word]+=1;
        rez = max(rez,dictionar[word]);
    }
    cout<<rez;
    return 0;
}
