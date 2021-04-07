import java.util.*;

public class Main {

	static int N, L, R, unitSize, ANS;
	static int[][] map, unitMap;
	static boolean[][] visit;
	static ArrayList<Pair> sumMap;
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };

	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		L = sc.nextInt();
		R = sc.nextInt();

		map = new int[N][N];
		visit = new boolean[N][N];
		unitMap = new int[N][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = sc.nextInt();

		while (true) {
			initUnitMap();
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					searchMap(i, j);
			if (unitSize == N * N) break;

			sumMap = new ArrayList<>();
			for (int i = 0; i < unitSize + 1; i++)
				sumMap.add(new Pair(0, 0));

			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++) {
					sumMap.get(unitMap[i][j]).x += map[i][j];
					sumMap.get(unitMap[i][j]).y++;
				}
			for (int i = 1; i <= unitSize; i++)
				sumMap.get(i).x /= sumMap.get(i).y;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					map[i][j] = sumMap.get(unitMap[i][j]).x;
			ANS++;
		}
		System.out.println(ANS);
	}

	static boolean check(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < N;
	}

	static void searchMap(int x, int y) {
		if (visit[x][y]) return;
		visit[x][y] = true;
		unitSize++;

		Queue<Pair> que = new LinkedList<>();
		que.add(new Pair(x, y));
		while (!que.isEmpty()) {
			Pair p = que.poll();
			unitMap[p.x][p.y] = unitSize;
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (!check(nx, ny)) continue;
				if (visit[nx][ny]) continue;
				int diff = Math.abs(map[p.x][p.y] - map[nx][ny]);
				if (diff < L || R < diff) continue;
				visit[nx][ny] = true;
				que.add(new Pair(nx, ny));
			}
		}
	}

	static void initUnitMap() {
		unitSize = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
				unitMap[i][j] = 0;
			}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				searchMap(i, j);
	}
}