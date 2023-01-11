#include <iostream>
#include <string>
using namespace std;

void LPS(string pat, int* lps)
{
    int j = 0;
    lps[0] = 0;
    int i = 1;

    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void IsKPeriodic(int K, const string& txt)
{
    if (K == 0)
    {
        cout << "K cannot be 0" << endl;
    }
    else
    {
        string pat;
        for (int i = 0; i < K; ++i)
            pat.push_back(txt[i]);

        int* lps = new int[pat.size()];

        LPS(pat, lps);

        int i = 0;
        int j = 0;
        int value = 0;

        while (i < txt.size()) {
            if (pat[j] == txt[i])
            {
                j++;
                i++;
            }
            if (j == pat.size()) {
                value++;
                j = lps[j - 1];
            }
            else if (i < txt.size() && pat[j] != txt[i]) {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i = i + 1;
                }
            }
        }
        if (K * value == txt.size())
            cout << "the string is a multiple of K" << endl;
        else
            cout << "the string is not a multiple of K" << endl;
    }
}

int main()
{
    string txt = "qweqweqwe";
    int K = 3;
    IsKPeriodic(K, txt);

    return 0;
}