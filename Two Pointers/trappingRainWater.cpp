// Brute force approach time complexity O(n^2) space complexity O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0){
            return 0;
        }
        int res = 0;

        for(int i = 0; i < n; i++){
            int leftMax = height[i];
            int rightMax = height[i];

            for(int j = 0; j < i; j++){
                leftMax = max(leftMax,height[j]);
            }
            for(int j = i + 1; j < n; j++){
                rightMax = max(rightMax,height[j]);
            }
            res += min(leftMax , rightMax) - height[i];
        }
        return res;
    }
};

// Optimal approach time complexity O(n) space complexity O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i - 1],height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1],height[i]);
        }

        for(int i = 0; i < n; i++){
            res += min(leftMax[i],rightMax[i]) - height[i];
        }

        return res;
    }
};
// Optimal approach time complexity O(n) space complexity O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0 , r = n - 1;
        int res = 0;
        int leftMax = height[l], rightMax = height[r];
        while(l < r){
            if(height[l] < height[r]){
                l++;
                leftMax = max(leftMax,height[l]);
                res += leftMax - height[l];
            }else{
                r--;
                rightMax = max(rightMax,height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
