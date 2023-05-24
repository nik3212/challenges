/*

Implement strstr

Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Note: You are not allowed to use inbuilt function.

*/

int hash_init(int str_len, int d, int q) {
    int h = 1;

    for (int i = 0; i < str_len - 1; ++i) {
        h = (h * d) % q;
    }

    return h;
}

int ring_hash(char const *s, int str_len, int prev_hash) {
    int h = 52;
    int q = 65713;

    int p = hash_init(str_len, h, q);

    if (prev_hash == 0) {
        for (int i = 0; i < str_len; ++i) {
            prev_hash = (prev_hash * h + (int)s[i]) % q;
        }
        return prev_hash;
    }

    int hash = (h * (prev_hash - (int)s[0] * p) + (int)s[str_len]) % q;

    if (hash < 0) {
        hash += q;
    }

    return hash;
}

int rabin_karp(char const *s, char const *t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    
    int s_hash = ring_hash(s, t_len, 0);
    int t_hash = ring_hash(t, t_len, 0);
    
    for (int i = 0; i <= (s_len - t_len); ++i) {
        if (s_hash == t_hash) {
            for (int j = 0; (j < t_len) && (t[j] == s[i + j]); ++j) {
                if (j == t_len - 1) {
                    return i;
                }
            }
        }
        
        s_hash = ring_hash(&s[i], t_len, s_hash);
    }
    
    return -1;
}

//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x) {
     return rabin_karp(s.c_str(), x.c_str());
}