class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> result;
        vector<vector<int>> results;
        
        dpsHandle(results, result, 1, k, n);
        
        return results;
    }
    
private:
    void dpsHandle(vector<vector<int>>& results,
                   vector<int>& result,
                   int idx,
                   int k,
                   int n){
        
        if(!k && !n){
            results.push_back(result);
            return;
        }
        if(!k){
            return;
        }
        
        for(int i = idx; i < 10 && i <= n; i++){
            
            result.push_back(i);
            dpsHandle(results, result, i + 1, k - 1, n - i);
            result.pop_back();
        }
    }
};
