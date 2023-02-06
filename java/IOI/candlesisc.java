public static int[] distribute_candies(int[] c, int[] l, int[] r, int[] v) {
    int n = c.length;
    int[] s = new int[n];
    for (int i = 0; i < n; i++) {
        s[i] = c[i];
    }

    for (int i = 0; i < v.length; i++) {
        int left = l[i];
        int right = r[i];
        int add = v[i];
        for (int j = left; j <= right; j++) {
            s[j] = Math.min(s[j] + add, c[j]);
            s[j] = Math.max(s[j], 0);
        }
    }
    return s;
}
