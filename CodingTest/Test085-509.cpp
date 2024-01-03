
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

    // 메모이제이션(Memoization)
    int arr[31] = { 0 };
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        if (arr[n] != 0)
        {
            return arr[n];
        }

        return arr[n] = fib(n - 1) + fib(n - 2);
    }
};


int main()
{
    Solution sol;

    sol.fib(5);

    return 0;
}