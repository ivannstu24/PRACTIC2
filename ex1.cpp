#include <iostream>
 #include <vector>
 #include <cmath>

 using namespace std;

 // Функция для проверки простоты числа
 bool isPrime(int n) {
     if (n <= 1) return false;
     if (n <= 3) return true;
     if (n % 2 == 0 || n % 3 == 0) return false;
     for (int i = 5; i * i <= n; i += 6) {
         if (n % i == 0 || n % (i + 2) == 0)
             return false;
     }
     return true;
 }

 // Функция для вычисления a^x mod p
 int modPow(int base, int exponent, int module) {
     // Проверка на случай отрицательного значения степени
     if (exponent < 0)
         return -1; // Признак ошибки
     int result = 1;
     base %= module; //  берем остаток от деления базы на модуль
     while (exponent > 0) {
         // Если степень нечетная, умножаем результат на базу по модулю
         if (exponent % 2 == 1)
             result = (result * base) % module;
         // Берем квадрат базы и обновляем степень
         base = (base * base) % module;
         exponent /= 2;
     }
     return result;
 }

 // Функция для вычисления a^x mod p через логарифмический метод
 int modPowLog(int base, int exponent, int module) {
     int t = log2(exponent); // Логарифм степени по основанию 2
     vector<int> a;
     int result = 1;
     for (int i = 1; i <= pow(2, t); i *= 2) {
         a.push_back(modPow(base, i, module)); // Ищем ряд а, заполняем вектор
     }
     // Преобразуем степень в двоичное представление
     int exp2 = exponent;
     vector<int> binaryExp;
     while (exp2 > 0) {
         binaryExp.push_back(exp2 % 2);
         exp2 /= 2;
     }
     // Умножаем результаты a по соответствующим битам двоичного представления степени
     for (int i = 0; i < a.size(); i++) {
         if (binaryExp[i] == 1)
             result = (result * a[i]) % module;
     }
     return result;
 }

 int main() {
     int a = 3; // база для первой операции
     int x = 100; // степень для первой операции
     int b = 5; // база для второй операции
     int y = 2; // степень для второй операции
     int p = 7; // модуль

     // Проверка на простоту модуля p
     if (!isPrime(p)) {
         cout << "Модуль p должен быть простым числом." << endl;
         return 1;
     }

     // Проверка на теорему Ферма для a и p
     if (modPow(a, p - 1, p) != 1) {
         cout << "Теорема Ферма не выполняется для a и p." << endl;
         return 1;
     }

     // Проверка на теорему Ферма для b и p
     if (modPow(b, p - 1, p) != 1) {
         cout << "Теорема Ферма не выполняется для b и p." << endl;
         return 1;
     }

     // Вычисляем a^x mod p и b^y mod p
     int result1 = modPowLog(a, x, p);
     int result2 = modPowLog(b, y, p);

     // Выводим результаты и сравниваем их по модулю p
     cout << "Результат вычисления a^x mod p: " << result1 << endl;
     cout << "Результат вычисления b^y mod p: " << result2 << endl;
     if (result1 == result2)
         cout << "Оба результата совпадают по модулю p." << endl;
     else
         cout << "Результаты по модулю p не совпадают." << endl;

     return 0;
 }

