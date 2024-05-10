import java.util.Scanner;

public class Fifth {

    // Метод для быстрого возведения в степень по модулю
    static int modExp(int base, int exp, int mod) {
        int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) { // Если степень нечетная
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Возводим основание в квадрат
            exp /= 2; // Делим степень на 2
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int a, b, c;

        System.out.print("Enter values a, b, c: ");
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Поскольку для нахождения последней цифры a^(b^c) достаточно найти b^c по модулю 4,
        // затем a^(b^c mod 4) по модулю 10
        int exp_mod_4 = modExp(b, c, 4);
        int lastDigit = modExp(a, exp_mod_4, 10);

        System.out.println("Last digit of the number " + a + "^(" + b + "^" + c + ") is " + lastDigit);
    }
}
