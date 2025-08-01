#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:

    int* nextGreater(const vector<int>& arr) {
        int size = arr.size();
        int* nge = new int[size];
        stack<int> st;

        for (int i = size - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nge[i] = st.empty() ? size : st.top();
            st.push(i);
        }

        return nge;
    }

    int* previousGreater(const vector<int>& arr) {
        int size = arr.size();
        int* pge = new int[size];
        stack<int> st;

        for (int i = 0; i < size; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pge;
    }

    int sumOfMax(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int* nge = nextGreater(arr);
        int* pge = previousGreater(arr);
        long long total = 0;

        for (int i = 0; i < n; ++i) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            long long contrib = ((arr[i] * left) % MOD * right) % MOD;
            total = (total + contrib) % MOD;
        }

       
        return static_cast<int>(total);
    }
};
