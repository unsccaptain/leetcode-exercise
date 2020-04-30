/**
 * 三数之和
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/993
 **/
#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

namespace s993 {
namespace use_twopointer {
/**
 * @brief: 双指针方法
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.size() < 3)
      return ret;

    sort(nums.begin(), nums.end());
    int size = nums.size() - 1;

    int cur_num = INT_MIN;
    for (int i = 0; i < nums.size() - 2; ++i) {
      /// 跳过相同的值，避免返回时出现相同序列
      if (cur_num == nums[i])
        continue;
      cur_num = nums[i];

      /// 计算target以及双指针的头和尾,后面基本和991一样了
      int target = 0 - cur_num;
      int cur_j = i + 1;
      int cur_k = nums.size() - 1;

      /// 执行双指针算法
      while (cur_j < cur_k) {
        int num_1 = nums[cur_j];
        int num_2 = nums[cur_k];
        if (num_1 + num_2 > target)
          --cur_k;
        else if (num_1 + num_2 < target)
          ++cur_j;
        else {
          ret.push_back({cur_num, (int)num_1, (int)num_2});
          /// 跳过相同的值，注意数组的边界
          while (cur_j < size && nums[++cur_j] == num_1)
            ;
          while (cur_k > cur_j && nums[--cur_k] == num_2)
            ;
        }
      }
    }

    return ret;
  }
};
} // namespace use_twopointer
} // namespace s993