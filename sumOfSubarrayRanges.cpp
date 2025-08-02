#include <vector>
#include <stack>
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

    long long sumOfMax(vector<int>& arr) {
        int n = arr.size();
        int* nge = nextGreater(arr);
        int* pge = previousGreater(arr);
        long long total = 0;

        for (int i = 0; i < n; ++i) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            long long contrib = 1LL * arr[i] * left * right;
            total += contrib;
        }

        delete[] nge;
        delete[] pge;
        return total;
    }

    int* previousSmall(vector<int>& arr) {
        int size = arr.size();
        int* pse = new int[size];
        stack<int> st;

        for (int i = 0; i < size; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    int* nextSmall(vector<int>& arr) {
        int size = arr.size();
        int* nse = new int[size];
        stack<int> st;

        for (int i = size - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? size : st.top();
            st.push(i);
        }

        return nse;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int* pse = previousSmall(arr);
        int* nse = nextSmall(arr);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contrib = 1LL * arr[i] * left * right;
            total += contrib;
        }

        delete[] pse;
        delete[] nse;
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long sumOfMinimum = sumSubarrayMins(nums);
        long long sumOfMaximum = sumOfMax(nums);
        return sumOfMaximum - sumOfMinimum;
    }
};
