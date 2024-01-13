#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 시간을 초로 변환
// ms와 처리시간은 소수점이므로 전체 시간에 1000을 곱하여 int로 활용할 수 있게 해준다
vector<pair<int, int>> TimeToSec(vector<string> lines)
{
    //      도착시간 / 출발시간
    vector<pair<int, int>> traffic;

    for (int i = 0; i < lines.size(); ++i)
    {
        string h, m, s, ms, process;

        h = lines[i].substr(11, 2);
        m = lines[i].substr(14, 2);
        s = lines[i].substr(17, 2);
        ms = lines[i].substr(20, 3);
        process = lines[i].substr(24, 5);

        int ih = stoi(h) * 3600 * 1000;
        int im = stoi(m) * 60 * 1000;
        int is = stoi(s) * 1000;
        int ims = stoi(ms);
        int iprocess = int(stof(process) * 1000);

        int endTime = ih + im + is + ims;
        int startTime = endTime - iprocess + 1;

        traffic.push_back({ endTime, startTime });
    }

    return traffic;
}



int solution(vector<string> lines) 
{
    int answer = 0;    
    vector<pair<int, int>> traffic;
    traffic = TimeToSec(lines);

    sort(traffic.begin(), traffic.end());

    int cnt = 1;

    for (int i = 0; i < traffic.size(); ++i)
    {
        int mintraffic = traffic[i].first;
        int Maxtraffic = traffic[i].first + 999;

        for (int j = i + 1; j < traffic.size(); ++j)
        {
            // 트래픽의 도착 시간이 처리시간의 시작보다 작거나
            // 트래픽의 출발 시간이 처리시간의 끝시간보다 크다면 해당 시간은 처리할 수 없다
            if (traffic[j].first < mintraffic || traffic[j].second > Maxtraffic)
            {
                continue;
            }

            ++cnt;
        }

        answer = max(answer, cnt);

        cnt = 1;
    }
    


    return answer;
}


int main()
{
    vector<string> lines =
    { "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s" };

    solution(lines);

    return 0;
}