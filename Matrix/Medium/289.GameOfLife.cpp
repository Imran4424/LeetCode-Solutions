/*
	According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular 
	automaton devised by the British mathematician John Horton Conway in 1970."

	The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented 
	by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
	using the following four rules (taken from the above Wikipedia article):

    	Any live cell with fewer than two live neighbors dies as if caused by under-population.
    	Any live cell with two or three live neighbors lives on to the next generation.
   	Any live cell with more than three live neighbors dies, as if by over-population.
    	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.


	The next state is created by applying the above rules simultaneously to every cell in the 
	current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, 
	return the next state.

*/

class Solution {
	int neighbourCount(vector<vector<int>> board, int x, int y) {
		int count = 0;

		// check horizontal
		// left
		if (y - 1 >= 0 && board[x][y - 1]) {
			count++;
		}

		// right 
		if (y + 1 < board[0].size() && board[x][y + 1]) {
			count++;
		}

		// check vertical
		// top
		if (x - 1 >= 0 && board[x - 1][y]) {
			count++;
		}

		// bottom
		if (x + 1 < board.size() && board[x + 1][y]) {
			count++;
		}

		// diagonal
		// top left
		if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1]) {
			count++;
		}

		// bottom left
		if (x + 1 < board.size() && y - 1 >= 0 && board[x + 1][y - 1]) {
			count++;
		}

		// top right
		if (x - 1 >= 0 && y + 1 < board[0].size() && board[x - 1][y + 1]) {
			count++;
		}

		// bottom right
		if (x + 1 < board.size() && y + 1 < board[0].size() && board[x + 1][y + 1]) {
			count++;
		}

		return count;
	}

public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> neighbour(board.size(), vector<int>(board[0].size(), 0));

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				neighbour[i][j] = neighbourCount(board, i, j);
			}
		}

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j]) {
					// alive
					if (neighbour[i][j] < 2 || neighbour[i][j] > 3) {
						board[i][j] = 0;
					}

				} else {
					// dead
					if (3 == neighbour[i][j]) {
						board[i][j] = 1;
					}
				}
			}
		}
	}
};