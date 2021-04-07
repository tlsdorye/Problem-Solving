import java.util.*;

public class Main {

	static int V, E;

	static int[] parent;
	static int[] rank; // 해당 루트의 트리 높이

	static List<Edge> adj;

	static class Edge implements Comparable<Edge> {
		int x, y;
		long w;

		public Edge(int x, int y, long w) {
			this.x = x;
			this.y = y;
			this.w = w;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare((int) this.w, (int) o.w);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		V = sc.nextInt();
		E = sc.nextInt();

		adj = new ArrayList<>();

		for (int i = 0; i < E; i++)
			adj.add(new Edge(sc.nextInt() - 1, sc.nextInt() - 1, sc.nextInt()));

		Collections.sort(adj);

		parent = new int[V];
		rank = new int[V];
		initSet();
		System.out.println(kruskal());
	}

	static void initSet() {
		for (int i = 0; i < V; i++)
			parent[i] = i;
	}

	static int findSet(int x) {
		if (parent[x] == x) return x;
		return parent[x] = findSet(parent[x]);
	}

	static void unionSet(int x, int y) {
		int px = findSet(x);
		int py = findSet(y);
		// 두 값의 root가 이미 같음 (같은 집합)
		if (px == py) return;
		if (rank[px] < rank[py]) parent[px] = py;
		else parent[py] = px;
		if (rank[px] == rank[py]) rank[px]++;
	}

	static long kruskal() {
		long ret = 0;
		int pick = 0, idx = 0;
		while (pick < V - 1 && idx < adj.size() - 1) {
			Edge e = adj.get(idx++);
			// cycle?
			if (findSet(e.x) == findSet(e.y)) continue;
			unionSet(e.x, e.y);
			pick++;
			ret += e.w;
		}
		if (pick != V - 1) return -1;
		return ret;
	}
}
