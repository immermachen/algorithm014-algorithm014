学习笔记

1. 方法论：
	- 1.5 ~ 2.0 倍数播放
	- 不要死磕
	- 记高票题解
	- 五毒神掌
	- 避免只做一遍的误区
	
2. Git & Github 的使用
	- generate new SSH key: 
	- Use SSH instead of HTTPS for connenctiong Github
	- git clone git@github.com:immermachen/algorithm014-algorithm014.git
	- git push -u origin master

	
3. 解题思路：
	- <1.Two Sum>: 
	
			- Method: 首先利用hashmap缓存数组pair<data[index], index>， 好处在map查找O(1).
			然后在遍历中查找 rest=target-data[i], 是否在map中。	
			
			- complexity: time: O(n), space: O(n)			
			
	- <283. Move Zeroes>: 
			- Method: 快慢指针+遍历交换。
			慢指针记录下个0位置，快指针记录下个非0位置。
			然后交换位置，再更新指针。
			- complexity: time: O(n), space: O(1)
	- <26. Remove Duplicates from Sorted Array>: 
			- Method: 快慢指针+遍历交换。
			- complexity: time: O(n), space: O(1)
	- <189. Rotate Array>: 
			Method: 首先计算最大公约数（gcd）+ 遍历交换。
			观察：如果最大公约数是1：连续跳n个k步，即结束；
			否则，需要gcd次循环。因为每次循环完毕，只能完成交换 n/gcd 个节点。下次循环起点需加1；			
			complexity: time: O(n), space: O(1)
	- <66. Plus One>: 
			Method: 右向左循环遍历判断加1后是否有进位，直到无进位终止。
			step 1: terminal：无进位; 
			step 2: process: 当前节点加1，更新进位符。					
			complexity: time: O(n), space: O(1)
	- <21. Merge Two Sorted Lists>: 
			Method: recursion: 
			step 1: terminal：l1 or l2 is null; 
			step 2: process: current min(l1, l2).next = next recursion(l1, l2); return current node.
			complexity: time: O(m+n), space: O(1)
	- <88. Merge Sorted Array>: 
			Method: 三指针，从后往前遍历：两个指针用于遍历两数组，第三指针更新返回数组。
			取当前指针两数中较大值，放到返回数组最后。
			complexity: time: O(m+n), space: O(1)
	- <641. Design Circular Deque>: 
			Method1: 用vector作为存储, 和用它的STL实现相应的方法。Method2: 用linkedList.
	- <42.trapping-rain-water>: 
			Method1: 左右指针夹逼法+遍历累加每个柱子的积水量；
			遍历方法：交替遍历左右柱子较小的；
			积水 = 当前最大可达水位 - 当前柱子值。
	

