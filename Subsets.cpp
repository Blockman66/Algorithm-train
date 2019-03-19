class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    
    vector<vector<int>> subs{{}};
    
    for(int num : nums){
        int n = subs.size();
        for(int i = 0; i < n; i++){
            subs.push_back(subs[i]);
            subs.back().push_back(num);
        }
    }
    return subs;
    }
};

--------------------------------------------------------------
    
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
    int subindex = 0;
    vector<int> subset;
    vector<vector<int>> result;
        
    vector<int> copy(nums);
        
    Sort(copy);
    dpsHandle(copy, subindex, subset, result);
        
    return result;
    }
    
private:
    void Sort(vector<int>& vec){
        
        for(int i = 0; i < vec.size(); i++){
            
            for(int j = 0; j < vec.size() - 1 - i; j++){
                
                if(vec[j] < vec[j+1]){
                    int temp = vec[j+1];
                    vec[j+1] = vec[j];
                    vec[j] = temp;
                }
        }
    }
    }
        
    void dpsHandle(vector<int>& copy,
                   int subindex,
                   vector<int>& subset,
                   vector<vector<int>>& result){
        
        result.push_back(subset);
            for(int j = subindex; j < copy.size(); j++){
                subset.push_back(copy[j]);
                dpsHandle(copy, j + 1, subset, result);
                subset.pop_back();
            }
        
    }
        
};
