import java.util.*;

public class Main {
	static int[][] D;

	public static int solve(boolean t, int s, int e) {
		if (D[s][e] != 0)
			return D[s][e];
		if (e - s < 2) {
			if (t) return D[s][e] = Math.max(D[s][s], D[e][e]);
			else return D[s][e] = Math.min(D[s][s], D[e][e]);
		}
		if (t) return D[s][e] = Math.max(D[s][s] + solve(!t, s + 1, e), D[e][e] + solve(!t, s, e - 1));
		else return D[s][e] = Math.min(solve(!t, s + 1, e), solve(!t, s, e - 1));
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T, N;
		T = sc.nextInt();
		while (T-- > 0) {
			N = sc.nextInt();
			D = new int[N + 1][N + 1];
			for (int i = 1; i <= N; i++) D[i][i] = sc.nextInt();
			System.out.println(solve(true, 1, N));
		}
	}
}
