#include <iostream>
#include <string>

void computeLPS(std::string pat, int* lps) //compute lps for algorythm
{
    int j = 0;

    lps[0] = 0; // lps[0] is always 0

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

int KMPSearch(const std::string& pat, std::string& txt) //count number of found patterns
{
    int * lps = new int[pat.size()];
    computeLPS(pat, lps);

    int i = 0;
    int j = 0;
    int periodicy = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size()) {
            //std::cout << "Found pattern at index " << i - j << std::endl;
            periodicy++;
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
    return periodicy;
}

//check if string periodic to k
//we'll use KMP-algorythm

bool IsKPeriodic(std::string periodic_string, int k){
  int len = periodic_string.size();
  int substr_len = len / k;
  char substring[substr_len] = {};
  for (int i = 0; i < substr_len; i++){
    substring[i] = periodic_string[i];
  }

  std::string substr = std::string(substring, substr_len);

  if (KMPSearch(substr, periodic_string) == (len / substr_len)){
    return true;
  } else {
    return false;
  }
}

int main(){
  std::string txt = "avaavaavaavaava";
  std::string pat = "ava";
  std::cout << "Real KMP search: " << KMPSearch(pat, txt) << std::endl;
  std::cout << IsKPeriodic(txt, 5) << std::endl;
  return 0;
}
