#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "node.h"
#include <bits/stdc++.h>
using namespace std;

typedef node* pNod;
class AVL {
    pNod root = nullptr;
  public:
    pNod get_root();
    void set_root(pNod p);
    pNod rightRotate(pNod pivot);
    pNod leftRotate(pNod pivot);
    pNod insert_helper(pNod root, int key);
    void preorder(pNod pivot);
    void inorder(pNod pivot);
    void insert(int key);
    bool find_helper(pNod pivot, int val);
    void find(int val);
    int predecesor_helper(pNod root, int key);
    int succesor_helper(pNod root, int key);
    void succesor(int val);
    void predecesor(int val);
    void interval_helper(pNod p, int x, int y);
    void interval(int x, int y);
    pNod celmaimic(pNod root);
    pNod delete_helper(pNod p, int key);
    void del(int key);
};

#endif // AVL_H_INCLUDED
