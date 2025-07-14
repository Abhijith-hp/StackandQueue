#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool expression(const string& expr){
    stack<char> st;
    for(char ch:expr){
        
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }else if(ch==')' || ch=='}' || ch==']'){
            if (st.empty()) return false;
            char topch = st.top();
            st.pop();
            
            if((ch==')' && topch!='(') || (ch==']') && topch!='[') || 
            (ch=='}' && topch!='{') return false;
        }
    }
    
    return st.empty();
}



int main() {
     string expr;

    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr)) {
        cout << "Balanced parentheses << endl;
    } else {
        cout << "Unbalanced parentheses << endl;
    }

    return 0;
}