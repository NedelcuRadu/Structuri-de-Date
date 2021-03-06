#include <fstream>
#define MAX 500001
using namespace std;
ifstream ino("curatenie.in");
ofstream cout("curatenie.out");
int in[MAX];
int pre[MAX];
int N;
int index = 0;
struct nod {
    int data;
    nod*st, *dr;
};
typedef nod* pNod;
pNod A[MAX];
int search(int l, int r, int val) {
    for(int i = l; i <= r; i++)
        if (in[i] == val)
            return i;
    return -1;

}
pNod build(int inl, int inr) { // Preordinea ne spune radacina curenta, inordinea ne da subarborii stangi si drepti
    if(inl > inr)
        return nullptr;
    pNod temp = new nod;
    temp->data = pre[index++]; // Radacina curenta
    temp->dr = nullptr; 
    temp->st = nullptr;
    A[pre[index - 1]] = temp; // Locul ei din vector
    if(inl == inr) // Inseamna ca nu mai are fii
        return temp;
    int index2 = search(inl, inr, temp->data); // Cautam radacina curenta in parcurgerea inordine

    temp->st = build(inl, index2 - 1    ); // Repetam pt arborii stangi si drepti
    temp->dr = build(index2 + 1, inr);
    return temp; // Returnam nodul
}

int main() {
    ino >> N;
    for(int i = 0; i < N; i++)
        ino >> in[i];
    for(int i = 0; i < N; i++)
        ino >> pre[i];
    build(0, N - 1);
    for(int i = 1; i <= N; i++) {
        if(A[i]->st != nullptr)
            cout << A[i]->st->data << " ";
        else
            cout << "0 ";
        if(A[i]->dr != nullptr)
            cout << A[i]->dr->data << '\n';
        else
            cout << "0\n";
    }
    return 0;
}
