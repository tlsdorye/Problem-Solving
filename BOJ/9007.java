import java.io.*;
import java.util.*;

public class Main {
	static int[][] Class = new int[4][1001];
	static int[] A, B;
	static final int INF = 0x7fffffff;

	static int myBinarySearch(int val, int begin, int end) {
		int mid = (begin + end) / 2;
		if (begin == mid) {
			int first = Math.abs(B[begin] - val);
			int second = Math.abs(B[end] - val);
			if (first > second)
				return end;
			else if (first < second)
				return begin;
			else
				return (B[begin] - val < B[end] - val) ? begin : end;
		}
		if (B[mid] < val)
			return myBinarySearch(val, mid, end);
		else if (B[mid] > val)
			return myBinarySearch(val, begin, mid);
		else
			return mid;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test_case = 0; test_case < T; test_case++) {
			
			int k = sc.nextInt();
			int n = sc.nextInt();

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < n; j++)
					Class[i][j] = sc.nextInt();
			
			A = new int[n * n];
			B = new int[n * n];
			
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					A[n * i + j] = Class[0][i] + Class[1][j];
					B[n * i + j] = Class[2][i] + Class[3][j];
				}
			
			Arrays.sort(B);
			int ans = INF;
			
			for (int x : A) {
				int val = myBinarySearch(k - x, 0, B.length - 1);
				int curr = Math.abs(k - ans);
				int next = Math.abs(k - x - B[val]);
				if (curr > next || (curr == next && ans > B[val] + x))
					ans = B[val] + x;
			}
			
			System.out.println(ans);
		}
	}
}