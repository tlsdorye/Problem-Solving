import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int M, N, V, X, Y, ans, max;
	static int[][] map;
	static boolean[][] visit;
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };
	static Queue<Tuple> que;
	static PriorityQueue<Tuple> pque = new PriorityQueue<>();

	static class Tuple implements Comparable<Tuple> {
		int x, y, t;

		Tuple(int x, int y, int t) {
			this.x = x;
			this.y = y;
			this.t = t;
		}

		@Override
		public int compareTo(Tuple o) {
			return this.t - o.t;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("./src/input.txt"));
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		V = sc.nextInt();
		X = sc.nextInt();
		Y = sc.nextInt();
		map = new int[N + 1][M + 1];
		visit = new boolean[N + 1][M + 1];

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				map[i][j] = sc.nextInt();

		int x = 0, y = 0, t = 0;
		for (int i = 0; i < V; i++) {
			x = sc.nextInt();
			y = sc.nextInt();
			t = sc.nextInt();
			pque.add(new Tuple(x, y, t));
			map[x][y] = -1;
		}
		
		BFS();
		System.out.println(max + " " + ans);
	}

	static boolean Check(int x, int y) {
		return 1 <= x && x <= N && 1 <= y && y <= M;
	}

	static void BFS() {
		que = new LinkedList<>();

		eruption(0);
		que.add(new Tuple(X, Y, -1));
		visit[X][Y] = true;

		ans = 0;
		max = map[X][Y];
		int qsize = 0;
		int time = 0;
		while (!que.isEmpty()) {
			qsize = que.size();
			eruption(time + 1);
			for (int i = 0; i < qsize; i++) {
				Tuple p = que.poll();
				if (p.t == -1 && max < map[p.x][p.y]) {
					ans = time;
					max = map[p.x][p.y];
				}
				for (int j = 0; j < 4; j++) {
					int nx = p.x + dx[j];
					int ny = p.y + dy[j];
					if(!Check(nx, ny)) continue;
					if(visit[nx][ny]) continue;
					if(p.t == -1 && map[nx][ny] == -1) continue;
					que.add(new Tuple(nx, ny, p.t));
					visit[nx][ny] = true;
				}
			}
			time++;
		}

	}

	static void eruption(int time) {
		while (!pque.isEmpty()) {
			Tuple tu = pque.peek();
			if (tu.t <= time) {
				que.add(pque.poll());
				visit[tu.x][tu.y] = true;
			}
			else return;
		}
	}
}
