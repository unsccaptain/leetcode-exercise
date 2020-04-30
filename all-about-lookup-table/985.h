/**
 * 有效的字母异位词
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/985
 * 先用set记录第一个string所有字母出现的次数，然后遍历第二个字符串，从set中减去其中出现的字符，最后判断set是不是被清空了
 * set最大数量是已知的，可以用一个数组来记录
 **/
#pragma once

#include <string>
using namespace std;

namespace s985 {
namespace use_map {
/**
 * @brief: 字典方法
 */
class Solution {
public:
  bool isAnagram(string s, string t) {
    int count[26] = {0};
    for (auto i : s) {
      count[i - 'a']++;
    }

    for (auto i : t) {
      if (count[i - 'a'] == 0)
        return false;
      count[i - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
      if (count[i])
        return false;
    }

    return true;
  }
};
} // namespace use_map
} // namespace s985