import java.util.*;

public class Main {
	static int N, T;
	static int[] TC, L, R, nM;
	static long[][] C;
	static long[] ans;

	static void getBinaryTree() {
		for (int i = 1; i <= N; i++) {
			if (i == 1)
				continue;
			int parent = TC[1];
			boolean flag = true;
			while (flag) {
				if (TC[i] < parent) {
					if (L[parent] == -1) {
						L[parent] = TC[i];
						flag = false;
					} else
						parent = L[parent];
				} else {
					if (R[parent] == -1) {
						R[parent] = TC[i];
						flag = false;
					} else
						parent = R[parent];
				}
			}
		}
	}

	static void getPascal() {
		for (int n = 1; n < 21; n++)
			for (int k = 1; k <= n; k++)
				C[n + 1][k] = C[n][k] + C[n][k - 1];
	}

	static int getnM(int x) {
		if (x == -1)
			return 0;
		if (nM[x] != 0)
			return nM[x];
		if (L[x] == -1 && R[x] == -1)
			return nM[x] = 1;
		return nM[x] = getnM(L[x]) + getnM(R[x]) + 1;
	}

	static long getC(int x, int y) {
		if (x < 0 || y < 0)
			return 1;
		return C[nM[x] + nM[y]][nM[y]];
	}

	static long solve(int x) {
		if (x == -1)
			return 1;
		if (ans[x] != 0)
			return ans[x];
		if (nM[x] == 1)
			return ans[x] = 1;
		return ans[x] = getC(L[x], R[x]) * solve(L[x]) * solve(R[x]);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		L = new int[22];
		R = new int[22];
		TC = new int[22];
		nM = new int[22];
		C = new long[22][22];
		ans = new long[22];
		for (int i = 0; i < 21; i++)
			for (int k = 0; k < 21; k++)
				C[i][k] = 1;
		getPascal();
		T = sc.nextInt();
		for (int test_case = 0; test_case < T; test_case++) {
			Arrays.fill(L, -1);
			Arrays.fill(R, -1);
			Arrays.fill(TC, -1);
			Arrays.fill(nM, 0);
			Arrays.fill(ans, 0);
			N = sc.nextInt();
			for (int i = 1; i <= N; i++)
				TC[i] = sc.nextInt();
			getBinaryTree();
			getnM(TC[1]);
			solve(TC[1]);
			System.out.println(ans[TC[1]]%9999991);
		}
	}
}