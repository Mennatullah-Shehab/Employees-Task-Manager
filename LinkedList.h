#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "task.h"
using namespace std;

template <class T>
class Node
{
    public:
        Node<T>* next;
        T data;
        Node();
        Node(T val);

};

template <class T>
class LinkedList
{
public:
    int count;
    Node<T>* head;
    Node<T>* tail;

    LinkedList();
    int Length();
    T At(int);
    void InsertAt(int, T);
    void Append(T);
    void DeleteAt(int);
    bool Empty();
    void Display();
    void Edit();
    string Reminder();
    void Update();
    void DateSorting();
    void Insert_sorted_descending();
    ~LinkedList();
};

#endif // LINKEDLIST_H
