func peakIndexInMountainArray(A []int) int {
    
    if len(A) == 0 { return -1}
    
    start, end := 0, len(A) - 1
    var mid int
    
    for start + 1 < end {
        mid = start + (end - start) / 2
        
        if A[mid] < A[mid + 1] {
            start = mid
            continue
        } else {
            end = mid
        }
        
    }
    return end
}
