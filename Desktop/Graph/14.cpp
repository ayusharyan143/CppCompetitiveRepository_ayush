// Knuth-Morris-Pratt (KMP) Algorithm

#include <bits/stdc++.h>

using namespace std;

void computeLSPArray(string p, int m, vector<int> &lps)
{
    int length = 0;

    lps[0] = 0;
    int i = 1;

    while (i < m)
    {
        if (p[i] == p[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string t, string p)
{
    int n = t.size();
    int m = p.size();

    vector<int> lps(m);

    computeLSPArray(p, m, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (p[j] == t[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            cout << "Pattern Found at Index : " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && p[j] != t[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMPSearch(text, pattern);
}