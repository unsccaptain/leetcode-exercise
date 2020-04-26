/**
 * ����֮�͢�
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/997
 * �����ֵ�ķ��������ȼ���A��B�����п��ܵĺͣ��ټ���C��D���п��ܵĺͣ����������ߺ�Ϊ0�ĳ��ִ������Ƚϼ򵥡�
 * ������������֮�͵�˼�����չ��
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
				/// �����A��B�����п������
				for (int i = 0;i < A.size();++i) {
					for (int j = 0;j < B.size();++j) {
						z[A[i] + B[j]]++;
					}
				}

				int cnt = 0;
				/// �ټ����C��D�����п�����ϣ���������������Ͻ��Ϊ0�ĸ���
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