

// Problem Link - https://leetcode.com/problems/implement-stack-using-queues/

#include <bits/stdc++.h>
using namespace std;

// Logic -
// 1. Insert the new element to q1.
// 2. Transfer all elements from q2 to q1.
// 3. Swap q1 and q2.

// My q2 will always have the elements in increasing order of there occurcence(recent first) & q1 will be empty always...
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int num)
    {
        q1.push(num);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        swap(q1, q2);
    }

    int pop()
    {
        int elm = q2.front();
        q2.pop();
        return elm;
    }

    int top()
    {
        return q2.front();
    }

    bool empty()
    {
        return q2.empty();
    }
};

int main()
{
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << st.pop() << endl;
    cout << st.top() << endl;
    cout << st.empty() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    return 0;
}