#include <vector>
#include <algorithm>


using namespace std;

// 나올 수 있는 경우의 수는 nCk를 따른다
class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> Res;
        vector<int> Temp;

        combineRecursive(Temp, 1, n, k, Res);

        return Res;
    }

private:
    void combineRecursive(vector<int>& _Temp, int _StartInt, int _MaxInt, int _MaxCount, vector<vector<int>>& _res)
    {
        // 현재 저장된 벡터의 크기가 _MaxCount와 같다면
        // 최대 조합 길이에 도달한 것이므로 _res에 push_back
        if (_Temp.size() == _MaxCount)
        {
            _res.push_back(_Temp);

            return;
        }

        for (int i = _StartInt; i <= _MaxInt; ++i)
        {
            _Temp.push_back(i);

            combineRecursive(_Temp, i + 1, _MaxInt, _MaxCount, _res);

            _Temp.pop_back();
        }
    }
};


int main()
{
    Solution sol;

    sol.combine(4, 3);

    return 0;
}