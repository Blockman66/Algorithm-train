class Solution {                                                //一种在高target时候会爆栈的双向递归（无法通过测试）
public:
    int combinationSum4(vector<int>& nums, int target) {
    
       int count = 0;
        
       sort(nums.begin(), nums.end());
       dpsCount(nums, target, count, 0);
       
       return count;
    }
    
private:
    void dpsCount(vector<int>& nums,
                  int target,
                  int& count,
                  int idx){
        
        if(!target){
            count++;
            return;
        }
        
        for(int i = idx; i < nums.size() && nums[i] <= target; i++){
            dpsCount(nums, target - nums[i], count, i);
        }
        for(int i = idx - 1; i >= 0; i--){
            if(target < nums[i]) continue;
            dpsCount(nums, target - nums[i], count, i);
        }
    }
};

----------------------------------------------------------------------------------------

