#include <iostream>
#include <string>
#include <vector>

// Функция построения LPS массива
void buildLps(std::vector<int> &lps, const std::string &str) {

  if (lps.empty() && !str.size()) {
    std::cout << "Error. Was sent str = 0.";
    return;
  }

  // Добавляем новые элементы в lps
  for (int i = 0; i < str.size(); ++i)
    lps.push_back(-1);

  lps[0] = 0;

  // Построение индексов для новых символов
  int i = 1;
  int j = 0;

  while (i < str.size()) {
    if (str[i] == str[j]) {
      ++j;
      lps[i] = j;
      ++i;
    } else {
      if (j != 0)
        j = lps[j - 1];
      else {
        lps[i] = 0;
        ++i;
      }
    }
  }
}

// Функция анализа строки на кратность
void printAnalysis(const std::string &str) {

  std::vector<int> lps;
  bool flag = true;

  buildLps(lps, str);

  std::cout << std::endl;

  for (int i = 0; i < lps.size(); ++i)
    std::cout << lps[i] << ", ";
  std::cout << std::endl;

  int strLength = str.size();
  int maxSuffLength = strLength - lps[lps.size() - 1];
  int k = strLength % maxSuffLength;

  flag = (k == 0) ? true : false;

  std::string pattern = str.substr(0, maxSuffLength);

  std::cout << "Analyzing string: " << str << std::endl;
  std::cout << "Pattern string: " << pattern << std::endl;

  if (flag)
    std::cout << "K (длина подстроки, как указано в задании)=  " << pattern.size();
  else
    std::cout << "Нужной подстроки нет";

  std::cout << (flag ? ", строка кратна." : ", строка не кратна.") << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;
}

int main() {

  printAnalysis("abcabcabcabcabcabc");
  printAnalysis("ababcababc");
  printAnalysis("ababababxabababab");

  return 0;
}
