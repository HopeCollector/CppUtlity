# 用来干什么
给定两个字符串 `target` `str`，在 `str` 中寻找 `target` 最先出现的位置

# 核心思想
对 `target` 建立 PMT(Partial Match Table)，这个表中的元素与  `target` 一一对应。
针对 `pmt[i]=n` ，其表示第 i 个字符与从头开始的第 n 个字符相同，同时第 i 个字符的前 n-1 个字符也与从头开始的前 n-1 个字符相同
![[KMP.png]]

利用这张表，在匹配失败后可以跳过一些字符，从而保证 str 中每个字符只需要被查找一次就能得到答案

# 流程
## 建立 PMT 表
```cpp
std::vector<int> pmt(target.size());
// 每次循环开始时 j 的含义：target[i-1] 对应的前缀长度
// target[j] ：长度为 j 的前缀后面的第一个字符
for(size_t i = 1, j = 0; i < target.size(); i++) {
	// 缩短前缀，使得前缀后的第一个字符与当前字符相同
	while(j && target[j] != target[i]) 
		// 以 target[i-1] 为前缀的结尾缩短前缀
		j = pmt[j-1];
	if(target[j] == target[i]) j++;
	pmt[i] = j;
}
```
针对 pmt[i] = j，target[j-1] 与 target[i] 是相同的。因此 pmt[i] 与 pmt[j-1] 表示的两个前缀其最后一个字符是相同的，使用 `j=pmt[j-1]` 就达到了 **保证前缀最后一字符不变的情况下缩短前缀**  


## 根据 PMT 表查找 `target` 的位置
```cpp
for (size_t i = 0, j = 0; i < str.size(); i++) {
	// 和上面同样的技术，保证前缀的最后一个字符是 target[i-1]
	// 的情况下缩短前缀，从而是的前缀后面的第一个字符与 target[i] 相同
	while (j && str[i] != target[j]) 
		j = pmt[j-1];

	if(target[j] == str[i]) j++;
	if(j == target.size())
		return i-j+1;
}
```


# 相关资料
[[https://gist.github.com/gongzhitaao/5e9d8f80aaba60e14a2c|一个比较好用的 cpp 实现]]
[[https://leetcode-cn.com/problems/implement-strstr/submissions/|leetcode-28-实现 strStr()]]
[[http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html:|宏观层面的 KMP 讲解]]