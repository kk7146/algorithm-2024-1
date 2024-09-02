#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

void print_map(vector<vector<int> > map)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
			cout << map[i][j];
		cout << '\n';
	}
	cout << '\n';
}

bool isRange(vector<vector<int> > map, int row, int col) {
	if (row < 0 || row >= map.size() || col < 0 || col >= map[0].size() || map[row][col] == 1) return false;
	else return (true);
}

bool	fill(vector<vector<int> >& map, int row, int col,int shape)
{
	if (shape == 0 && isRange(map, row, col) && isRange(map, row, col + 1) && isRange(map, row + 1, col + 1))
	{
		map[row][col] = 1, map[row][col + 1] = 1, map[row + 1][col + 1] = 1;
		return (true);
	}
	else if (shape == 1 && isRange(map, row, col) && isRange(map, row + 1, col) && isRange(map, row + 1, col + 1))
	{
		map[row][col] = 1, map[row + 1][col] = 1, map[row + 1][col + 1] = 1;
		return (true);
	}
	else if (shape == 2 && isRange(map, row, col) && isRange(map, row, col + 1) && isRange(map, row + 1, col))
	{
		map[row][col] = 1, map[row][col + 1] = 1, map[row + 1][col] = 1;
		return (true);
	}
	else if (shape == 3 && isRange(map, row, col) && isRange(map, row + 1, col) && isRange(map, row + 1, col - 1))
	{
		map[row][col] = 1, map[row + 1][col] = 1, map[row + 1][col - 1] = 1;
		return (true);
	}
	else
		return (false);

}

int	check_next_blank(vector<vector<int> > map, int& row, int& col)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if (map[i][j] == 0)
			{
				row = i;
				col = j;
				return (false);
			}
		}
	}
	return (true);
}

void	boardcover(vector<vector<int> > map, int& count, int row, int col, int shape)
{
	if (check_next_blank(map, row, col))
	{
		count++;
		return ;
	}
	if (!fill(map, row, col, shape))
			return ;
	for (int i = 0; i < 4; i++)
		boardcover(map, count, row, col, i);
}

int check_map(vector<vector<int> > map)
{
	int	count = 0;
	for (size_t i = 0; i < map.size(); i++)
		for (size_t j = 0; j < map[i].size(); j++)
			if (map[i][j] == 0)
				count++;
	if (count % 3 == 0)
		return (2);
	else if (count == 0)
		return (1);
	else
		return (0);
}

vector<vector<int> >	return_map(int H, int W)
{
	vector<vector<int> > map(H, vector<int>(W, 0));
	char				c;

	for (size_t i = 0; i < H; i++)
		for (size_t j = 0; j < W; j++)
		{
			cin >> c;
			if (c == '#')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	return (map);
}

//생각 정리. 앞으로 나아가면서 모든 빈칸에 대해 성공하면 1 반환인 듯? 근데 하나라도 중간에 블럭을 놓는데 실패하면 이제 0 반환하는거지.
//그럼 실패 종료 조건은 빈칸이 있는데 하나라도 들어가지 않을 경우 인거고, 성공의 경우는 끝까지 갔을 경우인 것 같은데?

int	main()
{
	vector<vector<int> >	array_map;
	int					T, H, W, goal, buf;
	int					count;

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		count = 0;
		cin >> H;//행
		cin >> W;//열
		array_map = return_map(H, W);
		buf = check_map(array_map);
		if (!buf)
		{
			cout << "0\n";
			continue ;
		}
		else if (buf == 1)
		{
			cout << "1-조기종료\n";//지워
			continue ;
		}
		for (int i = 0; i < 4; i++)
			boardcover(array_map, count, 0, 0, i);
		cout << count / 4 << '\n';
	}
}
