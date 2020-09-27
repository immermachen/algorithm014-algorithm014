/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */

// @lc code=start
class Solution {
    class UF {
        int count;
        vector<int> parent;
        vector<int> size;
    public:
        UF(int n) {
            count = n;
            parent.reserve(n);
            size.reserve(n);
            for(int i=0;i<n;++i) {
                parent[i] = i;
                size[i]=1;
            }
        }
        void Union(int i, int j) {
            int pi=Find(i);
            int pj=Find(j);
            if(pi==pj) return;
            if(size[pi]<size[pj]) {
                parent[pi] = pj;
                size[pj] += size[pi];
            } else {
                parent[pj] = pi;
                size[pi] += size[pj];
            }            
            count--;
        }
        int Find(int i) {            
            while(i!=parent[i])
                i = parent[i];
            return i;                
        }
        bool Connected(int i, int j) {
            int pi = Find(i);
            int pj = Find(j);
            return pi==pj;
        }
        int Count() {
            return count;
        }
    };
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res=0, N=M.size();
        if(N==0) return 0;
        UF uf(M.size());
        for(int i=0;i<N;++i) {
            for(int j=i;j<N;++j) {
                if(M[i][j]==1)
                    uf.Union(i,j);
            }
        }
        return uf.Count();
    }
};
// @lc code=end

