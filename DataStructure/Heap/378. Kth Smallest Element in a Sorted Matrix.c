
int Absolute(int x) {
	if(x < 0) {
		return -x;
	}

	return x;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int target){
	int rowSize = matrixSize;
	int colSize = *matrixColSize;

	int lowRow = 1, highRow = rowSize;
	int lowCol = 1, highCol = colSize;

	int midRow, midCol, calRow;

	while(1) {
		midRow = lowRow + (highRow - lowRow) / 2;

		calRow = (midRow * colSize);
		int diffRow = Absolute(calRow - target);

		if(diffRow < colSize) {
			break;
		} else if(target > calRow) {
			lowRow = midRow + 1;
		} else {
			highRow = midRow - 1;
		}
	}
	
	while(1) {
		midCol = lowCol + (highCol - lowCol) / 2;

		int calTotal = calRow + midCol;

		if(target == calTotal) {
			break;
		} else if (target > calTotal) {
			lowCol = midCol + 1;
		} else {
			highCol = midCol - 1;
		}
	}

	return matrix[midRow - 1][midCol - 1];
}

