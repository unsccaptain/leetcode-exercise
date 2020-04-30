/**
 * ��ĸ��λ�ʷ���
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/999
 **/
#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

namespace s999 {
namespace use_map {
/**
 * @brief: �ֵ䷽��
 */
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    unordered_map<string, vector<string>> um;
    vector<vector<string>> ret;

    /// ��ÿ���ַ������ַ���������Ľ������
    for (auto iter : strs) {
      string s = iter;
      sort(s.begin(), s.end());
      um[s].push_back(iter);
    }

    /// ���ط�����
    for (auto iter : um) {
      ret.push_back(iter.second);
    }

    return ret;
  }
};
} // namespace use_map
namespace use_prime {
/**
 * @brief: ��������
 */
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    /// ����ĸ���ϵ���ĸӳ�䵽һ������
    vector<int> prime = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    unordered_map<double, vector<string>> map;
    vector<vector<string>> ret;

    /// ��ȷ��֤����md�ļ�
    for (auto &str : strs) {
      double value = 1;
      for (auto c : str) {
        value *= prime[c - 'a'];
      }
      map[value].push_back(str);
    }

    for (auto iter : map) {
      ret.push_back(iter.second);
    }

    return ret;
  }
};
} // namespace use_prime
} // namespace s999