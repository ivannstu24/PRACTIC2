//// Задание 3
//#include <iostream>
//
//// Функция, вычисляющая НОД(a, b) и одновременно находящая коэффициенты x и y
//int extendedEuclidean(int a, int b, int &x_coefficient, int &y_coefficient) {
//    if (b == 0) {
//        x_coefficient = 1;
//        y_coefficient = 0;
//        return a;
//    }
//
//    int previous_x_coefficient, previous_y_coefficient;
//    int gcd = extendedEuclidean(b, a % b, previous_x_coefficient, previous_y_coefficient);
//
//    x_coefficient = previous_y_coefficient;
//    y_coefficient = previous_x_coefficient - (a / b) * previous_y_coefficient;
//
//    return gcd;
//}
//
//// Функция для нахождения обратного элемента по модулю
//int modInverse(int number, int modulo) {
//    int x_coefficient, y_coefficient;
//    int gcd = extendedEuclidean(number, modulo, x_coefficient, y_coefficient);
//
//    if (gcd != 1) {
//        std::cout << "inverse element does not exist!\n";
//        return -1;
//    } else {
//        return (x_coefficient % modulo + modulo) % modulo;
//    }
//}
//
//int main() {
//    int number, modulo;
//    std::cout << "Enter number and modulus: ";
//    std::cin >> number >> modulo;
//
//    int inverse = modInverse(number, modulo);
//    if (inverse != -1)
//        std::cout << "inverse element for " << number << " modulo " << modulo << " is: " << inverse << std::endl;
//
//    return 0;
//}
