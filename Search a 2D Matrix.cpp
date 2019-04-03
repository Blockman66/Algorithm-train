class Solution {
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
