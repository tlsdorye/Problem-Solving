import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int N = 5, ans;
	static int[][][] grid;
	static int[][][] copygrid;
	static int[] ret;
	static boolean[] sel;
	static boolean[][][] visit;
	static int[] dz = { 0, 0, 0, 0, 1, -1 };
	static int[] dx = { 0, 0, 1, -1, 0, 0 };
	static int[] dy = { 1, -1, 0, 0, 0, 0 };
	// (0, 0, 0) (0, 0, 5) (0, 5, 0) (0, 5, 5)
	// (5, 5, 5) (5, 5, 0) (5, 0, 5) (5, 0, 0)
	static tuple enter = new tuple(0, 0, 0);
	static tuple exit = new tuple(4, 4, 4);
	static Queue<tuple> que;

	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("src/input.txt"));
		Scanner sc = new Scanner(System.in);

		grid = new int[N][N][N];
		copygrid = new int[N][N][N];
		ret = new int[N];
		sel = new boolean[N];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					grid[i][j][k] = sc.nextInt();

		ans = Integer.MAX_VALUE;
		recur(0);
		if (ans == Integer.MAX_VALUE)
			ans = -1;
		System.out.println(ans);
	}

	static boolean check(int z, int x, int y) {
		return 0 <= z && z < N && 0 <= x && x < N && 0 <= y && y < N;
	}

	static void rotate(int z) {
		/*
		 * (x, y) -> (x - 2, y - 2) -> (y - 2, 2 - x) -> (y, 4 - x) (1, 1) -> (1, 3) (1,
		 * 2) -> (2, 3)
		 */
		int[][] copy = new int[N][N];
		for (int i = 0; i < N; i++)
			System.arraycopy(copygrid[z][i], 0, copy[i], 0, N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				copygrid[z][j][4 - i] = copy[i][j];
	}

	static void copy() {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					copygrid[i][j][k] = grid[ret[i]][j][k];
	}

	static void recur(int idx) {
		if (idx >= 5) {
			copy();
			solve(0);
			return;
		}
		for (int i = 0; i < 5; i++) {
			if (sel[i])
				continue;
			sel[i] = true;
			ret[idx] = i;
			recur(idx + 1);
			sel[i] = false;
		}
	}

	static void solve(int idx) {
		if (idx >= 5) {
			ans = Math.min(ans, BFS());
			return;
		}
		for (int i = 0; i < 4; i++) {
			rotate(idx);
			solve(idx + 1);
		}
	}

	static int BFS() {
		if (copygrid[enter.z][enter.x][enter.y] == 0 || copygrid[exit.z][exit.x][exit.y] == 0)
			return Integer.MAX_VALUE;

		visit = new boolean[N][N][N];
		que = new LinkedList<>();

		que.add(enter);
		visit[enter.z][enter.x][enter.y] = true;
		int level = 0;
		int qsize = que.size();

		while (!que.isEmpty()) {
			tuple cur = null;
			qsize = que.size();
			for (int i = 0; i < qsize; i++) {
				cur = que.poll();
				if (exit.isSame(cur))
					return level;
				for (int d = 0; d < 6; d++) {
					int nz = cur.z + dz[d];
					int nx = cur.x + dx[d];
					int ny = cur.y + dy[d];
					if (!check(nz, nx, ny) || copygrid[nz][nx][ny] == 0 || visit[nz][nx][ny])
						continue;
					visit[nz][nx][ny] = true;
					que.add(new tuple(nz, nx, ny));
				}
			}
			level++;
		}
		return Integer.MAX_VALUE;
	}
}

class tuple {
	public int z, x, y;

	public tuple() {
	};

	public tuple(int z, int x, int y) {
		this.z = z;
		this.x = x;
		this.y = y;
	}

	public boolean isSame(tuple t) {
		return z == t.z && x == t.x && y == t.y;
	}
}
