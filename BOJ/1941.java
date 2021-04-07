import java.util.*;
import java.io.*;

public class Main {

	static final int N = 5;
	static int ANS = 0;
	static char[][] map = new char[N][N];
	static boolean[] check = new boolean[25];
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };
	static ArrayList<Integer> ret;

	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int i = 0; i < N; i++) {
			String s = sc.next();
			for (int j = 0; j < N; j++)
				map[i][j] = s.charAt(j);
		}

		solve(0, 0);
		System.out.println(ANS);
	}

	static void solve(int depth, int idx) {
		if (depth == 7) {
			ret = new ArrayList<>();
			for (int i = 0; i < 25; i++) {
				if (!check[i]) continue;
				ret.add(i);
			}
			BFS();
		}
		for (int i = idx; i < 25; i++) {
			check[i] = true;
			solve(depth + 1, i + 1);
			check[i] = false;
		}
	}

	static void BFS() {
		boolean[][] visitMap = new boolean[N][N];
		int cnt = 0;
		for (int x : ret) {
			visitMap[x / 5][x % 5] = true;
			if (map[x / 5][x % 5] == 'S') cnt++;
		}
		if (cnt < 4) return;

		cnt = 0;
		Queue<Pair> que = new LinkedList<>();
		Pair start = new Pair(ret.get(0) / 5, ret.get(0) % 5);
		que.add(new Pair(ret.get(0) / 5, ret.get(0) % 5));
		visitMap[start.x][start.y] = false;
		while (!que.isEmpty()) {
			Pair p = que.poll();
			cnt++;
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (!checkBoundary(nx, ny)) continue;
				if (!visitMap[nx][ny]) continue;
				visitMap[nx][ny] = false;
				que.add(new Pair(nx, ny));
			}
		}
		if (cnt == 7) ANS++;
	}

	static boolean checkBoundary(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < N;
	}

}