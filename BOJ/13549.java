import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static final int MAX = 200000;
	static int N, K;
	static int[] visit = new int[MAX + 1];
	static Queue<Pair> que = new LinkedList<>();

	static class Pair {
		int pos, level;

		Pair(int pos, int level) {
			this.pos = pos;
			this.level = level;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		K = sc.nextInt();
		BFS();
		System.out.println(visit[K]);
	}

	static void BFS() {
		Arrays.fill(visit, Integer.MAX_VALUE);
		que.add(new Pair(N, 0));
		jump(new Pair(N, 0));

		while (!que.isEmpty()) {
			Pair p = que.poll();
			if (p.pos == K) return;
			if (p.pos + 1 <= MAX && visit[p.pos + 1] > p.level + 1) {
				jump(new Pair(p.pos + 1, p.level + 1));
			}
			if (0 <= p.pos - 1 && visit[p.pos - 1] > p.level + 1) {
				jump(new Pair(p.pos - 1, p.level + 1));
			}
		}
	}

	static void jump(Pair p) {
		if (p.pos == 0) {
			visit[p.pos] = p.level;
			return;
		}
		while (p.pos <= MAX) {
			if (visit[p.pos] > p.level) {
				visit[p.pos] = p.level;
				que.add(new Pair(p.pos, p.level));
			}
			p.pos *= 2;
		}
	}
}
