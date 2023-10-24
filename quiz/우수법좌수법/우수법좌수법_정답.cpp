#if 0

#include <stdio.h>

int m[5][5] = { 0 };
int v[7][7] = { 0 };

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int maze(int x, int y, int d, int hand) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (j == 6 || j == 0 || i == 0 || i == 6) v[i][j] = 1;
			else v[i][j] = 0;
		}
	}
	v[y][x] = 1;
	if (hand) printf("\n¿ì¼ö¹ı Å»Ãâ\n");
	else printf("\nÁÂ¼ö¹ı Å»Ãâ\n");
	printf("(%d,%d)", x, y);
	while (1) {
		int ny = y + dy[d], nx = x + dx[d];
		if (v[ny][nx] == 0) {
			x = nx, y = ny;
			v[y][x] = 1;
			printf(" -> (%d,%d)", nx, ny);
		}
		else if (v[ny][nx] == 1) {
			if (hand) d = (d + 1) % 4;
			else {
				d -= 1;
				if (d < 0) d += 4;
			}
		}

		if (x == 3 && y == 3) {
			printf("\n");
			return 1;
		}
	}
}

int main() {
	maze(1, 1, 0, 1);
	maze(1, 5, 2, 0);
	return 0;
}

#endif