// Brute force approach time complexity O(n^3) space complexity O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> myset;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        myset.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        return vector<vector<int>>(myset.begin(),myset.end());
    }
};
