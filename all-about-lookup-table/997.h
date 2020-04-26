/**
 * 四数之和Ⅱ
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/997
 * 还是字典的方法，首先计算A和B的所有可能的和，再计算C和D所有可能的和，计算这两者和为0的出现次数，比较简单。
 * 基本还是两数之和的思想的扩展。
 **/
#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

namespace s997 {
	namespace use_map {
		class Solution {
		public:
			int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
				unordered_map<int, int> z;
				/// 计算出A和B的所有可能组合
				for (int i = 0;i < A.size();++i) {
					for (int j = 0;j < B.size();++j) {
						z[A[i] + B[j]]++;
					}
				}

				int cnt = 0;
				/// 再计算出C和D的所有可能组合，并计数这两个组合结果为0的个数
				for (int i = 0;i < A.size();++i) {
					for (int j = 0;j < B.size();++j) {
						int k = -(C[i] + D[j]);
						cnt += z[k];
					}
				}

				return cnt;
			}
		};
	}
}