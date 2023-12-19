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
	int diameterOfBinaryTree(TreeNode* root)
	{
		int Res = 0;
		int MaxLength = diameterOfBinaryTreeRecursive(root, Res);

		return Res;
	}

private:
	int diameterOfBinaryTreeRecursive(TreeNode* root, int& _Res)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int Left = diameterOfBinaryTreeRecursive(root->left, _Res);
		int Right = diameterOfBinaryTreeRecursive(root->right, _Res);

		_Res = max(_Res, Left + Right);

		return max(Left, Right) + 1;
	}

	// 상태값 = 리프노드(자식 노드가 없는 노드)로부터 현재 노드까지의 거리
	int diameterOfBinaryTreeRecursive2(TreeNode* root, int& _Res)
	{
		// 둘 중 하나의 자식 노드만 가지고 있을 때
		// 근데 TreeNode는 정이진트리 구조인데 이 예외처리를 해주는 이유가 있나
		if (root == nullptr)
		{
			return -1;
		}

		// 리프 노드일 때(자식 노드가 없을 때)
		if (root->left == nullptr && root->right == nullptr)
		{
			return 0;
		}

		// root 기준 왼쪽 노드 탐색 결과 리프 노드로부터 root 노드까지의 거리
		int Left = diameterOfBinaryTreeRecursive(root->left, _Res) + 1;

		// root 기준 오른쪽 노드 탐색 결과 리프 노드로부터 root 노드까지의 거리
		int Right = diameterOfBinaryTreeRecursive(root->right, _Res) + 1;

		_Res = max(_Res, Left + Right);

		return max(Left, Right);
	}
};


int main()
{
	Solution sol;

	TreeNode* Tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));

	sol.diameterOfBinaryTree(Tree);

	return 0;
}