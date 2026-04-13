//Brute force approach : O(n^2) time complexity & O(n) space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int prod = 1;
            for(int j = 0; j < n; j++){
                if(i != j){
                    prod *= nums[j];
                }
            }
            res[i] = prod;
        }
        return res;
    }
};

//Optimal approach : O(n) time complexity & O(1) space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCount = 0;
        for(int num: nums){
            if(num != 0){
                prod *= num;
            }else{
                zeroCount++;
            }
        }

        if(zeroCount > 1){
            return vector<int>(nums.size(),0);
        }

        vector<int> res(nums.size());
        for(size_t i = 0; i < nums.size(); i++){
            if(zeroCount > 0){
                res[i] = (nums[i] == 0) ? prod : 0;
            }else{
                res[i] = prod / nums[i];
            }
        }
        return res;
    }
};


