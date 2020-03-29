#include <bits/stdc++.h>
#include "Bloom.h"
using namespace std;

int main() {
    int n;
    double p;
    cout << "Cate nr de elemente vrei sa introduci:\n";
    cin >> n;
    cout << "Probabilitatea tolerata pentru fals pozitiv (double):\n";
    cin >> p;
    BloomFilter bloom(n, p);
    cout << "Bloom filter construit.\n";
    cout << "Introduceti cele " << n << " elemente.\n";
    string a;
    for(auto i = 0; i < n; i++) {
        try {
            cin >> a;
            bloom.insert(a);
        } catch(...) {
            cout << "Elementul nu a putut fi introdus, incercati iar.\n";
            cin >> a;
        }
    }
    string b;
    while(b != "exit") {
        cout << "Dati elementul de verificat (exit pentru exit): ";
        cin >> b;
        if(bloom.isThere(b))
            cout << b << " are " << 100 - p << " sanse sa fie in filtru\n";
        else
            cout << b << " NU se afla in filtru\n";
    }

    return 0;
}
