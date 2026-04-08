
// Brute force approach: O(n^2) time complexity & O(1) space complexity

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int ele = nums[i];
            for(int j = i + 1; j < n; j++){
                if(nums[j] == ele){
                    return true;
                }
            }
        }
        return false;
    }
};

// Optimal approach: O(n) time complexity & O(n) space complexity
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for(auto& num: nums){
            if(myset.find(num) != myset.end()){
                return true;
            }
            myset.insert(num);
        }
        return false;
    }
};