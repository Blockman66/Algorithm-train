class Solution {                                                       //击败 91%， 不懂与100% 的差距在哪里。
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> results;
        vector<string> result;
        
        if(s.empty()) return {};
        
        dpsHandle(results, result, s, 0);
        
        return results;
    }
private:
    bool if_palindrome(string& n, int i, int j){
        while(i < j){
            if(n[i] != n[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void dpsHandle(vector<vector<string>>& results,
                   vector<string>& result,
                   string s,
                   int idx){
        
        if(idx == s.size()){
            results.push_back(result);
            return;
        }
        for(int i = idx; i < s.size(); i++){
            
            if(if_palindrome(s, idx, i)){
            
            result.push_back(s.substr(idx, i - idx + 1));
            dpsHandle(results, result, s, i + 1);
            result.pop_back();
            }
    }
    return;
    }
};
