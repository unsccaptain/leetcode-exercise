/**
 * 直线上最多的点数
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/1003
 **/
#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

namespace s1003 {
	namespace use_map {
		class Solution {
		public:
			int maxPoints(vector<vector<int>>& points) {
				if (points.size() < 2) return points.size();
				int max = 0;
				double k;
				vector<vector<int>> flag = vector<vector<int>>(points.size(), vector<int>(points.size(), 0));
				for (unsigned i = 0;i < points.size();++i)
					flag[i][i] = 1;

				for (unsigned i = 0;i < points.size();++i) {
					vector<int>& I = points[i];
					int duplicate = 0;
					unordered_map<double, vector<int>> ss;
					for (unsigned j = i + 1;j < points.size();++j) {
						if (flag[i][j]) continue;
						vector<int>& J = points[j];
						if (I == J) {
							++duplicate;
							for (unsigned k = i;k < j;++k)
								flag[k][j] = 1;
							for (unsigned k = j;k < points.size();++k)
								flag[j][k] = 1;
							continue;
						}
						else if (J[0] - I[0] == 0)
							k = INFINITY;
						else
							k = 1.0 * (J[1] - I[1]) / (J[0] - I[0]);

						for (auto& point : ss[k]) {
							flag[point][j] = 1;
						}
						ss[k].push_back(j);
					}

					if (max < duplicate + 1)
						max = duplicate + 1;

					for (auto& solt : ss) {
						int local = solt.second.size() + duplicate + 1;
						if (max < local)
							max = local;
					}
				}

				return max;
			}
		};
	}
}