// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   private:
//     int knapsackRecSolver(int W, vector<int> &val, vector<int> &wt, int curr_weight, int curr_value, int index){
//         if(index >= wt.size() || curr_weight >= W){
//             return curr_value;
//         }
//         if(curr_weight + wt[index] > W){
//             return knapsackRecSolver(W, val, wt, curr_weight, curr_value, index+1);
//         }else{
//             return max(knapsackRecSolver(W, val, wt, curr_weight+wt[index], curr_value+val[index], index+1), knapsackRecSolver(W, val, wt, curr_weight, curr_value, index+1));
//         }
//     }
//   public:
//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         // code here
//         return knapsackRecSolver(W, val, wt, 0, 0, 0);
//     }
// };

class Solution {
    
    // int dp[1001][1001];
    // std::memset(dp, -1, sizeof(dp));
    // for(int i = 0; i<dp.size(); i++){
    //     for(int j = 0; j<dp[0].size(); j++){
    //         dp[i][j] = -1;
    //     }
    // }
        
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
            return dp[index][W] = max(val[index] + knapsackRecSolver(W-wt[index], val, wt, index-1, dp), knapsackRecSolver(W, val, wt, index-1, dp));
        }
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return knapsackRecSolver(W, val, wt, val.size()-1, dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends