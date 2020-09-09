# week4 学习笔记

# 1. 深度优先遍历DFS(回溯算法) and 广度优先遍历BFS


## DFS 代码模板

- 递归写法:
```
//C/C++
map<int, int> visited;
void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}
```
```
#Python
visited = set() 

def dfs(node, visited):
    if node in visited: # terminator
    	# already visited 
    	return 

	visited.add(node) 

	# process current node here. 
	...
	for next_node in node.children(): 
		if next_node not in visited: 
			dfs(next_node, visited)
```

```
//Java
public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> allResults = new ArrayList<>();
    if(root==null){
        return allResults;
    }
    travel(root,0,allResults);
    return allResults;
}
private void travel(TreeNode root,int level,List<List<Integer>> results){
    if(results.size()==level){
        results.add(new ArrayList<>());
    }
    results.get(level).add(root.val);
    if(root.left!=null){
        travel(root.left,level+1,results);
    }
    if(root.right!=null){
        travel(root.right,level+1,results);
    }
}
```

```
//JavaScript
const visited = new Set()
const dfs = node => {
  if (visited.has(node)) return
  visited.add(node)
  dfs(node.left)
  dfs(node.right)
}
```

- 非递归写法: 
```
//C/C++
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();

    if (visited.count(node->val)) continue;
    visited[node->val] = 1;
	
    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}
```

```
#Python
def DFS(self, tree): 

	if tree.root is None: 
		return [] 

	visited, stack = [], [tree.root]

	while stack: 
		node = stack.pop() 
		visited.add(node)

		process (node) 
		nodes = generate_related_nodes(node) 
		stack.push(nodes) 

	# other processing work 
	...
```


## BFS 代码模板

```
// C/C++
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
	
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}
```

```
# Python
def BFS(graph, start, end):
    visited = set()
	queue = [] 
	queue.append([start]) 
	while queue: 
		node = queue.pop() 
		visited.add(node)
		process(node) 
		nodes = generate_related_nodes(node) 
		queue.push(nodes)
	# other processing work 
	...
```

```
//Java
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}
public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> allResults = new ArrayList<>();
    if (root == null) {
        return allResults;
    }
    Queue<TreeNode> nodes = new LinkedList<>();
    nodes.add(root);
    while (!nodes.isEmpty()) {
        int size = nodes.size();
        List<Integer> results = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            TreeNode node = nodes.poll();
            results.add(node.val);
            if (node.left != null) {
                nodes.add(node.left);
            }
            if (node.right != null) {
                nodes.add(node.right);
            }
        }
        allResults.add(results);
    }
    return allResults;
}
```

```
//JavaScript
const bfs = (root) => {
  let result = [], queue = [root]
  while (queue.length > 0) {
    let level = [], n = queue.length
    for (let i = 0; i < n; i++) {
      let node = queue.pop()
      level.push(node.val) 
      if (node.left) queue.unshift(node.left)
      if (node.right) queue.unshift(node.right)
    }
    result.push(level)
  }
  return result
};
```

## BFS 代码模板进一步思考：

```
// 思考1： 如果遍历row时，需要保持当前row的公共状态，e.g 当前是第几row的， 则用一个for遍历当前row的所有nodes，如下：
void bfs(Node* root) {    
  if(!root) return ;
  int row=0;
  queue<Node*> queueNode;
  queueNode.push(root);
  
  while (!queueNode.empty()) {    
  
	int n = queueNode.size();
	row++;
	
	for(int i=0; i<n; ++i) { //NOTE: only loop all nodes in current row!
		//current logic	
		Node* node = queueNode.top();
		queueNode.pop();
		...

		//drill down
		for (int i = 0; i < node->children.size(); ++i) {
			queueNode.push(node->children[i]);
		}
	}    
  }
  return ;
}
// 思考2 ： 如果遍历不需要保存当前row的公共状态，则用： 

void bfs(Node* root) {
  if(!root) return ;
  
  queue<Node*> queueNode;
  queueNode.push(root);
  
  while (!queueNode.empty()) {    
  
    //current logic	
    Node* node = queueNode.top();
    queueNode.pop();
	...

	//drill down
    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}
```

## 贪心的实现、特性及实战题目解析

	- 贪心算法(greedy algorithm)：一般实际中很少用到，面试一般也少！
	- 贪心： 当下做局部最优判断。
	- 回溯：能够回退。
	- 动态规划：最优判断 + 回退。

