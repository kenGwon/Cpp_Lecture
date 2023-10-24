/*
  <23.10.20. 퀴즈>
*/


#define _CRT_SECURE_NO_WARNINGS // C의 scanf()에서 발생할 수 있는 보안이슈를 무시하겠다는 것
#include <stdio.h>

enum {
	UP = 0,
	RIGHT,
	DOWN,
	LEFT
};


int main()
{
	char maze[5][5][5] = {
		{"1001", "1010", "1010", "1010", "1100"},
		{"0101", "1001", "1010", "1100", "0101"},
		{"0101", "0011", "1110", "0101", "0101"},
		{"0011", "1010", "1010", "0110", "0101"},
		{"1011", "1010", "1010", "1010", "0110"}
	};

	int visited_position[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};


	//	left_hand_find_path();

	maze(1, 1, 0, 1);
	maze(1, 5, 2, 0);
	return 0;
}








void left_hand_find_path(char maze[5][5][5], int row, int col, int given_direction)
{
	int direction_lv = -1; // 재귀 호출의 base case (갈 곳이 없는 경우: -1)

	int closed_path;
	if (given_direction == UP)
	{
		closed_path = DOWN;
	}
	else if (given_direction == RIGHT)
	{
		closed_path = LEFT;
	}
	else if (given_direction == DOWN)
	{
		closed_path = UP;
	}
	else if (given_direction == LEFT)
	{
		closed_path = RIGHT;
	}



	for (int i = 0; i < 4; i++)
	{
		// 이전에 지나온 길은 막혔다고 가정해야 함
		if (i == closed_path)
		{
			continue;
		}

		// 상우하좌 순으로 탐색하여 가장 먼저 만난 뚫린 곳으로 방향 설정
		if (maze[row][col][i] == '0')
		{
			direction_lv = i;
			break;
		}
	}

	printf("(%d, %d)->", row, col);

	if (direction_lv == UP)
	{
		left_hand_find_path(maze[5][5][5], row, col - 1, direction_lv);
	}
	else if (direction_lv == RIGHT)
	{
		left_hand_find_path();
	}
	else if (direction_lv == DOWN)
	{
		left_hand_find_path();
	}
	else if (direction_lv == LEFT)
	{
		left_hand_find_path();
	}
	else
	{
		// 더 이상 갈 곳이 없으면 base case 도달
		printf("(좌수법 탐색 끝)\n");
		return;
	}


}
