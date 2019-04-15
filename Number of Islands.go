func numIslands(grid [][]byte) int {
    
    if len(grid) == 0 || len(grid[0]) == 0 {
        return 0
    }
    
    l := len(grid)
    w := len(grid[0])
    num := 0
    
    for i := 0; i < l; i++ {
        for j := 0; j < w; j++ {
            if grid[i][j] == '1' {
                Handle(grid, l, w, i, j)
                num++
            }
        }
    }
    return num
}

func Handle(grid [][]byte, l int, w int, i int, j int) {
    
    if i < 0 || j < 0 || i >= l || j >= w || grid[i][j] == '0' {
        return
    }
    
    grid[i][j] = '0'
    
    Handle(grid, l, w, i - 1, j)
    Handle(grid, l, w, i + 1, j)
    Handle(grid, l, w, i, j + 1) 
    Handle(grid, l, w, i, j - 1)
}
