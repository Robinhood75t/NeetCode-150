// baccho vala solution.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for(int i = 0; i < nums.size(); i++){
            if(myset.find(nums[i]) != myset.end()){
                return nums[i];
            }else{
                myset.insert(nums[i]);
            }
        }
        return -1;
    }
};
 


