char* removeDuplicateLetters(char* s) {
    int freq[26] = {0}, vis[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; ++i)
        freq[s[i] - 'a']++;

    char* res = (char*)malloc((n + 1) * sizeof(char));
    int resIndex = 0;

    for (int i = 0; i < n; ++i) {
        freq[s[i] - 'a']--;

        if (!vis[s[i] - 'a']) {
            while (resIndex > 0 && res[resIndex - 1] > s[i] && freq[res[resIndex - 1] - 'a'] > 0) {
                vis[res[resIndex - 1] - 'a'] = 0;
                resIndex--;
            }

            vis[s[i] - 'a'] = 1;
            res[resIndex++] = s[i];
        }
    }

    res[resIndex] = '\0';
    return res;
}
