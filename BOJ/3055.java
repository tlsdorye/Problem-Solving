import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int N, M, Sx, Sy, Fx, Fy;
	static char[][] map;
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };
	static Queue<Pair> que;

	static class Pair {
		int x, y, t;

		Pair(int x, int y, int t) {
			this.x = x;
			this.y = y;
			this.t = t;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();
		map = new char[N][M];
		que = new LinkedList<>();

		for (int i = 0; i < N; i++) {
			String s = sc.next();
			for (int j = 0; j < M; j++) {
				map[i][j] = s.charAt(j);
				if (map[i][j] == 'S') {
					Sx = i;
					Sy = j;
				} else if (map[i][j] == 'D') {
					Fx = i;
					Fy = j;
				} else if (map[i][j] == '*')
					que.add(new Pair(i, j, 2));
			}
		}

		que.add(new Pair(Sx, Sy, 1));

		int level = -1;
		int qsize = 0;
		boolean flag = false;
		while (!que.isEmpty() && !flag) {
			qsize = que.size();
			level++;
			for (int i = 0; i < qsize; i++) {
				Pair p = que.poll();
				if (p.x == Fx && p.y == Fy && p.t == 1) {
					flag = true;
					break;
				}
				for (int j = 0; j < 4; j++) {
					int nx = p.x + dx[j];
					int ny = p.y + dy[j];
					if (!Check(nx, ny))
						continue;
					if (map[nx][ny] == 'S' || map[nx][ny] == '*' || map[nx][ny] == 'X')
						continue;
					if (nx == Fx && ny == Fy && p.t == 2)
						continue;
					que.add(new Pair(nx, ny, p.t));
					map[nx][ny] = map[p.x][p.y];
				}
			}
		}
		
		if (flag)
			System.out.println(level);
		else
			System.out.println("KAKTUS");
	}

	static boolean Check(int x, int y) {
		return 0 <= x && x < N && 0 <= y && y < M;
	}

}
