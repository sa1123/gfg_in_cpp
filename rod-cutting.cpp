// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    int cutRodRec(vector<int> &price, int index, int rodsize, int dp[1001][1001]){
        if(index < 0 || rodsize <= 0){
            return 0;
        }
        if(dp[index][rodsize] != -1){
            return dp[index][rodsize];
        }
        if(index+1 > rodsize){
            return dp[index][rodsize] = cutRodRec(price, index-1, rodsize, dp);
        }else{
            return dp[index][rodsize] = max(price[index] + cutRodRec(price, index, rodsize-index-1, dp), cutRodRec(price, index-1, rodsize, dp));
        }
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return cutRodRec(price, price.size()-1, price.size(), dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends