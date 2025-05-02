// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int recSolver(vector<int>& arr, int target, int index, vector<vector<int>>& dp){
        if(index > arr.size()){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        if(arr[index] > target){
            return dp[index][target] = recSolver(arr, target, index+1, dp);
        }else{
            return dp[index][target] = recSolver(arr, target-arr[index], index+1, dp) + recSolver(arr, target, index+1, dp);
        }
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        if(target == 0){
            double numofZeros = 0;
            for(int i = 0; i<arr.size(); i++){
                if(arr[i] == 0){
                    numofZeros++;
                }
            }
            return int(pow(2,numofZeros) + 0.000000001);
        }else{
            sort(arr.begin(), arr.end());
            vector<vector<int>> dp(arr.size()+1, vector<int>(target+1, -1));
            return recSolver(arr, target, 0, dp);
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends