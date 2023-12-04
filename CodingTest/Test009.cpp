#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> res = {};
		vector<int> tempVec = {};

		sort(nums.begin(), nums.end());

		for (int i = nums.size() - 1; i > 1; --i)
		{
			int OriginalNum = nums[i];
			int TargetNum = -OriginalNum;
			int MaxRight = i - 1;

			for (int j = 0; j < nums.size();)
			{
				int Left = nums[j];
				int Right = nums[MaxRight];

				if (j == MaxRight)
				{
					break;
				}

				if (TargetNum == Left + Right)
				{
					tempVec = {};

					tempVec.push_back(nums[j]);
					tempVec.push_back(nums[MaxRight]);
					tempVec.push_back(nums[i]);

					sort(tempVec.begin(), tempVec.end());

					res.push_back(tempVec);

					--MaxRight;
				}
				else if (TargetNum < Left + Right)
				{
					--MaxRight;
				}
				else if (TargetNum > Left + Right)
				{
					++j;
				}
			}
		}

		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res.size(); ++j)
			{
				if (i != j)
				{
					if (res[i] == res[j])
					{
						res.erase(res.begin() + j);
						--j;
					}
				}
			}
		}

		return res;
	}
};

int main()
{
	Solution S;
	vector<int> Nums1 = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };

	S.threeSum(Nums1);

	return 0;
}