## 二分查找代码模板

	```
	//C/C++
	int binarySearch(const vector<int>& nums, int target) {
		int left = 0, right = (int)nums.size()-1;
		
		while (left <= right) {
			int mid = left + (right - left)/ 2;  //Note: not use mid=(right+left)/2, due to overflow!
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		
		return -1;
	}
	```

	```
	# Python
	left, right = 0, len(array) - 1 
	while left <= right: 
		  mid = (left + right) / 2 
		  if array[mid] == target: 
			    # find the target!! 
			    break or return result 
		  elif array[mid] < target: 
			    left = mid + 1 
		  else: 
			    right = mid - 1
	```

	```
	// Java
	public int binarySearch(int[] array, int target) {
	    int left = 0, right = array.length - 1, mid;
	    while (left <= right) {
	        mid = (right - left) / 2 + left;
	
	        if (array[mid] == target) {
	            return mid;
	        } else if (array[mid] > target) {
	            right = mid - 1;
	        } else {
	            left = mid + 1;
	        }
	    }
	
	    return -1;
	}
	```	

	```
	/* JavaScript */
	let left = 0, right = len(array) - 1
	while (left <= right) {
	  let mid = (left + right) >> 1
	  if (array[mid] === target) { /*find the target*/; return }
	  else if (array[mid] < target) left = mid + 1
	  else right = mid - 1
	}
	```

## 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
	
	分析过程：same to <153. Find Minimum in Rotated Sorted Array>	
	每次二分时，查看左右两半部分，无序的则进入下一层，需要带上mid作为下一层边界。
	（有序条件：左边界小于右边界）。递归直到只有两个元素并且是无序时，右边元素就是拐点pivot了。
	
	奇数：[4, 5, 6, 7, 0, 1, 2] 
	[4, 5, 6, 7],  [7, 0, 1, 2] -- 左半部份有序，则递归进入右半部份。
					[7, 0], [0, 1, 2]  -- 右半部份有序，则递归进入左半部份。
							[7, 0] -- 只有两个元素，则右边元素0， 就是中间无序的地方。

	偶数：[2, 4, 5, 6, 0, 1] 
		[2, 4, 5], [5, 6, 0, 1] 
					[5, 6, 0, 1] 
					[5, 6], [6, 0, 1] 
							[6, 0],[0, 1] 
								[6, 0] -- 只有两个元素, 则右边元素0， 就是中间无序的地方。

	```
	//find the index of pivot(=the minimum number).
    int findPivot (std::vector<int>& nums) {        
        //if(nums.size()==0), assume nums.size()>0.
        int L=0, R=nums.size()-1;
        if(nums[L]<nums[R]) return nums[0];
        while(L<R) {
            if(L+1==R) return nums[R];
            int mid = L+(R-L)/2;
            if(nums[L]<nums[mid]) L=mid;
            else R=mid;
        }
        return nums[0];
    }
	```
## 解题思路

- <874. Walking Robot Simulation>: Easy. 

	- Method: 贪心算法(greedy algorithm). 始终记录当前位置是否是最大Distance。
	- complexity:
    	- time: O(N). 
    	- space: O(N). One HashSet for obstacles. 
	- Trick: to define the direction:
		```
        int dir(0);//North
        int dirX[] = {0,1,0,-1};
		int dirY[] = {1,0,-1,0};		
        if(commands[i]==-1) { dir=(dir+1)%4; }
        else if(commands[i]==-2) { dir=(dir+3)%4; }
		```

- <45. Jump Game II>: Hard. TODO. 

- <55. Jump Game>: Medium.
	
	- Method1:贪心算法(greedy algorithm). from end to front. 计数上一步跳到当前可到达位置需要的步数。
	- complexity:
    	- time: O(N).
    	- space: O(1). 

	- Method2:贪心算法(greedy algorithm). from front to end. 计数当前位置能跳到的最大距离。若当前位置超出上一步能到达的最大位置，则失败。 https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/
	- complexity:
    	- time: O(N).
    	- space: O(1). 

- <455. Assign Cookies>: Easy.
	
	- Method: 贪心算法(greedy algorithm). 	
	- complexity:
    	- time: O(N).
    	- space: O(1). 

- <122. Best Time to Buy and Sell Stock II>: Easy.
	
	- Method: 贪心算法(greedy algorithm). 
	- complexity:
    	- time: O(N).
    	- space: O(1). 

- <860. Lemonade Change>: Easy.

	- Method: 贪心算法(greedy algorithm). 
	- complexity:
    	- time: O(N).
    	- space: O(1). 

- <74.search-a-2-d-matrix>

	- Method: binarySearch, 分别对行和列进行标准二分查找.
	- complexity:
    	- time: O(logM+logN).M,N 是行列数。 
    	- space: O(1). 

- <153. Find Minimum in Rotated Sorted Array>

	- Method1: DFS+binarySearch.
	- complexity:
    	- time: O(logN). 
    	- space: O(logN). 用于递归栈。
		
	- Method2: binarySearch.
	- complexity:
    	- time: O(logN). 
    	- space: O(1). 改进到O(1), 用while代替递归。

