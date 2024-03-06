
// Problem Link - https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

// Logic -
/*
    For BruteForce : We know we need to check whether the string is a valind parantheses or not..which means first thing is for every opening bracket there must be a closing bracket...which means if the string length  is odd...its always false...now the main idea is ...whenever we encounter a closing bracket...we need to check the most `recent unused opening bracket`....(this line is very important)...and if the opening and closing bracket makes a pair...then its good we check further...if they dont...then we return false...as its never possible...now there can be some edge cases... 1. we still have some closing brackets left..but we are out of opening brackets...to make pair
             2. we dont have any closing brackets...but sill have openining brackets left...to make pair
             3.when we are searching for a valid opening bracket for a closing bracket...we are unable to find one..

    Now for a particular closing brakcet when we move backwards to check the most recent opening bracket...we have to know whether the opening bracket has been paired before or not...so for that we have to use a visited array...


    For Optimal : if we observe carefully...what we are doing is whenever we are encountering a closing bracket...we are checking the `most recent opening bracket`....so what if we store the opening brackets somewhere...because its not a good choice to go back again and again to see the opening bracket for a particular closing bracket...we have reached this closing bracket(let's say at index `i`) after visting indexes from 0 to i...and as we just bothered about the opening brackets...why not we store it somewhere...that's why we thought of using stack :)...
*/

class Solution
{
public:
    int validParaenthesesBrute(string s)
    {

        int n = s.length();
        vector<int> visited(n, 0);
        unordered_map<char, char> mpp = {{'}', '{'}, {']', '['}, {')', '('}};

        for (int i = 0; i < n; i++)
        {

            // if closing bracket
            if (mpp.find(s[i]) != mpp.end())
            {
                bool found = false; // to check if the pair for the current closing bracket is found or not...
                int j = i - 1;
                while (j >= 0)
                {
                    if (visited[j] == 0 && (mpp.find(s[j]) == mpp.end()))
                    {
                        // mpp.find(s[j]) == mpp.end() => not present in the map...which means this is a opening bracket...
                        if (mpp[s[i]] != s[j])
                        {
                            return false;
                        }

                        visited[i] = 1;
                        visited[j] = 1;
                        found = true;
                    }

                    if (found)
                        break;

                    j--;
                }

                if (found == false)
                {
                    return false;
                }
            }
        }

        // this check is verifying if we dont have any brackets left before or after...
        if (visited[0] == 0 || visited[n - 1] == 0)
        {
            return false;
        }

        return true;
    }

    int validParaenthesesOptimal(string s)
    {
        int n = s.length();
        stack<char> st;
        unordered_map<char, char> mpp = {{')', '('}, {'}', '{'}, {']', '['}};

        for (int i = 0; i < n; i++)
        {
            // if opening bracket...push it in the stack
            if (mpp.find(s[i]) == mpp.end())
            {
                st.push(s[i]);
            }
            else
            {
                // closing bracket...we need to check if the top of the stack(that represents the most recent opening bracket)...makes a pair with the current closing bracket or not...if yes then we pop it from stack...otherwise return false...but we also need to check if we have something in the stack top or not...if not which means...we dont have any opening bracket for this closing bracket...so false...
                if (st.empty())
                {
                    return false;
                }

                if (mpp[s[i]] != st.top())
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }

        // at the end...just check if the stack is empty...meaning every opening bracket has been paired
        if (!st.empty())
        {
            return false;
        }

        return true;
    }
};

int main()
{

    Solution sol;

    string s;
    cout << "Enter the string of brackets : " << endl;
    cin >> s;

    cout << "Using BruteForce Approach :" << sol.validParaenthesesBrute(s) << endl;
    cout << "Using BruteForce Approach :" << sol.validParaenthesesOptimal(s) << endl;

    return 0;
}