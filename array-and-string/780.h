/**
 * 实现 strStr()
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/780
 **/
#pragma once

#include <string>
#include <vector>
using namespace std;

namespace s780 {
namespace plain {
/// @brief:暴力方法，也就是官方的双指针方法
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0)
      return 0;
    if (needle.size() > haystack.size())
      return -1;
    for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); ++i) {
      bool found = true;
      for (int j = 0; j < needle.size(); ++j) {
        if (haystack[i + j] != needle[j]) {
          found = false;
          break;
        }
      }
      if (found)
        return i;
    }
    return -1;
  }
};
} // namespace plain
namespace kmp {
/// @brief:KMP算法
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0)
      return 0;
    if (needle.size() > haystack.size())
      return -1;
    vector<int> next = vector<int>(needle.size() + 1, 0);
    int cur_state = -1;
    /// 第一个设置为-1，方便统一处理吧
    next[0] = cur_state;
    for (int i = 0; i < needle.size(); ++i) {
      /// 递归找到相同的前后缀
      while (cur_state >= 0 && needle[i] != needle[cur_state])
        cur_state = next[cur_state];
      /// 下一个字符不匹配的话跳转到前一个状态进行字符接收
      next[i + 1] = ++cur_state;
    }

    int pos_h = 0;
    int pos_n = 0;
    while (pos_h < haystack.size()) {
      if (haystack[pos_h] != needle[pos_n]) {
        if (next[pos_n] == -1)
          /// 开头就失配，模式串之间往后挪一个
          ++pos_h;
        else
          /// 模式串往后挪next[pos_n]，即移动到上一个前后缀处
          pos_n = next[pos_n];
        continue;
      }
      ++pos_h;
      if (pos_n + 1 == needle.size())
        /// 命中
        return pos_h - needle.size();
      else
        ++pos_n;
    }
    return -1;
  }
};
} // namespace kmp
namespace sunday {
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0)
      return 0;
    vector<int> exist = vector<int>(128, -1);
    /// 记录所有字符最后出现的位置
    for (unsigned i = 0; i < needle.size(); ++i)
      exist[needle[i]] = i;
    int pos = 0;
    while (pos <= (int)haystack.size() - (int)needle.size()) {
      bool equal = true;
      for (unsigned i = 0; i < needle.size(); ++i) {
        if (haystack[pos + i] != needle[i]) {
          /// 失配
          char c = haystack[pos + needle.size()];
          if (exist[c] == -1)
            /// 模式串结束后的一个字符没有在文本串中出现
            pos += needle.size() + 1;
          else
            /// 将模式串对齐到文本串
            pos += needle.size() - exist[c];
          equal = false;
          break;
        }
      }
      if (equal)
        return pos;
    }
    return -1;
  }
};
} // namespace sunday
} // namespace s780