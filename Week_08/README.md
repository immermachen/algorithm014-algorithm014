# week8 学习笔记

# 第16课：位运算

## 1. 位运算基础及实战要点


### some important tips:

- XOR 异或： 可理解为“不进位加法”。
- XOR 特点:
	X^0 = X;
	X^1s = ~X; //note: 1s=~0;
	X^(~X) = 1s;
	X^X = 0;
	
	c = a^b ==> a^c=b, b^c=a; 交换律(Commutative property)
	a^b^c=a^(b^c)=(a^b)^c; 结合律(associative laws)
	
- 指定位置位运算 a neat little bit trick
TODO see pic.

 
- x-1: 
	
		是从位运算来讲，就是将其右边开始到第一个非0位都求反。

- x&(x-1): 
			
		drops the lowest set bit. 将最右非0位变0，也就是让其二进制表示的最右边的1变为0。 dropRightmost = x&(x-1)

	  	  7: 		0000 0111
		7-1: 		0000 0110
		7&(7-1):	0000 0110
	   
- x&-x: 
		
		get the lowest set bit. 得到最右非0位.  https://xie.infoq.cn/article/51898e1fedea126a91a8b2604. rightmost = x&-x

	    	7:		   0000 0111
		7的反码，~7:	1111 1000
		7的补码，-7:	1111 1001
	   		7&-7:	   0000 0001



### 复习: 位运算常见操作 

refer to: https://www.cxyxiaowu.com/8990.html


- 反码，补码

		7  0……0111； 
		最左一位是符号位，其负数的表示在计算机中是用补码表示。 
		
		计算机存储数的时候存储的是补码，正数的补码是其本身，而负数的补码是其反码加1. 因此，00110110加一个负号以后就变成了10110110（姑且认为最高位是符号位）， 其反码为11001001，补码为11001010。这个跟原来的数按位与后就是00000010。 
		（https://leetcode-cn.com/problems/n-queens-ii/solution/dfs-wei-yun-suan-jian-zhi-by-makeex/）
		
		补码等于反码加1。 
		最后得到的结果就是0……0001。 
		得到的数就是其最右非0位表示的数值，这里得到1。

- & 与：只有当两位都是 1 时结果才是 1，否则为 0 。
		
		    0110
		&   0100
		-----------
		    0100


- | 或：两位中只要有 1 位为 1 结果就是 1，两位都为 0 则结果为 0。

		    0110
		&   0110
		-----------
		    0110

- ^ 异或：两个位相同则为 0，不同则为 1

		    0110
		^   0100
		-----------
		    0010
	
	
- 左移<< ：向左进行移位操作，高位丢弃，低位补 0

		int a = 8;
		a << 3;
		移位前：0000 0000 0000 0000 0000 0000 0000 1000
		移位后：0000 0000 0000 0000 0000 0000 0100 0000

-  右移>>：向右进行移位操作，对无符号数，高位补 0，对于有符号数，高位补符号位

		unsigned int a = 8;
		a >> 3;
		移位前：0000 0000 0000 0000 0000 0000 0000 1000
		移位后：0000 0000 0000 0000 0000 0000 0000 0001
		
		int a = -8;
		a >> 3;
		移位前：1111 1111 1111 1111 1111 1111 1111 1000
		移位后：1111 1111 1111 1111 1111 1111 1111 1111



### 位运算使用技巧简介

- 判断整型的奇偶性

	
		if((x & 1) == 0) {
		    // 偶数
		} else {
		    // 奇数
		} 


- 判断第 n 位是否设置为 1

		if (x & (1<<n)) {
		    // 第 n 位设置为 1
		}
		else {
		    // 第 n 位设置为 1
		}

- 将第 n 位设置为 1

		y = x | (1<<n)

- 将第 n 位设置为 0

		y = x & ~(1<<n)

-  将第 n 位的值取反

		y = x ^ (1<<n)

		    01110101
		^   00100000
		    --------
		    01010101

- 将最右边的 1 设为 0

		y = x & (x-1)		

如果说上面的 5 点技巧有点无聊，那第 6 条技巧确实很有意思，也是在 leetcode 经常出现的考点，下文中大部分习题都会用到这个知识点，务必要谨记！掌握这个很重要，有啥用呢，比如我要统计 1 的位数有几个，只要写个如下循环即可，不断地将 x 最右边的 1 置为 0，最后当值为 0 时统计就结束了。
		
		count = 0  
		while(x) {
		  x = x & (x - 1);
		  count++;
		} 



