import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

	static int N, K, ANS;
	static String[] word;

	static boolean[] check;

	public static void main(String[] args) throws Exception {
//		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		check = new boolean[26];
		check['a' - 'a'] = true;
		check['n' - 'a'] = true;
		check['t' - 'a'] = true;
		check['i' - 'a'] = true;
		check['c' - 'a'] = true;

		N = sc.nextInt();
		K = sc.nextInt();
		if (K < 5) {
			System.out.println(ANS);
			return;
		}
		K -= 5;

		word = new String[N];
		for (int i = 0; i < N; i++)
			word[i] = sc.next();

		solve(0, 0);
		System.out.println(ANS);
	}

	static void solve(int depth, int idx) {
		if (depth == K) {
			int ret = 0;
			for (int i = 0; i < N; i++) {
				boolean flag = true;
				for (int j = 4; j < word[i].length() - 4; j++) {
					if (!check[word[i].charAt(j) - 'a']) {
						flag = false;
						break;
					}
				}
				if (flag) ret++;
			}
			ANS = Math.max(ANS, ret);
			return;
		}

		for (int i = idx; i < 26; i++) {
			if (check[i]) continue;
			check[i] = true;
			solve(depth + 1, i + 1);
			check[i] = false;
		}
	}
}
