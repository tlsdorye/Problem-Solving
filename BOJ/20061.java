import java.util.ArrayList;
import java.util.*;

public class Main {

    static int N, t, x, y, point, count;
    static ArrayList<Pos>[] blocks;
    static int[][][] board;

    static class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Init();

        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            t = sc.nextInt();
            x = sc.nextInt();
            y = sc.nextInt();
            int[] endIdx = SetBlock(t, x, y);
            MoveBlock(endIdx);
            EraseLine();
            CheckSpecialLines();
        }

        for (int b = 0; b < 2; b++)
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 4; j++)
                    if (board[b][i][j] != 0) count++;

        System.out.println(point + "\n" + count);
    }

    static void Init() {
        blocks = new ArrayList[3];
        for (int i = 0; i < 3; i++) {
            blocks[i] = new ArrayList<>();
            blocks[i].add(new Pos(0, 0));
        }
        blocks[1].add(new Pos(0, 1));
        blocks[2].add(new Pos(1, 0));
        board = new int[2][10][4];
    }

    static int[] SetBlock(int t, int x, int y) {
        int[] ret = new int[2];

        for (Pos p : blocks[t - 1]) {
            board[0][x + p.x][y + p.y] = 1;
            ret[0] = Math.max(ret[0], x + p.x);

            board[1][y + p.y][3 - (x + p.x)] = 1;
            ret[1] = Math.max(ret[1], y + p.y);
        }
        return ret;
    }

    static void MoveBlock(int[] endIdx) {
        for (int b = 0; b < 2; b++) {
            while (endIdx[b] < 9) {
                boolean flag = true;
                for (int j = 0; j < 4; j++)
                    if (board[b][endIdx[b]][j] == 1 && board[b][endIdx[b] + 1][j] != 0) {
                        flag = false;
                        break;
                    }
                if (!flag) break;
                for (int i = endIdx[b]; i >= 0; i--)
                    for (int j = 0; j < 4; j++)
                        if (board[b][i][j] == 1) {
                            board[b][i][j] = 0;
                            board[b][i + 1][j] = 1;
                        }
                endIdx[b]++;
            }
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 4; j++)
                    if (board[b][i][j] == 1)
                        board[b][i][j] = 2;
        }
    }

    static void EraseLine() {
        for (int b = 0; b < 2; b++) {
            for (int i = 0; i < 10; i++) {
                boolean flag = true;
                for (int j = 0; j < 4; j++)
                    if (board[b][i][j] == 0) {
                        flag = false;
                        break;
                    }
                if (!flag) continue;
                for (int j = 0; j < 4; j++)
                    board[b][i][j] = 0;
                ShiftLines(b, i - 1);
                point++;
            }
        }
    }

    static void ShiftLines(int b, int endIdx) {
        for (int i = endIdx; i >= 0; i--)
            for (int j = 0; j < 4; j++)
                if (board[b][i][j] == 2) {
                    board[b][i][j] = 0;
                    board[b][i + 1][j] = 2;
                }
    }

    static void CheckSpecialLines() {
        for (int b = 0; b < 2; b++) {
            while (true) {
                boolean flag = false;
                for (int j = 0; j < 4; j++)
                    if (board[b][5][j] != 0) {
                        flag = true;
                        break;
                    }
                if (!flag) break;
                for (int j = 0; j < 4; j++) 
                    board[b][9][j] = 0;
                ShiftLines(b, 9);
            }
        }
    }

    static boolean check(int x, int y) {
        return 0 <= x && x < 10 && 0 <= y && y < 10;
    }
}