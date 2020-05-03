   
#include <bits/stdc++.h>
using namespace std;

bool wayToSort(string a, string b)
{
    if(a+b > b+a)
        return 1;
    return 0;
}
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char ch) {
        return !(ch=='0');
    }));
}
string largestConcat(vector<string>& v) {
    string rez="";
    sort(v.begin(),v.end(),wayToSort);
    for(auto &i:v)
    rez+=i;
    ltrim(rez);
    if(rez.size()==0)
    return "0";
    return rez;
}
   
int main() {
    int N;
    cin >> N;
    vector<string> v;
    for (int i = 0; i < N; ++i) {
        string number;
        cin >> number;
        v.push_back(number);
    }
    
    cout << largestConcat(v) << "\n";
    return 0;
}
