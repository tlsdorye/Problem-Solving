import java.util.*;

class Solution {
	public int[] solution(int[] answers) {
		int[] cnt = new int[3];

		int[] MAX_IDX = { 5, 8, 10 };
		int[][] player = { { 1, 2, 3, 4, 5 }, { 2, 1, 2, 3, 2, 4, 2, 5 }, { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };

		int i = 0, j = 0, k = 0, max = -1;
		for (int x : answers) {
			if (x == player[0][i++]) cnt[0]++;
			if (x == player[1][j++]) cnt[1]++;
			if (x == player[2][k++]) cnt[2]++;
			i %= MAX_IDX[0];
			j %= MAX_IDX[1];
			k %= MAX_IDX[2];
			max = Math.max(max, Math.max(cnt[0], Math.max(cnt[1], cnt[2])));
		}
		int N = 0;
		for (i = 0; i < 3; i++) if (cnt[i] == max) N++;
		int[] answer = new int[N];

		for (i = 0, j = 0; i < 3; i++) if (cnt[i] == max) answer[j++] = i + 1;

		return answer;
	}
}