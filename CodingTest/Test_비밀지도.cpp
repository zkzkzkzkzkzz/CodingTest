#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    for (int i = 0; i < n; ++i)
    {
        int temp = arr1[i] | arr2[i];
        string s;
        int count = 0;

        // count를 쓴 이유
        // temp가 0이 아닐때까지 while문을 돌리니까
        // 한줄이 모두 0이었을 경우에는 s에 빈칸을 넣지 못함 => 아마 테스트 4,5번이 그런 경우가 아니었나 싶음
        // 따라서 count를 이용해서 모든 순회를 마칠 수 있도록 했다
        while (count < n)
        {
            if ((temp & 1) == 1)
            {
                s.insert(s.begin(), '#');
            }
            else
            {
                s.insert(s.begin(), ' ');
            }
            
            temp = temp >> 1;

            ++count;
        }

        answer.push_back(s);
    }

    return answer;
}


int main()
{
    vector<int> vec1 = { 46, 33, 33 ,22, 31, 50 };
    vector<int> vec2 = { 27 ,56, 19, 14, 14, 10 };

    solution(6, vec1, vec2);

    return 0;
}