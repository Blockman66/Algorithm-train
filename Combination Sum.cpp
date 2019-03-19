class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> results;
        vector<int> result;
        
        sort(candidates.begin(), candidates.end());
        dpsHandle(result, results, candidates, 0, target);
        
        return results;
    }
    
private:
    
    void dpsHandle(vector<int>& result, 
              vector<vector<int>>& results, 
              vector<int>& candidates,
              int idx,
              int target){
        
        // if(target < 0){
        //     return;
        // }
        if(!target){
            results.push_back(result);
            return;
        }
        
        
        for(int i = idx; i < candidates.size() && candidates[i] <= target; i++){ 
            
        result.push_back(candidates[i]);
        dpsHandle(result, results, candidates, i, target - candidates[i]);
        result.pop_back();
    }
    
    }
    
};
----------------------------------------


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> results;
        vector<int> result;
        int num = 0;
        
        dpsHandle(result, results, candidates, num, 0, target);
        
        return results;
    }
    
private:
    
    void dpsHandle(vector<int>& result, 
              vector<vector<int>>& results, 
              vector<int>& candidates,
              int& num,
              int idx,
              int target){
        
        if(num > target){
            return;
        }
        if(num == target){
            results.push_back(result);
            return;
        }
        
        
        for(int i = idx; i < candidates.size(); i++){  
        num += candidates[i];
        result.push_back(candidates[i]);
           
        int k = i;
        dpsHandle(result, results, candidates, num, k, target);
            
        num -= candidates[i];
        result.pop_back();
    }
    
    }
   
