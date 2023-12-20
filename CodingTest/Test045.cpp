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
	TreeNode* invertTree(TreeNode* root) 
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		invertTree(root->left);
		invertTree(root->right);

		TreeNode* Temp = root->left;

		root->left = root->right;
		root->right = Temp;

		return root;
	}
};



int main()
{
	Solution sol;

	TreeNode* Tree = new TreeNode(2, new TreeNode(1), new TreeNode(3));

	sol.invertTree(Tree);

	return 0;
}