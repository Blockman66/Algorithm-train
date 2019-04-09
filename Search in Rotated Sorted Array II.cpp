class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        
        int start = 0, end = nums.size() - 1;
        int mid;
        
        while (start + 1 < end) {
            
            mid = start + (end - start) / 2;
            
            if (nums[start] == nums[end] && nums[start] != target) {start++; end--;continue;}
                
            if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target <= nums[mid])
                    end = mid;
                else
                    start = mid;
            }
            
            if (nums[mid] < nums[start]) {
                if (target >= nums[mid] && target <= nums[end])
                    start = mid;
                else
                    end = mid;
            }
        }
        
        if (nums[start] == target || nums[end] == target) return true;
        
        return false;
        
    }
};
