本文件主要阐述自己对算法的理解，参考《算法设计与分析》这本书，结合自己的感悟

一切算法都可转化为搜索方法，因为一切问题都可转化为解空间的搜索问题，一切优化策略都可用剪枝的思想来理解。
优化包括两方面，时间复杂度和空间复杂度，如果是真正的系统，还应包括IO复杂度，以及稳定性、安全性。

算法是一种思想，复杂度可用理论来分析，但具体性能还是由实现方式决定。
理论分析的复杂度是最佳实现的预期结果，但真正的最佳实现也许根本没法实现。
理论与实践，就是算法与数据结构的关系，你永远无法在一个链表上实现堆排序算法。
算法受问题特征制约，数据结构受问题规模制约，有些现实问题注定是无法用线性表来表示的，那么一切需要数组才能实现的算法都不适用，
哪怕其复杂度再低。

现实中为了应对大数据的挑战，包括时间和空间，可以采取并行或者分布式的方法，
通过添加不昂贵的机器。
在大数据时代，多项式时间的复杂度不一定够用。
在基于子图同构的QA系统中，虽然子图同构是NPC问题，但查询图一般很小，所以查询响应反而更快。

