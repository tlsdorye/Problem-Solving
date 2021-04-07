import java.util.*;

class Solution {

	public int solution(int[] a) {
		int answer = 2;

		int S = a.length;
		int[] L = new int[S];
		int[] R = new int[S];

		L[0] = a[0];
		R[S - 1] = a[S - 1];

		for (int i = 1; i < S; i++) {
			L[i] = Math.min(L[i - 1], a[i]);
			R[S - i - 1] = Math.min(R[S - i], a[S - i - 1]);
		}

		for (int i = 1; i < S - 1; i++) {
			int l = L[i - 1];
			int r = R[i + 1];
			if(a[i] > l && a[i] > r) continue;
			answer++;
		}

		return answer;
	}

}