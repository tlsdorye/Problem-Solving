import java.util.*;
import java.io.*;

public class Main {

	static int N, cnt = 1;
	static int[][] map;
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };
	static ArrayList<Queue<Pair>> ques;

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
		map = new int[N][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = sc.nextInt();

		ques = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 1) continue;
				map[i][j] = cnt + 1;
				Pair p = new Pair(i, j);
				ques.add(new LinkedList<>());
				ques.get(ques.size() - 1).add(p);
				Queue<Pair> que = new LinkedList<>();
				que.add(p);
				getIsland(que);
				cnt++;
			}
		}

		int ANS = Integer.MAX_VALUE;
		for (Queue<Pair> que : ques)
			ANS = Math.min(ANS, getMinLength(que));
		System.out.println(ANS);
	}

	static int getMinLength(Queue<Pair> que) {
		int qsize = 0;
		int level = 0;
		boolean[][] visit = new boolean[N][N];
		int idx = -1;
		for (Pair p : que) {
			visit[p.x][p.y] = true;
			idx = map[p.x][p.y];
		}
		
		while (!que.isEmpty()) {
			qsize = que.size();
			for (int i = 0; i < qsize; i++) {
				Pair p = que.poll();
				if (map[p.x][p.y] != 0 && map[p.x][p.y] != idx) return level - 1;
				for (int j = 0; j < 4; j++) {
					int nx = p.x + dx[j];
					int ny = p.y + dy[j];
					if (!check(nx, ny)) continue;
					if (visit[nx][ny]) continue;
					visit[nx][ny] = true;
					que.add(new Pair(nx, ny));
				}
			}
			level++;
		}
		return level - 1;
	}

	static void getIsland(Queue<Pair> que) {
		Queue<Pair> temp = ques.get(ques.size() - 1);

		while (!que.isEmpty()) {
			Pair p = que.poll();
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (!check(nx, ny)) continue;
				if (map[nx][ny] != 1) continue;
				map[nx][ny] = cnt + 1;
				Pair np = new Pair(nx, ny);
				que.add(np);
				temp.add(np);
			}
		}
	}

	static boolean check(int x, int y) {
		return 0 <= x && x < N & 0 <= y && y < N;
	}

	static void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.printf("%2d", map[i][j]);
			}
			System.out.println();
		}
	}
}
