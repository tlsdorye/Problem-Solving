import java.util.*;

class Solution {

	public int CraneMove(int[][] board, int jdx) {
		int ret = -1;
		for (int i = 0; i < board.length; i++)
			if (board[i][jdx - 1] != 0) {
				ret = board[i][jdx - 1];
				board[i][jdx - 1] = 0;
				break;
			}
		return ret;
	}

	public int solution(int[][] board, int[] moves) {
		int answer = 0;
		Stack<Integer> stk = new Stack<>();
		for (int jdx : moves) {
			int next = CraneMove(board, jdx);
			if (next == -1) continue;
			if (!stk.empty() && stk.peek() == next) {
				stk.pop();
				answer += 2;
			} else stk.add(next);
		}

		return answer;
	}
}