import java.io.*;
import java.util.*;

public class Main {

	static int N, M, ans = Integer.MAX_VALUE;
	static boolean[] sel;
	static ArrayList<Pair> home, chicken;

	static class Pair {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		home = new ArrayList<>();
		chicken = new ArrayList<>();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				int x = sc.nextInt();
				if (x == 1) home.add(new Pair(i, j));
				else if (x == 2) chicken.add(new Pair(i, j));
			}
		sel = new boolean[chicken.size()];

		pickChicken(0, 0);
		System.out.println(ans);

	}

	static void pickChicken(int depth, int selNum) {
		if (selNum == M) getDistance();
		if (depth >= chicken.size()) return;
		if (chicken.size() - depth < M - selNum) return;
		
		sel[depth] = true;
		pickChicken(depth + 1, selNum + 1);
		sel[depth] = false;
		pickChicken(depth + 1, selNum);
	}

	static void getDistance() {
		int ret = 0;
		int[] dist = new int[home.size()];
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		for (int i = 0; i < chicken.size(); i++) {
			if (!sel[i]) continue;
			Pair c = chicken.get(i);
			for (int j = 0; j < home.size(); j++) {
				Pair h = home.get(j);
				dist[j] = Math.min(dist[j], Math.abs(c.x - h.x) + Math.abs(c.y - h.y));
			}

		}
		for (int d : dist) ret += d;
		ans = Math.min(ans, ret);
	}
}