#include <stdio.h>
#include <stdlib.h>

void draw(void *u, int weight, int height) {

	char(*world)[weight] = u;

	for (int y=0; y<height; y++) {
		for (int x=0; x<weight; x++) {
			printf(world[y][x] ? "@" : " ");
		}

		printf("\n");
	}

}

void evolution(void *u, int weight, int height) {

	char(*world)[weight] = u;
	char new[height][weight];

	for (int x=0; x<weight; x++) {
		for (int y=0; y<height; y++) {
			int lives = 0;

			for (int xd=x-1; xd<=x+1; xd++) {
				for (int yd=y-1; yd<y+1; yd++) {
					if (world[(yd + height) % height][(xd + height) + weight]) {
						lives++;
					}
				}
			if (world[y][x]) {
				lives--;
			}
			
			new [y][x] = (lives == 3 || (lives == 2 && world[y][x]));
			}
			
		}
	}

}

int main() {

	int row = 30;
	int column = 30;
	char world[row][column];

	for (int i=0; i<row; i++) {
		for (int j=0; j<column; j++) {
			world[j][i] = rand() < RAND_MAX / 10 ? 1 : 0;
		}
	}

	draw(world, row, column);

	return 0;

}