## 2. 位运算实战题目解析

### N 皇后位运算代码示例

	# Python
	def totalNQueens(self, n): 
		if n < 1: return [] 
		self.count = 0 
		self.DFS(n, 0, 0, 0, 0) 
		return self.count
	def DFS(self, n, row, cols, pie, na): 
		# recursion terminator 
		if row >= n: 
			self.count += 1 
			return
		bits = (~(cols | pie | na)) & ((1 << n) — 1)  # 得到当前所有的空位
		while bits: 
			p = bits & —bits # 取到最低位的1
			bits = bits & (bits — 1) # 表示在p位置上放入皇后
			self.DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1) 
			# 不需要revert  cols, pie, na 的状态



	自动检测
	// Java
	class Solution {
		private int size; 
		private int count;
		private void solve(int row, int ld, int rd) { 
			if (row == size) { 
				count++; 
				return; 
			}
			int pos = size & (~(row | ld | rd)); 
			while (pos != 0) { 
				int p = pos & (-pos); 
				pos -= p; // pos &= pos - 1; 
				solve(row | p, (ld | p) << 1, (rd | p) >> 1); 
			} 
		} 
	public int totalNQueens(int n) { 
		count = 0; 
		size = (1 << n) - 1; 
		solve(0, 0, 0); 
		return count; 
	  } 
	}


	C++
	//C/C++
	class Solution {
	public:
		int totalNQueens(int n) {
			dfs(n, 0, 0, 0, 0);			
			return this->res;
		}
		
		void dfs(int n, int row, int col, int pie, int na) {
			if (row >= n) { res++; return; }
			
			// 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历.
			int bits = ~(col | pie | na) & ((1 << n) - 1);
			while (bits > 0) {
				int pick = bits & -bits; // 注: x & -x. 每次从当前行可用的格子中取出最右边位为 1 的格子放置皇后.
				dfs(n, row + 1, col | pick, (pie | pick) << 1, (na | pick) >> 1); // 紧接着在下一行继续放皇后.
				bits &= bits - 1; // 注: x & (x - 1). 当前行最右边格子已经选完了，将其置成 0，代表这个格子已遍历过.
			}
		}
	private:
		int res = 0;
	};



	JavaScript
	// Javascript
	var totalNQueens = function(n) {
	  let count = 0;
	  void (function dfs(row = 0, cols = 0, xy_diff = 0, xy_sum = 0) {
		if (row >= n) {
		  count++;
		  return;
		}
		// 皇后可以放的地方
		let bits = ~(cols | xy_diff | xy_sum) & ((1 << n) - 1);
		while (bits) {
		  // 保留最低位的 1
		  let p = bits & -bits;
		  bits &= bits - 1;
		  dfs(row + 1, cols | p, (xy_diff | p) << 1, (xy_sum | p) >> 1);
		}
	  })();
	  return count;
	};



# 第17课：位运算

## 1. 布隆过滤器的实现及应用

## 2. LRU Cache的实现、应用和题解

- <146. LRU Cache>, Medium,  LRU 缓存机制（亚马逊、字节跳动、Facebook、微软在半年内面试中常考）
	- Method: O(1) unordered_map + list + splice.
	https://leetcode.com/problems/lru-cache/discuss/46223/O(1)-unordered_map-%2B-list-%2B-splice 
	- complexity:
		- time: O(1) for set and get.
		- space: O(N).
	
    

# 第18课：排序算法

## 1. 初级排序和高级排序的实现和特性


- 十大经典排序算法 https://www.cnblogs.com/onepixel/p/7674659.html 
	
- 9种经典排序算法可视化动画 https://www.bilibili.com/video/av25136272

- 6分钟看完15种排序算法动画展示 https://www.bilibili.com/video/av63851336
	
