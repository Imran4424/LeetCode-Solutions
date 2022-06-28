class Solution {
    
    var path = Array(repeating: 0, count: 46)

    func climbStairs(_ n: Int) -> Int {
        if n == 1 || n == 2 {
            return n
        }
        
        if path[n] != 0 {
            return path[n]
        }
        
        path[n] = climbStairs(n - 1) + climbStairs(n - 2)
        return path[n]
    }
}