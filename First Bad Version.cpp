// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0;
        int mid;
        
        while (start + 1 < n) {
            mid = start + (n - start) / 2;
            
            if (!isBadVersion(mid)) start = mid;
            if (isBadVersion(mid)) n = mid;
    }
        if (isBadVersion(start)) return start;
        return n;
    }
};
