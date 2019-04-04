class Solution {                                                                       //my solution which is not brief.
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int start = 0;
        int end = matrix.size() - 1;
        int mid;
        
        while (start + 1 < end){
            mid = start + (end - start) / 2;
            if (target > matrix[mid][0]) start = mid;
            if (target <= matrix[mid][0]) end = mid;
        }
        
        if (target == matrix[start][0] || target == matrix[end][0])
            return true;
        if (target > matrix[start][0] && target <= matrix[end][0])
            return Judge(matrix[start], target);
        if (target > matrix[end][0])
            return Judge(matrix[end], target);
        
        return false;
    }
    
private:
    bool Judge(vector<int>& n, int target) {
        
        int start = 0;
        int end = n.size() - 1;
        int mid;
        
        while (start + 1 < end){
            mid = start + (end - start) / 2;
            if (target > n[mid]) start = mid;
            if (target <= n[mid]) end = mid;
        }
        
        if (n[start] == target || n[end] == target) return true;
        return false;
    }
};
------------------------------------------------------------------------------------------
    
class Solution {                                                               //通过取模实现
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int start = 0;
        int m = matrix.size(), n = matrix[0].size();
        int end = m * n - 1;
        int mid;
        
        while (start + 1 < end){         //如果这么写，会避免死循环，但会跳过只有一个元素的情况。
            
            mid = start + (end - start) / 2;
            int num = matrix[mid / n][mid % n];
            
            if (target > num) start = mid;
            if (target < num) end = mid;
            if (target == num) return true;
        }
       
        if (matrix[start / n][start % n] == target || matrix[end / n][end % n] == target)
            return true;
        
        return false;
    }
};
