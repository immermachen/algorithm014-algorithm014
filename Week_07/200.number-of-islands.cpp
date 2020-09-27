/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class UF {
    int count=0;
    vector<int> parent;
    vector<int> size;
public: 
    UF(vector<vector<char>>& grid) {
        int M=grid.size(), N=grid[0].size();
        parent.reserve(M*N);
        size.reserve(M*N);
        for(int i=0;i<M;++i) {
            for(int j=0;j<N;++j) {
                if(grid[i][j]=='1') {
                    parent[i*N+j]=i*N+j;
                    size[i*N+j]=1;
                    count++;
                }
                else 
                    parent[i*N+j] = -1;                
            }
        }
    }
    void Union(int i, int j) {
        int pi = Find(i);
        int pj = Find(j);
        if(pi==pj) return;
        if(size[pi]>size[pj]) swap(pi, pj);
        parent[pi] = pj;
        size[pj]+=size[pi];
        count--;
    }
    int Find(int i) {
        while(i!=parent[i]) {
            i = parent[i];
        }
        return i;
    }
    bool Connected(int i, int j) {        
        int pi = Find(i);
        int pj = Find(j);
        return pi==pj;
    }
    int Count() {return count;}
};
class Solution {
public:
    //Method2: Disjoint Set
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int M=grid.size(), N=grid[0].size();
        UF uf(grid);
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if(grid[i][j]=='1') {
                    int x=i*N+j;
                    if(j+1<N && grid[i][j+1]=='1') //right: y=x+1
                        uf.Union(x, x+1);
                    if(i+1<M && grid[i+1][j]=='1') //down: y=x+N
                        uf.Union(x, x+N);
                }
            }
        }
        return uf.Count();
    }
    
    //Method1: DFS
    int numIslands_11111(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j]=='1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()) return;
        if(grid[row][col]=='0') return;
        if(grid[row][col]=='1') grid[row][col]='0';
        dfs(grid, row-1, col);
        dfs(grid, row+1, col);
        dfs(grid, row, col-1);
        dfs(grid, row, col+1);
    }    
};
// @lc code=end

