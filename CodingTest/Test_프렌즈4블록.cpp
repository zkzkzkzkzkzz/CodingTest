#include <string>
#include <vector>
#include <map>

using namespace std;

bool check(int i, int j, vector<string>& board)
{
	char c = board[i][j];

	// 현재 탐색중인 곳이 아직 문자가 남아있고, 자기를 기점으로 2*2 형태가 나온다면
	if (c != 'X' && board[i][j + 1] == c && board[i + 1][j] == c && board[i + 1][j + 1] == c)
	{
		return true;
	}

	return false;
}

int remove(int m, int n, vector<string>& board)
{
	// 삭제할 좌표를 저장할 맵
	map<pair<int, int>, bool> ma;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i + 1 < m && j + 1 < n && check(i, j, board))
			{
				ma.insert({ {i, j}, true });
				ma.insert({ {i, j + 1}, true });
				ma.insert({ {i + 1, j}, true });
				ma.insert({ {i + 1, j + 1}, true });
			}
		}
	}

	// 저장된 좌표들 삭제 -> X로 변환
	map<pair<int, int>, bool>::iterator iter = ma.begin();
	
	for ( ; iter != ma.end(); ++iter)
	{
		board[iter->first.first][iter->first.second] = 'X';
	}

	// 삭제된 (X로 변환된) 좌표의 개수 반환
	return ma.size();
}

void move(int m, int n, vector<string>& board)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// 우측 최하단부터 탐색 시작
			if (board[m - (i + 1)][n - (j + 1)] == 'X')
			{
				// X를 발견하면 해당 열에 대한 정보 저장
				int row = m - (i + 1);

				// X가 아닌 문자가 나올때까지 해당 열의 행을 올리고
				// X가 아닌 문자를 현재 X 위치와 바꾼다
				while (row >= 0)
				{
					if (board[row][n - (j + 1)] != 'X')
					{
						board[m - (i + 1)][n - (j + 1)] = board[row][n - (j + 1)];
						board[row][n - (j + 1)] = 'X';
						break;
					}
					else
					{
						--row;
					}
				}
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int EraseCount = -1;

	while (EraseCount != 0)
	{
		EraseCount = remove(m, n, board);

		if (EraseCount != 0)
		{
			answer += EraseCount;
			move(m, n, board);
		}
	}

	return answer;
}

int main()
{
	vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };

	solution(6, 6, board);

	return 0;
}