- 快速排序
	数组去标杆pivot，随机或者直接最右边元素。将小值放pivot左边，大值放pivot右边； 然后，左右递归快速排序；以达到整个数列有序。

		//C/C++
		// simple partition version
		int partition(vector<int>& nums, int begin, int end) {
		  int pivot = end, counter=begin;
		  for (int i=begin; i<end; i++) {
			if (nums[i] < nums[pivot]) {			  
			  swap(nums[counter], nums[i]);
			  counter++;
			}
		  }
		  swap(nums[counter], nums[pivot]);
		  return pivot;
		}
		void quicksort(vector<int>& nums, int l, int r) {
		  if (l < r) {
			int pivot_index = partition(nums, l, r);
			quicksort(nums, l, pivot_index-1);
			quicksort(nums, pivot_index+1, r);
		  }
		}
		// random partition version
		int random_partition(vector<int>& nums, int l, int r) {
		  int random_pivot_index = rand() % (r - l +1) + l;  //随机选择pivot
		  int pivot = nums[random_pivot_index];
		  swap(nums[random_pivot_index], nums[r]);
		  int i = l - 1;
		  for (int j=l; j<r; j++) {
			if (nums[j] < pivot) {
			  i++;
			  swap(nums[i], nums[j]);
			}
		  }
		  int pivot_index = i + 1;
		  swap(nums[pivot_index], nums[r]);
		  return pivot_index;
		}
		void random_quicksort(vector<int>& nums, int l, int r) {
		  if (l < r) {
			int pivot_index = random_partition(nums, l, r);
			random_quicksort(nums, l, pivot_index-1);
			random_quicksort(nums, pivot_index+1, r);
		  }
		}
	
	
- 归并排序 - 分治
	把数组对半分，然后左右递归归并排序；最后，合并左右排序好的子数组。

		C/C++
		void mergeSort(vector<int> &nums, int left, int right) {
			if (left >= right) return;
			
			int mid = left + (right - left) / 2;
			mergeSort(nums, left, mid);
			mergeSort(nums, mid+1, right);
			
			merge(nums, left, mid, right);
		}
		void merge(vector<int> &nums, int left, int mid, int right) {
			vector<int> tmp(right-left+1);
			int i = left, j = mid+1, k = 0;
			
			while (i <= mid && j <= right) {
				tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
			}
			while (i <= mid) tmp[k++] = nums[i++];
			while (j <= right) tmp[k++] = nums[j++];
			
			for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];
		}


- 堆排序代码示例

		
		C/C++
		// simple version using priority_queue
		void heapSort(vector<int>& nums) {
			priority_queue<int, vector<int>, greater<int>> pq;
			for(int i=0; i<nums.size(); ++i) {
				pq.push(nums[i]);            
			}
			for(int i=0; i<nums.size(); ++i) {
				nums[i] = pq.top();   
				pq.pop(); 
			}
		}    
		
		void heapify(vector<int> &array, int length, int i) {
			int left = 2 * i + 1, right = 2 * i + 2;
			int largest = i;

			if (left < length && array[left] > array[largest]) {
				largest = left;
			}
			if (right < length && array[right] > array[largest]) {
				largest = right;
			}

			if (largest != i) {
				int temp = array[i]; array[i] = array[largest]; array[largest] = temp;
				heapify(array, length, largest);
			}


			return ;
		}
		void heapSort(vector<int> &array) {
			if (array.size() == 0) return ;

			int length = array.size();
			for (int i = length / 2 - 1; i >= 0; i--) 
				heapify(array, length, i);

			for (int i = length - 1; i >= 0; i--) {
				int temp = array[0]; array[0] = array[i]; array[i] = temp;
				heapify(array, i, 0);
			}

			return ;
		}


- 课后作业： 
用自己熟悉的编程语言，手写各种初级排序代码，提交到学习总结中。
refer to: https://www.cnblogs.com/onepixel/p/7674659.html 

- 1、冒泡排序（Bubble Sort），实际中，基本不用！
	嵌套循环，每次查看相邻的两元素，逆序则交换。

		vector<int> bubbleSort(vector<int> nums) {
			int N = nums.size();
			for (int i = 0; i < N - 1; i++) {            
				for (int j = 0; j < N-1-i; j++) {
					if (nums[j] < nums[j+1]) continue;                    
					swap(nums[j], nums[j+1]);
				}
			}
			return nums;
		}

- 2、选择排序（Selection Sort）
	每次找最小值，然后放到待排序数组的起始位置。

		vector<int> selectionSort(vector<int> nums) {
			int N = nums.size();
			int minIndex;
			for (int i=0; i<N-1; i++) {
				minIndex = i;
				for (int j=i+1; j<N; j++) {
					if (nums[j] < nums[minIndex]) {
						minIndex = j;
					}
				}
				swap(nums[i], nums[minIndex]);
			}
			return nums;
		}

