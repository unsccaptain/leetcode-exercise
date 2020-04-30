/**
 * �����ظ�Ԫ�� III
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
      /// ��[i, boundary)�Ĵ����в���
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
    /// ����set��������Ļ������ڣ����Խ�ֱ���㷨�е����Բ���תΪ���ֲ���
    for (int i = 0; i < nums.size(); ++i) {
      /// lower_bound���ǵ�һ�����ڵ���nums[i]��λ�ã�����--lower_bound���ǵ�һ��С��nums[i]��λ��
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

// Ͱ����
// ���ˣ���ô���������Ǹ�10000������
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