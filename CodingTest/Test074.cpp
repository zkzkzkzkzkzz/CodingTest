#include <algorithm>

// 비트 연산자
// & : 두 비트가 모두 1이면 1을 반환 (비트 AND 연산)
// | : 두 비트 중 하나라도 1이면 1을 반환 (비트 OR 연산)
// ^ : 두 비트가 다르면 1을 반환 (비트 XOR 연산)
// ~ : 비트가 1이면 0으로, 0이면 1로 반전 (비트 NOT 연산)
// << : 지정한 수만큼 비트들을 전부 왼쪽으로 이동 (left shift 연산)
// >> : 부호를 유지하면서 지정한 수만큼 비트를 전부 오른쪽으로 이동시킴 (right shift 연산)

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int Res = 0;
        
        // n & n-1의 첫번째 연산은 제일 오른쪽 비트를 0으로 만든다
        // n이 5라면 0101이고, n-1은 0100이다
        // 연산을 진행하면 n은 0100이 나온다
        // 다시 1을 빼서 가장 오른쪽에 있는 1을 0으로 만드는 작업 반복
        while (n)
        {
            n &= n - 1;

            ++Res;
        }

        int a = -7;

        int b = a >> 1;

        return Res;
    }
};


int main()
{
    Solution Sol;

    Sol.hammingWeight(5);

    return 0;
}