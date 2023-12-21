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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		// 전위 순회로 알 수 있는 것
		// 루트 노드(첫번째 노드)
		// 가장 오른쪽 노드 == preorder 벡터의 마지막 원소

		// 중위 순회로 알 수 있는 것
		// 노드의 순서
		// 루트 노드에 해당되는 인덱스 기준으로 왼쪽은 왼쪽 트리, 오른쪽은 오른쪽 트리로 구성된다

		int n = inorder.size();
		int Idx = 0;

		return buildTreeRecursive(preorder, inorder, Idx, 0, n - 1);
 
	}

private:
	TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder, int& _idx, int left, int right)
	{
		// 범위 left부터 right까지의 중위 순회에서 루트 노드를 찾는다
		// 만약 left가 right보다 더 크다면 해당되는 범위가 없으므로 nullptr 리턴
		if (left > right)
		{
			return nullptr;
		}
		
		// 중위 순회 배열에서 현재 루트 노드의 인덱스
		int pivot = left;

		// 중위 순회 배열에서 루트 노드를 찾을 때까지 pivot 증가
		while (inorder[pivot] != preorder[_idx])
		{
			++pivot;
		}

		// 현재 전위 순회 배열에서 사용한 노드의 인덱스 증가
		++_idx;

		TreeNode* newNode = new TreeNode(inorder[pivot]);
		
		// 루트 노드를 찾았으면 해당 노드를 기점으로 왼쪽, 오른쪽 서브트리 재귀적으로 구축
		newNode->left = buildTreeRecursive(preorder, inorder, _idx, left, pivot - 1);
		newNode->right = buildTreeRecursive(preorder, inorder, _idx, pivot + 1, right);
		
		return newNode;
	}
};


int main()
{
	Solution Sol;

	vector<int> Vec1 = { 3, 9, 20, 15, 7 };
	vector<int> Vec2 = { 9, 3, 15, 20, 7 };

	Sol.buildTree(Vec1, Vec2);


	return 0;
}