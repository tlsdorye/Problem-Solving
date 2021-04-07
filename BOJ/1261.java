import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int N, M;
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };
	static int[][] map, visit;
	static Queue<Pair> que = new LinkedList<>();

	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);

		M = sc.nextInt();
		N = sc.nextInt();
		map = new int[N + 1][M + 1];
		visit = new int[N + 1][M + 1];
		for (int i = 1; i <= N; i++)
			Arrays.fill(visit[i], Integer.MAX_VALUE);

		for (int i = 1; i <= N; i++) {
			String s = sc.next();
			for (int j = 1; j <= M; j++)
				map[i][j] = (s.charAt(j - 1) - '0');
		}

		BFS();
		System.out.println(visit[N][M]);
		//printMap();
	}

	static boolean Check(int x, int y) {
		return 1 <= x && x <= N && 1 <= y && y <= M;
	}
	
	static void printMap() {
		for (int i = 1; i <= N; i++, System.out.println())
			for (int j = 1; j <= M; j++)
				System.out.print(visit[i][j] + " ");
	}

	static void BFS() {
		que.add(new Pair(1, 1));
		visit[1][1] = 0;

		while (!que.isEmpty()) {
			Pair p = que.poll();
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (!Check(nx, ny))
					continue;
				if (visit[nx][ny] > visit[p.x][p.y] + map[nx][ny]) {
					visit[nx][ny] = visit[p.x][p.y] + map[nx][ny];
					que.add(new Pair(nx, ny));
				}
			}
		}

	}
}
