class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            
            if (nums[mid] < target) start = mid;
            if (nums[mid] >= target) end = mid;
        }
        
        
        if (target <= nums[start]) return start;
        if (target > nums[start] && target <= nums[end]) return end;
        
        return end + 1;
    }
};
