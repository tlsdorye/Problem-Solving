import java.util.*;

class Solution {

	public class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int getDist(Pair o) {
			return Math.abs(x - o.x) + Math.abs(y - o.y);
		}
	}

	public void changeStatus(String answer, String next, Pair hand, Pair cur) {
		answer += next;
		hand = cur;
	}

	public String solution(int[] numbers, String hand) {
		String answer = "";

		Pair left = new Pair(3, 0), right = new Pair(3, 2);

		for (int x : numbers) {
			if (x == 0) x = 11;
			x--;

			Pair cur = new Pair(x / 3, x % 3);
			int l = left.getDist(cur);
			int r = right.getDist(cur);

			if (x % 3 == 0) {
				answer += "L";
				left = cur;
			}
			else if (x % 3 == 2) {
				answer += "R";
				right = cur;
			}
			else {
				if (l < r) {
					answer += "L";
					left = cur;
				}
				else if (l > r) {
					answer += "R";
					right = cur;
				}
				else {
					if ("left".equals(hand)) {
						answer += "L";
						left = cur;
					}
					else {
						answer += "R";
						right = cur;
					}
				}
			}
		}

		return answer;
	}
}