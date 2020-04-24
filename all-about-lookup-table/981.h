/**
 * ����set��ʹ��:�����ظ�Ԫ��
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/981
 **/

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

namespace s981 {
	namespace use_sort {
		/**
		 * @brief�����򷽷�
		 */
		class Solution {
		public:
			/// �������Ӧ����set�����������֣�ΪʲôsetЧ�ʻ�ܲ
			bool containsDuplicate(vector<int>& nums){
				sort(nums.begin(), nums.end());
				for (auto i = 1;i < nums.size();++i) {
					if (nums[i] == nums[i - 1])
						return true;
				}
				return false;
			}
		};
	}
	namespace use_set {
		/**
		 * @brief�����Ϸ���
		 */
		class Solution {
		public:
			bool containsDuplicate(vector<int>& nums) {
				unordered_set<int> num_set;
				for (auto i = 0;i < nums.size();++i) {
					if (num_set.count(nums[i]))
						return true;
					num_set.insert(nums[i]);
				}
				return false;
			}
		};
	}
}