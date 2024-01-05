#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) 
{
    int answer = 0;
    vector<int> vScore(3);  // 해당 다트의 점수
    int idx = 0;            // 몇번째 다트인가
    
    string temp;
    string::iterator iter = dartResult.begin();

    // 점수에 해당하는 부분만 vScore로 옮기고 dartResult에서 지운다
    for (; iter != dartResult.end();)
    {
        if ((*iter) == 'S' || (*iter) == 'D' || (*iter) == 'T' || (*iter) == '*' || (*iter) == '#')
        {
            if ((*iter) == '*' || (*iter) == '#')
            {
                ++iter;
                continue;
            }

            vScore[idx] = atoi(temp.c_str());
            temp = "";
            ++iter;
            ++idx;
        }
        else
        {
            temp += (*iter);
            dartResult.erase(iter);
        }
    }

    // vScore에는 각 다트의 점수가 들어있고 dartResult에는 점수 계산 로직만 남아있다
    idx = 0;

    for (int i = 0; i < dartResult.size(); ++i)
    {
        char c = dartResult[i];

        switch (c)
        {
        case 'S':
            vScore[idx] = vScore[idx];
            break;
        case 'D':
            vScore[idx] = vScore[idx] * vScore[idx];
            break;
        case 'T':
            vScore[idx] = vScore[idx] * vScore[idx] * vScore[idx];
            break;
        // 스타상 또는 아차상일 때는 무조건 앞에 점수 영역이 존재한다
        // 아래에서 무조건 switch문을 돌면서 idx를 증가시키는데
        // 스타상과 아차상은 이전 idx의 점수에 대해 계산을 진행하기 때문에
        // idx를 하나 감소시키고 계산을 진행한다
        case '*':
            --idx;
            vScore[idx] *= 2;
            if (idx >= 1)
            {
                vScore[idx - 1] *= 2;
            }
            break;
        case '#':
            --idx;
            vScore[idx] *= -1;
            break;
        }

        ++idx;
    }

    // 점수 계산 로직이 끝난 각 다트의 최종 점수가 vScore에 들어있다
    for (int i = 0; i < vScore.size(); ++i)
    {
        answer += vScore[i];
    }

    return answer;
}


int main()
{
    string s = "1S2D*3T";

    solution(s);

    return 0;
}