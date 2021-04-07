import java.util.*;

public class Main {

	static final long MOD = 1000000007;
	static long[] A, B;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		A = new long[N + 1];
		B = new long[N + 1];

		A[0] = 1;
		A[1] = 2;
		B[0] = 0;
		B[1] = 1;

		for (int i = 2; i <= N; i++) {
			B[i] = ((A[i - 1] + A[i - 2]) % MOD + B[i - 2]) % MOD;
			A[i] = (A[i - 2] + (2 * B[i]) % MOD) % MOD;
		}
		System.out.println(A[N]);
	}

}
