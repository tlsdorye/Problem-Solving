import java.util.*;
import java.io.*;

public class Main {

	static int ANS;
	static int[][] score, check;
	static HashSet<int[]> set;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		for (int tc = 0; tc < 4; tc++) {
			score = new int[6][3];
			check = new int[6][3];
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++)
					score[i][j] = sc.nextInt();
			}
			ANS = 0;
			solve(0, 1);
			System.out.print(ANS + " ");
		}
	}

	static void solve(int A, int B) {
//		System.out.println(A + " " + B);
		if (A == 6) {
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++)
					if (score[i][j] != check[i][j])
						return;
			ANS = 1;
			return;
		}
		if (B == 6) {
			solve(A + 1, A + 2);
			return;
		}
		for (int i = 0; i < 3; i++) {
			check[A][0 + i]++;
			check[B][2 - i]++;
			if (score[A][0 + i] >= check[A][0 + i] &&
					score[B][2 - i] >= check[B][2 - i]) {
				solve(A, B + 1);
			}
			check[A][0 + i]--;
			check[B][2 - i]--;
		}
	}
}
