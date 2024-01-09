#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 콘이 가장 늦게 출근하기 위해서는 되도록 가장 마지막 셔틀에 타는 것이 유리
// 그러나 만약 마지막 셔틀에 자리가 없을 경우 마지막 셔틀에 타는 사람 중 가장 빨리 온 사람보다 1분 더 먼저 와야한다 

string solution(int n, int t, int m, vector<string> timetable) 
{
    string answer = "";

    // 크루의 도착 시간을 저장할 벡터
    vector<int> CrewTime;

    // timetable의 도착 시간을 분 단위로 변환하여 CrewTime에 저장
    for (int i = 0; i < timetable.size(); ++i)
    {
        string temp = timetable[i];

        int hour = atoi(temp.substr(0, 2).c_str());
        int minute = atoi(temp.substr(3, 2).c_str());

        CrewTime.push_back(hour * 60 + minute);
    }

    // 크루의 도착시간을 오름차순으로 정렬한다
    sort(CrewTime.begin(), CrewTime.end());

    int ShuttleTime = 540;  // 오전 9시에 첫 셔틀버스 도착 => 분단위로 변환
    int ShuttleCount = 1;   // 몇번째 셔틀버스인가
    int CrewCount = 0;      // 현재 셔틀에 탄 크루의 수
    int lastTime = 0;       // 마지막으로 탄 사람의 시간

    // n번째 셔틀까지 운행하며, 각 셔틀마다 크루를 태우고 ShuttleTime을 갱신한다
    for (ShuttleCount = 1; ShuttleCount <= n; ++ShuttleCount, ShuttleTime += t)
    {
        for (CrewCount = 0; CrewCount < m; ++CrewCount)
        {
            // 모두 탑승했거나
            if (CrewTime.empty())
            {
                break;
            }
            // 처음으로 도착한 사람이 셔틀 운행시간보다 느릴 때
            if (CrewTime.front() > ShuttleTime)
            {
                break;
            }

            lastTime = CrewTime.front();
            CrewTime.erase(CrewTime.begin());
        }
    }

    // 마지막 셔틀이 운행한 시간으로 돌아감
    ShuttleTime -= t;

    // 콘이 도착해야하는 시간
    int con = 0;
    
    // 셔틀 카운트가 위 반복문에서 +1되어 나오므로 다시 1을 감소시켜 막차를 가리키게 한다
    ShuttleCount -= 1;

    // 막차인데 사람이 꽉 참
    // 마지막에 탄 사람의 시간보다 1분 먼저 와야 한다
    if (ShuttleCount == n && CrewCount == m)
    {
        con = lastTime - 1;
    }
    // 막차에 자리가 남았을 경우, 그 버스를 타면 된다
    else
    {
        con = ShuttleTime;
    }

    if (con / 60 < 10)
    {
        if (con % 60 < 10)
        {
            answer = "0" + to_string(con / 60) + ":0" + to_string(con % 60);
        }
        else
        {
            answer = "0" + to_string(con / 60) + ":" + to_string(con % 60);
        }
    }
    else
    {
        if (con % 60 < 10)
        {
            answer = to_string(con / 60) + ":0" + to_string(con % 60);
        }
        else
        {
            answer = to_string(con / 60) + ":" + to_string(con % 60);
        }
    }
    
    return answer;
}



int main()
{
    vector<string> timetable = { "09:10", "09:09", "08:00" };

    solution(2, 10, 3, timetable);

    return 0;
}