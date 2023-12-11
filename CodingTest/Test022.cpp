#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> st;
        vector<int> vRes(temperatures.size(), 0);
        
        st.push(0);

        // 현재 날짜 인덱스
        int DayIdx = 1;
        
        // 어제와 오늘의 기온을 비교
        while (DayIdx < temperatures.size())
        {
            // 어제 온도가 오늘보다 높을 때
            if (!st.empty() && temperatures[DayIdx] <= temperatures[st.top()])
            {
                // 스택에 오늘을 추가
                st.push(DayIdx);
            }
            else
            {
                // 어제보다 오늘이 더 온도가 높을 때
                while (!st.empty() && temperatures[DayIdx] > temperatures[st.top()])
                {
                    // 스택에는 온도가 높아지는 날이 올때까지 지나온 날들의 정보를 저장해둔다
                    vRes[st.top()] = DayIdx - st.top();

                    // 스택에는 아직 자신보다 기온이 높은 날을 만나지 못한 애들만 남아있다
                    st.pop();
                }

                st.push(DayIdx);
            }

            // 다음날로 이동
            ++DayIdx;
        }

        return vRes;
    }
};

int main()
{
    Solution sol;

    vector<int> vTemp = { 5, 3, 1 };

    sol.dailyTemperatures(vTemp);



    return 0;
}