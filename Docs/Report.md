# LeetCode 解题报告

## 1. Two Sum

```
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

题目: 
给定一个整型数组, 找出其中两个数字, 使得它们的和等于某个指定的值. 返回这两个数在数组中的索引.(假设只有一种答案, 并且数组中的同一个元素只能被用一次.)

例如: 
给定一个数组 nums = [2, 7, 11, 15], 指定的值为 target = 9,
因为 nums[0] + nums[1] = 2 + 7 = 9,
所以应该返回 [0, 1].

思路:
较直观的方法是对这个 nums 做嵌套遍历. 这个方法较暴力. 时间复杂度是 `O(n^2)`.


