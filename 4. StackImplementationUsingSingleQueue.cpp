
// Problem Link - https://leetcode.com/problems/implement-stack-using-queues/

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> q;
    MyStack() {}

    void push(int num)
    {

        q.push(num);
        int sz = q.size();
        for (int i = 1; i <= sz - 1; i++)
        {
            int elm = q.front();
            q.pop();
            q.push(elm);
        }
    }

    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
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