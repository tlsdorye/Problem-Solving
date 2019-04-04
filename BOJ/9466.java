import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		for (int test_case = 0; test_case < T; test_case++) {
			int n, ans = 0;
			n = sc.nextInt();

			int student[] = new int[n + 1];
			int count[] = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				student[i] = sc.nextInt();
				count[student[i]]++;
			}

			Stack<Integer> notSelect = new Stack<Integer>();
			for (int i = 1; i <= n; i++)
				if (count[i] == 0)
					notSelect.push(student[i]);

			while (!notSelect.empty()) {
				int curr = notSelect.pop();
				count[curr]--;
				if (count[curr] == 0)
					notSelect.push(student[curr]);
			}
			for (int i = 1; i <= n; i++)
				if (count[i] == 0)
					ans++;
			System.out.println(ans);
		}
	}
}