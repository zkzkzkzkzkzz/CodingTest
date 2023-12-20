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
	int longestUnivaluePath(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int Res = 0;

		longestUnivaluePathRecursive(root, Res);

		return Res;
	}

private:
	int longestUnivaluePathRecursive(TreeNode* root, int& _Res)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int Left = longestUnivaluePathRecursive(root->left, _Res);
		int Right = longestUnivaluePathRecursive(root->right, _Res);

		int LeftDist = 0;
		int RightDist = 0;

		if (root->left != nullptr && root->left->val == root->val)
		{
			LeftDist = Left + 1;
		}

		if (root->right != nullptr && root->right->val == root->val)
		{
			RightDist = Right + 1;
		}

		_Res = max(_Res, LeftDist + RightDist);

		return max(LeftDist, RightDist);
	}
};


int main()
{
	Solution sol;

	TreeNode* Tree = new TreeNode(5, new TreeNode(4, new TreeNode(1), new TreeNode(1)), new TreeNode(5, nullptr, new TreeNode(5)));

	sol.longestUnivaluePath(Tree);

	return 0;
}