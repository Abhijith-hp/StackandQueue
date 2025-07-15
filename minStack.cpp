#include <stack>

class MinStack {
public:
    
    std::stack<long long> st;
    long long minVal;

    MinStack() {
      while (!st.empty()) st.pop();
      minVal = LLONG_MAX;
    }
    
    void push(int val) {
       if(st.empty()){
        st.push(val);
        minVal=val;
       }else if(val>minVal){
        st.push(val);
       }else{
        st.push(2LL*val - minVal);
        minVal = val;
       }
    }
    
    void pop() {
       if(st.empty()) return;
       long long encodedVal = st.top();
       st.pop();
       if(encodedVal<minVal){
        minVal = 2LL * minVal - encodedVal;
       }
    }
    
    int top() {
        if(st.empty()) return 0; 
        long long topVal = st.top();
        if(minVal<=topVal) return topVal;
        return minVal;
    }
    
    int getMin() {
        return minVal;
    }
};
