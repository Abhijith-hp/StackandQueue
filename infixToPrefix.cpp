#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPostfix(string& s) {
        stack<char> st;
        string ans;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == ' ') continue;  

            if (isalnum(ch)) {
                ans += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); 
            } else {
                while (!st.empty() &&
                       (priority(ch) < priority(st.top()) ||
                       (priority(ch) == priority(st.top())))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
