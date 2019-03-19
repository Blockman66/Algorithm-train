class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        Handle(nums, 0, result);
        
        return result;
    }
    
private:
    void Handle(vector<int>& nums, int idx, vector<vector<int>>& result){
        
        if(idx == nums.size() -1){
            result.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            Handle(nums, idx + 1, result);
            swap(nums[idx], nums[i]);
        }
    }
};

---------------------------------------------
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int n = factorial(nums.size());
        for(int i  = 0; i < n; i++){
            result.push_back(nums);
            next_permutation(nums);
        }
        
        return result;
    }
    
private:
    int factorial(int n){
        int fac = 1;
        while(n > 1){
            fac *= n--;
        }
        return fac;
    }
    
    void next_permutation(vector<int>& nums){
        
        int n = nums.size();
        int i, j;
        for(i = n - 2; i >= 0; i--){
            
            if(nums[i] < nums[i + 1]){
            break;
            }
        }
        if(i < 0){
            reverse(nums.begin(), nums.end());
        }  else {
            
        for(j = n - 1; j > i; j--){
            if(nums[j] > nums[i]){
                break;
            }
        }
        
        swap(nums[j], nums[i]);
        reverse(nums.begin() + i + 1, nums.end());
    }
  }
};
