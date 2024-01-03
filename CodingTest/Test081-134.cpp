#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        // 시작점은 gas[i] > = cost[i]인 인덱스 중 한 곳
        // 주유소는 원형으로 위치하기 때문에 해당 인덱스에서 다음 인덱스로 이동해야함
        // 마지막 인덱스일 경우 처음 인덱스로 이동한다
        // fuel = gas - cost라 할 때, vector<int> fuel의 원소는 다음과 같다
        //   0  1   2   3   4
        // { 1, -3, 1, -2,  3}
        // 모든 원소를 더했을 때 0이상이므로 모든 주유소를 돌 수 있다는 걸 일단 알 수 있다
        // 시작 인덱스는 3 또는 4인데, 해당 인덱스부터 차례대로 더해가다 중간에 음수가 나온다면
        // 해당 인덱스는 시작점이 아니다 -> 시간 초과

        int fuel = 0;
        int StartIdx = 0;
        int totalGas = 0;
        int totalCost = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            totalGas += gas[i];
            totalCost += cost[i];

            fuel += gas[i] - cost[i];

            // fuel이 0 미만이라는 건 해당 시작지점에선 모든 주유소를 돌 수 없다는 것을 의미
            if (fuel < 0)
            {
                // 다음 주유소부터 다시 순회
                StartIdx = i + 1;
                fuel = 0;
            }
        }

        if (totalGas < totalCost)
        {
            return -1;
        }
        
        return StartIdx;
    }
};


int main()
{
    Solution sol;

    vector<int> gas = { 5,1,2,3,4 };
    vector<int> cost = { 4,4,1,5,1 };

    sol.canCompleteCircuit(gas, cost);

    return 0;
}