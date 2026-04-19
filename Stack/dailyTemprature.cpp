// Brute force Time complexity O(n^2) space complexity O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(temperatures[i] < temperatures[j]){
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};