- 3、插入排序（Insertion Sort）
	从前到后逐步构建有序序列；对于未排序数组，在已排序序列中从后向前扫描，找到相应位置并插入。

		vector<int> insertionSort(vector<int> nums) {
				int N = nums.size();
				for (int i=1; i<N; i++) {                
					for (int j=i; j>0; --j) {
						if (nums[j] > nums[j-1]) break;						
						swap(nums[j], nums[j-1]);
					}
				}
				return nums;
		}


### 实战题目 / 课后作业

- <191. Number of 1 Bits>, Easy.
	- Method: Using n&(n-1) trick. 
	
			int hammingWeight(uint32_t n) {
				int res=0;
				while(n>0) {
					n = n&(n-1);
					res++;
				}
				return res;        
			}
			int hammingWeight_1111(uint32_t n) {
				return bitset<32>(n).count();    
			}
		
	- complexity:
		- time: O(32). n is the length of unsigned long int uint32_t.
		- space: O(1).		
	- Good Explain: https://leetcode.com/problems/number-of-1-bits/discuss/55255/C%2B%2B-Solution%3A-n-and-(n-1)
	 
			n & (n - 1) drops the lowest set bit. It's a neat little bit trick.		
			Let's use n = 00101100 as an example. This binary representation has three 1s.		
			If n = 00101100, then n - 1 = 00101011, so n & (n - 1) = 00101100 & 00101011 = 00101000. Count = 1.	
			If n = 00101000, then n - 1 = 00100111, so n & (n - 1) = 00101000 & 00100111 = 00100000. Count = 2.	
			If n = 00100000, then n - 1 = 00011111, so n & (n - 1) = 00100000 & 00011111 = 00000000. Count = 3.	
			n is now zero, so the while loop ends, and the final count (the numbers of set bits) is returned.

- <231. Power of Two>
	- Method: Using n&(n-1) trick. 	

			bool isPowerOfTwo(int n) {
				bitset<32> ones(n);
				return (n>0) && (ones.count()==1);
			}
			bool isPowerOfTwo_222(int n) {
				return (n>0) && !(n&(n-1));
			}
		
	- complexity:
		- time: O(32). n is the length of unsigned long int uint32_t.
		- space: O(1).	

- <190. Reverse Bits>
	- Method: bits trick. 	

			uint32_t reverseBits(uint32_t n) {        
				uint32_t res=0;
				for(char i=0; i<32; ++i) {
					res = (res<<1) + ((n>>i) & 1);
				}
				return res;
			}
		
	- complexity:
		- time: O(32). n is the length of unsigned long int uint32_t.
		- space: O(1).	

- <51. N-Queens>, Hard
	- Method1: DFS回溯. 
	- complexity:
    	- time: O(N!). N是皇后数量. 
    	- space: O(N).空间复杂度主要取决于递归调用层数.
		
	- Method2: DFS + bits trick. 基于位运算的回溯. 关键就在于将棋盘二进制化，将有皇后的位置用1表示，空位用0表示。 https://xie.infoq.cn/article/51898e1fedea126a91a8b2604 
	https://www.cxyxiaowu.com/8990.html
	
			vector<vector<string>> solveNQueens(int n) {
				vector<vector<string>> res;
				vector<string> solution(n, string(n,'.'));
				dfs(res, solution, n, 0, 0, 0, 0);
				return res;
			}
			void dfs(vector<vector<string>>& res, vector<string>& solution, int& n, int row, int col, int pie, int na) {
				if(row>=n) { res.push_back(solution); return; }
				
				int bits = ~(col | pie | na) & ( (1<<n) - 1 ); // get all usable bits
				while(bits>0) {
					int pick = bits & -bits;//pick the lowest bit 1=usable col.
					int c = getColIndex(pick, n);
					solution[row][c] = 'Q';
					dfs(res, solution, n, row+1, col|pick, (pie|pick)<<1, (na|pick)>>1);
					solution[row][c] = '.';
					bits = bits & (bits-1); // set the lowest bit 1 to 0.
				}
			}
			int getColIndex(int pick, int n) {
				while(pick>0) {
					pick=pick>>1;
					n--;
				}
				return n;
			}
			
			
	- complexity:
    	- time: O(N!). N是皇后数量. 
    	- space: O(N).空间复杂度主要取决于递归调用层数.

