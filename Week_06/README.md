# week6 学习笔记

# 1. 动态规划的实现及关键点

## 动态规划定义

https://en.wikipedia.org/wiki/Dynamic_programming

## 动态规划关键点

- 基本概念：动态规划,本质上与分治和递归没有本质区别，都是找所谓的重复性。只不过，它在中间有一个筛选的过程: e.g. 路径计数: 	
	
		```
		//路径计数
		opt[i,j]=opt[i+1,j]+opt[i,j+1];
		if a[i,j]="空地"
			opt[i,j]=opt[i+1,j]+opt[i+1,j];
		else
			opt[i,j]=0;
		```

- 1.最优子结构: opt[n] = best_of (opt[n-1], opt[n-2], ...)
- 2.存储中间状态: opt[i]
- 3.递推公式（状态转移方程/DP方程）

		```
		Fibonacci: opt[n]=opt[n-1]+opt[n-2];
		二维路径：opt[i,j]=opt[i+1,j]+opt[i+1,j];
		```

- 面试考点：对于面试，只要能定义存储中间状态，基本就可以解决出来。难点在于推导递推公式，面试一般不会考。

- 要点： 一般递归就转化为for循环，自底向上进行累加循环即可。 写DP时，初学者可以用递归，高层次时用for代替！For版本就可以认为DP的终结模板。

- 简单DP一维数组，复杂的就可以有二三维度或更高维度DP。
	
	
## 递归代码模板

### C++

	```
	// C/C++
	void recursion(int level, int param) { 
	  // recursion terminator
	  if (level > MAX_LEVEL) { 
		// process result 
		return ; 
	  }

	  // process current logic 
	  process(level, param);

	  // drill down 
	  recursion(level + 1, param);

	  // reverse the current level status if needed
	}
	```
	
### Python 代码模板

	```
	自动检测
	# Python
	def recursion(level, param1, param2, ...): 
		# recursion terminator 
		if level > MAX_LEVEL: 
		   process_result 
		   return 
		# process logic in current level 
		process(level, data...) 
		# drill down 
		self.recursion(level + 1, p1, ...) 
		# reverse the current level status if needed
	```

### Java 代码模板
	自动检测
	```
	// Java
	public void recur(int level, int param) { 
	  // terminator 
	  if (level > MAX_LEVEL) { 
		// process result 
		return; 
	  }
	  // process current logic 
	  process(level, param); 
	  // drill down 
	  recur( level: level + 1, newParam); 
	  // restore current status 
	 
	}
	```


### JavaScript
	```
	// JavaScript
	const recursion = (level, params) =>{
	   // recursion terminator
	   if(level > MAX_LEVEL){
		 process_result
		 return 
	   }
	   // process current level
	   process(level, params)
	   //drill down
	   recursion(level+1, params)
	   //clean current level status if needed
	   
	}
	```

## 分治代码模板


### C++
	```
	C/C++
	int divide_conquer(Problem *problem, int params) {
	  // recursion terminator
	  if (problem == nullptr) {
	    process_result
	    return return_result;
	  } 
	
	  // process current problem
	  subproblems = split_problem(problem, data)
	  subresult1 = divide_conquer(subproblem[0], p1)
	  subresult2 = divide_conquer(subproblem[1], p1)
	  subresult3 = divide_conquer(subproblem[2], p1)
	  ...
	
	  // merge
	  result = process_result(subresult1, subresult2, subresult3)
	  // revert the current level status
	 
	  return 0;
	}
	```

### Python
	```
	# Python
	def divide_conquer(problem, param1, param2, ...): 
	  # recursion terminator 
	  if problem is None: 
		print_result 
		return 
	
	  # prepare data 
	  data = prepare_data(problem) 
	  subproblems = split_problem(problem, data) 
	
	  # conquer subproblems 
	  subresult1 = self.divide_conquer(subproblems[0], p1, ...) 
	  subresult2 = self.divide_conquer(subproblems[1], p1, ...) 
	  subresult3 = self.divide_conquer(subproblems[2], p1, ...) 
	  …
	
	  # process and generate the final result 
	  result = process_result(subresult1, subresult2, subresult3, …)
		
	  # revert the current level states
	```

