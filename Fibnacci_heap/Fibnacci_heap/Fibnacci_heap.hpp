//
//  Fibnacci_heap.hpp
//  Fibnacci_heap
//
//Please refer to book "Introduction to Algorithms" for more details.
//  Created by PorUnaCabeza on 2022/1/31.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#ifndef Fibnacci_heap_hpp
#define Fibnacci_heap_hpp
/*
 The armortized costs of all operations:
 Make_heap:O(1)
 Insert:O(1)
 Minimum:O(1)
 Union:O(1)
 Extract_min:O(D(n))=O(lgn)
 Decrease_key:O(1)
 Delete:O(1gn)
 */
#include<iostream>
#include<cmath>
using namespace std;
#define D(n) log(n)/log(1.61803)
#define MIN_INFINE -99999999

template <typename T>
class Node{
public:
    T key;//The key to compare in the node
    size_t degree=0;//The number of children
    bool mark=false;//Indicates if the node has lost a child since it was linked to another node.
    //when the node lose its second child, it should be cut from its parent.
    Node* parent=nullptr;
    Node* child=nullptr;//a child of the node(it may has several children,just pick one to link)
    Node* left=nullptr;//left sibling in doubly linked list
    Node* right=nullptr;
    Node(T key):key(key){};
};
template <typename T>
class Heap{
public:
    Node<T>* min=nullptr;//a pointer to the minimum node in the fibnacci heap
    Node<T>* left_edge=nullptr;//the left edge(i.e. the leftest) of root list
    Node<T>* right_edge=nullptr;
    size_t n=0;//The number of nodes in the fibnacci heap
    void insert(T key);//insert a node with key 'key'
    T findMin();//return the minimum key
    void heap_link(Node<T>* x,Node<T>* y);//make x as a child of y,that is link x to y
    void conSolidate();//fix the heap to be a fibnacci heap,will be called in delete_min()
    void delete_min();//delete the node with minimum key and call conSolidate() to fix the heap.
    void decrease_key(Node<T>* x,T new_key);//decrease x->key to be new_key
    void delete_node(Node<T>* x);//delete the node x
private:
    void cut(Node<T>* x,Node<T>* y);//remove x from the child list of y,that is cut x from y
    void cascading_cut(Node<T>* y);//After lose a child,y may has already lost two children in total,hence y itself //should be cut from its parent. This procedure will call itself recursively until reach the root or a node //that is unmarked(i.e. has not lost a child before)
};
//template <typename T> //union two heap and return a new heap
//Heap<T>* operator+(Heap<T> H1,Heap<T> H2);
template <typename T>
Heap<T>* operator+(Heap<T>& H1,Heap<T>& H2)
{
    Heap<T> *H=new Heap<T>;
    H->min=H1.min;
    if(H1.right_edge!=nullptr)          //Concatenate H1 and H2
        H1.right_edge->right=H2.left_edge;
    if(H2.left_edge!=nullptr)
        H2.left_edge->left=H1.right_edge;
    if((H1.min==nullptr)||(H2.min!=nullptr&&H1.min->key>H2.min->key))
        H->min=H2.min;
    H->n=H1.n+H2.n;
    H->left_edge=H1.left_edge;
    H->right_edge=H2.right_edge;
    delete &H1;
    delete &H2;
    return H;
}
#endif /* Fibnacci_heap_hpp */
