

int perimeter, maxX, maxY;

void perimeterCounting(int** grid, int x, int y) {
	// checking upper
	if(x - 1 < 0 || (x - 1 >= 0 && 0 == grid[x - 1][y])) {
		perimeter++;
	}

	// checking lower
	if(x + 1 >= maxX || (x + 1 < maxX && 0 == grid[x + 1][y])) {
		perimeter++;
	}

	// checking left
	if(y - 1 < 0 || (y - 1 >= 0 && 0 == grid[x][y - 1])) {
		perimeter++;
	}

	// checking right
	if(y + 1 >= maxY || (y + 1 < maxY && 0 == grid[x][y + 1])) {
		perimeter++;
	}

	// making it visited
	grid[x][y] = 5;

	if(x - 1 >= 0 && 1 == grid[x - 1][y]) {
		perimeterCounting(grid, x - 1, y);
	}

	if(x + 1 < maxX && 1 == grid[x + 1][y]) {
		perimeterCounting(grid, x + 1, y);
	}

	if(y - 1 >= 0 && 1 == grid[x][y - 1]) {
		perimeterCounting(grid, x, y - 1);
	}

	if(y + 1 < maxY && 1 == grid[x][y + 1]) {
		perimeterCounting(grid, x, y + 1);
	}
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
	perimeter = 0;
	maxX = gridSize;
	maxY = *gridColSize;

	for(int i = 0; i < maxX; i++) {
		for(int j = 0; j < maxY; j++) {
			if(1 == grid[i][j]) {
				perimeterCounting(grid, x, y);
				break;
			}
		}
	}

	return perimeter;
}