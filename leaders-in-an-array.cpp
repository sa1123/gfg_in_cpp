// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        
        int i = arr.size()-1;
        int max = arr[i];
        
        while(i>-1){
            if(arr[i] >= max){
                ans.insert(ans.begin(), arr[i]);
                max = arr[i];
            }
            i--;
        }
        
        return ans;
    }
};