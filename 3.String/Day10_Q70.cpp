// Search Pattern

#include <iostream>
#include <string>
using namespace std;

void search(string txt, string pat)
{
    int n = txt.length(), m = pat.length();
    int i{0};
    while (i < n)
    {
        if (pat[0] == txt[i])
        {
            int temp = 0;
            for (int k = 0, l = i; k < m; k++, l++)
            {
                if (pat[k] == txt[l])
                {
                    temp++;
                }
                else
                {
                    break;
                }
            }
            if (temp == m)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }
        i++;
        // cout << "i value" << i << endl;
    }
}

int main()
{
    // string txt = "THIS IS A TEST TEXT";
    // string pat = "TEST";
    // string txt = "AABAACAADAABAABA";
    // string pat = "AABA";
    string txt = "batmanandrobinarebat";
    string pat = "bat";

    search(txt, pat);

    return 0;
}