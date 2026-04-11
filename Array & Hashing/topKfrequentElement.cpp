//Brute Force approach : O(nlogn) time complexity & O(n) space complexity
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mymap;
        for(int i = 0; i < n; i++){
            mymap[nums[i]]++;
        }

        vector<pair<int,int>> ans;
        for(auto& pair: mymap){
            ans.push_back({pair.second,pair.first});
        }
        sort(ans.rbegin(),ans.rend());

        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(ans[i].second);
        }
        return res;
    }
};
// Brute approach : O(nlogn) time complexity & O(n) space complexity ( slightly better then above approach )
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mymap;
        for(int i = 0; i < nums.size(); i++){
            mymap[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto& pair: mymap){
            pq.push({pair.second,pair.first});
        }
        vector<int> ans;
        while(k > 0){
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }
        return ans;
    }
};


