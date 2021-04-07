import java.util.*;
import java.io.*;

public class Main {

	static int N, M, ANS = Integer.MAX_VALUE;
	static int[][] map;
	static int[] dx = { 0, 1, 0, -1 };
	static int[] dy = { 1, 0, -1, 0 };
	static int[][] dirType = new int[][] { {}, { 0 }, { 0, 2 }, { 0, 3 }, { 0, 2, 3 }, { 0, 1, 2, 3 } };
	static ArrayList<CCTV> clist;

	static Scanner sc;

	static class CCTV {
		int type, x, y;
		int[] dir;

		public CCTV(int type, int x, int y, int[] copy) {
			this.type = type;
			this.x = x;
			this.y = y;
			dir = new int[copy.length];
			for (int i = 0; i < copy.length; i++)
				dir[i] = copy[i];
		}

		public void rotate() {
			for (int i = 0; i < dir.length; i++) {
				dir[i] = (dir[i] + 1) % 4;
			}
		}

		public void view(int idx) {
			for (int i = 0; i < dir.length; i++) {
				int nx = x;
				int ny = y;
				while (check(nx += dx[dir[i]], ny += dy[dir[i]])) {
					if (map[nx][ny] == 6) break;
					if (map[nx][ny] == 0) map[nx][ny] = -idx;
				}

			}
		}

		public void review(int idx) {
			for (int i = 0; i < dir.length; i++) {
				int nx = x;
				int ny = y;
				while (check(nx += dx[dir[i]], ny += dy[dir[i]])) {
					if (map[nx][ny] == 6) break;
					if (map[nx][ny] == -idx) map[nx][ny] = 0;

				}
			}
		}
	}

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();

		map = new int[N][M];
		clist = new ArrayList<>();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				map[i][j] = sc.nextInt();
				if (1 <= map[i][j] && map[i][j] <= 5) {
					clist.add(new CCTV(map[i][j], i, j, dirType[map[i][j]]));
				}
			}
		solve(0);
		System.out.println(ANS);

	}

	static void solve(int idx) {
		if (idx == clist.size()) {
			ANS = Math.min(ANS, getEmpty());
			return;
		}
		CCTV cctv = clist.get(idx);
		for (int j = 0; j < 4; j++) {
			cctv.rotate();
			cctv.view(idx + 1);
			solve(idx + 1);
			cctv.review(idx + 1);
		}
	}

	static boolean check(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < M;
	}

	static int getEmpty() {
		int ret = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 0) ret++;
		return ret;
	}
}
