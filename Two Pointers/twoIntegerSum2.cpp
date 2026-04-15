
// Brute Forece Approach Time Complexity O(n^2) space complexity O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(numbers[i] + numbers[j] == target){
                    return {i + 1,j + 1};
                }
            }
        }
        return {};
    }
};

Two pointer approach --

// Optimal Approach Time complexity O(n) space complexity O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int n = numbers.size();
        int i = 0,j = n - 1;
        while(i < j){
            if(numbers[i] + numbers[j] == target){
                return {i + 1 , j + 1};
            }
            else if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                i++;
            }
        }
        return {};
    }
};

