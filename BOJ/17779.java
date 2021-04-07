import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	static int N, ans = Integer.MAX_VALUE;
	static int[][] grid;
	static boolean[][] visit;
	static int[] section;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		grid = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				grid[i][j] = sc.nextInt();

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) solve(i, j);
		
		System.out.println(ans);
	}

	static void solve(int x, int y) {
		for (int d1 = 1; d1 <= N; d1++)
			for (int d2 = 1; d2 <= N; d2++) {
				if (x + d1 + d2 > N) continue;
				if (1 > y - d1) continue;
				if (y + d2 > N) continue;

				section = new int[6];
				visit = new boolean[N + 1][N + 1];

				// get section 1
				int step = 0;
				for (int r = 1; r < x + d1; r++) {
					if (r >= x) step++;
					for (int c = 1; c <= y - step; c++) {
						section[1] += grid[r][c];
						visit[r][c] = true;
					}
				}

				// get section 2
				step = 0;
				for (int r = 1; r <= x + d2; r++) {
					for (int c = y + 1 + step; c <= N; c++) {
						section[2] += grid[r][c];
						visit[r][c] = true;
					}
					if (r >= x) step++;
				}

				// get section 3
				step = 0;
				for (int r = x + d1; r <= N; r++) {
					for (int c = 1; c < y - d1 + step; c++) {
						section[3] += grid[r][c];
						visit[r][c] = true;
					}
					if (r < x + d1 + d2) step++;
				}

				// get section 4
				step = 0;
				for (int r = N; r > x + d2; r--) {
					if (r <= x + d1 + d2) step++;
					for (int c = y - d1 + d2 + step; c <= N; c++) {
						section[4] += grid[r][c];
						visit[r][c] = true;
					}
				}

				// get section 5
				for (int r = 1; r <= N; r++)
					for (int c = 1; c <= N; c++)
						if (!visit[r][c]) section[5] += grid[r][c];


				int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
				for (int i = 1; i <= 5; i++) {
					min = Math.min(min, section[i]);
					max = Math.max(max, section[i]);
				}
				ans = Math.min(ans, max - min);
			}
	}
}
