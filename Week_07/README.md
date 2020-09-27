# week7 学习笔记

# 第13课： 字典树和并查集

## 1. Trie树的基本实现和特性

## Trie 树代码模板

	 ```
	//C/C++
	class Trie {
	    struct TrieNode {
	        map<char, TrieNode*>child_table;
	        int end;
	        TrieNode(): end(0) {}
	    };
	        
	public:
	    /** Initialize your data structure here. */
	    Trie() {
	        root = new TrieNode();
	    }
	    
	    /** Inserts a word into the trie. */
	    void insert(string word) {
	        TrieNode *curr = root;
	        for (int i = 0; i < word.size(); i++) {
	            if (curr->child_table.count(word[i]) == 0)
	                curr->child_table[word[i]] = new TrieNode();
	                
	            curr = curr->child_table[word[i]];                
	        }
	        curr->end = 1;
	    }
	    
	    /** Returns if the word is in the trie. */
	    bool search(string word) {
	        return find(word, 1);
	    }
	    
	    /** Returns if there is any word in the trie that starts with the given prefix. */
	    bool startsWith(string prefix) {
	        return find(prefix, 0);
	    }
	private:
	    TrieNode* root;
	    bool find(string s, int exact_match) {
	        TrieNode *curr = root;
	        for (int i = 0; i < s.size(); i++) {
	            if (curr->child_table.count(s[i]) == 0)
	                return false;
	            else
	                curr = curr->child_table[s[i]];
	        }
	        
	        if (exact_match)
	            return (curr->end) ? true : false;
	        else
	            return true;
	    }
	};
	```	
		 
## 2. Trie树实战题目解析：单词搜索2


### 分析单词搜索 2 用 Tire 树方式实现的时间复杂度.

- <212. Word Search II>, Hard [TODO +1]
	- Method: 使用前缀树的回溯. TODO, need to be improved!
	- complexity:
    	- time: O(M*N*4^W),  M=rows, N=cols, W=其中W为查找Trie键长. TODO: need to be checked!
		- space: O(N).
		


## 3. 并查集的基本实现、特性和实战题目解析

### 并查集 Disjoint-Set
	- 一般题目套用模板使用即可，没有太多变化性。
	- 使用场景：组团，配对问题。Group or not? 
	
	- Union-Find 算法详解: https://leetcode-cn.com/problems/friend-circles/solution/union-find-suan-fa-xiang-jie-by-labuladong/ 
		- Union-Find 算法解决的是图的动态连通性问题，这个算法本身不难，能不能应用出来主要是看抽象问题的能力， 是否能够把原始问题抽象成一个有关图论的问题。
		- 很多更复杂的 DFS 算法问题，都可以利用 Union-Find 算法更漂亮的解决。

### 并查集代码模板

	//C/C++
	class UnionFind {
	public:
	    UnionFind(vector<vector<char>>& grid) {
	        count = 0;
	        int m = grid.size();
	        int n = grid[0].size();
	        for (int i = 0; i < m; ++i) {
	            for (int j = 0; j < n; ++j) {
	                if (grid[i][j] == '1') {
	                    parent.push_back(i * n + j);
	                    ++count;
	                }
	                else {
	                    parent.push_back(-1);
	                }
	                rank.push_back(0);
	            }
	        }
	    }
	
	//递归
	    int find(int i) {
	        if (parent[i] != i) {
	            parent[i] = find(parent[i]);
	        }
	        return parent[i];
	    }
	
	
	    void unite(int x, int y) {
	        int rootx = find(x);
	        int rooty = find(y);
	        if (rootx != rooty) {
	            if (rank[rootx] < rank[rooty]) {
	                swap(rootx, rooty);
	            }
	            parent[rooty] = rootx;
	            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
	            --count;
	        }
	    }
	
	
	    int getCount() const {
	        return count;
	    }
	
	
	private:
	    vector<int> parent;
	    vector<int> rank;
	    int count;
	};


- <547. Friend Circles>, Medium	

	- Method: Disjoint-Set.
	
			```
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
			```
	- complexity:
		- time: O(N^2). 访问半个矩阵一次，并查集操作需要最坏 O(N)的时间。
		- space: O(N). parent大小为N。
		
- <547. Friend Circles>, Medium

    - Method1: DFS
	- complexity:
		- time: O(MN), M=rows, N=cols. 
		- space: O(MN), 主要为深度优先搜索的栈的开销。 

	- Method2: Disjoint-Set.	
	- complexity:
		- time: O(MN). 访问矩阵一次，并查集操作需要 O(1)的时间,这里parent树的深度只有1层孩子。
		- space: O(MN). parent大小为MN。


- <130. Surrounded Regions>, Medium

	- Method1: DFS. 
	- complexity:
		- time: O(MN), M=rows, N=cols.
		- space: O(MN), 主要为深度优先搜索的栈的开销。

	- Method2: Disjoint-Set.	
	- complexity:
		- time: O(MN). 访问矩阵一次，并查集操作需要 O(1)的时间,这里parent树的深度只有1层孩子。
		- space: O(MN). parent大小为MN+1。
		
# 第14课： 高级搜素

