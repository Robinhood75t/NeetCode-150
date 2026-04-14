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
