# week9 学习笔记

# 第19课：高级动态规划

## 1. 动态规划、状态转移方程串讲

## 课后作业

在学习总结中，写出不同路径 2 这道题目的状态转移方程。

	if obstacleGrid[i][j]==0: dp[i][j]=dp[i-1][j]+dp[i][j-1];
	else dp[i][j]=0;

## 2. 高级动态规划题目详解

- <72. Edit Distance>, Hard
	- Method: DP.	
	
			vector<vector<int>> dp(2,vector<int>(N+1,0));
			if word1[i]=word2[j] : dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+ min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
			
	- complexity:
		- time: O(MN).
		- space: O(N).

- <746. Min Cost Climbing Stairs>, Easy
	- Method: DP. dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
	- complexity:
		- time: O(N).
		- space: O(1).	


# 第20课：字符串算法

## 1. 字符串基础知识和引申题目

## 2. 高级字符串算法

## 3. 字符串匹配算法

- <8. String to Integer (atoi)>
	- Method: loop.
	- complexity:
		- time: O(N).
		- space: O(1).	

- <5. Longest Palindromic Substring>
	- Method: CenterSpread.
	- complexity:
		- time: O(N^2).
		- space: O(1).	
	- Method: DP, TODO, but slowly.
	- complexity:
		- time: O(N^2).
		- space: O(N^2).	
	
