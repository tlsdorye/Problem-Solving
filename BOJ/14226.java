import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int S, ans;
	static int[][] visit = new int[2001][2001];
	static Queue<Pair> que = new LinkedList<>();

	static class Pair {
		int cnt, size;

		Pair(int cnt, int size) {
			this.cnt = cnt;
			this.size = size;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("./src/input.txt"));
		Scanner sc = new Scanner(System.in);

		S = sc.nextInt();
		for (int i = 0; i < 2000; i++)
			Arrays.fill(visit[i], Integer.MAX_VALUE);

		ans = Math.max(ans, BFS());
		System.out.println(ans);
	}

	static int BFS() {
		que.add(new Pair(1, 0));
		visit[1][0] = 0;

		int level = 0;
		int qsize = 0;
		while (!que.isEmpty()) {
			qsize = que.size();
			for (int i = 0; i < qsize; i++) {
				Pair p = que.poll();
				if (p.cnt == S)
					return level;
				int cnt = p.cnt;
				int size = p.cnt;
				if (visit[cnt][size] > level) {
					que.add(new Pair(cnt, size));
					visit[cnt][size] = level;
				}
				cnt = p.cnt + p.size;
				size = p.size;
				if (cnt <= 2000 && visit[cnt][size] > level) {
					que.add(new Pair(cnt, size));
					visit[cnt][size] = level;
				}
				cnt = p.cnt - 1;
				size = p.size;
				if (cnt >= 0 && visit[cnt][size] > level) {
					que.add(new Pair(cnt, size));
					visit[cnt][size] = level;
				}
			}
			level++;
		}
		return Integer.MAX_VALUE;
	}
}
