class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> count;
        for(int num: nums){
            count[num]++;
        }
        
        vector<vector<int>> subs{{}};
        vector<int> sub;
        
        map<int, int>::iterator it;
        
        for(it = count.begin(); it != count.end(); it++){
            int n = subs.size();
            
            for(int i = 0; i < n; i++){
                for(int j = 1; j <= (*it).second; j++){
                    subs.push_back(subs[i]);
                    int loop = j;
                    while(0 != loop--){
                    subs.back().push_back((*it).first);}
                }
            }
        }
        
        return subs;
    }
};

-----------------------------------
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        int idx;
        
        Sort(nums);
        dpsHandle(nums, sub, subs, idx);
        
        return subs;
    }
    
private:
    void Sort(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size() -1 -i; j++){
                if(nums[j] > nums[j + 1]){
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
    
    void dpsHandle(vector<int>& nums,
                   vector<int>& sub,
                   vector<vector<int>>& subs,
                   int idx){
        subs.push_back(sub);
        for(int i = idx; i < nums.size(); i++){
            if(i == idx || nums[i-1] != nums[i]){
                sub.push_back(nums[i]);
                dpsHandle(nums, sub, subs, i + 1);
                sub.pop_back();
            }
        }
    }
};
