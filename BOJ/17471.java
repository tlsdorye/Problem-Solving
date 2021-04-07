import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	static int N, ans = Integer.MAX_VALUE;
	static int[] people;
	static boolean[] sel, visit;
	static boolean[][] edge;

	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("./src/input.txt"));
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		people = new int[N];
		sel = new boolean[N];
		edge = new boolean[N][N];
		for (int i = 0; i < N; i++)
			people[i] = sc.nextInt();

		for (int i = 0; i < N; i++) {
			int size = sc.nextInt();
			for (int j = 0; j < size; j++) {
				int jdx = sc.nextInt();
				edge[i][jdx - 1] = true;
			}
		}

		recur(0);
		if(ans == Integer.MAX_VALUE) ans = -1;
		System.out.println(ans);

	}

	static void DFS(int idx, boolean group) {
		visit[idx] = true;
		for (int i = 0; i < N; i++) {
			if (visit[i]) continue;
			if (sel[i] != group) continue;
			if (!edge[idx][i]) continue;
			DFS(i, group);
		}
	}

	// 찾아봐좀 이거떔에 오늘 멘탈나감
	
	static int solve() {
		int Asum = 0, Bsum = 0, adx = 0, bdx = 0;
		for (int i = 0; i < N; i++) {
			if (sel[i]) {
				Asum += people[i];
				adx = i;
			} else {
				Bsum += people[i];
				bdx = i;
			}
		}

		visit = new boolean[N];
		DFS(adx, true);
		DFS(bdx, false);
		for (int i = 0; i < N; i++)
			if (!visit[i]) return Integer.MAX_VALUE;
		return Math.abs(Asum - Bsum);
	}

	static void recur(int depth) {
		if (depth > N / 2) return;
		for (int i = 0; i < N; i++) {
			if (sel[i]) continue;
			sel[i] = true;
			ans = Math.min(ans, solve());
			recur(depth + 1);
			sel[i] = false;
		}
	}
}