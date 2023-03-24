#include "isKPeriodic.h"

int main() 
{

    isKPeriodic("abcabcabcabcabcabc", 9);
    isKPeriodic("abcabcabcabcabcabc", 3);
    isKPeriodic("abcabcabcabcabcabc", 4);
    isKPeriodic("abcabcabcabcabcabc", 0);


    return 0;
}