class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while(i <= j){
            int mid = (i + j)/ 2;

            if(nums[mid] == target){
                return mid;
            }
            if(nums[i] < target){
                i++;
            }else {
                j--;
            }
        }
        return -1;
    }
};
