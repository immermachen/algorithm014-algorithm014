/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class UF {
    int count=0;
    vector<int> parent;
    vector<int> size;
public:
    UF(vector<vector<char>>& board) {
        int M=board.size(), N=board[0].size();
        parent.reserve(M*N+1); parent[M*N] = M*N; 
        size.reserve(M*N+1); size[M*N] = 1;
        for(int i=0;i<M;++i) {
            for(int j=0;j<N;++j) {
                if(board[i][j]=='O') {                    
                    int x=i*N+j;
                    parent[x] = x;
                    size[x] = 1;
                    count++;
                }
            }
        }
    }
    void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if(px==py) return;
        if(size[px]>size[py]) swap(px, py);
        parent[px] = py;
        size[py] += size[px];
        count--;
    }
    int Find(int x) {
        while(x!=parent[x]) {
            x = parent[x];
        }
        return x;
    }
    bool Connected(int x, int y) {        
        int px = Find(x);
        int py = Find(y);
        return px==py;
    }
    int Count() { return count; }    
};

class Solution {
public:
    //Method2: Disjoint Set
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int M=board.size(), N=board[0].size();
        UF uf(board);
        int dummy = M*N; //for O on the edge        
        for(int i=0;i<M;++i) {
            for(int j=0;j<N;++j) {
                if(board[i][j]=='O') {                    
                    int x=i*N+j;
                    if(i==0 || j==0 || i==M-1 || j==N-1) uf.Union(x, dummy);
                    else {
                        if(board[i-1][j]=='O') uf.Union(x, x-N);
                        if(board[i+1][j]=='O') uf.Union(x, x+N);
                        if(board[i][j-1]=='O') uf.Union(x, x-1);
                        if(board[i][j+1]=='O') uf.Union(x, x+1);
                    }
                }
            }
        }
        
        for(int i=0;i<M;++i) {
            for(int j=0;j<N;++j) {
                if(board[i][j]=='O') {
                    int x=i*N+j;
                    if(!uf.Connected(x, dummy))
                        board[i][j]='X';
                }
            }
        }
    }
    //Method1: DFS
    void solve_DFS(vector<vector<char>>& board) {
        int M=board.size(); if(M==0) return;
        int N=board[0].size();
        for(int j=0;j<N;++j) {
            DFS(board, M, N, 0, j);
            DFS(board, M, N, M-1, j);
        }
        for(int i=1;i<M-1;++i) {
            DFS(board, M, N, i, 0);
            DFS(board, M, N, i, N-1);
        }
        for(int i=0;i<M;++i) {
            for(int j=0;j<N;++j) {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='1') board[i][j]='O';
            }
        }
    }
    void DFS(vector<vector<char>>& board, int& M, int& N, int i, int j) {        
        if(i<0 || i>=M || j<0 || j>=N || board[i][j]!='O') return;
        board[i][j]='1';
        DFS(board, M, N, i, j-1);
        DFS(board, M, N, i, j+1);
        DFS(board, M, N, i-1, j);
        DFS(board, M, N, i+1, j);
    }
};
// @lc code=end

