// Brute Force approach : O(n^2) time complexity & O(1) space complexity
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i , j};
                }
            }
        }
        return {};
    }
};

// Optimal Approach : O(n) time complexity & O(n) space complexity || two pass hashing
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        for(int i = 0; i < nums.size(); i++){
            mymap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(mymap.find(diff) != mymap.end() && mymap[diff] != i){
                return {i,mymap[diff]};
            }
        }
        return {};
    }
};


// Optimal Approach : O(n) time complexity & O(n) space complexity || one pass hashing
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(mymap.find(diff) != mymap.end()){
                return {mymap[diff], i};
            }
            mymap.insert({nums[i], i});
        }
        return {};
    }
};
