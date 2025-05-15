#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Построение массива LPS (Longest Prefix Suffix).
 *
 * Массив LPS показывает длину максимального префикса,
 * который одновременно является суффиксом для подстроки,
 * заканчивающейся на текущем символе.
 *
 * @param lps Вектор, куда записывается построенный LPS-массив.
 * @param str Исходная строка для анализа.
 */
void buildLps(std::vector<int> &lps, const std::string &str) {

  // Проверка на пустую строку и пустой вектор.
  if (lps.empty() && !str.size()) {
    std::cout << "Error. Was sent str = 0.";
    return;
  }

  // Инициализация массива LPS значениями -1
  for (int i = 0; i < str.size(); ++i)
    lps.push_back(-1);

  lps[0] = 0; // Первое значение всегда 0.

  // Индексы для прохода по строке
  int i = 1;
  int j = 0;

  // Цикл построения массива LPS
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

/**
 * @brief Анализирует входную строку на периодичность.
 *
 * Функция выводит LPS-массив, анализируемую строку,
 * найденный минимальный повторяющийся шаблон (если есть),
 * и выводит длину этого шаблона как K.
 *
 * @param str Анализируемая строка.
 */
void printAnalysis(const std::string &str) {

  std::vector<int> lps;
  bool flag = true;

  buildLps(lps, str);

  // Вывод полученного LPS-массива
  std::cout << std::endl;
  for (int i = 0; i < lps.size(); ++i)
    std::cout << lps[i] << ", ";
  std::cout << std::endl;

  // Анализ периодичности строки на основе LPS-массива
  int strLength = str.size();
  int maxSuffLength = strLength - lps[lps.size() - 1];
  int k = strLength % maxSuffLength;

  flag = (k == 0) ? true : false;

  std::string pattern = str.substr(0, maxSuffLength);

  // Вывод результатов анализа
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

/**
 * @brief Точка входа в программу.
 *
 * Запускает функцию анализа строк с несколькими примерами.
 */
int main() {

  printAnalysis("abcabcabcabcabcabc");
  printAnalysis("ababcababc");
  printAnalysis("ababababxabababab");

  return 0;
}
