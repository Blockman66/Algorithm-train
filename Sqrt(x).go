func mySqrt(x int) int {
    
    start := 0

    for {
        if start * start > x {
            start--
            break
        }
        start++
    }
    
    return start
}

-------------------------------------------------------------------------------------------------------------

func mySqrt(x int) int {
    
    if x == 0 || x == 1{
        return x
    }
    
    start := 0
    end := x
    
    for start + 1 < end {
        mid := start + (end - start) / 2
        
        if mid * mid <= x {
            start = mid
        }
        if mid * mid > x {
            end = mid
        }
    }
    
    return start
}
