

int sizeX, sizeY;
int activeVal;

void floodFillHelper(int** image, int x, int y, int newColor) {
	image[x][y] = newColor;

	// checking upper
	if(x - 1 >= 0 && activeVal == image[x - 1][y]) {
		floodFillHelper(image, x - 1, y, newColor);
	}

	// checking lower
	if(x + 1 < sizeX && activeVal == image[x + 1][y]) {
		floodFillHelper(image, x + 1, y, newColor);
	}

	// checking left
	if(y - 1 >= 0 && activeVal == image[x][y - 1]) {
		floodFillHelper(image, x, y - 1, newColor);
	}

	// checking right
	if(y + 1 < sizeY && activeVal == image[x][y + 1]) {
		floodFillHelper(image, x, y + 1, newColor);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
	sizeX = imageSize;
	sizeY = *imageColSize;
	activeVal = image[sr][sc];

	floodFillHelper(image, sr, sc, newColor);

	*returnSize = imageSize;
	*returnColumnSizes = imageColSize;
	return image;
}