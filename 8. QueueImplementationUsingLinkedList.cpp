
// Problem Link - https://www.codingninjas.com/studio/problems/implement-queue-using-linked-list_8161235

#include <bits/stdc++.h>
using namespace std;

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

class Queue
{
public:
    Node *head;
    Node *tail;

    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push(int num)
    {

        if (head == nullptr)
        {
            // this will be the first element in the queue / linkedList..
            head = new Node(num);
            tail = head;
        }
        else
        {
            // we already have some elements in the stack/linkedList
            Node *temp = new Node(num);
            tail->next = temp;
            tail = tail->next;
        }
    }

    int pop()
    {

        Node *temp = head;
        int ans = temp->data;
        head = head->next;
        delete temp;

        return ans;
    }

    int front()
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

    Queue q;
    q.push(100);
    q.push(122);
    q.push(145);
    q.push(1000);

    cout << q.pop() << endl;
    cout << "Current Front element : " << q.front() << endl;
    cout << "Is Empty : " << q.empty() << endl;
    return 0;
}