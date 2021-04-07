import java.util.*;

class Solution {

    public int solution(int n, int[][] edge) {
        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            adj[i] = new ArrayList<>();

        for (int[] x : edge) {
            adj[x[0]].add(x[1]);
            adj[x[1]].add(x[0]);
        }

        Queue<Integer> que = new LinkedList<>();
        que.add(1);

        boolean[] visit = new boolean[n + 1];
        visit[1] = true;

        int level = 0;
        int qsize = 0;
        while (!que.isEmpty()) {
            qsize = que.size();
            for (int i = 0; i < qsize; i++) {
                int cur = que.poll();
                for (int next : adj[cur]) {
                    if (visit[next])
                        continue;
                    visit[next] = true;
                    que.add(next);
                }
            }
            level++;
        }
        return qsize;
    }

}