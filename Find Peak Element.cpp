class Solution {                                                                 //一个不简洁的答案
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return (nums[0]>nums[1])?0:1;
        
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        while(start + 1 < end){
            mid = start + (end - start) / 2;
            
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] < nums[mid - 1]){
                end = mid;
                continue;
            } else {
                start = mid;
            }
        }
        
        return (nums[start] > nums[end]) ? start:end;
    }
};

---------------------------------------------------------------------------------------------------------
class Solution {                                                                    //非logn复杂度，但居然能通过？？
public:
    int findPeakElement(const vector<int> &num) {
        
        if (num.empty()) return -1;
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] < num[i-1])
            {
                return i-1;
            }
        }
        return num.size()-1;
    }
};
------------------------------------------------------------------------------------------------------
