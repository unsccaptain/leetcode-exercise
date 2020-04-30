/**
 * 同构字符串
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/987
 * 建立两个映射，s->t和t->s，然后分别检查确保没有一对多的映射。
 * 因为是字符串，所以仍然使用数组来建立映射。
 **/
#pragma once

#include <map>
#include <set>
#include <string>

using namespace std;

namespace s987 {
namespace use_map {
/**
 * @brief: 字典方法
 */
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    char s_map[128] = {0};
    for (auto i = 0; i < s.size(); i++) {
      /// 首先在s_map中建立s->t的映射
      if (s_map[s[i]] != 0) {
        /// 当前映射不符合之前的映射，返回失败
        if (t[i] != s_map[s[i]])
          return false;
      } else {
        s_map[s[i]] = t[i];
      }
    }

    char s_set[128] = {0};
    /// 这里检查t->s的映射是否正确，如果出现多对一的映射，返回失败
    for (unsigned i = 0; i < 128; ++i) {
      const char c = s_map[i];
      if (c != 0) {
        if (s_set[c] == 1)
          return false;

        s_set[c] = 1;
      }
    }

    return true;
  }
};
} // namespace use_map
} // namespace s987