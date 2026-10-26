/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void go(char **ans, int *cnt, char *buf, int n, int pos, int o, int c) {
    if (o == n && c == n) {
        buf[pos] = '\0';
        ans[*cnt] = malloc(pos + 1);
        strcpy(ans[*cnt], buf);
        (*cnt)++;
        return;
    }
    if (o < n) {
        buf[pos] = '(';
        go(ans, cnt, buf, n, pos + 1, o + 1, c);
    }
    if (c < o) {
        buf[pos] = ')';
        go(ans, cnt, buf, n, pos + 1, o, c + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char **ans = malloc(1500 * sizeof(char *));
    char buf[20];
    int cnt = 0;
    go(ans, &cnt, buf, n, 0, 0, 0);
    *returnSize = cnt;
    return ans;
}