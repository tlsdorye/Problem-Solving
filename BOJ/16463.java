import java.util.*;

public class Main {

    static int D = 1;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Calendar time = Calendar.getInstance();
        time.set(2019, 0, 4);
        int year = 2019, month = 0, day = 4;
        int ANS = 0;
        while (time.getWeekYear() <= N) {
            if (time.DATE == 5 && time.getTime().getDate() == 13)
                ANS++;
            time.set(year, month, day+=7);
        }
        System.out.println(ANS);
    }
}