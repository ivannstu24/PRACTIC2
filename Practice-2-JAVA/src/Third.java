import java.util.Scanner;

public class Third {

    // Метод, вычисляющий НОД(a, b) и одновременно находящий коэффициенты x и y
    public static int extendedEuclidean(int a, int b, int[] coefficients) {
        if (b == 0) {
            coefficients[0] = 1;
            coefficients[1] = 0;
            return a;
        }

        int[] previousCoefficients = new int[2];
        int gcd = extendedEuclidean(b, a % b, previousCoefficients);

        coefficients[0] = previousCoefficients[1];
        coefficients[1] = previousCoefficients[0] - (a / b) * previousCoefficients[1];

        return gcd;
    }

    // Метод для нахождения обратного элемента по модулю
    public static int modInverse(int number, int modulo) {
        int[] coefficients = new int[2];
        int gcd = extendedEuclidean(number, modulo, coefficients);

        if (gcd != 1) {
            System.out.println("inverse element does not exist!");
            return -1;
        } else {
            return (coefficients[0] % modulo + modulo) % modulo;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number and modulus: ");
        int number = scanner.nextInt();
        int modulo = scanner.nextInt();

        int inverse = modInverse(number, modulo);
        if (inverse != -1)
            System.out.println("inverse element for " + number + " modulo " + modulo + " is: " + inverse);
    }
}
