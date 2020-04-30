/**
 * ����֮��
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
 * @brief: ˫ָ�뷽��
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
      /// ������ͬ��ֵ�����ⷵ��ʱ������ͬ����
      if (cur_num == nums[i])
        continue;
      cur_num = nums[i];

      /// ����target�Լ�˫ָ���ͷ��β,���������991һ����
      int target = 0 - cur_num;
      int cur_j = i + 1;
      int cur_k = nums.size() - 1;

      /// ִ��˫ָ���㷨
      while (cur_j < cur_k) {
        int num_1 = nums[cur_j];
        int num_2 = nums[cur_k];
        if (num_1 + num_2 > target)
          --cur_k;
        else if (num_1 + num_2 < target)
          ++cur_j;
        else {
          ret.push_back({cur_num, (int)num_1, (int)num_2});
          /// ������ͬ��ֵ��ע������ı߽�
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