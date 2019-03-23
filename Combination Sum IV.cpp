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

class Solution {                                                                      //蠢到爆的算式方法，大数下会超出int的大小范围。
public:
    int combinationSum4(vector<int>& nums, int target) {
    
       int count = 0;
       map<int, int> result;
        
       sort(nums.begin(), nums.end());
       dpsCount(nums, target, count, 0, result);
       
       return count;
    }
    
private:
    
    int factorial(int n){
        int output = 1;
        
        while(n > 1){
            output *= n--;
        }
        return output;
    }
    
    void dpsCount(vector<int>& nums,
                  int target,
                  int& count,
                  int idx,
                  map<int, int> result){
        
        if(!target){
            map<int, int>::iterator it;
            int a = 0;
            int b = 1;
            
            for(it = result.begin(); it != result.end(); it++){
                a += it -> second;
                b *= factorial(it -> second);
            }
            count += factorial(a) / b;
            return;
        }
        
        for(int i = idx; i < nums.size() && nums[i] <= target; i++){
            
            result[nums[i]]++;
            dpsCount(nums, target - nums[i], count, i, result);
            
            if(--result[nums[i]] == 0){
                result.erase(nums[i]);
            }
        }
    }
};

------------------------------------------------------------------------------------------

class Solution {                                                                              //Solution ~
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<unsigned int> result(target + 1);
        result[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num) {
                    result[i] += result[i - num];
                }
            }
        }
        
        return int(result[target]);
    }
};

----------------------------------------------------------------------------------------------
class Solution {                                                                                  //未优化递归（无法通过）
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        if(target == 0){
            return 1;
        }
        
        int result = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= target){
                result += combinationSum4(nums, target - nums[i]);
            }
        }
        
        return result;
    }
};

------------------------------------------------------------------------------------------------------
class Solution {                                                                                     //递归优化         
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> result(target + 1, -1);
        result[0] = 1;
        
        return dpsHandle(nums, result, target);
    }
    
private:
    
    int dpsHandle(vector<int>& nums,
                  vector<int>& result,
                  int target){
        
        if(result[target] != -1){
            return result[target];
        }
        int re = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] > target) continue;
            re += dpsHandle(nums, result, target - nums[i]);
        }
        result[target] = re;
        return re;

    }
};
