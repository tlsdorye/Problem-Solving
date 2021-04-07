import java.io.*;
import java.util.*;

public class Main {
    static Line[] lines;
    static char[][] board;
    static int r, c, n, col;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        board = new char[r][c];
        for (int i = 0; i < r; i++)
            board[i] = br.readLine().toCharArray();

        lines = new Line[c];
        for (int i = 0; i < c; i++) {
            lines[i] = new Line(r, c, i);
            lines[i].search(board);
        }

        n = Integer.parseInt(br.readLine());
        for (int z = 0; z < n; z++) {
            col = Integer.parseInt(br.readLine()) - 1;
            drop();
        }

        for (int i = 0; i < r; i++) {
            bw.write(board[i]);
            bw.write('\n');
        }

        bw.flush();
    }

    private static void drop() {
        int end = lines[col].end;
        board[end-1][lines[col].route[end-1]] = 'O';

        for (int i = 0; i < c; i++)
            lines[i].search(board);
    }
}

class Line {
    int r, c, end;
    int[] route;
    Line(int r, int c, int i) {
        this.r = r;
        this.c = c;

        end = 1;
        route = new int[r];
        route[0] = i;
    }

    public void search(char[][] board) {
        int col;

        while (true) {
            col = route[end-1];

            if (end > 1 && board[end-1][col] != '.') {
                --end;
                continue;
            }

            if (end == r || board[end][col] == 'X')
                break;
            else if (board[end][col] == '.')
                route[end++] = col;
            else {
                if (col > 0 && board[end][col-1] == '.' && board[end-1][col-1] == '.')
                    route[end++] = col-1;
                else if (col < c-1 && board[end][col+1] == '.' && board[end-1][col+1] == '.')
                    route[end++] = col+1;
                else
                    break;
            }
        }
    }
}