// Brute Forece approach : O(nlogn) time complexity & O(1) space complexity
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

// Optimal approach : O(n) time complexity & O(n) in general , but O(1) space complexity
class Solution {
public:
    bool isAnagram(string s, string t) {
        string lar = (s.length() >= t.length()) ? s : t;
        string sml = (s.length() >= t.length()) ? t : s;
        unordered_map<char,int> mymap;
        for(int i = 0; i < lar.length(); i++){
            mymap[lar[i]]++;
        }
        for(int i = 0; i < sml.length(); i++){
            if(mymap.find(sml[i]) != mymap.end()){
                mymap[sml[i]]--;
                if(mymap[sml[i]] == 0){
                    mymap.erase(sml[i]);
                }
            }
        }
        return mymap.empty();
    }
};

