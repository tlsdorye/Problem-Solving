import java.util.*;
import java.io.*;

public class Main {

	static int N = 10, ANS;
	static int[][] map;
	static int[] paperCnt = { 0, 5, 5, 5, 5, 5 };

	public static void main(String[] args) throws Exception {
//		System.setIn(new FileInputStream("./src/input.txt"));
		Scanner sc = new Scanner(System.in);

		int T = 1;
		for (int tc = 1; tc <= T; tc++) {

			map = new int[N][N];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < 10; j++)
					map[i][j] = sc.nextInt();

			ANS = Integer.MAX_VALUE;
			solve(0, 0, 0);
			if(ANS == Integer.MAX_VALUE) ANS = -1;
			System.out.println(ANS);
		}
	}

	static void solve(int x, int y, int cnt) {
		if (x == N) ANS = Math.min(ANS, cnt);
		else if (y == N) solve(x + 1, 0, cnt);
		else if (map[x][y] == 0) solve(x, y + 1, cnt);
		else {
			for (int i = 1; i <= 5; i++) {
				if (paperCnt[i] == 0) continue;
				if (!checkArea(x, y, i)) continue;
				fillArea(x, y, i, 0);
				paperCnt[i]--;
				solve(x, y + i, cnt + 1);
				fillArea(x, y, i, 1);
				paperCnt[i]++;
			}
		}
	}

	static boolean checkArea(int x, int y, int size) {
		boolean ret = true;
		for (int i = x; i < x + size; i++)
			for (int j = y; j < y + size; j++) 
				if (!check(i, j) || map[i][j] != 1) return false;
		return ret;
	}

	static void fillArea(int x, int y, int size, int type) {
		for (int i = x; i < x + size; i++)
			for (int j = y; j < y + size; j++)
				map[i][j] = type;
	}

	static boolean check(int x, int y) {
		return 0 <= x && x < N & 0 <= y && y < N;
	}

	static void print() {
		for (int i = 0; i < N; i++, System.out.println())
			for (int j = 0; j < N; j++)
				System.out.printf("%2d", map[i][j]);
		System.out.println();
	}

}