### JavaScript

	```
	//Javascript
	const divide_conquer = (problem, params) => {
	
	  // recursion terminator
	
	  if (problem == null) {
	
	    process_result
	
	    return
	
	  } 
	
	  // process current problem
	
	  subproblems = split_problem(problem, data)
	
	  subresult1 = divide_conquer(subproblem[0], p1)
	
	  subresult2 = divide_conquer(subproblem[1], p1)
	
	  subresult3 = divide_conquer(subproblem[2], p1)
	
	  ...
	
	  // merge
	
	  result = process_result(subresult1, subresult2, subresult3)
	
	  // revert the current level status
	
	}
	```

### Java

		
	```	
	private static int divide_conquer(Problem problem, ) {
	  
	  if (problem == NULL) {
	    int res = process_last_result();
	    return res;     
	  }
	  subProblems = split_problem(problem)
	  
	  res0 = divide_conquer(subProblems[0])
	  res1 = divide_conquer(subProblems[1])
	  
	  result = process_result(res0, res1);
	  
	  return result;
	}
		
	```

## 2. DP例题解析：Fibonacci数列、路径计数

- <509. Fibonacci Number>: Easy, [TODO +3]
	- Method: DP. 自底向上递推。
	- complexity:
    	- time: O(N). 
		- space: O(1).

- <64. Minimum Path Sum>: Medium, [TODO +2]
	- Method: DP. 自底向上递推。
	- complexity:
    	- time: O(MN). 
		- space: O(1).


## 3. DP例题解析：最长公共子序列

- <63. Unique Paths II>
	- Method: DP.	
	
			```	   
			int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			    int m = obstacleGrid.size();
			    if(m==0) return 0;
			    int n = obstacleGrid[0].size();        
			    vector<int> dp(n,0); dp[0]=1;
			    for(int i=0; i<m; ++i) {            
			        for(int j=0; j<n; ++j) {
			            if(obstacleGrid[i][j]==0) {
			                //int left = j-1<0 || obstacleGrid[i][j-1]==1 ? 0 : dp[j-1];                    
			                //dp[j] = dp[j] + left;
			                dp[j] += j-1<0 ? 0 : dp[j-1];//summary of above!
			            } else {
			                dp[j] = 0;
			            }
			        }
			    }
			    return dp[n-1]; 
			}
			```
	
	- complexity:
    	- time: O(MN). M is rows, N is columns. 
		- space: O(N).
		

- <62. Unique Paths>
	- Method: DP.
	
			```
			int uniquePaths(int m, int n) {
		        if(m==1 || n==1) return 1;
		        if(m<n) uniquePaths(n, m);
		        vector<int> dp(n,1);
		        for(int i=1; i<m; ++i) {            
		            for(int j=1; j<n; ++j) {
		                dp[j] += dp[j-1];
		            }
		        }
		        return dp[n-1];
		    }
			```
	- complexity:
    	- time: O(MN). M is rows, N is columns. 
		- space: O(N). N = min(M, N);
		
## 4. 实战题目解析：三角形最小路径和
	TODO some tasks again.

## 5. 实战题目解析：最大子序列和
	
- 经验总结：对于字符串变化的DP问题，特别是两个字符串的变换问题，最后都要做成二维数组来解决！行和列分别是两个字符串。

- 动态规划小结：
	1. 打破自己的思维惯性，形成机器思维。
	2. 理解复杂逻辑的关键。
	3. 也是职业进阶的要点要领。

- TODO: MIT algorithm course: B站搜素：mit动态规划。
	- 5 easy steps to DP:
		1. define subproblems.
		2. guess (part of solution).
		3. relate/merge subproblem solutions.
		4. recurse & memorize, or build DP table bottom-up.
		5. solve original problem. (冗余不需要了)
	- step1,2,3, 其实就是分治思想，其关键点就是找重复性，之所以要找重复性，就计算机指令只能循环和递归。
	- 总结：化繁为简：
		第一，分治，找他的重复性和子问题。 第二，定义出状态空间，然后，用记忆化的搜素递归或者自底向上进行DP的顺推，最后解决这个问题。
	
- <1143. Longest Common Subsequence>: TODO
	
	- Method: DP. https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)
					Good explanation by Tushar Roy https://www.youtube.com/watch?v=NnD96abizww
	- complexity:
    	- time: O(nm), where n and m are the string sizes.
    	- space: O(min(n,m)). 此处，需要额外判断 if (text1.size() < text2.size()) return longestCommonSubsequence(text2, text1);


	
## 6. 实战题目解析：打家劫舍

		
- <213. House Robber II> Medium 



## 解题思路 


