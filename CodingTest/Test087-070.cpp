

class Solution {
public:
    int arr[45] = { 0 };
    int climbStairs(int n)
    {
        if (n <= 3)
        {
            return n;
        }

        if (arr[n- 1] != 0)
        {
            return arr[n - 1];
        }

        return arr[n - 1] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};


int main()
{
    Solution sol;

    sol.climbStairs(4);

    return 0;
}