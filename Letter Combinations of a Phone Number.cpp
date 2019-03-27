class Solution {                                                               //map影响时间复杂度（搜索），递归影响空间复杂度。
public:
    vector<string> letterCombinations(string digits) {
        
        map<char, string> M;
        M['2'] = "abc";
        M['3'] = "def";
        M['4'] = "ghi";
        M['5'] = "jkl";
        M['6'] = "mno";
        M['7'] = "pqrs";
        M['8'] = "tuv";
        M['9'] = "wxyz";
        
        vector<string> results;
        string result;
        
        dpsHandle(M, results, result, digits, 0);
        
        return results;
    }
    
private:
    void dpsHandle(map<char, string> M,
                   vector<string> results,
                   string& result,
                   string digits,
                   int count){
        
        if(count >= digits.size()){
            results.push_back(result);
            return;
        }
        
        for(int i = 0; i < M[digits[count]].size(); i++){
            
            result.push_back(M[digits[count]][i]);
            dpsHandle(M, results, result, digits, count + 1);
            result.pop_back();
    }
    }
};
-----------------------------------------------------------------------------------

class Solution {                                                          //Iterations似乎并没有让速度变快
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> Map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> results;
        
        if(digits.empty()){
            return results;
        }
        results.push_back("");
        
        for(int i = 0; i < digits.size(); i++){
            
            vector<string> temp;
            
            int location = int(digits[i] - '0');
            if(location < 2 || location > 9) break;
            string candidate(Map[location]);
            
            for(int m = 0; m < results.size(); m++){
                for(int n = 0; n < candidate.size(); n++){
                    temp.push_back(results[m] + candidate[n]);
                }
            }
            results.swap(temp);
        }

        return results;
    }
};
