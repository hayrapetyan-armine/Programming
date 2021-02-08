class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        
        if (len == 1)
            return 0;
        
        if (len >= 2)
            if (nums[0] > nums[1])
                return 0;
            if (nums[len - 2] < nums[len - 1])
                return len - 1;
        
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i] && nums[i] > nums[i - 1]) {
                return i;
            }
        }
        return -1;
    }
};