## 1. 剪枝的实现和特性

## 2. 剪枝实战题目解析：数独

- <36. Valid Sudoku>, Medium
	- Method: loop. 
	- complexity:
		- time: O(1).
		- space: O(1).

- <37. Sudoku Solver>, Hard, TODO

- <70. Climbing Stairs>
		

- <22. Generate Parentheses>, Medium
	
	- Method1: DFS.	
	- complexity: 
		- time: O(n). 事实证明这是第n个卡特兰数\dfrac{1}{n+1}\dbinom{2n}{n}.
		- space: O(n). 除了答案数组之外，我们所需要的空间取决于递归栈的深度，每一层递归函数需要O(1)的空间，最多递归2n层，因此空间复杂度为O(n).

	- Method2: BFS: slowly! But good for training of BFS. 
	- complexity:
    	- time: O(n).
    	- space: O(depth)：depth 是树的高度。
	
	- Method3: DP. https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/
	 "(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】,p + q = n-1，且 p,q 均为非负整数。
		
	- Equation: dp[i] = "(" + one in dp[j] + ")" + one in dp[i-1-j];  where j>=0&&j<i.
	- complexity:
    	- time: O(N^2). TODO, ??? not sure!
    	- space: O(N).

- <51. N-Queens>, Hard
	- Method1: DFS回溯. 
	- complexity:
    	- time: O(N!). N是皇后数量. 
    	- space: O(N).空间复杂度主要取决于递归调用层数.
	- Method2: TODO: 基于位运算的回溯. 
	- complexity:
    	- time: TODO.
    	- space: TODO.
		

## 3. 双向BFS的实现、特性和题解


### TODO 总结双向 BFS 代码模版，请同学们提交在学习总结中。

	```
	// C/C++
	void bfs(string start, string end) {	  
	  set<string> q1,q2,tmp;
	  q1.insert(start); 
	  q2.insert(end);
	  while (!q1.empty() && !q.empty()) {	  
		if(q1.size()>q2.size()) {
			tmp = q1;
			q1 = q2;
			q2 = tmp;
		}		
		for (String word : q1) {			
			//TODO process BFS
			//update tmp
		}
		q1 = tmp;
	  }
	}
	```

- <127. Word Ladder> TODO

- <433. Minimum Genetic Mutation> TODO


## 4. 启发式搜索的实现、特性和题解

- <1091. Shortest Path in Binary Matrix>, Medium, TODO
- <773. Sliding Puzzle>, Hard, TODO
- <37. Sudoku Solver>, Hard, TODO

# 第15课： 红黑树和AVL树

## AVL树和红黑树的实现和特性



## 解题思路 



## 每日一题

- <16. 3Sum Closest>
	- Method: 排序+双指针. 
	- complexity:
		- time: O(N^2). 首先需要 O(Nlog⁡N)对数组进行排序，随后枚举，使用一重循环O(N)枚举i，双指针O(N)枚举L和R，共是O(N^2).
		- space: O(NlogN). 空间复杂度：O(log⁡N)。排序需要使用O(log⁡N)的空间, depending on recursive depth.

- <152. Maximum Product Subarray>, Medium, but easy
	- Method: DP. 
	- complexity:
		- time: O(N).
		- space: O(1).
	

- <208. Implement Trie (Prefix Tree)>, Medium
	
		```
		class Trie {
		Trie* next[26]={nullptr};
		bool isEnd;
		public:
			/** Initialize your data structure here. */
			Trie() {
				isEnd=false;
			}
			
			/** Inserts a word into the trie. */
			void insert(string word) {
				Trie* root=this;
				for(char& c : word){
					if(!root->next[c-'a']) root->next[c-'a']=new Trie();
					root = root->next[c-'a'];
				}
				root->isEnd=true;
			}
			
			/** Returns if the word is in the trie. */
			bool search(string word) {
				Trie* root=this;
				for(char& c:word){
					if(!root->next[c-'a']) return false;
					root=root->next[c-'a'];
				}
				return root->isEnd;
			}
			
			/** Returns if there is any word in the trie that starts with the given prefix. */
			bool startsWith(string prefix) {
				Trie* root=this;
				for(char& c:prefix) {
					if(!root->next[c-'a']) return false;
					root=root->next[c-'a'];
				}
				return true;
			}
		};	
		```

-  <240. Search a 2D Matrix II>, Medium [TODO +1]

	- Method: 数组从左到右和从上到下都是升序的，如果从右上角出发开始遍历呢？每次比较完，可以相应的删除当前行或者列。

			
			```
			bool searchMatrix(vector<vector<int>>& matrix, int target) {
			    if(matrix.size()==0) return false;
			    if(matrix[0].size()==0) return false;
			    int M = matrix.size(), N = matrix[0].size(), i=0, j=N-1, n=0;        
			    while(i<M && j>=0) {
			        n = matrix[i][j];
			        if(n==target) return true;
			        if(n<target) {
			            i++;
			        } else {
			            j--;
			        }
			    }
			    return false;
			}
			```
	
	- complexity:
		- time: O(M+N),  M=rows, N=cols.
		- space: O(1).