#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> vStr1;
    vector<string> vStr2;

    // 두 문자씩 끊어서 모두 알파벳일 경우에만 벡터에 삽입
    for (int i = 0; i < str1.size() - 1; ++i)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            string s = "";

            s = str1[i];
            s += str1[i + 1];

            vStr1.push_back(s);
        }
    }
    for (int i = 0; i < str2.size() - 1; ++i)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            string s = "";

            s = str2[i];
            s += str2[i + 1];

            vStr2.push_back(s);
        }
    }
    
    // 모두 공집합이면 1로 간주
    if (vStr1.size() == 0 && vStr2.size() == 0)
    {
        return 65536;
    }

    // 두 벡터 모두 소문자로 변환
    for (int i = 0; i < vStr1.size(); ++i)
    {
        transform(vStr1[i].begin(), vStr1[i].end(), vStr1[i].begin(), ::tolower);
    }
    for (int i = 0; i < vStr2.size(); ++i)
    {
        transform(vStr2[i].begin(), vStr2[i].end(), vStr2[i].begin(), ::tolower);
    }

    vector<string> intersection;    // 교집합
    vector<string> sum;             // 합집합

    for (int i = 0; i < vStr1.size(); ++i)
    {
        string s = "";

        s = vStr1[i];

        sum.push_back(s);
    }
    for (int i = 0; i < vStr2.size(); ++i)
    {
        string s = "";

        s = vStr2[i];

        sum.push_back(s);
    }

    if (vStr1.size() >= vStr2.size())
    {
        for (int i = 0; i < vStr2.size(); ++i)
        {
            vector<string>::iterator iter = find(vStr1.begin(), vStr1.end(), vStr2[i]);

            if (iter != vStr1.end())
            {
                intersection.push_back(*iter);
                vStr1.erase(iter);
            }
        }
    }
    else
    {
        for (int i = 0; i < vStr1.size(); ++i)
        {
            vector<string>::iterator iter = find(vStr2.begin(), vStr2.end(), vStr1[i]);

            if (iter != vStr2.end())
            {
                intersection.push_back(*iter);
                vStr2.erase(iter);
            }
        }
    }

    float intersectionCount = (float)intersection.size();

    for (int i = 0; i < intersection.size(); ++i)
    {
        vector<string>::iterator iter = find(sum.begin(), sum.end(), intersection[i]);

        if (iter != sum.end())
        {
            sum.erase(iter);
        }
    }

    float sumCount = (float)sum.size();

    answer = int(intersectionCount / sumCount * 65536);

    return answer;
}


int main()
{
    string str1 = "FRANCE";
    string str2 = "french";

    solution(str1, str2);

    return 0;
}