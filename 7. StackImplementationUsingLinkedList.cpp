
// Problem Link - https://www.codingninjas.com/studio/problems/implement-stack-with-linked-list_1279905

#include <bits/stdc++.h>
using namespace std;

// Here for this Question where we need to implement stacks using LinkedList...we have two options:
// 1. Either we store the elements in the fashion of putting every new element to the end of the LinkedList.
// 2. Or we can store the new element in the front...

// By using the first method....whenver we call push() and top() it happens in O(1) time...but the pop() will occur in O(n) time..even if we store the address of the tail node...then we can add and get the top element in O(1) time...but for poping the element...we can do it just using tail node in O(1) time..as it is a singly LinkedList....
// If we go with the second method...then push will be O(1) time...and pop() and top() also occur in O(1) time...so this method is optimal..

// Defining the class for Node for the LinkedList
class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Defining Class for Stack
class Stack
{
public:
    Node *head;
    Stack()
    {
        head = nullptr;
    }

    void push(int num)
    {

        Node *temp = new Node(num);
        temp->next = head;
        head = temp;
    }

    int pop()
    {
        Node *curr = head;
        int val = curr->data;
        head = head->next;
        free(curr);

        return val;
    }

    int top()
    {

        return head->data;
    }

    bool empty()
    {

        return (head == nullptr) ? true : false;
    }
};

int main()
{

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
    s.pop();
    s.pop();
    cout << s.empty() << endl;

    return 0;
}