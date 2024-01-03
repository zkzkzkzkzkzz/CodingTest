
// f(n)을 f(1)과 f(0)으로만 이루어질 때까지 분할해라
class Solution {
public:
    int fib(int n) 
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }

        int left = fib(n - 1);
        int right = fib(n - 2);

        return left + right;
    }
};


int main()
{
    Solution sol;

    sol.fib(5);

    return 0;
}