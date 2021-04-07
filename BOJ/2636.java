import java.util.*;
import java.io.*;

public class Main {

	static int N, M, ANS, TIME;
	static int[][] map;
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };

	static Queue<Pair> cheese, que, melted;

	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		map = new int[N][M];
		cheese = new LinkedList<>();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				map[i][j] = sc.nextInt();
				if (map[i][j] == 1) cheese.add(new Pair(i, j));
			}

		melted = new LinkedList<>();
		melted.add(new Pair(0, 0));
		map[0][0] = -1;
		eraseZero(melted, -1);

		eraseCheese();
		System.out.println(TIME);
		System.out.println(ANS);
	}

	static void eraseCheese() {
		int qsize = 0;
		int level = -1;
		while (!cheese.isEmpty()) {
			qsize = cheese.size();
			for (int i = 0; i < qsize; i++) {
				Pair p = cheese.poll();
				boolean flag = false;
				for (int j = 0; j < 4; j++) {
					int nx = p.x + dx[j];
					int ny = p.y + dy[j];
					if (!check(nx, ny)) continue;
					if (map[nx][ny] != level) continue;
					map[p.x][p.y] = level - 1;
					melted.add(p);
					flag = true;
					break;
				}
				if (!flag) cheese.add(p);
			}
			if (!cheese.isEmpty()) eraseZero(melted, level - 1);
			else {
				TIME = -level;
				ANS = melted.size();
			}
			level--;
		}
	}

	static void eraseZero(Queue<Pair> que, int level) {
		while (!que.isEmpty()) {
			Pair p = que.poll();
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (!check(nx, ny)) continue;
				if (map[nx][ny] != 0) continue;
				map[nx][ny] = level;
				que.add(new Pair(nx, ny));
			}
		}
	}

	static boolean check(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < M;
	}
}