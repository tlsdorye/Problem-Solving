import java.util.*;

class Solution {
public int solution(int n, int[][] results) {
		int answer = 0;

		ArrayList<Integer>[] win = new ArrayList[n + 1];
		ArrayList<Integer>[] lose = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			win[i] = new ArrayList<>();
			lose[i] = new ArrayList<>();
		}

		for (int[] x : results) {
			win[x[0]].add(x[1]);
			lose[x[1]].add(x[0]);
		}

		for(int i=1;i<=n;i++) {
			if(dfs(win, new boolean[n+1], i) + 
					dfs(lose, new boolean[n + 1], i) == n - 1)
				answer++;
		}
		return answer;
	}

	public int dfs(ArrayList<Integer>[] graph, boolean[] visit, int V) {
		int ret = 0;
		visit[V] = true;
		for (int nv : graph[V]) {
			if (visit[nv]) continue;
			ret++;
			ret += dfs(graph, visit, nv);
		}
		return ret;
	}
}