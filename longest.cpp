class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int start = 0;
        int maxLen = 0;
        int bitmask = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) { // end = i
            // Shrinking the window
            while ((bitmask & nums[i]) != 0) {
                bitmask ^= nums[start];
                start++;
            }
            bitmask |= nums[i];
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
