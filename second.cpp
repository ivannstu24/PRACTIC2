//#include <iostream>
//#include <vector>
//
//// Функция для расширенного алгоритма Евклида
//int gcdExtended(int a, int b, int& x, int& y, std::vector<std::vector<int>>& table) {
//    if (a == 0) {
//        x = 0;
//        y = 1;
//        table.push_back({a, b, x, y, b}); // Сохраняем промежуточное состояние в таблицу
//        return b;
//    }
//
//    int prev_x, prev_y;
//    int gcd = gcdExtended(b % a, a, prev_x, prev_y, table);
//
//    x = prev_y - (b / a) * prev_x;
//    y = prev_x;
//
//    table.push_back({a, b, x, y, gcd}); // Сохраняем промежуточное состояние в таблицу
//
//    return gcd;
//}
//
//// для вычисления обратного элемента
//int modInverse(int c, int m) {
//    int x, y;
//    std::vector<std::vector<int>> table; // Таблица для сохранения состояний
//    int g = gcdExtended(c, m, x, y, table);
//    if (g != 1) {
//        std::cout << "Обратный элемент не существует" << std::endl;
//        return -1;
//    }
//
//    // Вывод таблицы
//    std::cout << "Таблица по расширенному алгоритму:" << std::endl;
//    std::cout << "a\tb\tx\ty\tgcd" << std::endl;
//    for (const auto& row : table) {
//        std::cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << "\t" << row[4] << std::endl;
//    }
//
//    return (x % m + m) % m;
//}
//
//int main() {
//    int c, m;
//    std::cout << "Введите число c: ";
//    std::cin >> c;
//    std::cout << "Введите модуль m: ";
//    std::cin >> m;
//
//    int d = modInverse(c, m);
//    if (d != -1) {
//        std::cout << "Обратный элемент d: " << d << std::endl;
//    }
//
//    return 0;
//}
//
