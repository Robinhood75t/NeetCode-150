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
// Binary search solution - O(log n)

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int minVal = INT_MAX;
        while(st <= end){
            if(nums[st] < nums[end]){
                minVal = min(nums[st], minVal);
                break;
            }
            int mid = st + (end - st) / 2;
            minVal = min(minVal,nums[mid]);

            if(nums[mid] >= nums[st]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return minVal;
    }
};
