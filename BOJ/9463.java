import java.io.*;
import java.util.*;

public class Main {
	public static int T, N;
	static int[] A, _A, B, _B, M;

	static long solve(int s, int e) {
		long ret = 0;
		if (s == e) return ret;
		int mid = (s + e) / 2;
		ret += solve(s, mid) + solve(mid + 1, e);
		int i = s, j = mid + 1, k = s;
		while (i <= mid && j <= e) 
		{
			if (B[i] > B[j]) 
			{
				ret += (mid - i + 1);
				M[k++] = B[j++];
			} 
			else M[k++] = B[i++];
		}
		while (i <= mid) M[k++] = B[i++];
		while (j <= e) M[k++] = B[j++];
		for (int t = s; t <= e; t++) B[t] = M[t];
		return ret;
	}

	public static void main(String[] args) throws Exception {
		//long st = System.currentTimeMillis();
		//Scanner sc = new Scanner(new File("Permutation_input.txt"));
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		while (T-- > 0) {
			N = sc.nextInt();
			A = new int[N + 1];
			B = new int[N + 1];
			M = new int[N + 1];
			_A = new int[N + 1];
			_B = new int[N + 1];
			
			for (int i = 1; i <= N; i++) _A[i] = sc.nextInt();
			for (int i = 1; i <= N; i++) _B[i] = sc.nextInt();
			for (int i = 1; i <= N; i++) A[_A[i]] = i;
			for (int i = 1; i <= N; i++) B[i] = A[_B[i]];
			System.out.println(solve(1, N));
		}
		//long et = System.currentTimeMillis();
		//System.out.println("걸린시간 : " + (et - st) + "ms");
	}
}
