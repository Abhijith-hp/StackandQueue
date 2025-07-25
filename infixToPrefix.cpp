#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPrefix(string s) {
        
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
        }

        stack<char> st;
        string result;

        for (char ch : s) {
            if (ch == ' ') continue;

            if (isalnum(ch)) {
                result += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); 
            } else {
                while (!st.empty() &&
                      (priority(ch) < priority(st.top()) ||
                      (priority(ch) == priority(st.top()) && ch != '^'))) {
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

    
        reverse(result.begin(), result.end());
        return result;
    }
};
