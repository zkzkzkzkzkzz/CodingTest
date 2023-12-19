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
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int LeftDepth = maxDepth(root->left);
		int RightDepth = maxDepth(root->right);

		// 부모 노드의 레벨을 더해준다
		return max(LeftDepth, RightDepth) + 1;
	}
};

int main()
{
	Solution sol;

	TreeNode* Tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

	sol.maxDepth(Tree);

	return 0;
}