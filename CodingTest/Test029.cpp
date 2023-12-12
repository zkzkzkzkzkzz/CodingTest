#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int Stone = stones.size();
        int Jewel = 0;

        // 첫 번째 문자열의 각 알파벳을 두 번째 문자열에서 찾아서 제거
        for (auto c : jewels)
        {
            size_t found = stones.find(c);

            // 해당 알파벳을 찾았을 경우 제거
            while (found != string::npos)
            {
                stones.erase(found, 1);

                found = stones.find(c);
            }

            Jewel = stones.size();
            
        }

        int Res = Stone - Jewel;

        return Res;
    }
};

int main()
{
    Solution sol;

    string str1 = "aA";
    string str2 = "aAABBBB";

    sol.numJewelsInStones(str1, str2);

    return 0;
}