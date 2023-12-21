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
	int minDiffInBST(TreeNode* root)
	{
		vector<int> NodeDist;

		int Res = INT_MAX;

		minDiffInBSTRecursive(root, NodeDist);

		for (int i = 1; i < NodeDist.size(); ++i)
		{
			Res = min(Res, NodeDist[i] - NodeDist[i - 1]);
		}

		return Res;
	}

private:
	void minDiffInBSTRecursive(TreeNode* root, vector<int>& _vec)
	{
		if (nullptr == root)
		{
			return;
		}

		minDiffInBSTRecursive(root->left, _vec);

		_vec.push_back(root->val);
		
		minDiffInBSTRecursive(root->right, _vec);
	}
};


int main()
{
	Solution Sol;

	TreeNode* Node = new TreeNode(4,
		new TreeNode(2, new TreeNode(1), new TreeNode(3)),
		new TreeNode(6));

	Sol.minDiffInBST(Node);


	return 0;
}