import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class First {
    // Функция для проверки простоты числа
    public static boolean isPrime(int n) {
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
    public static int modPow(int base, int exponent, int module) {
        // Проверка на случай отрицательного значения степени
        if (exponent < 0)
            return -1; // Признак ошибки
        int result = 1;
        base %= module; // берем остаток от деления базы на модуль
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
    public static int modPowLog(int base, int exponent, int module) {
        int t = (int) (Math.log(exponent) / Math.log(2)); // Логарифм степени по основанию 2
        List<Integer> a = new ArrayList<>();
        int result = 1;
        for (int i = 1; i <= Math.pow(2, t); i *= 2) {
            a.add(modPow(base, i, module)); // Ищем ряд а, заполняем список
        }
        // Преобразуем степень в двоичное представление
        int exp2 = exponent;
        List<Integer> binaryExp = new ArrayList<>();
        while (exp2 > 0) {
            binaryExp.add(exp2 % 2);
            exp2 /= 2;
        }
        // Умножаем результаты a по соответствующим битам двоичного представления степени
        for (int i = 0; i < a.size(); i++) {
            if (binaryExp.get(i) == 1)
                result = (result * a.get(i)) % module;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введите число a: ");
        int a = scanner.nextInt();

        System.out.print("Введите степень x: ");
        int x = scanner.nextInt();

        System.out.print("Введите число b: ");
        int b = scanner.nextInt();

        System.out.print("Введите степень y: ");
        int y = scanner.nextInt();

        System.out.print("Введите модуль p: ");
        int p = scanner.nextInt();

        // Проверка на простоту модуля p
        if (!isPrime(p)) {
            System.out.println("Модуль p должен быть простым числом.");
            return;
        }

        // Проверка на теорему Ферма для a и p
        if (modPow(a, p - 1, p) != 1) {
            System.out.println("Теорема Ферма не выполняется для a и p.");
            return;
        }

        // Проверка на теорему Ферма для b и p
        if (modPow(b, p - 1, p) != 1) {
            System.out.println("Теорема Ферма не выполняется для b и p.");
            return;
        }

        // Вычисляем a^x mod p и b^y mod p
        int result1 = modPowLog(a, x, p);
        int result2 = modPowLog(b, y, p);

        // Выводим результаты и сравниваем их по модулю p
        System.out.println("Результат вычисления a^x mod p: " + result1);
        System.out.println("Результат вычисления b^y mod p: " + result2);
        if (result1 == result2)
            System.out.println("Оба результата совпадают по модулю p.");
        else
            System.out.println("Результаты по модулю p не совпадают.");
    }
}
