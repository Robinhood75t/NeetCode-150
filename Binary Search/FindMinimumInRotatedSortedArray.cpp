//Time complexity: O(n) 
class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int minVal = INT_MAX;
        while(st <= end){
            int mid = (st + end)/2;
            minVal = min(nums[mid],minVal);
            if(nums[st] > nums[end]){
                st++;
                minVal = min(nums[end],minVal);
            }else if(nums[st] < nums[end]){
                end--;
                minVal = min(nums[st],minVal);
            }
        }
        return minVal;
    }
};
