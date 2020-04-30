/**
 * 集合set的使用:快乐数
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/979
 **/
#pragma once

#include <set>
using namespace std;

namespace s979 {
namespace use_set {
/**
 * @brief: 集合解法
 */
class Solution {
public:
  bool isHappy(int n) {
    set<int> appeared;
    /// 计算迭代平方和
    while (true) {
      int num = n;
      int sum = 0;
      while (num != 0) {
        int remain = num % 10;
        num = (num - remain) / 10;
        sum += remain * remain;
      }
      if (sum == 1)
        return true;
      if (appeared.count(sum))
        return false;
      appeared.insert(sum);
      n = sum;
    }
  }
};
} // namespace use_set
namespace use_two_pointer {
/**
 * @brief: 双指针解法
 */
class Solution {
public:
  int result(int num) {
    int sum = 0;
    while (num != 0) {
      int remain = num % 10;
      num = (num - remain) / 10;
      sum += remain * remain;
    }
    return sum;
  }
  bool isHappy(int n) {
    int slow = result(n), fast = result(result(n));
    while (fast != 1 && fast != slow) {
      slow = result(slow);
      fast = result(result(fast));
    }
    return fast == 1;
  }
};
} // namespace use_two_pointer
} // namespace s979