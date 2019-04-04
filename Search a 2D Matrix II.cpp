class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int x = 0, y = matrix.size() - 1;
        
        while (x <= matrix[0].size() - 1 && y >= 0) {
            
            if (target > matrix[y][x]) {
                x++;
                continue;
            } else if (target < matrix[y][x]) {
                y--;
                continue;
            }
            return true;
        }
        
        return false;
    }
};
