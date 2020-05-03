/**
 * ʵ�� strStr()
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/780
 **/
#pragma once

#include <string>
#include <vector>
using namespace std;

namespace s780 {
namespace plain {
/// @brief:����������Ҳ���ǹٷ���˫ָ�뷽��
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
/// @brief:KMP�㷨
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0)
      return 0;
    if (needle.size() > haystack.size())
      return -1;
    vector<int> next = vector<int>(needle.size() + 1, 0);
    int cur_state = -1;
    /// ��һ������Ϊ-1������ͳһ�����
    next[0] = cur_state;
    for (int i = 0; i < needle.size(); ++i) {
      /// �ݹ��ҵ���ͬ��ǰ��׺
      while (cur_state >= 0 && needle[i] != needle[cur_state])
        cur_state = next[cur_state];
      /// ��һ���ַ���ƥ��Ļ���ת��ǰһ��״̬�����ַ�����
      next[i + 1] = ++cur_state;
    }

    int pos_h = 0;
    int pos_n = 0;
    while (pos_h < haystack.size()) {
      if (haystack[pos_h] != needle[pos_n]) {
        if (next[pos_n] == -1)
          /// ��ͷ��ʧ�䣬ģʽ��֮������Ųһ��
          ++pos_h;
        else
          /// ģʽ������Ųnext[pos_n]�����ƶ�����һ��ǰ��׺��
          pos_n = next[pos_n];
        continue;
      }
      ++pos_h;
      if (pos_n + 1 == needle.size())
        /// ����
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
    /// ��¼�����ַ������ֵ�λ��
    for (unsigned i = 0; i < needle.size(); ++i)
      exist[needle[i]] = i;
    int pos = 0;
    while (pos <= (int)haystack.size() - (int)needle.size()) {
      bool equal = true;
      for (unsigned i = 0; i < needle.size(); ++i) {
        if (haystack[pos + i] != needle[i]) {
          /// ʧ��
          char c = haystack[pos + needle.size()];
          if (exist[c] == -1)
            /// ģʽ���������һ���ַ�û�����ı����г���
            pos += needle.size() + 1;
          else
            /// ��ģʽ�����뵽�ı���
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