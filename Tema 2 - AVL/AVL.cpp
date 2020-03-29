#include "AVL.h"
#include <fstream>
#include <iostream>
using namespace std;
ofstream out("data.out");
pNod AVL::get_root() {
    return root;
};
void AVL::set_root(pNod p) {
    root = p;
}
pNod AVL::rightRotate(pNod pivot) {
    int a = 0;
    int b = 0;
    pNod x = pivot->get_left();
    pivot->set_left( x->get_right());
    x->set_right(pivot);
    if (pivot->get_left() != nullptr)
        a = pivot->get_left()->get_height();
    if (pivot->get_right() != nullptr)
        b = pivot->get_right()->get_height();

    pivot->set_height(max(a, b) + 1);
    a = 0;
    b = 0;
    if (x->get_left() != nullptr)
        a = x->get_left()->get_height();
    if (x->get_right() != nullptr)
        b = x->get_right()->get_height();
    x->set_height(max(a, b) + 1);
    return x;
}

pNod AVL::leftRotate(pNod pivot) {
    int a = 0;
    int b = 0;
    pNod y = pivot->get_right();
    pivot->set_right(y->get_left());
    y->set_left(pivot);
    if (pivot->get_left() != nullptr)
        a = pivot->get_left()->get_height();
    if (pivot->get_right() != nullptr)
        b = pivot->get_right()->get_height();
    pivot->set_height(max(a, b) + 1);
    a = 0;
    b = 0;
    if (y->get_left() != nullptr)
        a = y->get_left()->get_height();
    if (pivot->get_right() != nullptr)
        b = y->get_right()->get_height();
    y->set_height(max(a, b) + 1);
    return y;
}
pNod AVL::insert_helper(pNod root, int key) {
    int a = 1;
    int b = 1;
    if (root == nullptr) {
        root = new node;
        root->set_key(key);
        return root;
    }
    if (key < root->get_key())
        root->set_left(insert_helper(root->get_left(), key));
    else
        root->set_right(insert_helper(root->get_right(), key));

    if (root->get_left() != NULL)
        a = root->get_left()->get_height();
    if( root->get_right() != NULL)
        b = root->get_right()->get_height();

    root ->set_height(1 + max(a, b));
    int balance = root->get_balance();

    //Left Left - subarborele stang e prea inalt, il rotim la dreapta
    if(balance > 1 && key < root->get_left()->get_key())
        return rightRotate(root);

    //Left Right - rotim in stanga fiul stang si apoi in dreapta arborele
    if (balance > 1 && key > root->get_left()->get_key()) {
        root->set_left(leftRotate(root->get_left()));
        return rightRotate(root);
    }
    //Right Right - subarborele drept e prea inalt, il rotim la stanga
    if(balance < -1 && key > root->get_right()->get_key())
        return leftRotate(root);

    //Right Left - rotim in dreapta subarborele din fiul drept si apoi rotim la stanga
    if(balance < -1 && key < root->get_right()->get_key()) {
        root->set_right(rightRotate(root->get_right()));
        return leftRotate(root);
    }
    return root;
}
void AVL::preorder(pNod pivot) { // Parcurgere in preordine
    if(pivot != NULL) {
        out << pivot->get_key() << " ";
        preorder(pivot->get_left());
        preorder(pivot->get_right());
    }
}
void AVL::inorder(pNod pivot) { // Parcurgere in ordine - elementele vor fi sortate
    if(pivot != NULL) {
        inorder(pivot->get_left());
        out << pivot->get_key() << " ";
        inorder(pivot->get_right());
    }
}
void AVL::insert(int key) {
    set_root(insert_helper(get_root(), key));
}
bool AVL::find_helper(pNod pivot, int val) {
    if (pivot == nullptr)
        return 0;
    else if (pivot->get_key() == val)
        return 1;
    else if (pivot->get_key() > val)
        return find_helper(pivot->get_left(), val);
    else
        return find_helper(pivot->get_right(), val);
}
bool AVL::find(int val) {
    out << find_helper(root, val) << '\n';
}

int AVL::predecesor_helper(pNod root, int key) {
    if (root == nullptr)
        return -1;
    if(root->get_key() == key)
        return key;

    if (root->get_key() < key) {
        int a = predecesor_helper(root->get_right(), key);
        if (a == -1)
            return root->get_key();
        else
            return  a;
    } else
        return predecesor_helper(root->get_left(), key);
}
int AVL::succesor_helper(pNod root, int key) {
    if (root == nullptr)
        return -1;
    if(root->get_key() == key)
        return key;

    if (root->get_key() > key) {
        int a = succesor_helper(root->get_left(), key);
        if (a == -1)
            return root->get_key();
        else
            return  a;
    } else
        return succesor_helper(root->get_right(), key);
}
void AVL::succesor(int val) {
    out << succesor_helper(root, val) << '\n';
}
void AVL::predecesor(int val) {
    out << predecesor_helper(root, val) << '\n';
}

void AVL::interval_helper(pNod p, int x, int y) {
    if (p == nullptr)
        return;
    int key = p->get_key();
    if(x < key)
        interval_helper(p->get_left(), x, y);
    if(x < key && y > key)
        out << key << " ";
    if(y > key)
        interval_helper(p->get_right(), x, y);
}

void AVL::interval(int x, int y) {
    interval_helper(root, x, y);
    out << '\n';
}

pNod AVL::celmaimic(pNod root) {
    pNod iter = root;
    while(iter->get_left() != nullptr)
        iter = iter->get_left();
    return iter;
}
pNod AVL::delete_helper(pNod p, int key) {
    int a = 1;
    int b = 1;
    if (p == nullptr)
        return p;
    if (p->get_key() < key)
        p->set_right(delete_helper(p->get_right(), key));
    else if(p->get_key() > key)
        p->set_left(delete_helper(p->get_left(), key));
    else {
        //Verificam cati copii are
        // 1 copil
        if (p->get_left() == nullptr ||  p->get_right() == nullptr) {
            pNod a;
            if (p->get_left() != nullptr)
                a = p->get_left();
            else
                a = p->get_right();
            // 0 copii
            if (a == nullptr) {
                a = p;
                p = nullptr;
            } else // 1 copil
                p = a;
            free(a);

        } else
            // 2 copii
        {
            pNod a = celmaimic(p->get_right());
            p->set_key(a->get_key());
        }
    }

    if (p == nullptr)
        return p ;
    if (p->get_left() != NULL)
        a = p->get_left()->get_height();
    if( p->get_right() != NULL)
        b = p->get_right()->get_height();
    p->set_height(1 + max(a, b));

    int balance = p->get_balance();
    if(balance > 1) {
        if (p->get_left()->get_balance() >= 0)
            return rightRotate(p);
        else {
            p->set_left(leftRotate(p->get_left()));
            return rightRotate(p);
        }

    } else if(balance < -1) {
        if (p->get_right()->get_balance() <= 0)
            return leftRotate(p);
        else {
            p->set_right(rightRotate(p->get_right()));
            return leftRotate(p);
        }
    }
    return p;
}
void AVL::del(int key) {
    int k=0;
    while(find_helper(root,key))
        {delete_helper(root,key);
        k++;}
    out<<k<<'\n';
}

