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
	int rangeSumBST(TreeNode* root, int low, int high)
	{
		int Res = 0;

		rangeSumBSTRecursive(root, low, high, Res);

		return Res;
	}

private:
	void rangeSumBSTRecursive(TreeNode* root, int low, int high, int& _Res)
	{
		if (root == nullptr)
		{
			return;
		}

		rangeSumBSTRecursive(root->left, low, high, _Res);

		int Temp = root->val;

		if (Temp >= low && Temp <= high)
		{
			_Res += Temp;
		}

		rangeSumBSTRecursive(root->right, low, high, _Res);
	}
};


int main()
{
	Solution Sol;

	TreeNode* Node = new TreeNode(10,
		new TreeNode(5, new TreeNode(3), new TreeNode(7)),
		new TreeNode(15, nullptr, new TreeNode(18)));

	Sol.rangeSumBST(Node, 7, 15);


	return 0;
}