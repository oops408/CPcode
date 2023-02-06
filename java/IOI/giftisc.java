import java.util.*;

public class Main {
    static int[] color;

    public static void craft(int pos, int c) {
        color[pos] = c;
    }

    public static int construct(int n, int r, int[] a, int[] b, int[] x) {
        color = new int[n + 1];
        Arrays.fill(color, -1);
        for (int i = 0; i < r; i++) {
            int cnt = 0;
            for (int j = a[i]; j <= b[i]; j++) {
                if (color[j] == -1) {
                    cnt++;
                }
            }
            if (cnt < x[i]) {
                return -1;
            }
            cnt = 0;
            for (int j = a[i]; j <= b[i]; j++) {
                if (color[j] == -1) {
                    cnt++;
                    if (cnt <= x[i] / 2) {
                        craft(j, 0);
                    } else {
                        craft(j, 1);
                    }
                }
            }
        }
        return 1;
    }
}
