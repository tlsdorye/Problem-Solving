import java.util.*;
import java.io.*;

public class Main {

	static int N, M, ANS, EMPTY;
	static int[][] map;
	static List<Pair> virusPos;

	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };

	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][N];
		virusPos = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 2) virusPos.add(new Pair(i, j));
				if (map[i][j] == 0) EMPTY++;
			}
		}

		ANS = Integer.MAX_VALUE;
		choiceVirusPos(0, 0, new ArrayList<Pair>());
		if (ANS == Integer.MAX_VALUE) ANS = -1;
		System.out.println(ANS);
	}

	static void print(int[][] arr) {
		for (int i = 0; i < N; i++, System.out.println())
			for (int j = 0; j < N; j++)
				System.out.printf("%2d", arr[i][j]);
		System.out.println();
	}

	static void BFS(int[][] copyMap, List<Pair> choice) {
		Queue<Pair> que = new LinkedList<>();
		boolean[][] visit = new boolean[N][N];
		for (Pair p : choice) {
			visit[p.x][p.y] = true;
			que.add(p);
		}

		int level = 0;
		int qsize = 0;
		int emptyCnt = EMPTY;
		while (!que.isEmpty() && emptyCnt > 0) {
			qsize = que.size();
			for (int i = 0; i < qsize; i++) {
				Pair p = que.poll();
				for (int j = 0; j < 4; j++) {
					int nx = p.x + dx[j];
					int ny = p.y + dy[j];
					if (!check(nx, ny)) continue;
					if (copyMap[nx][ny] < 0 || copyMap[nx][ny] == 1) continue;
					if (copyMap[nx][ny] == 0) emptyCnt--;
					copyMap[nx][ny] = -(level + 1);
					que.add(new Pair(nx, ny));
				}
			}
			level++;
			if (ANS < level) return;
		}
		if (emptyCnt <= 0) ANS = Math.min(ANS, level);
	}

	static void choiceVirusPos(int depth, int idx, List<Pair> choice) {
		if (depth == M) {
			int[][] copyMap = new int[N][N];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					copyMap[i][j] = map[i][j];

			for (Pair p : choice)
				copyMap[p.x][p.y] = -1;
			BFS(copyMap, choice);
			return;
		}

		for (int i = idx; i < virusPos.size(); i++) {
			choice.add(virusPos.get(i));
			choiceVirusPos(depth + 1, i + 1, choice);
			choice.remove(choice.size() - 1);
		}
	}

	static boolean check(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < N;
	}
}
