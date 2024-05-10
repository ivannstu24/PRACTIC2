////Задание 5
//
//#include <iostream>
//#include <cmath>
//
//// Функция для быстрого возведения в степень по модулю
//int modExp(int base, int exp, int mod) {
//    int result = 1;
//    while (exp > 0) {
//        if (exp % 2 == 1) { // Если степень нечетная
//            result = (result * base) % mod;
//        }
//        base = (base * base) % mod; // Возводим основание в квадрат
//        exp /= 2; // Делим степень на 2
//    }
//    return result;
//}
//
//int main() {
//    int a = 1;
//    int b = 1;
//    int c = 1;
//    
//
//    std::cout << "enter values a, b, c: ";
//    std::cin >> a >> b >> c;
//
//    // для нахождения последней цифры a^(b^c) достаточно найти b^c по модулю 4,
//    // а затем a^(b^c mod 4) по модулю 10, сделаем это
//    int exp_mod_4 = modExp(b, c, 4);
//    int last_digit = modExp(a, exp_mod_4, 10);
//
//    std::cout << "Last digit of the number " << a << "^(" << b << "^" << c << ") is " << last_digit << std::endl;
//
//    return 0;
//}


