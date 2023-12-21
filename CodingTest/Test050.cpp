#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		if (nums.size() == 0)
		{
			return nullptr;
		}
		else if (nums.size() == 1)
		{
			return new TreeNode(nums[0]);
		}

		// nums는 오름차순 정렬이 되어있으므로 중앙 인덱스는 nums의 사이즈에 2를 나눈 값
		int MidIdx = nums.size() / 2;

		TreeNode* ResNode = new TreeNode(nums[MidIdx]);

		// 중앙 노드 기준으로 왼쪽 자식에 해당하는 노드들의 벡터
		vector<int> Left(nums.begin(), nums.begin() + MidIdx);

		// 중앙 노드 기준으로 오른쪽 자식에 해당하는 노드들의 벡터
		vector<int> Right(nums.begin() + MidIdx + 1, nums.end());

		ResNode->left = sortedArrayToBST(Left);
		ResNode->right = sortedArrayToBST(Right);

		return ResNode;
	}
};


int main()
{
	Solution Sol;

	vector<int> vec = { -10, -3,0,5,9 };

	Sol.sortedArrayToBST(vec);


	return 0;
}