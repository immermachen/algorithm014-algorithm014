week2：学习笔记


1. 哈希表、映射、集合的实现与特性.

	- 写一个关于 HashMap 的小总结。说明：对于不熟悉 Java 语言的同学，此项作业可选做。
		
		Instead of Java, here for C++:
		STL中，map 对应的数据结构是红黑树。 
		红黑树是一种近似于平衡的二叉查找树，里面的数据是有序的。在红黑树上做查找操作的时间复杂度为 O(logN)。
		而 unordered_map 对应哈希表，哈希表的时间复杂度为常数级别 O(1)， 而额外空间复杂度则要高出许多。所以对于需要高效率查询的情况，使用 unordered_map 容器。 而如果对内存大小比较敏感或者数据存储要求有序的话，则可以用 map 容器。
		

	- HeapSort ：自学 https://www.geeksforgeeks.org/heap-sort/ 

				
	
2. 树、二叉树、二叉搜索树的实现和特性.
		
	- 二叉树、二叉搜索树的区别： 

		二叉树(binary tree)是一种特殊的树；若加一个额外的条件, 就是二叉搜索树(binary search tree)。 
		
		条件：每个节点都不比它左子树的任意元素小，而且不比它的右子树的任意元素大。(如果我们假设树中没有重复的元素，那么上述要求可以写成：每个节点比它左子树的任意节点大，而且比它右子树的任意节点小)。
		
	- 思考题: 树的面试题解法一般都是递归，为什么？

		基于树的结构考虑，循环不适合左右树的遍历，递归更适合！
	
	- three standart tree recursive traversal method:
	
		preorder:
		```
		void preorder(root)
			if(root==nullptr) return;
			processing;
			preoder(root.left);
			preorder(root.right);		
		```
		inorder:
		```
		void inorder(root)
			if(root==nullptr) return;			
			inorder(root.left);
			processing;
			inorder(root.right);
		```			
		postorder:
		```
		void postorder(root)
			if(root==nullptr) return;			
			postorder(root.left);
			postorder(root.right);
			processing;
		```
			
3. 堆和二叉堆的实现和特性

	- priority_queue: 
	
		1. change the comparisor to get Max-Heap or Min-Heap. 
		
			e.g. ```priority_queue< int, vector<int>, greater<int> > minHeap;```
			

		2. Complexity: pq.push = push_back + push_heap : O(1) + O(LogN) = O(LogN). 

			(One call to push_back on the underlying container and one call to push_heap on the range that includes all the elements of the underlying container. )


4. 解题思路：

	- <1.Two Sum>: 
	
		- Method: 首先利用hashmap缓存数组pair<data[index], index>， 好处在map查找O(1).
		然后在遍历中查找 rest=target-data[i], 是否在map中。				
			
		- complexity: time: O(n), space: O(n)
	
	- <242. Valid Anagram> 有效的字母异位词: 
	
		- Method: 首先利用hashmap缓存记录单个char在两个字符串中加减次数是否为0。但为了提高效率利用array代替hashmap。
			
		- complexity: time: O(n), space: O(1)

	- <589. N-ary Tree Preorder Traversal>: 
	
		- Method 1: recursive.
			
		- complexity: time: O(n), space: O(n)
			
		- Method 2: Iterative. Using a stack to traverse tree top-down.

			```		
			stack<Node*> stackTree;
			stackTree.push(root);
			while(!stackTree.empty()){
				Node* tmp = stackTree.top();
				ret.push_back(tmp->val);
				stackTree.pop();
				for(int i=tmp->children.size()-1; i>=0; --i) {
					stackTree.push(tmp->children[i]);
				}
			}
			```

		- complexity: time: O(n), space: O(n)
			
	- <590. N-ary Tree Postorder Traversal>: 
	
		- Method 1: recursive.
		
		- complexity: time: O(n), space: O(n)
		
		- Method 2: Iterative.  just firstly use preoder iterative, then reverse the result.
		
		- complexity: time: O(n), space: O(n)
			
			
	- <94. Binary Tree Inorder Traversal>: 
	
		- Method 1:  recursive. But looks slowly!
		
		- complexity: time: O(n), space: O(n)
		
		- Method 2: TODO Iterative.
			
	- <49. Group Anagrams> 字母异位词分组: 
	
		- Method 1:  firstly sort each string, them push into unordered_map.
		
		- complexity: time: O(n), space: O(n)
			
			
	- <剑指 Offer 40. 最小的k个数>:
			
		- Method 1: sort.
		
		- complexity: time: O(nLogN), space: O(logN),排序所需额外的空间复杂度为 O(log⁡N).
		
		- Method 2: heap. 
		
		- complexity: time: O(nLogK), space: O(K), 因为大根堆里最多K个数.
		Insert heap: O(Logk)
					
		- Method 3:  quick select（快速选择）算法. TODO:  quick-sort,快速排序.分治法的思想.
		
		- complexity: time: O(nLogK), space: O(n).
			
	
	- <239. Sliding Window Maximum>: Hard. 
			
		- Method 1: use deque, not priority_queue, which is different from that in JAVA. 
		
		- complexity: time: O(N), space: O(N).
		
		- Method 2: TODO  动态规划 https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/ 
			
			
	- <264. Ugly Number II>:
	
		- Method 1: Precompute all possibilities in easy order and sort them.  https://leetcode.com/problems/ugly-number-ii/discuss/69373/Short-and-O(n)-Python-and-C%2B%2B
					
		- complexity: time: O(INT_MAX), space: O(INT_MAX) TODO: ???
		
		- Method 2: 动态规划
		//https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/
			
		- complexity: time: O(N), space: O(N)
	
	- <347. Top K Frequent Elements>:
						
		- Method 1: unordered_map, Bucket sort 桶排序.
		
		- complexity: time: O(N), space: O(N).
		
		- Method 2: Using a max heap. 
		
		- complexity: time: O(NLogK), space: O(N)
	
			
			
	
	