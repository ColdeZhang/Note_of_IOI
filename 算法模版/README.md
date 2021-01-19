# Templates In OI

## 概述

总结了一些在 **信息学竞赛(Olympiad in Informatics, OI)** 中可能会用到的模板， 配置文件等。

## 目录

### [AL]算法及常用思想

- `/AL/cantor-expansion.cpp`, 基于树状数组的康托展开
- `/AL/radix-sort.cpp`, 基数排序
- `/AL/divide.cpp`， 整体二分求静态区间第k小
- `/AL/divide-2.cpp`，整体二分求动态区间第k小
- `/AL/cdq.cpp`, `cdq` 分治求[P3157 [CQOI2011]动态逆序对](https://www.luogu.com.cn/problem/P3157)
- `/AL/three-divide.cpp`, 三分法求函数最值
- `/AL/discretization.cpp`, 离散化

### [DP]动态规划

- `/DP/knapsack-pure.cpp`, `01` 背包
- `/DP/knapsack-complete.cpp`, 完全背包
- `/DP/knapsack-multiple.cpp`, 单调队列优化多重背包
- `/DP/knapsack-grouped.cpp`, 分组背包
- `/DP/lcis.cpp`, 最长公共上升子序列
- `/DP/lcs-lis.cpp`, 用最长上升子序列实现的最长公共子序列
- `/DP/lcs-normal.cpp`, 最长公共子序列的朴素实现
- `/DP/lis-bit.cpp`, 最长上升子序列的树状数组写法
- `/DP/lis-greedy.cpp`, 基于贪心和单调栈的最长上升子序列
- `/DP/digit.cpp`, 记忆化搜索实现数位dp求解[P2657 [SCOI2009] windy 数](https://www.luogu.com.cn/problem/P2657)

### [DS]数据结构

- `/DS/chairman-tree.cpp`, 静态主席树（~~可持久化离散化桶~~）
- `/DS/disjoint-set.cpp`, 并查集
- `/DS/dynamic-sgt.cpp`, 动态开点线段树
- `/DS/linear-basis.cpp`, 线性基
- `/DS/normal-bit.cpp`, 朴素树状数组（~~芬维克树~~）
- `/DS/normal-sgt.cpp`, 朴素线段树
- `/DS/normal-splay.cpp`, 朴素 `splay` 实现普通平衡树
- `/DS/reverse-splay.cpp`, `splay` 实现文艺平衡树
- `/DS/sparse-table.cpp`, `st` 表
- `/DS/humdrum-queue.cpp`, 单调队列求滑动窗口

### [GT]图论

- `/GT/bridge.cpp`, `Tarjan` 桥
- `/GT/cut-point.cpp`, `Tarjan` 割点
- `/GT/dijkstra.cpp`, 堆优化 `dijkstra` 实现单源最短路径
- `/GT/kruskal.cpp`, `kruskal` 最小生成树
- `/GT/boruvka.cpp`, `boruvka` 最小生成树
- `/GT/prim.cpp`, `prim` 最小生成树
- `/GT/shrink-point.cpp`, `Tarjan` 缩点
- `/GT/spfa.cpp`, `spfa` 实现单源最短路径
- `/GT/tarjan-lca.cpp`, `tarjan` 离线求最近公共祖先(Lowest Common Ancestor, LCA)
- `/GT/tree-cut-lca.cpp`, 树链剖分求 `LCA`
- `/GT/tree-cut.cpp`, 树链剖分
- `/GT/double-lca.cpp`, 倍增求 `LCA`
- `/GT/ssst.cpp`, 基于树剖的严格次小生成树
- `/GT/negative-circle.cpp`, 基于 `spfa` 的负环
- `/GT/hungarian-algorithm.cpp`, 匈牙利算法求解二分图最大匹配
- `/GT/hlpp.cpp`, 预留推进求最大流
- `/GT/dinic.cpp`, `dinic` 求最大流
- `/GT/isap.cpp`, `ISAP` 求最大流
- `/GT/kth-short-path-A-star.cpp`, `A*` 求 `k` 短路
- `/GT/point-divide.cpp`, 点分治

### [MT]数论

- `/MT/crt.cpp`, 中国剩余定理
- `/MT/euler-prime.cpp`, 欧拉筛
- `/MT/gcd-lcm.cpp`, 欧几里得定理求最大公约数/最小公倍数
- `/MT/inv-exgcd.cpp`, 扩展欧几里得定理求单个数字的乘法逆元
- `/MT/inv-fermat.cpp`, 费马小定理求单个数字的乘法逆元
- `/MT/inv-linear.cpp`, 线性求 `1 ~ n` 中每个数字的乘法逆元
- `/MT/lucas.cpp`, 卢卡斯定理
- `/MT/miller-rabin.cpp`, `miller-rabin` 快速判素
- `/MT/pollard-rho.cpp`, `pollard-rho` 快速质因数分解
- `/MT/quick-matrix-pow.cpp`, 矩阵快速幂
- `/MT/quick-pow.cpp`, 快速幂
- `/MT/fft.cpp`, 快速傅里叶变换
- `/MT/ntt.cpp`, 快速数论变换
- `/MT/nim.cpp`, `nim` 游戏
- `/MT/Bézout’s-theorem.cpp`, 裴蜀定理

### [SA]字符串算法

- `/SA/ac-automaton.cpp`, `AC` 自动机实现多串匹配
- `/SA/kmp.cpp`, `KMP` 算法实现单串匹配
- `/SA/manacher.cpp`, `manacher` 求最长回文子串

### [CONF]配置

- `/CONF/.vimrc`, `vim` 编辑器的配置文件

