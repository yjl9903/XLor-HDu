# A Ascending Rating

注意输入规则！

反向维护一个滑动窗口的单调队列。

# C Dynamic Graph Matching

状压DP好题。

匹配：一个边集，边集中任意两条边没有公共顶点。

题意要询问的是每次操作后每个边集大小为 1,2,...,n/2 的方案数。

考虑状压dp，对于加边操作, dp\[i][s] = dp\[i - 1][s] + dp\[i - 1][s ^ (u | v)] (状态s中0表示未选中，1表示已经选中)

对于删边操作，上式改为减法更新。

# D Euler Function

考虑欧拉函数是积性函数，对于一个合数x, phi(x) = phi(p1) * phi(p2) * ...

对于素数p, phi(p) = p - 1，显然 2 | p - 1

特殊考虑 x = 6 的情况。

# F Grab The Tree

对于原图分层染色，那么如果两个集合的异或和不同，那么先手只需要取大的那个。

如果异或和相同，那么从刚才取得集合中，不断删去元素，看是否能比另外一个大，并记录是否会相等（如果不能比另外一个大），瞎搞完成！

# L Visual Cube

模拟。