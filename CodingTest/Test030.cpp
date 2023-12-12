#include <string>
#include <unordered_set>

using namespace std;

// 슬라이딩 윈도우
// 고정 사이즈의 윈도우가 이동하면서 윈도우 내에 있는 데이터를 이용해 문제를 풀이하는 알고리즘
// 윈도우 끼리의 교집합의 정보를 공유하고, 차이가 나는 양쪽 끝 원소만 갱신하는 방법
// 1, 2, 3, 4, 5인 숫자 배열이 있고, 연속된 3개의 숫자의 합의 최댓값을 구한다고 했을 때
// 나올 수 있는 경우는 [1, 2, 3], [2, 3, 4], [3, 4, 5]이다
// 이를 통해 다음 배열의 값은 이전 배열에서 처음 원소를 빼고, 다음에 들어올 원소를 더해주면 된다는 것을 알 수 있다


class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        // map의 경우 이진 검색 트리를 사용하며 검색 속도가 O(log n)이다
        // 하지만 unordered_set의 경우 해시 테이블을 사용하여 요소를 저장하고 검색하기 때문에
        // 평균적으로 O(1)의 시간 복잡도를 가진다
        // ※ 해시 테이블 -> 키(Key)와 값(Value)을 연관시켜 저장하는 구조
        unordered_set<char> charSet;
        
        int n = s.length();

        // 문자열이 한 개 이하일 때
        if (n <= 1)
        {
            return n;
        }

        // 가장 긴 부분 문자열
        int maxLength = 0;

        // 투 포인터로 사용할 두 int 변수 생성
        // 두 변수 사이의 값은 윈도우 사이즈가 된다
        int left = 0;
        int right = 0;

        while (right < n)
        {
            char curChar = s[right];

            // charSet에 curChar가 없다면
            if (charSet.find(curChar) == charSet.end())
            {
                // curChar을 삽입
                charSet.insert(curChar);

                // 현재 저장된 부분 문자열 길이보다 현재 윈도우 사이즈가 더 클 경우
                if (maxLength < right - left + 1)
                {
                    maxLength = right - left + 1;
                }

                ++right;
            }
            // charSet에 curChar가 있다면
            else 
            {
                // 슬라이딩 윈도우 방식을 이용하여 가장 처음 원소를 지움
                // right는 증가시키지 않고 다시 찾아보기 때문에
                // 다음에 들어올 원소로 추가하게 된다
                charSet.erase(s[left]);

                ++left;
            }
        }

        return maxLength;
    }
};



int main()
{
    Solution sol;

    string str1 = "abcabcfbb";

    sol.lengthOfLongestSubstring(str1);

    return 0;
}