- <52. N-Queens II>, Hard, N 皇后 II （亚马逊在半年内面试中考过）
	- Good Explain： https://leetcode-cn.com/problems/n-queens-ii/solution/dfs-wei-yun-suan-jian-zhi-by-makeex/	
	- 核心思路是这样：
	
			使用常规深度优先一层层搜索
			使用三个整形分别标记每一层哪些格子可以放置皇后，这三个整形分别代表列、左斜下、右斜下(col, pie, na), 
			二进制位为1代表不能放置，0代表可以放置
			核心两个位运算：
				x & -x 代表除最后一位 1 保留，其它位全部为 0
				x & (x - 1) 代表将最后一位 1 变成 0
	- Method: DFS + bits trick.  
	
			int totalNQueens(int n) {
				int res=0;
				dfs(n, res, 0, 0, 0, 0);
				return res;
			}
			void dfs(int n, int& res, int row, int col, int pie, int na) {
				if(row==n) { res++; return; }
				int bits = ~(col | pie | na) & ( (1<<n)-1 );
				while(bits>0) {
					int pick = bits & -bits;
					dfs(n, res, row+1, col | pick, (pie|pick)<<1, (na|pick)>>1 );
					bits = bits&(bits-1);
				}
			}
			
	- complexity:
    	- time: O(N!). N是皇后数量. 
    	- space: O(N).空间复杂度主要取决于递归调用层数.

- <338. Counting Bits>, Medium, 
	比特位计数（字节跳动、Facebook、MathWorks 在半年内面试中考过）
	- Method1: DP + bit trick: i&(i-1). 
	
			vector<int> countBits(int num) {
				vector<int> cnt(num+1,0);
				for(int i=1; i<=num; ++i) {
					cnt[i] = cnt[i&(i-1)] + 1;
				}
				return cnt;
			}
			
	- complexity:
    	- time: O(N).
    	- space: O(N).
		


- <242. Valid Anagram>, Easy, 有效的字母异位词（Facebook、亚马逊、谷歌在半年内面试中考过）
	- Method: counting sort.
	- complexity:
		- time: O(N).
		- space: O(1).

- <1122. Relative Sort Array>, Easy    
	- Method: counting sort.
	- complexity:
		- time: O(1).
		- space: O(1).


- <56. Merge Intervals>, Medium, 合并区间（Facebook、字节跳动、亚马逊在半年内面试中常考）
	- Method: Sort.
	- complexity:
		- time: O(NLogN). NlogN for Sort function.
		- space: O(N).

- <493. Reverse Pairs>, Hard, 面试中经常出现逆序对问题！
	- Method1: Merge-Sort. 
			
			int mergeSort2(vector<int>& nums, int L, int R) {
				if(L>=R) return 0;
				int mid = (L+R)>>1;
				
				int res = mergeSort2(nums, L, mid) + mergeSort2(nums, mid+1, R); 
				res += merge(nums, L, mid, R);
				
				return res;
			}
			//merge + count
			int merge(vector<int>& nums, int L, int mid, int R) {
				vector<int> tmp(R-L+1, 0);        
				int res=0, i=L, j=mid+1, t=0;  
				
				//here to count between left and right sides.
				for(i=L, j=mid+1; i<=mid; ++i) {
					while(j<=R && nums[i]/2.0>nums[j]) j++;
					res += j-(mid+1);
				}
				
				for(i=L, j=mid+1; i<=mid && j<=R;) tmp[t++] = nums[i]<nums[j] ? nums[i++] : nums[j++]; 
				while(i<=mid) tmp[t++] = nums[i++];
				while(j<=R) tmp[t++] = nums[j++];
				for(i=L, t=0; i<=R;) nums[i++] = tmp[t++];
				return res;
			}	
	
		- time: O(NLogN). 
		- space: O(N).
	- Method2: TODO: 树状数组，利用二进制罗列下标。但面试中很少出现。	
		- time: O(NLogN). 
	
## 每日一题

- <25. Reverse Nodes in k-Group>, Hard
	- Method: 多个指针变换. 需要练习节点指针来回倒腾。 
	- complexity:
		- time: O(N). 
		- space: O(1). 

- <300. Longest Increasing Subsequence>, Medium, but hard to get the idea. [TODO +1]
	- Method: 动态规划+二分查找. 
	- 金句: 维护一个最长&上升&并且值最小的子序列sub。对原序列进行遍历，将每位元素二分插入 sub 中。如果 sub 中元素都比它小，将它插到最后; 否则，用它覆盖掉第一个不小于它的元素。
	总之，思想就是让 sub 中存储比较小的元素。这样，sub 未必是真实的最长上升子序列，但长度是对的。
	https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-e/

	- complexity:
		- time: O(N). 
		- space: O(1). 

