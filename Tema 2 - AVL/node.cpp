#include "node.h"
typedef node* pNod;
node::node(): left(nullptr), right(nullptr), height(1) {}; // Constructor pt nod, inaltimea frunzei e 1
void node::set_height(int x) {
    height = x;
};
void node::set_left(pNod x) {
    left = x;
}
void node::set_right(pNod x) {
    right = x;
}
void node::set_key(int x) {
    key = x;
};
int node::get_key() {
    return key;
}
int fheight(pNod p) {
    if(p == nullptr)
        return 0;
    return p->height;
}
int node::get_balance() { // Inaltimea subarborelui stang - drept
    return fheight(left) - fheight(right);
}
pNod node::get_left() {
    return left;
}
pNod node::get_right() {
    return right;
}
