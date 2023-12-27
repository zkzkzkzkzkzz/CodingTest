#include <vector>

using namespace std;

// 비트 연산자
// & : 두 비트가 모두 1이면 1을 반환 (비트 AND 연산)
// | : 두 비트 중 하나라도 1이면 1을 반환 (비트 OR 연산)
// ^ : 두 비트가 다르면 1을 반환 (비트 XOR 연산)
// ~ : 비트가 1이면 0으로, 0이면 1로 반전 (비트 NOT 연산)
// << : 지정한 수만큼 비트들을 전부 왼쪽으로 이동 (left shift 연산)
// >> : 부호를 유지하면서 지정한 수만큼 비트를 전부 오른쪽으로 이동시킴 (right shift 연산)


//       Number of Bytes |      UTF - 8 Octet Sequence
//                       |              (binary)
//  -------------------- + ---------------------------------------- -
//  1                    | 0xxxxxxx
//  2                    | 110xxxxx 10xxxxxx
//  3                    | 1110xxxx 10xxxxxx 10xxxxxx
//  4                    | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

// 1바이트일 때 -> 0 ~ 127
// 2바이트일 때 -> 192 ~ 223 / 128 ~ 191
// 3바이트일 때 -> 224 ~ 239 / 128 ~ 191 / 128 ~ 191
// 4바이트일 때 -> 240 ~ 247 / 128 ~ 191 / 128 ~ 191 / 128 ~ 191


class Solution {
public:
    bool validUtf8(vector<int>& data) 
    {
        int size = data.size();
        int idx = 0;

        while (idx < size)
        {
            int num_bytes = getNumBytes(data[idx]);

            if (num_bytes == 0)
            {
                return false;
            }

            // num_bytes에 맞게 필요한 수만큼 원소 확인
            for (int i = 1; i < num_bytes; ++i)
            {
                if (idx + i >= size || !isContinuationByte(data[idx + i]))
                {
                    return false;
                }
            }

            // n바이트만큼 인덱스 추가
            idx += num_bytes;
        }

        return true;
    }

private:
    int getNumBytes(int num)
    {
        if ((num & 0b10000000) == 0)
        {
            return 1;   // 1바이트
        }
        else if ((num & 0b11100000) == 0b11000000)
        {
            return 2;   // 2바이트
        }
        else if ((num & 0b11110000) == 0b11100000)
        {
            return 3;   // 3바이트
        }
        else if ((num & 0b11111000) == 0b11110000)
        {
            return 4;   // 4바이트
        }
        else
        {
            return 0;
        }
    }

    // num이 두번째 이후 바이트인지 판별
    // 즉, 10xxxxxx 형태인지 확인
    bool isContinuationByte(int num)
    {
        if ((num & 0b11000000) == 0b10000000)
        {
            return true;
        }

        return false;
    }
};


int main()
{
    Solution sol;

    vector<int> data = { 197,130,1 };

    sol.validUtf8(data);

    return 0;
}