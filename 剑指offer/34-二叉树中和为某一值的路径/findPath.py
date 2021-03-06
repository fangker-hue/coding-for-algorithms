# -*- coding:utf-8 -*-
"""
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

            10
          /   \
        5      12
      /  \
    4     7

如找和为 22 的路径，则输出：
[[10, 5, 7], [10, 12]]
如找和为 15 的路径，则输出 [[]]，
虽然从 10->5 是一个路径，但不是题目中描述的从根节点到叶子节点的路径
"""


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here

        if not root:
            return []
        if root and root.val == expectNumber and not root.left and not root.right:
            return [[root.val]]
        path = []
        left = self.FindPath(root.left, expectNumber - root.val)
        right = self.FindPath(root.right, expectNumber - root.val)
        for subPath in left + right:
            path.append([root.val] + subPath)
        return path



