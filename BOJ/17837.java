import java.util.*;

public class Main {

	static int N, K;
	static boolean flag;
	static int[] dx = { 0, 0, 0, -1, 1 };
	static int[] dy = { 0, 1, -1, 0, 0 };

	static int[][] map;
	static Stack<Integer>[][] PM;
	static Player[] player;

	static class Pos {
		int x;
        int y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static class Player {
		Pos p;
		int d;

		public Player(Pos p, int d) {
			this.p = p;
			this.d = d;
		}	
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		K = sc.nextInt();
        flag = false;
		map = new int[N][N];
		PM = new Stack[N][N];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				PM[i][j] = new Stack<>();
				map[i][j] = sc.nextInt();
			}

		player = new Player[K];
		for (int i = 0; i < K; i++) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			int d = sc.nextInt();
			player[i] = new Player(new Pos(x, y), d);
			PM[x][y].push(i);
		}
		
		int ANS = 1;
		for (; ANS <= 1000; ANS++) {
			for (int i = 0; i < K; i++) {
				Player p = player[i];
				int nx = p.p.x + dx[p.d];
				int ny = p.p.y + dy[p.d];
				int cnt = 0;
				if (!Check(nx, ny)) {
					p.d = Reverse(p.d);
					nx = p.p.x + dx[p.d];
					ny = p.p.y + dy[p.d];
					cnt++;
				}
				if (map[nx][ny] == 0) MoveWhite(p.p, new Pos(nx, ny), i);
				if (map[nx][ny] == 1) MoveRed(p.p, new Pos(nx, ny), i);
				if (map[nx][ny] == 2 && cnt == 0) {
					p.d = Reverse(p.d);
					nx = p.p.x + dx[p.d];
					ny = p.p.y + dy[p.d];
					if (!Check(nx, ny)) continue;
					if (map[nx][ny] == 0) MoveWhite(p.p, new Pos(nx, ny), i);
					if (map[nx][ny] == 1) MoveRed(p.p, new Pos(nx, ny), i);
				}
				if (flag) break;
			}
			if (flag) break;
		}
		if (ANS == 1001) ANS = -1;
		System.out.println(ANS);

	}

	static int Reverse(int d) {
		if (d == 1) return 2;
		else if (d == 2) return 1;
		else if (d == 3) return 4;
		return 3;
	}

	static boolean Check(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < N;
	}

	static void MoveWhite(Pos p1, Pos p2, int idx) {
		Stack<Integer> a = PM[p1.x][p1.y];
		Stack<Integer> b = PM[p2.x][p2.y];
		Stack<Integer> temp = new Stack<>();

		int top = -1;
		while (!a.empty() && top != idx)
			temp.push(top = a.pop());

		while (!temp.empty()) {
			int pdx = temp.pop();
			b.push(pdx);
			player[pdx].p = new Pos(p2.x, p2.y);
		}
		if (b.size() >= 4) flag = true;
	}

	static void MoveRed(Pos p1, Pos p2, int idx) {
		Stack<Integer> a = PM[p1.x][p1.y];
		Stack<Integer> b = PM[p2.x][p2.y];

		int top = -1;
		while (!a.empty() && top != idx) {
			top = a.pop();
			b.push(top);
			player[top].p = new Pos(p2.x, p2.y);
		}
		if (b.size() >= 4) flag = true;
	}
}
