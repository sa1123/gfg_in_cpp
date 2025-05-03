// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    int knapsackRecSolver(int W, vector<int> &val, vector<int> &wt, int index, int dp[1001][1001]){
        if(index < 0 || W <= 0){
            return 0;
        }
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        if(W - wt[index] < 0){
            return dp[index][W] = knapsackRecSolver(W, val, wt, index-1, dp);
        }else{
            return dp[index][W] = max(val[index] + knapsackRecSolver(W-wt[index], val, wt, index, dp), knapsackRecSolver(W, val, wt, index-1, dp));
        }
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return knapsackRecSolver(capacity, val, wt, val.size()-1, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends