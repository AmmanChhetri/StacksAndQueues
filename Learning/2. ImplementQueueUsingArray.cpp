

// Problem Link - https://www.codingninjas.com/studio/problems/implement-queue-using-arrays_8390825

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int start, end, n;
    int *arr;

    Queue(int capacity)
    {
        n = capacity;
        start = -1; // start will point to the first element...
        end = -1;   // end will point to the last elemnet inserted...
        arr = new int[n];
    }

    void push(int num)
    {

        if (end < n - 1)
        {
            if (end == -1) // if inserting for the first time ...then increase the start pointer...
                start++;
            arr[end + 1] = num;
            end++;
        }
    }

    int pop()
    {

        if (end == -1)
            return -1; // no element is present

        int x = arr[end];
        end--;
        return x;
    }

    int front()
    {

        if (start == -1)
            return -1;

        return arr[start];
    }

    bool isEmpty()
    {
        return (end == -1) ? true : false;
    }

    bool isFull()
    {
        return (end == n - 1) ? true : false;
    }
};

int main()
{

    Queue q(3);
    q.push(100);
    q.push(122);
    q.push(145);
    q.push(1000);

    cout << q.pop() << endl;
    cout << "Current Front element : " << q.front() << endl;
    cout << "Is Full : " << q.isFull() << endl;
    cout << "Is Empty : " << q.isEmpty() << endl;
    return 0;
}