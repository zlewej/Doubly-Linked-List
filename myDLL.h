/*
 Julius Garma
 Hank Stalica
 HW 3
 Doubly-Linked List
 */

#ifndef HW_3_Doubly_Linked_List_myDLL_h
#define HW_3_Doubly_Linked_List_myDLL_h

#include<iostream>

class myDll
{
private:
    struct
    {
        int i;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    
public:
    myDll();
    ~myDll();
    void append(int i);
    void remove(int i);
    bool find(int i) const;
    void clear();
    void print() const;
    void reverse() const;
    
};

/**********************
 CLASS MEMBER FUNCTIONS
 **********************/

myDll::myDll()
{
    head = nullptr;
    tail = nullptr;
}

myDll::~myDll()
{
    clear();
}

// O(1) operation
void myDll::append(int i)
{
        Node* temp = new Node;
        temp->i = i;
        temp->next = nullptr;
        temp->prev = nullptr;
        
        if(head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    
}

// O(n) operation
void myDll::remove(int i)
{
    Node* temp = head;
    Node* q = nullptr;
    
    // moves pointer into position
    while(temp != 0 && temp->i != i)
    {
        q = temp;
        temp = temp->next;
    }
    
    // if temp is nullptr, then we didnt find a match, so quit
    if(temp == nullptr)
        return;
    
    // if not, we found a node to delete & update pointers
    if(q == nullptr)
    {
        head = temp->next;
    }
    else
    {
        q->next = temp->next;
    }
    
    if(temp->next == nullptr)
    {
        tail = q;
    }
    else
    {
        /***************************************************
                            statement below:
         accesses prev pointers node whose address is stored
         in the next pointer of the node whose address is in
         temp
         ***************************************************/
        temp->next->prev = q;
    }
    delete temp;
}

// O(n) operation
bool myDll::find(int i) const
{
    Node* temp = tail;
    while(temp != nullptr)
    {
        if(temp->i == i)
        {
            return true;
        }
        temp = temp->prev;
    }
    return false;
}

// O(n) operation
// deletes nodes from first to last
void myDll::clear()
{
    while(head != nullptr)
    {
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
    tail = nullptr;
}

void myDll::print() const
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->i << " ";
        temp = temp->next;
    }
    cout << endl;
}

void myDll::reverse() const
{
    Node* temp = tail;
    while(temp != nullptr)
    {
        cout << temp->i << " ";
        temp = temp->prev;
    }
    cout<< endl;
}

#endif