- <72. Edit Distance>, Hard	
	- Method: DP. use a dp table with 2 rows. Easy to code but hard to find out the DP Table Idea!!!
	- DP-Equation: dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1


			```	
			int minDistance(string word1, string word2) {
			    int M = word1.size(), N = word2.size();
			    vector<vector<int>> dp(2, vector<int>(N+1, 0));
			    for(int j=0; j<N+1; ++j) {
			        dp[0][j]=j;//first row 
			    }
			    for(int i=1; i<M+1; ++i) {
			        int r1 = i%2, r2=(r1+1)%2;//2 row index for dp.
			        char c1 = word1[i-1];
			        for(int j=0; j<N+1; ++j) {
			            if(j==0) {
			                dp[r1][0]=i; //first column in table
			            } else {
			                char c2 = word2[j-1];
			                if(c1==c2) {
			                    dp[r1][j] = dp[r2][j-1];
			                } else {
			                    dp[r1][j] = 1 + min( dp[r1][j-1], min(dp[r2][j-1], dp[r2][j]));
			                }
			            }
			        }
			    }
			    return dp[M%2][N];
			}
		
			```


	- complexity:
    	- time: O((M+1)*(N+1)). M=length of word1, N=length of word2.
		- space: O(2(N+1)).
		
- <221. Maximal Square>, Medium	
	- Method: DP. use a dp table with 2 rows.
	- DP-Equation: dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1
	
			```
		    int maximalSquare(vector<vector<char>>& matrix) {
		        if(matrix.size()==0 || matrix[0].size()==0) return 0;
		        int res=0, M = matrix.size(), N = matrix[0].size();
		        vector<vector<int>> dp(2, vector<int>(N+1, 0));
		        for(int i=0; i<M; ++i) {
		            int r1 = i%2, r2=(r1+1)%2;
		            for(int j=0; j<N; ++j) {
		                if(matrix[i][j]=='1') {
		                    dp[r1][j+1] = min(dp[r1][j], min(dp[r2][j+1], dp[r2][j])) + 1;
		                    res = max(res, dp[r1][j+1]);
		                } else {
		                    dp[r1][j+1] = 0;
		                }
		            }
		        }
		        return res*res;        
		    }
			```
	- complexity:
    	- time: O((M+1)*(N+1)). M=rows, N=cols.
		- space: O(2(N+1)).
		
- <32. Longest Valid Parentheses>, Hard
	- Method: DP. DP-Equation: dp[i]=dp[i−2]+2; dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2;
	- complexity:
    	- time: O(N).
		- space: O(N). 
	
	- Method2: TODO  方法三：不需要额外的空间  https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
	

- <647. Palindromic Substrings>, Medium
	- Method: 中心扩展法。奇数偶数分开考虑，或者合并考虑. 枚举遍历每个可能性。
	- complexity:
    	- time: O(N^2). 
		- space: O(1).
	- Method2: DP. But slowly. DP-Equation:  s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])
	- complexity:
    	- time: O(N^2).
		- space: O(N^2). 可以优化到O(N). 只需要保持上一列的dp.


- <621. Task Scheduler>, Medium
	- Method: 桶思想. 
	- complexity:
    	- time: O(N). N是任务的总数。
		- space: O(1).

- <91. Decode Ways>, Medium [TODO +1]	
	- Method: DP. https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/
	- complexity:
    	- time: O(N).
		- space: O(1).


- <363. Max Sum of Rectangle No Larger Than K>, Hard [TODO +1]	
	- Method: DP. TODO very hard!!! https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/solution/javacong-bao-li-kai-shi-you-hua-pei-tu-pei-zhu-shi/ 
	- complexity:
    	- time: O(M^2N^2). M=rows, N=cols.
		- space: O(M).
		
		

## 每日一题

- <212. Word Search II>, Hard [TODO +1]
	- Method: 使用前缀树的回溯. TODO, need to be improved!
	- complexity:
    	- time: O(M*N*W),  M=rows, N=cols, W=其中W为查找Trie键长.
		- space: O(N).

- <589. N-ary Tree Preorder Traversal> Easy [TODO +3]
	

- <322. Coin Change>: Medium 
	- Method: DP. 
	- complexity:
    	- time: O(Sn)，其中 S 是金额，n 是面额数。我们一共需要计算 O(S) 个状态，S 为题目所给的总金额。对于每个状态，每次需要枚举 n 个面额来转移状态，所以一共需要 O(Sn) 的时间复杂度。
		- space: O(S)。DP 数组需要开长度为总金额 S 的空间.
    	
	