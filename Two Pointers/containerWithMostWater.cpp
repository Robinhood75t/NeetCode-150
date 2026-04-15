// Brute Force Approach Time Complexity O(n^2) space complexity O(1)
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int area = min(heights[i] , heights[j]) * abs(i - j);
                maxArea = max(area,maxArea);
            }
        }
        return maxArea;
    }
};
// Optima Approach Time Complexity O(n) space complexity O(1)
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        int i = 0 , j = n - 1;
        while(i <= j){
            int minHeight = min(heights[i], heights[j]);
            int area = minHeight * (j - i);
            maxArea = max(area,maxArea);
            if(minHeight == heights[i]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
};

