#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class node {
    typedef node* pNod;
  private:
    pNod left;
    pNod right;
    int key;
    int height;
  public:
    node();
    void set_height(int x);
    void set_left(pNod x);
    void set_right(pNod x);
    void set_key(int x);
    int get_key();
    friend int fheight(pNod p);
    int get_balance();
    pNod get_left();
    pNod get_right();
};

#endif // NODE_H_INCLUDED
