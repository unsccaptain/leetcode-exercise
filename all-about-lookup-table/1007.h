/**
 * 存在重复元素 III
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/1007
 **/
#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

namespace s1007 {
namespace direct {
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    for (int i = 0; i < nums.size(); ++i) {
      int boundary = min((int)nums.size(), i + k + 1);
      /// 在[i, boundary)的窗口中查找
      for (int j = i + 1; j < boundary; ++j) {
        if (abs((long long)nums[i] - nums[j]) <= t)
          return true;
      }
    }
    return false;
  }
};
} // namespace direct
namespace use_set {
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    set<int> window;
    /// 利用set建立有序的滑动窗口，可以将直接算法中的线性查找转为二分查找
    for (int i = 0; i < nums.size(); ++i) {
      /// lower_bound就是第一个大于等于nums[i]的位置，所以--lower_bound就是第一个小于nums[i]的位置
      auto equal_or_greater = window.lower_bound(nums[i]);
      if (equal_or_greater != window.end() &&
          (long long)*equal_or_greater - nums[i] <= t)
        return true;
      if (equal_or_greater != window.begin()) {
        --equal_or_greater;
        if ((long long)nums[i] - *equal_or_greater <= t)
          return true;
      }
      window.insert(nums[i]);
      if (window.size() > k)
        window.erase(nums[i - k]);
    }
    return false;
  }
};
} // namespace use_set
} // namespace s1007

// 桶方法
// 疯了，怎么都过不了那个10000的用例
// class Solution {
// public:
//
//    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//        map<long long, int> buckets;
//        if (t < 0) return false;
//        long long w = (long long)t + 1;
//        for (int i = 0;i < nums.size();++i) {
//            long long key = t != 0 ? std::floor(1.0 * nums[i] / w) : 0;
//            map<long long, int>::iterator key_it = buckets.find(key);
//            if (key_it != buckets.end())
//                return true;
//            key_it = buckets.find(key - 1);
//            if (key_it != buckets.end() && (nums[i] - key_it->second < w))
//            return true; key_it = buckets.find(key + 1); if (key_it !=
//            buckets.end() && (key_it->second - nums[i] < w)) return true;
//            buckets[key] = nums[i];
//            if (buckets.size() > k)
//                buckets.erase(t != 0 ? std::floor(1.0 * nums[i - k] / w) : 0);
//        }
//        return false;
//    }
//};