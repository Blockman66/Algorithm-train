class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> copy(nums);
        
        do{
            result.push_back(nums);
            Dictionary(nums);
        }while(Dif_exist(nums, copy));
        
        return result;
    }

private:
    
     bool Dif_exist(vector<int>& nums, vector<int>& copy){
         int n = copy.size();
         for(int i = 0; i < copy.size(); i++){
             if(nums[i] != copy[i]){
                 return true;
             }
         }
         return false;
     }
  
     void Dictionary(vector<int>& nums){
         int n = nums.size();
         int i, j;
         
         for(i = n - 2; i >= 0; i--){
             if(nums[i] < nums[i + 1]){
                 break;
             }
         }
         if(i < 0){
             reverse(nums.begin(), nums.end());
             return;
         }
         
         for(j = n - 1; j > i; j--){
             if(nums[j] > nums[i]){
                 break;
             }
         }
         
         swap(nums[i], nums[j]);
         reverse(nums.begin() + i + 1, nums.end());
     }

};
--------------------------------------------------------

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> result;
        int idx = 0;
        
        sort(nums.begin(), nums.end());
        recursion(nums, result, idx);
        
        return result;
    }
    
private:
    bool Judge(int start, int end, vector<int>& nums){
        for(; start < end; start++){
            if(nums[start] == nums[end]){
                return false;
            }
        }
        return true;
    }
    
    void recursion(vector<int>& nums,
                   vector<vector<int>>& result,
                   int idx){
        
        if(idx >= nums.size() - 1){
            result.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++){

            if(Judge(idx, i, nums)){
                  swap(nums[i], nums[idx]);
                  recursion(nums, result, idx + 1);
                  swap(nums[i], nums[idx]);
              }
          
              
    }
}
    
};
