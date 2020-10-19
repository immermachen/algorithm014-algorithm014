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

参考链接

[不可变字符串](https://lemire.me/blog/2017/07/07/are-your-strings-immutable/)
	
[Atoi 代码示例](https://shimo.im/docs/5kykuLmt7a4DdjSP/read)

	//C/C++
	int myAtoi(string str) {
	   int res = 0;
	   int sign = 1;
	   size_t index = 0;
	   if(str.find_first_not_of(' ') != string::npos) 
		   index = str.find_first_not_of(' ');
	   if(str[index] == '+' || str[index] == '-')
		   sign = str[index] == '-' ? -1 : 1;
		
		while(index < str.size() && isdigit(str[index])) {
			res = res * 10 + (str[index++] - '0');
			if(res*sign > INT_MAX) return INT_MAX;
			if(res*sign < INT_MIN) return INT_MIN; 
		}
	
	   return res*sign;
	}

- <709. To Lower Case>, Easy
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	
		
- <58. Length of Last Word>, Easy
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	
		
- <771. Jewels and Stones>, Easy
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	
		
- <387. First Unique Character in a String>, Easy
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	
		
- <8. String to Integer (atoi)>, Medium
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	

- <14. Longest Common Prefix>, Easy
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	
		
- <344. Reverse String>, Easy
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	
		
- <541. Reverse String II>, Easy
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	
		
- <151. Reverse Words in a String>, Medium
	- Method: string.
	- complexity:
		- time: O(N).
		- space: O(1).	
		
## 2. 高级字符串算法

## 3. 字符串匹配算法

- <438. Find All Anagrams in a String>, Medium
	- Method: sliding window.
	- complexity:
		- time: O(N).
		- space: O(1).	

- <8. String to Integer (atoi)>, Medium
	- Method: loop.
	- complexity:
		- time: O(N).
		- space: O(1).	

- <5. Longest Palindromic Substring>, Medium
	- Method: CenterSpread.
	- complexity:
		- time: O(N^2).
		- space: O(1).	
	- Method: DP, TODO, but slowly.
	- complexity:
		- time: O(N^2).
		- space: O(N^2).	
	
