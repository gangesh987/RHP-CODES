import java.util.*;

class Sofa {
    int fsr, fsc, ssr, ssc;
    char dir;
    int moves;

    public Sofa(int fsr, int fsc, int ssr, int ssc, char d, int m) {
        this.fsr = fsr;
        this.fsc = fsc;
        this.ssr = ssr;
        this.ssc = ssc;
        this.dir = d;
        this.moves = m;
    }
}

public class Main {
    static final String DELIM = "-";

    private static boolean canAdd(int fsr, int fsc, int ssr, int ssc,
                                  Set<String> vis) {
        StringBuilder sb = new StringBuilder();
        sb.append(fsr).append(DELIM).append(fsc).append(DELIM);
        sb.append(ssr).append(DELIM).append(ssc);

        String key = sb.toString();

        if (vis.contains(key)) {
            return false;
        }

        vis.add(key);
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int R = sc.nextInt();
        int C = sc.nextInt();

        char[][] grid = new char[R][C];

        int fsr = -1, fsc = -1, ssr = -1, ssc = -1;
        int sofacount = 0;

        Queue<Sofa> q = new LinkedList<>();
        Set<String> vis = new HashSet<>();

        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                char ch = sc.next().charAt(0);
                grid[row][col] = ch;

                if (ch == 's') {
                    sofacount++;

                    if (sofacount == 1) {
                        fsr = row;
                        fsc = col;
                    } else {
                        ssr = row;
                        ssc = col;
                    }
                }
            }
        }

        Sofa start = new Sofa(
            fsr, fsc, ssr, ssc,
            (fsr == ssr) ? 'H' : 'V', 0
        );

        q.add(start);
        canAdd(fsr, fsc, ssr, ssc, vis);

        while (!q.isEmpty()) {
            Sofa s = q.poll();

            if (grid[s.fsr][s.fsc] == 'S' &&
                grid[s.ssr][s.ssc] == 'S') {
                System.out.println(s.moves);
                sc.close();
                return;
            }

            if (s.fsc + 1 < C && s.ssc + 1 < C &&
                grid[s.fsr][s.fsc + 1] != 'H' &&
                grid[s.ssr][s.ssc + 1] != 'H') {

                if (canAdd(s.fsr, s.fsc + 1,
                           s.ssr, s.ssc + 1, vis)) {
                    q.add(new Sofa(
                        s.fsr, s.fsc + 1,
                        s.ssr, s.ssc + 1,
                        s.dir, s.moves + 1
                    ));
                }
            }

            if (s.fsc > 0 && s.ssc > 0 &&
                grid[s.fsr][s.fsc - 1] != 'H' &&
                grid[s.ssr][s.ssc - 1] != 'H') {

                if (canAdd(s.fsr, s.fsc - 1,
                           s.ssr, s.ssc - 1, vis)) {
                    q.add(new Sofa(
                        s.fsr, s.fsc - 1,
                        s.ssr, s.ssc - 1,
                        s.dir, s.moves + 1
                    ));
                }
            }

            if (s.fsr > 0 && s.ssr > 0 &&
                grid[s.fsr - 1][s.fsc] != 'H' &&
                grid[s.ssr - 1][s.ssc] != 'H') {

                if (canAdd(s.fsr - 1, s.fsc,
                           s.ssr - 1, s.ssc, vis)) {
                    q.add(new Sofa(
                        s.fsr - 1, s.fsc,
                        s.ssr - 1, s.ssc,
                        s.dir, s.moves + 1
                    ));
                }
            }

            if (s.fsr + 1 < R && s.ssr + 1 < R &&
                grid[s.fsr + 1][s.fsc] != 'H' &&
                grid[s.ssr + 1][s.ssc] != 'H') {

                if (canAdd(s.fsr + 1, s.fsc,
                           s.ssr + 1, s.ssc, vis)) {
                    q.add(new Sofa(
                        s.fsr + 1, s.fsc,
                        s.ssr + 1, s.ssc,
                        s.dir, s.moves + 1
                    ));
                }
            }

            if (s.dir == 'H') {
                int row = s.fsr;
                int col = Math.min(s.fsc, s.ssc);

                if (row + 1 < R &&
                    grid[row + 1][col] != 'H' &&
                    grid[row + 1][col + 1] != 'H') {

                    if (canAdd(row, col, row + 1, col, vis)) {
                        q.add(new Sofa(
                            row, col, row + 1, col,
                            'V', s.moves + 1
                        ));
                    }

                    if (canAdd(row, col + 1,
                               row + 1, col + 1, vis)) {
                        q.add(new Sofa(
                            row, col + 1, row + 1, col + 1,
                            'V', s.moves + 1
                        ));
                    }
                }

                if (row > 0 &&
                    grid[row - 1][col] != 'H' &&
                    grid[row - 1][col + 1] != 'H') {

                    if (canAdd(row - 1, col, row, col, vis)) {
                        q.add(new Sofa(
                            row - 1, col, row, col,
                            'V', s.moves + 1
                        ));
                    }

                    if (canAdd(row - 1, col + 1,
                               row, col + 1, vis)) {
                        q.add(new Sofa(
                            row - 1, col + 1, row, col + 1,
                            'V', s.moves + 1
                        ));
                    }
                }
            } else {
                int row = Math.min(s.fsr, s.ssr);
                int col = s.fsc;

                if (col + 1 < C &&
                    grid[row][col + 1] != 'H' &&
                    grid[row + 1][col + 1] != 'H') {

                    if (canAdd(row, col, row, col + 1, vis)) {
                        q.add(new Sofa(
                            row, col, row, col + 1,
                            'H', s.moves + 1
                        ));
                    }

                    if (canAdd(row + 1, col,
                               row + 1, col + 1, vis)) {
                        q.add(new Sofa(
                            row + 1, col, row + 1, col + 1,
                            'H', s.moves + 1
                        ));
                    }
                }

                if (col > 0 &&
                    grid[row][col - 1] != 'H' &&
                    grid[row + 1][col - 1] != 'H') {

                    if (canAdd(row, col - 1, row, col, vis)) {
                        q.add(new Sofa(
                            row, col - 1, row, col,
                            'H', s.moves + 1
                        ));
                    }

                    if (canAdd(row + 1, col - 1,
                               row + 1, col, vis)) {
                        q.add(new Sofa(
                            row + 1, col - 1, row + 1, col,
                            'H', s.moves + 1
                        ));
                    }
                }
            }
        }

        System.out.println("Impossible");
        sc.close();
    }
}