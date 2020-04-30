/**
 * 两数之和
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/991
 **/
#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

namespace s991 {
namespace use_map {
/**
 * @brief: 字典方法
 */
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    using ni_map = unordered_map<int, int>;
    vector<int> ret;
    ni_map nm;
    for (int i = 0; i < nums.size(); ++i) {
      nm[nums[i]] = i;
    }
    for (int i = 0; i < nums.size() - 1; ++i) {
      int k = target - nums[i];
      ni_map::iterator it;
      if ((it = nm.find(k)) == nm.end()) {
        continue;
      }
      int z = it->second;
      if (z != i) {
        ret.push_back(i);
        ret.push_back(z);
        return ret;
      }
    }
    return ret;
  }
};
} // namespace use_map
namespace use_twopointer {
/**
 * @brief: 双指针方法
 */
class Solution {
public:
  struct NumIndex {
    int num;
    int index;
  };

  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ret;
    vector<NumIndex> ni = vector<NumIndex>(nums.size());
    for (unsigned i = 0; i < nums.size(); ++i) {
      ni[i].index = i;
      ni[i].num = nums[i];
    }
    /// 按照数字大小进行排序
    sort(ni.begin(), ni.end(),
         [](const NumIndex &a, const NumIndex &b) -> bool {
           if (a.num < b.num)
             return true;
           return false;
         });

    NumIndex *a = &ni.front();
    NumIndex *b = &ni.back();
    while (a != b) {
      if (a->num + b->num > target)
        --b;
      else if (a->num + b->num < target)
        ++a;
      else {
        ret.push_back(a->index);
        ret.push_back(b->index);
        break;
      }
    }
    return ret;
  }
};
} // namespace use_twopointer
} // namespace s991