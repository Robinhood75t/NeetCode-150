class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> myset(nums.begin(),nums.end());
        int longest = 0;
        for(int i = 0; i < n; i++){
            if(myset.find(nums[i] - 1) == myset.end()){
               int count = 1;
               while(myset.find(nums[i] + count) != myset.end()){
                count += 1;
               }
               longest = max(count,longest);
            }
        }
        return longest;
    }
};
