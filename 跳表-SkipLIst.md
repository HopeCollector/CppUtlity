# 用来干什么
用来在 [[链表]] 中进行快速查找特定元素

# 核心思想
类似于书籍的目录，为链表存储的数据构建目录，在查找数据的时候先去查目录确定大致范围，再跑去链表上找数据就很快了
![[跳表.jpg]]	

# 结构
如上所示的结构就是跳表的大致结构。为了加速查找调表的 “目录” 一般是多级目录，就像书的 “卷、册、部、章、节、、、” 等等，从上到到下分级越来越细。（我觉得这样极致的跳表其实就是 [[树]]
![[跳表2.jpg]]

## 空间、时间复杂度
针对有 n 个节点的链表来说，其跳表的索引层级为 $log(n)-1$，因此相比于原来的链表其所占空间约为原来的两倍
因为查找一次的时间是固定的，所以时间复杂度为 $O(log(n))$

# 相关操作
## 插入
- 通过跳表找到合适的插入位置
- 插入节点
- while（晋升成功（新节点））
	- 在更高一层把该节点插入

`晋升成功()` 是一个返回 true 的概率为 50% 的随机函数，目的就是让新节点随机获得进入上一层的机会，防止因为插入太多数据导致索引不够用
![[跳表3.jpg]]
![[跳表4.jpg]]
![[跳表5.jpg]]
![[跳表6.jpg]]

## 删除
- 找到目标节点
- 删掉
- while（更高层还有指向该节点的节点）
	- 删除节点

![[跳表7.jpg]]
![[跳表8.jpg]]