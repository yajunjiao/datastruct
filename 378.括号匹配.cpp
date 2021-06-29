/*************************************************************************
	> File Name: 378.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Jun 2021 01:27:58 AM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

bool isMatch(string input) {
    int ans = 0;
    int len = input.length();
    std::stack<int> st;
    for (int i = 0; i < len; i++) {
        if(ans == -1) {
            break;
        }
        switch (input[i]) {
            case '(':
                st.push(1); 
                break;
            case ')':
            {
                int top = st.top();
                if (top == 1) {
                    st.pop();
                    break;
                } else {
                    ans = -1;
                    break;
                }
            }
            case '[':
                st.push(2);
                break;
            case ']':
            {
                int top = st.top();
                if (top == 2) {
                    st.pop();
                    break;
                } else {
                    ans = -1;
                    break;
                }
            }
            case '{':
                st.push(3);
                break;
            case '}':
            {
                int top = st.top();
                if (top == 3) {
                    st.pop();
                    break;
                } else {
                    ans = -1;
                    break;
                }
            }
            default: break;
        }
    }
    ans = ans != -1 && st.empty() ? 1 : 0;
    return ans;
}

int main() {
    string input;
    cin >> input;
    if (isMatch(input)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
