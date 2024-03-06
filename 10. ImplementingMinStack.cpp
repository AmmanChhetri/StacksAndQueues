
// Problem Link - https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

// Logic -
/*
    1. So whenever we call push() we need to push in stack...whenever we call the pop() we need to pop from the stack...for top() we need to return the top of stack...and for getMin() we need to get the min element of the stack....so we cant change the order in which the elements is occuring because when we say pop() we need to pop the Last In element...so which means we need to have elements in the order...so which means we need to keep the elements in the order in a stack...and we need a datastructure that keeps element in the ascending order...so we can use something like min-Heap...that stores elements in ascending order...but the problem is the minHeap itself takes nlogn time to maintain the order of elements...whenever we pop any element...we need to remove it from the minHeap too...so this wont be a good approach...as we want every operation to be in O(1) time...so we thought of some other logic..

    2. as we want two DataStructure ...one to keep element in the order of there occurence(Stack) and one in ascending order(minHeap)..so why can't we store them as one...using stack<pair<int,int>> ...where each element of stack represents a pair...where pair.first represents the element ...and pair.second represents the minimum element till now...how to think of this is simple..we know we don't want to alter the sequence of elements that are coming in the stack...as push(), pop() and top()...is applied on the orginal stack...but for getMin() we want the minimum element...so we know we are filling the stack right?....so when we fill any element in the stack...we know what was the last element(through top)..so what if we also know what was the minimum till that number...if only we know...we can tell the minimum till now after adding new element...as we know the value of this new element....

    3. Optimal Approach - Using just a variable to store the minimum...we just have to change the function accordingly....which is explained in this video , just dry run the example taken here - https://www.youtube.com/watch?v=V09NfaGf2ao
    see our main aim in the bruteForce was to maintain the elements in ascending order right? ...so that even if the minimum element is deleted ...we will still have the second minimum....but just to store this we were taking extra space....so we use a hashing technique to handle this...in which we are just maintaining a single variable to store the minimum....

    Suppose the elements we have to insert are -2,0,-3...first we insert -2..as the stack is empty...so our minimum will be -2...when 0 comes...as 0 is > -2(mini)..which means later at some point even if we delete this 0...it wont affect my mini right...we can delete this element blindly...but when -3 comes...this is < mini(-2)...so if we push this element at update our mini...and after we do pop() this -3 will be deleted from the stack...and then our mini still remains -3...we can't go back to what it was before..so we have to do something else to solve this issue...we have to push a modified value...such that modified value remains < mini....refer the above video for proof...
*/

// Approach - 1
class MinStack1UsingPairs
{
public:
    stack<pair<int, int>> st;
    void push(int num)
    {

        if (st.empty())
        {
            st.push({num, num});
        }
        else
        {
            int mini = min(st.top().second, num); // minimum till now
            st.push({num, mini});
        }
    }
    void pop()
    {

        st.pop();
    }
    int top()
    {
        // have to return the top element of the stack
        return st.top().first;
    }
    int getMin()
    {
        // have to return the minimum element till now
        return st.top().second;
    }
};

// Approach - 2
class MinStackOptimal
{
public:
    stack<int> st;
    int mini;
    MinStackOptimal()
    {
        mini = INT_MAX;
    }

    void push(int num)
    {
        if (st.empty())
        {
            st.push(num);
            mini = num;
        }
        else
        {
            int elm = st.top();
            if (num > mini)
            {
                // just insert the value directly..as it wont affect our min element...
                st.push(num);
            }
            else
            {
                // push the modified value
                int modifiedValue = 2 * num - mini;
                mini = num;
                st.push(modifiedValue);
            }
        }
    }

    void pop()
    {

        int elm = st.top();
        st.pop();
        if (elm < mini)
        {
            // this is a modified value...if we delete this...we have to revert our min element to previous value...
            // for the given example above we know 2*val - oldMini = -4...here val is the original value to be pushed at that time...which is nothing but the current mini....which means = oldMini = 2*currMini + 4 (st.top())..
            mini = 2 * mini - elm;
        }
    }

    int top()
    {
        int elm = st.top();
        if (elm < mini)
        {
            // this is a modified value...and we know we have this modified value here...because this current minimum element...as to update this minimum value to current value i have pushed the modified value...
            return mini;
        }

        return elm;
    }

    int getMin()
    {
        return mini;
    }
};

int main()
{
    // Time Complexity - O(1)
    // Space Complexity - O(2n)
    MinStack1UsingPairs minStack1;
    minStack1.push(10);
    minStack1.push(1);
    minStack1.push(4);
    minStack1.push(2);
    minStack1.push(9);

    cout << minStack1.getMin() << endl;
    minStack1.pop();
    cout << minStack1.getMin() << endl;
    cout << minStack1.top() << endl;

    // Time Complexity - O(1)
    // Space Complexity - O(n)
    MinStackOptimal minStack2;
    minStack2.push(10);
    minStack2.push(1);
    minStack2.push(4);
    minStack2.push(2);
    minStack2.push(9);

    cout << minStack2.getMin() << endl;
    minStack2.pop();
    cout << minStack2.getMin() << endl;
    cout << minStack2.top() << endl;

    return 0;
}