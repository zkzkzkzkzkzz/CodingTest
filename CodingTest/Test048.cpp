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
	bool isBalanced(TreeNode* root) 
	{
		if (root == nullptr)
		{
			return true;
		}

		int Res = 0;

		isBalancedRecursive(root, Res);

		if (Res > 1)
		{
			return false;
		}
		
		return true;
	}

private:
	int isBalancedRecursive(TreeNode* root, int& _Res)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int Left = isBalancedRecursive(root->left, _Res);
		int Right = isBalancedRecursive(root->right, _Res);
		
		_Res = max(_Res, abs(Left - Right));

		return max(Left, Right) + 1;
	}
};


int main()
{
	Solution sol;

	TreeNode* Tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

	sol.isBalanced(Tree);

	return 0;
}