class Solution {                                                                        //my solution
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        int start = 0, end = nums.size() - 1;
        int mid;
        int lastnum = nums[nums.size() - 1];
        
        if (target <= lastnum) {
            while (start + 1 < end) {
                mid = start + (end - start) / 2;
                if (nums[mid] > lastnum) {
                    start = mid;
                    continue;
                }
                if (nums[mid] >= target)
                    end = mid;
                else
                    start = mid;
            }
        }
        
        if (target > lastnum) {
            while (start + 1 < end) {
                mid = start + (end - start) / 2;
                if (nums[mid] <= lastnum) {
                    end = mid;
                    continue;
                }
                if (nums[mid] >= target)
                    end = mid;
                else
                    start = mid;
            }
        }
        
        if (nums[start] == target) return start;
        if (nums[end] == target) return end;
        
        return -1;
    }
};
--------------------------------------------------------------------------------------------------

Discussion里面的方法没看懂。。。。

