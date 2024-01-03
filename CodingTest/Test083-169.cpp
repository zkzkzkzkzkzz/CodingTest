#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        return nums[size/2];
    }

    // O(N), 공간복잡도(1)
    // boyer moore 알고리즘
    // 동작방식
    // 1. Bad Character Heuristic(나쁜 문자 휴리스틱)
    // 패턴 내의 각 문자에 대해, 패턴 내에서 그 문자의 오른쪽 끝에서부터 가장 멀리 있는 위치를 미리 계산한다
    // 만약 텍스트 내에서 패턴의 해당 문자와 일치하지 않는 위치에서 패턴을 이동시킬 수 있다
    // 2. Good Suffix Heuristic(좋은 접미사 휴리스틱)
    // 패턴의 끝에서부터 일치하지 않는 부분 문자열을 찾아 해당 부분 문자열을 패턴의 뒤쪽으로 이동시킨다
    // 이것은 패턴 내에서 일치하는 부분을 재활용하여 검색 범위를 줄이는 데 도움이 된다
    
    // 보이어-무어 알고리즘은 주로 문자열 검색에 사용되는 알고리즘이기 때문에, 다음 문제는 Boyer-Moore Voting Algorithm을 통해 푸는 것이 더 효율적
    // Boyer-Moore Voting Algorithm
    // 해당 알고리즘은 candidate(후보), count(등장 횟수) 두 개의 변수를 사용한다
    // 첫 후보는 배열의 첫번째 원소로 설정하고 count를 1로 초기화한다 (후보를 설정했으므로 일단 한번 등장했다고 간주하기 때문)
    // 배열을 순회하면서 현재 원소가 후보와 같다면 count를 증가시키고, 다르다면 count를 감소시킨다
    // 만약 count가 0이 되면, 후보를 현재 원소로 변경하고 count를 다시 1로 초기화한다
    // 모든 순회가 끝나고 최종적으로 후보에 저장된 값이 다수가 된다
    int majorityElement2(vector<int>& nums)
    {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
            else if (nums[i] == candidate) 
            {
                --count;
            }
            else
            {
                ++count;
            }
        }

        return candidate;
    }
};


int main()
{
    Solution sol;

    vector<int> nums = { 3,2,3 };

    sol.majorityElement(nums);

    return 0;
}