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

class Solution 
{
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == nullptr && root2 == nullptr)
		{
			return nullptr;
		}

		if (root1 == nullptr && root2 != nullptr)
		{
			return root2;
		}

		// root1, root2 모두 왼쪽 자식이 존재할 때까지 내려감
		if (root1 != nullptr && root1->left != nullptr 
			&& root2 != nullptr && root2->left != nullptr)
		{
			mergeTrees(root1->left, root2->left);

		}

		// root1, root2 모두 오른쪽 자식이 존재할 때까지 내려감
		if (root1 != nullptr && root1->right != nullptr 
			&& root2 != nullptr && root2->right != nullptr)
		{
			mergeTrees(root1->right, root2->right);

		}

		// root1의 왼쪽 자식은 비어있으나 root2의 왼쪽 자식은 존재할 때
		if (root1 != nullptr && root1->left == nullptr 
			&& root2 != nullptr && root2->left != nullptr)
		{
			root1->left = root2->left;
		}

		// root1의 오른쪽 자식은 비어있으나 root2의 오른쪽 자식은 존재할 때
		if (root1 != nullptr && root1->right == nullptr 
			&& root2 != nullptr && root2->right != nullptr)
		{
			root1->right = root2->right;
		}

		// 두 노드 모두 같은 방향에 자식 노드가 존재한다면 두 노드의 값을 더한다
		if (root1 != nullptr && root2 != nullptr)
		{
			root1->val += root2->val;
		}

		return root1;
	}
};


int main()
{
	Solution sol;

	TreeNode* Tree1 = new TreeNode(1, new TreeNode(3, new TreeNode(5), nullptr), new TreeNode(2));
	TreeNode* Tree2 = new TreeNode(2, new TreeNode(1, nullptr, new TreeNode(4)), new TreeNode(3, nullptr, new TreeNode(7)));

	sol.mergeTrees(Tree1, Tree2);

	return 0;
}