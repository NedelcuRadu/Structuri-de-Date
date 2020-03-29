#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "node.h"
typedef node* pNod;
class AVL {
    pNod root = nullptr;
  public:
    pNod get_root();
    void set_root(pNod p);
    pNod rightRotate(pNod pivot);
    pNod leftRotate(pNod pivot);
    pNod insert_helper(pNod root, int key);
    pNod delete_helper(pNod root, int key);
    int succesor_helper(pNod root, int key);
    int predecesor_helper(pNod root, int key);
    void preorder(pNod pivot);
    void inorder(pNod pivot) ;
    void insert(int key);
    void del(int key);
    bool find_helper(pNod pivot,int val);
    bool find(int val);
    void succesor(int val);
    void predecesor(int val);
    void interval_helper(pNod p,int x, int y);
    void interval(int x, int y);
    pNod celmaimic(pNod root);
};

#endif // AVL_H_INCLUDED
