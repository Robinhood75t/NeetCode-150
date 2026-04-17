//Brute force approach : O(n * mlogm) time complexity & O(n * m) space complexity
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mymap;
        for(int i = 0; i < strs.size(); i++){
            string st = strs[i]; 
            sort(st.begin(),st.end()); 
            mymap[st].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto& arr: mymap){
            ans.push_back(arr.second);
        }
        return ans;
    }
};
