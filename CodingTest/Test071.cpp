

// 비트 연산자
// & : 두 비트가 모두 1이면 1을 반환 (비트 AND 연산)
// | : 두 비트 중 하나라도 1이면 1을 반환 (비트 OR 연산)
// ^ : 두 비트가 다르면 1을 반환 (비트 XOR 연산)
// ~ : 비트가 1이면 0으로, 0이면 1로 반전 (비트 NOT 연산)
// << : 지정한 수만큼 비트들을 전부 왼쪽으로 이동 (left shift 연산)
// >> : 부호를 유지하면서 지정한 수만큼 비트를 전부 오른쪽으로 이동시킴 (right shift 연산)

class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int Count = 0;

        int hd = x ^ y;

        while (hd != 0)
        {
            hd &= hd - 1;
            ++Count;
        }

        return Count;
    }
};

int main()
{
    Solution sol;

    sol.hammingDistance(1, 4);

    return 0;
}