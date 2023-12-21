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
	TreeNode* bstToGst(TreeNode* root) 
	{
		int Sum = 0;

		bstToGstRecursive(root, Sum);
		
		return root;
	}

private:
	void bstToGstRecursive(TreeNode* root, int& _res)
	{
		if (root == nullptr)
		{
			return;
		}

		bstToGstRecursive(root->right, _res);

		int Temp = root->val;
		root->val += _res;
		_res += Temp;

		bstToGstRecursive(root->left, _res);
	}
};

int main()
{
	Solution Sol;

	TreeNode* Node = new TreeNode(4,
		new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))),
		new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8))));

	Sol.bstToGst(Node);


	return 0;
}