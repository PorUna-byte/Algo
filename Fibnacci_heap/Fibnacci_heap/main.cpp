//
//  main.cpp
//  Fibnacci_heap
//
//  Created by PorUnaCabeza on 2022/1/31.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#include "Fibnacci_heap.hpp"
int main(int argc, const char * argv[]) {
    Heap<int>* heap=new Heap<int>;
    heap->insert(23);
    heap->insert(7);
    heap->insert(21);
    heap->insert(3);
    heap->insert(17);
    heap->insert(24);
    heap->insert(18);
    heap->insert(52);
    heap->insert(38);
    heap->insert(39);
    heap->insert(41);
    heap->insert(30);
    heap->insert(26);
    heap->insert(46);
    heap->insert(35);
    heap->delete_min();
    Heap<int>* heap_add=new Heap<int>;
    heap_add->insert(2);
    heap=*heap+*heap_add;
    Node<int> *p=heap->min;
    p=heap->left_edge;
    cout<<heap->min->key<<endl;
    while(p!=nullptr)
    {
        cout<<p->key<<"  ";
        p=p->right;
    }
    cout<<endl;
    cout<<heap->left_edge->key<<" "<<heap->right_edge->key<<endl;
    cout<<heap->n<<endl;
    return 0;
}
