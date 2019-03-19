class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> results;
        vector<int> result;
        
        sort(candidates.begin(), candidates.end());
        dpsHandle(candidates, results, result, target, 0);
        return results;
    }
    
private:
    void dpsHandle(vector<int>& candidates, 
                   vector<vector<int>>& results,
                   vector<int>& result,
                   int target,
                   int idx){
        
        if(!target){
            results.push_back(result);
            return;
        }
        
        for(int i = idx; i < candidates.size() && candidates[i] <= target; i++){
            
            if(i > idx && candidates[i] == candidates[i - 1]) continue;

            result.push_back(candidates[i]);
            dpsHandle(candidates, results, result, target - candidates[i], i + 1);
            result.pop_back();
            }
    }
};
