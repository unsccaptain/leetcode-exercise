/**
 * 回旋镖的数量
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/1001
 **/
#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

namespace s1001 {
namespace use_map {
class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int count = 0;

    unordered_map<double, int> dis;
    double *result = new double[points.size() * points.size()];

    /// 首先将图上任意两点间的距离计算出来，避免后面的重复计算
    for (unsigned i = 0; i < points.size(); ++i) {
      vector<int> &I = points[i];
      for (unsigned j = 0; j < points.size(); ++j) {
        vector<int> &J = points[j];
        result[i * points.size() + j] = result[j * points.size() + i] =
            pow(I[0] - J[0], 2) + pow(I[1] - J[1], 2);
      }
    }

    for (unsigned i = 0; i < points.size(); ++i) {
      dis.clear();
      for (unsigned j = 0; j < points.size(); ++j) {
        if (i == j)
          continue;
        int d = result[i * points.size() + j];
        /// 累计所有到points[i]这个点距离为d的点
        ++dis[d];
      }

      /// 这里就是排列数P(m, 2)
      for (auto &C : dis) {
        count += C.second * (C.second - 1);
      }
    }

    return count;
  }
};
} // namespace use_map
} // namespace s1001