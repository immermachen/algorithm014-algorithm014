# week3：学习笔记

## 1. 泛型递归的实现、特性以及思维要点
	
	- 为什么叫泛型递归？

	- 递归模板: 
		
		```
		void recursion(int level, int param) { 
		// terminator
		if (level > MAX_LEVEL) { 
			// process result 
			return ; 
		}

		// current logic 
		process(level, param);

		// drill down 
		recursion(level + 1, param);

		// reverse the current level status if needed
		}
		```

	- 思维要点： 
		- 不要人肉进行递归（最大误区）
		- 找到最近最简单方法，将其拆解成可重复解决的问题（重复子问题）
		- 数学归纳法思维
	
## 2. 分治、回溯的实现和特性
	
	- 递归：碰到问题就找重复性！最近重复性（分治、回溯等），和最优重复性（动态规划），但本质上都是递归。
	
	-  分治代码模板
		```	
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
	- 

## 3. 解题思路：

	- <47. Permutations II>
	
		- Method 1:  backtracking. Based on <46. Permutations>. First Sort the input nums!
			
			signatures：helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm)
			terminator: if nums==0: res.push(perm); return;
			current problem: for i=start in n:
								if nums[i-1]==num[i]: continue;
								push one int in perm;
								next drill down:  update the nums for next level.
								revert current level status: pop the latest int in perm.
						
		- complexity: time: O(n*n!), space: O(n^2)???
		
		- Method 2: TODO: backtracking + 交换.		
		
	- <46. Permutations>
	
		- Method 1:  backtracking
			signatures：helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm)
			terminator: if nums==0: res.push(perm); return;
			current problem: for i=start in n:
								push one int in perm;					
								next drill down:  update the nums for next level.
								revert current level status: pop the latest int in perm.
						
		- complexity: time: O(n*n!), space: O(n^2)???
		

		- Method 2: backtracking + 交换.		
			https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/ 
			ideal：通过swap和指针start实现下一个level的可用的subvector。
			Note: 下一个for起始位置是start+1.
			```			
			void helper(vector<int>& nums, vector<vector<int>>& res, int start) {
				if(nums.size()==start) {
					res.push_back(nums);
					return;
				}
				for(int i=start; i<nums.size(); ++i) {            
					swap(nums[i], nums[start]);
					helper(nums, res, start+1);
					swap(nums[i], nums[start]);
				}
			```
		
		- complexity: 
			time: O(n*n!)
			space: O(n)：其中 n为序列的长度。除答案数组以外，递归函数在递归过程中需要为每一层递归函数分配栈空间， 所以这里需要额外的空间且该空间取决于递归的深度，这里可知递归调用深度为 O(n).
					
		
	- <77. Combinations>
		
		- Method: backtracking 回溯法. 
			signatures：helper(n, k, start, res, comb)
			terminator: if k==0: res.push(comb); return;
			current problem: for i=start in n:
								push one int;							
								next drill down: k--, start++;
								revert current level status: pop the latest int.
			
			one improvement: for(int i=start;i<=n-k+1;++i) instead of for(int i=start;i<=n;++i)
			
		- complexity: time: O(n), space: O(n)
			
	- <105. Construct Binary Tree from Preorder and Inorder Traversal>
		
		- Method: preorderDFS + hashmap for inorder. 
			signatures：TreeNode <= preorder, index of L-R subtree: (preLeft, preRight, InLeft, InRight)
			terminator: 检查preorder， if preLeft  > preRight, return null;
			current logic: 用preorder第一个值 create a new TreeNode* root; preoder第一个值肯定是根节点. With hashmap to find the index of preleft in inorder in order to decide L-R subtree.
			drill down: 重点计算左右子树边界index。
			return root;
			
		- complexity: time: O(n), space: O(n)
		
	- <236. Lowest Common Ancestor of a Binary Tree>
		
		-Method: postorderDFS: 
			terminator: if root=null, return null;
			Drill Down: reverse(left); reverse(right);
			current logic: 总结归纳最小公共节点条件, 及返回找到的节点.
			如果root是p or q, 说明root就是要找的。否则，pq要不在left， 要不在right。
				
			```
			TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
				if(root==nullptr) return nullptr;
				TreeNode* left = lowestCommonAncestor(root->left, p, q);
				TreeNode* right = lowestCommonAncestor(root->right, p, q);
				if(root==p || root==q) return root;
				if(left==nullptr) return right;
				if(right==nullptr) return left;
				return root;
			}
			```
		- complexity: time: O(n), space: O(n)
	
	- <111. Minimum Depth of Binary Tree>
	
		- Method: postorder DFS.
			terminator: if root = null, return 0;
			drill down: 
				if left = null: return right subtree +1;
				if right = null: return left subtree +1;
				return min(left subtree, right subtree) + 1;			
				
		- complexity: time: O(n), space: O(1)
		
	- <104. Maximum Depth of Binary Tree>
		
		- Method: postorder DFS.
			terminator: if root = null, return 0;
			drill down: return max(left subtree, right subtree) + 1;
			
		- complexity: time: O(n), space: O(1)
		
	- <98. Validate Binary Search Tree>
	
		- Method: inorder DFS. It is easier to use inorderDFS! 
			terminator: if root = null, return true;
			drill down left: left = reverse(left);
			current logic: 交换(swap)左右的返回节点树;  return root;
			drill down right: right = reverse(right);
			return left & right;
			
		- complexity: time: O(n), space: O(n)
		
	- <226. Invert Binary Tree>
	
		- Method: 后序深度优先遍历(postorder DFS)。
			terminator: if root = null, return root;
			drill down: newleft = reverse(left); newright = reverse(right);
			current logic: 交换(swap)左右的返回节点树;  return root;
			
		- complexity: time: O(n), space: O(n)
		
	- <22. Generate Parentheses> 
		- Method: 前序深度优先遍历(preorder DFS)（回溯算法）
			terminator: if s has n "(" and n )"; save string; return;
			drill down: if s has less than n "(", recur(s+"(");
						if number of ")" is less than number of "(", recur(s+")");
						
		- complexity: time: TODO: difficult to find !!!
		
	- <70. Climbing Stairs>: 
	
		- Method: 后序深度优先遍历(postorder DFS) + hashmap缓存中间结果。
			terminator: if root = 1 or 2; return root;
			drill down: left=recur(n-1); right=recur(n-2); 同时这里要缓存中间结果，避免重复子计算。
			current logic: return left + right;
			
		- complexity: time: O(n), space: O(n)
		