- <33. Search in Rotated Sorted Array>

	- Method: DFS+binarySearch.
	- complexity:
    	- time: O(logN). 
    	- space: O(logN). 用于递归栈。

	- Method2: binarySearch.
	- complexity:
    	- time: O(logN). 
    	- space: O(1). 改进到O(1), 用while代替递归。
		
- <126. Word Ladder II> 

	- Method: BFS. 
		- my original code has time limited problem.
		- solve the time limited problem: use an additional visited hashmap to record all nodes in current level. The only tricky thing you need to remember is this is a BFS of paths not words! So the element is the queue is a vector.  That's it.
		- Tricky: erase all visited nodes in original hashmap from last level.		https://leetcode.com/problems/word-ladder-ii/discuss/40434/C%2B%2B-solution-using-standard-BFS-method-no-DFS-or-backtracking. 
		- TODO: still need to be improved on time!
	- complexity:
    	- time: O(n). O(26*n*m)-->O(n): 26小写字母总数，n 是word长度，m是BFS每层的个数， 总体来看是线性的，所以是O(n).
    	- space: O(n).	用到hashmap存wordList的字符串。
	
	
		
- <127. Word Ladder>

	- Method: BFS, exact same code to <433. Minimum Genetic Mutation>：把4个变异变为本题的26个变异即可。
	- complexity:
    	- time: O(n). O(26*n*m)-->O(n): 26小写字母总数，n 是word长度，m是BFS每层的个数， 总体来看是线性的，所以是O(n).
    	- space: O(n).	用到hashmap存wordList的字符串。

- <433. Minimum Genetic Mutation>
	
	- Method: BFS. 取BFS每层一个节点，用4个可用变异字符去变异每个字符，判断是否在bank中,或者找到end。
	- complexity:
    	- time: O(n). O(4*n*m)-->O(n): 4是变异的种类，n 是gene长度，m是BFS每层的个数， 总体来看是线性的，所以是O(n).
    	- space: O(n).	用到hashmap存bank的字符串。


- <529. Minesweeper> 
	
	- Method: DFS.
	- complexity:
    	- time: O(MN)，其中 M 和 N 分别为行数和列数。
    	- space: O(MN)，在最坏情况下，遍历整个网格，深度优先搜索的深度达到 MN。
		
	- Method: BFS TODO.


- <200. Number of Islands> 
	
	- Method: DFS.
	- complexity:
    	- time: O(MN)，其中 M 和 N 分别为行数和列数。
    	- space: O(MN)，在最坏情况下，整个网格均为陆地，深度优先搜索的深度达到 MN。
		
	- Method: TODO: BFS. https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/ 
	- complexity:
    	- time: O(MN)，其中 M 和 N 分别为行数和列数。
    	- space: O(min(M,N))，在最坏情况下，整个网格均为陆地，队列的大小可以达到 min⁡(M,N)。

- <515. Find Largest Value in Each Tree Row>

	- Method: BFS.
	- complexity:
    	- time: O(n).
    	- space: O(depth)：depth 是树的高度。		

- <22. Generate Parentheses>
	
	- Method1: DFS.	
	- complexity: 
		- time: O(n). 事实证明这是第n个卡特兰数\dfrac{1}{n+1}\dbinom{2n}{n}.
		- space: O(n). 除了答案数组之外，我们所需要的空间取决于递归栈的深度，每一层递归函数需要O(1)的空间，最多递归2n层，因此空间复杂度为O(n).

	- Method2: BFS: slowly! But good for training of BFS. 
	- complexity:
    	- time: O(n).
    	- space: O(depth)：depth 是树的高度。
	

- <102. Binary Tree Level Order Traversal>
	
	- Method1: DFS + preorder.
		
		```
		void preorderDFS(TreeNode* root, vector<vector<int>>& ret, int level){
			if(root==NULL) return;        
			if(ret.size()<=level){
				ret.push_back(vector<int>());
			}        
			ret[level].push_back(root->val);        
			level++;
			doing(root->left, ret, level);
			doing(root->right, ret, level);                
		}
		```
		
	- complexity: 
		time: O(n)： 
		space: O(depth)：depth 是树的高度。
	
	- Method2: BFS + queue.
		
		```
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> res;        
			if(root==nullptr) return res;
			queue<TreeNode*> q;
			q.push(root);
			while(!q.empty()) {
				int n = q.size();
				vector<int> row(n,0);
				for(int i=0; i<n; ++i) {                
					TreeNode* node = q.front();
					q.pop();
					row[i] = node->val;
					if(node->left) q.push(node->left);
					if(node->right) q.push(node->right);
				}
				res.push_back(row);
			}
			return res;
		}	
		```
		
	- complexity: 
	
		- time: O(n)：每个点进队出队各一次，故渐进时间复杂度为 O(n)。
		- space: O(n)：队列中元素的个数不超过 n 个，故渐进空间复杂度为 O(n)。
	
	
