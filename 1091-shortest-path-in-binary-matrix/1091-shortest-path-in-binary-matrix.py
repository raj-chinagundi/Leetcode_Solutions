class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [[-1,-1],[0,-1],[1,-1],[1,0],[1,1],[0,1],[-1,1],[-1,0]]
        n = len(grid)
        if grid[n-1][n-1]==1 or grid[0][0]==1:
            return -1
        
        queue = []
        queue.append([0,0])
        grid[0][0] = 1
        while len(queue)>0:
            t = queue.pop(0)
            for i in range(8):
                new_x = directions[i][0]+t[0]
                new_y = directions[i][1]+t[1]
                if (new_x>=0 and new_x<n) and (new_y>=0 and new_y<n) and grid[new_x][new_y]==0:
                    grid[new_x][new_y] = grid[t[0]][t[1]]+1
                    queue.append([new_x,new_y])

        return grid[n-1][n-1] if grid[n-1][n-1]!=0 else -1        