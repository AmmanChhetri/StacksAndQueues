

// Problem Link - https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int n, last;
    int *arr;
    Stack(int capacity)
    {
        n = capacity;
        last = -1;
        arr = new int[n];
    }

    void push(int num)
    {

        if (last < n - 1)
        {
            arr[last + 1] = num;
            last++;
        }
    }

    int pop()
    {

        // We can only pop if stack has some elements...
        if (last == -1)
        {
            return -1;
        }

        int x = arr[last];
        last--;
        return x;
    }

    int top()
    {

        if (last == -1)
            return -1;

        return arr[last];
    }

    bool isEmpty()
    {
        return (last == -1) ? true : false;
    }

    bool isFull()
    {
        return (last == n - 1) ? true : false;
    }
};

int main()
{

    Stack s(3);
    s.push(12);
    s.push(13);
    s.pop();
    cout << s.top() << endl;
    s.push(100);
    cout << s.top() << endl;
    s.push(200);
    cout << s.isFull() << endl;
    return 0;
}