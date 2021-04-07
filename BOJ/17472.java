import java.util.*;
import java.io.*;

public class Main {

	static int N, M;
	static int[][] map, graph;
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };

	static int V, E;
	static int[] parent, rank;

	static class Pair {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static class Edge implements Comparable<Edge> {
		int w, x, y;

		Edge(int w, int x, int y) {
			this.w = w;
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Edge o) {
			return this.w - o.w;
		}
	}

	public static void main(String[] args) throws Exception {
//		System.setIn(new FileInputStream("./src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++)
				map[i][j] = Integer.parseInt(st.nextToken());
		}

		V = getVertex();
		getEdge();
//		print(graph);
		System.out.println(Kruskal());

	}

	static void print(int[][] arr) {
		for (int i = 0; i < arr.length; i++, System.out.println())
			for (int j = 0; j < arr[i].length; j++)
				System.out.printf("%4d", arr[i][j]);
	}

	static int getVertex() {
		int ret = 0;
		Queue<Pair> que;
		boolean[][] visit = new boolean[N][M];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (map[i][j] <= 0) continue;
				map[i][j] = -(++ret);
				que = new LinkedList<>();
				que.add(new Pair(i, j));
				while (!que.isEmpty()) {
					Pair p = que.poll();
					for (int k = 0; k < 4; k++) {
						int nx = p.x + dx[k];
						int ny = p.y + dy[k];
						if (!check(nx, ny)) continue;
						if (map[nx][ny] <= 0) continue;
						map[nx][ny] = -ret;
						que.add(new Pair(nx, ny));
					}
				}
			}
//		print(map);
		return ret;
	}

	static void getEdge() {
		graph = new int[V + 1][V + 1];
		for (int i = 0; i <= V; i++)
			Arrays.fill(graph[i], 10);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) continue;

				for (int k = 0; k < 4; k++) {
					int len = 0, nx = i, ny = j;
					while (check(nx += dx[k], ny += dy[k]) && map[nx][ny] == 0)
						len++;
					if (!check(nx, ny) || len < 2) continue;
					int u = -map[i][j];
					int v = -map[nx][ny];
					if (u == v) continue;
					graph[u][v] = Math.min(graph[u][v], len);
					graph[v][u] = Math.min(graph[v][u], len);
				}
			}
		}
	}

	static int Kruskal() {
		int ret = 0;
		initSet();
		PriorityQueue<Edge> edges = new PriorityQueue<>();
		for (int i = 1; i <= V; i++)
			for (int j = i + 1; j <= V; j++)
				if (graph[i][j] != 10)
					edges.add(new Edge(graph[i][j], i, j));
		//
		int pick = 0;
		while (pick < V - 1 && !edges.isEmpty()) {
			Edge e = edges.poll();
			if (findSet(e.x) == findSet(e.y)) continue;
			unionSet(e.x, e.y);
			pick++;
			ret += e.w;
		}
		return pick == V - 1 ? ret : -1;
	}

	static void initSet() {
		parent = new int[V + 1];
		rank = new int[V + 1];
		for (int i = 0; i <= V; i++)
			parent[i] = i;
	}

	static int findSet(int x) {
		if (parent[x] == x) return parent[x];
		return parent[x] = findSet(parent[x]);
	}

	static void unionSet(int x, int y) {
		int px = findSet(x);
		int py = findSet(y);
		if (rank[px] < rank[py]) parent[x] = py;
		else {
			parent[y] = px;
			if (rank[px] == rank[py]) rank[px]++;
		}
	}

	static boolean check(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < M;
	}
}
