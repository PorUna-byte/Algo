//
//  Fibnacci_heap.cpp
//  Fibnacci_heap
//
//  Created by PorUnaCabeza on 2022/1/31.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#include "Fibnacci_heap.hpp"
template<typename T>
void Heap<T>::insert(T key)
{
    Node<T>* x=new Node<T>(key);
    if(min==nullptr)
    {
        min=x;
        left_edge=right_edge=x;
    }
    else
    {
        Node<T>* left=min->left;
        if(left==nullptr)
            left_edge=x;
        else
            left->right=x;

        x->right=min;
        min->left=x;
        x->left=left;
        if(x->key<min->key)
            min=x;
    }
    n++;
}
template<typename T>
T Heap<T>::findMin()
{
    return min->key;
}
template<typename T>
void Heap<T>::heap_link(Node<T>* x,Node<T>* y)
{
    Node<T>* left=x->left;
    Node<T>* right=x->right;
    if(left!=nullptr)
        left->right=right;
    else
        left_edge=right;
    if(right!=nullptr)
        right->left=left;
    else
        right_edge=left;
    x->parent=y;
    Node<T>* child=y->child;
    if(child!=nullptr)
    {
        Node<T>* lleft=child->left;
        child->left=x;
        x->left=lleft;
        if(lleft!=nullptr)
            lleft->right=x;
        x->right=child;
    }
    else
    {
        x->left=x->right=nullptr;
        y->child=x;
    }
    y->degree++;
    x->mark=false;
}
template<typename T>
void Heap<T>::conSolidate()
{
    int d=D(n);
    Node<T> **A=(Node<T> **)malloc(sizeof(Node<T> *)*(d+1));
    for(int i=0;i<=d;i++)
        A[i]=nullptr;
    for(Node<T> *w=left_edge;w!=nullptr;)
    {
        Node<T> *x=w;
        size_t degree=x->degree;
        w=w->right;
        while(A[degree]!=nullptr)
        {
            Node<T> *y=A[degree];
            if(x->key>y->key)        //Make sure x->key<=y->key
                swap(x, y);
            heap_link(y,x);
            A[degree]=nullptr;
            degree++;
        }
        A[degree]=x;
    }
    min=left_edge=right_edge=nullptr;  //reset the fibnacci heap
    for(int i=0;i<=d;i++)
    {
        if(A[i]!=nullptr)
        {
            if(min==nullptr)
            {
                min=A[i];
                Node<T> *leftest=A[i];
                Node<T> *rightest=A[i];
                while(leftest->left!=nullptr)
                    leftest=leftest->left;
                while(rightest->right!=nullptr)
                    rightest=rightest->right;
                left_edge=leftest;
                right_edge=rightest;
            }
            else if(A[i]->key<min->key)
                min=A[i];
        }
    }
}
template<typename T>
void Heap<T>::delete_min()
{
    if(min!=nullptr)
    {
        if(n==1)//There is only one node,deletion would make it empty
        {
            min=nullptr;
            n=0;
            return ;
        }
        Node<T> *child=min->child;
        if(child!=nullptr){
            while(child->left!=nullptr)  //find the leftest child of min
                child=child->left;
            Node<T> *temp=nullptr;
            while(child!=nullptr)    //Add all children of min to the left of root list
            {
                temp=child->right;
                child->parent=nullptr;
                left_edge->left=child;
                child->right=left_edge;
                child->left=nullptr;
                left_edge=child;
                child=temp;
            }
        }
        Node<T> *left=min->left;
        Node<T> *right=min->right;
        if(left!=nullptr)   //delete min from
            left->right=right;
        if(right!=nullptr)
            right->left=left;
        n--;
        delete min;
        min=nullptr;
        conSolidate();
    }
}
template<typename T>
void Heap<T>::cut(Node<T>* x,Node<T>* y)
{
    Node<T> *left=x->left;
    Node<T> *right=x->right;
    if(left!=nullptr)
        left->right=right;
    if(right!=nullptr)
        right->left=left;
    y->degree--;
    insert(x->key);

}
template<typename T>
void Heap<T>::cascading_cut(Node<T>* y)
{
    Node<T> *z=y->parent;
    if(z!=nullptr)
    {
        if(y->mark==false)
            y->mark=true;
        else
        {
            cut(y,z);
            cascading_cut(z);
        }
    }
}
template<typename T>
void Heap<T>::decrease_key(Node<T>* x,T new_key)
{
    if(new_key>x->key)
    {
        cout<<"new key is greater than current key"<<endl;
        return ;
    }
    x->key=new_key;
    Node<T> *p=x->parent;
    if(p!=nullptr&&x->key<p->key)
    {
        cut(x,p);
        cascading_cut(p);
    }
    if(x->key<min->key)
        min=x;
}
template<typename T>
void Heap<T>::delete_node(Node<T>* x)
{
    decrease_key(x,MIN_INFINE);
    delete_min();
}
template class Node<int>;
template class Heap<int>;
