#include"isKPeriodic.h"
#include <string>
using namespace std;
void schik(string stroka, int* poi)
{
    int j = 0, i = 1;
    while (i < stroka.size())
    {
        if (stroka[i] == stroka[j])
        {
            j++;
            poi[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = poi[j - 1];
            }
            else
            {
                poi[i] = 0;
                i++;
            }
        }
    }
}
bool isKPeriodic(const string& txt, int k) 
{
    setlocale(LC_ALL, "");
    if (k <= 0) 
    {
        cout<< "строка не может быть <= 0" << k << endl << endl;
       
        return false;
    }
    string siz;
    for (int i = 0; i < k; i++)
        siz += txt[i];
    int* ket = new int[siz.size()];
   schik(siz, ket);
    int c = 0, i = 0,j = 0;
    while (i < txt.size())
    {
        if (siz[j] == txt[i]) 
        {
            i++;
            j++;
        }
        if (j == siz.size())
        {
            if (j % k == 0 && i % k == 0)
            {
                c++;
            }
            j = ket[j - 1];
        }
        if (i < txt.size() && siz[j] != txt[i]) 
        {
            if (j != 0) 
            {
                j = ket[j - 1];
            }
            else 
            {
                i = i + 1;
            }
        }
    }
    if (k * c == txt.size() && k != txt.size())
    {
        cout << txt << endl;
        cout << "строка кратна числу " << k << endl << endl;
        return true;
    }
    else 
    {
        cout << txt << endl;
        cout << "строка не кратна числу " << k << endl << endl;
        return false;
    }
}