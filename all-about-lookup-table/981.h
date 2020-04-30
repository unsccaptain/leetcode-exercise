/**
 * 集合set的使用:存在重复元素
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/981
 **/
#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

namespace s981 {
namespace use_sort {
/**
 * @brief：排序方法
 */
class Solution {
public:
  /// 这道题理应是用set解决，但很奇怪，为什么set效率会很差。
  bool containsDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (auto i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1])
        return true;
    }
    return false;
  }
};
} // namespace use_sort
namespace use_set {
/**
 * @brief：集合方法
 */
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> num_set;
    for (auto i = 0; i < nums.size(); ++i) {
      if (num_set.count(nums[i]))
        return true;
      num_set.insert(nums[i]);
    }
    return false;
  }
};
} // namespace use_set
} // namespace s981