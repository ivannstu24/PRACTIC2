import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Second {
    // Функция для расширенного алгоритма Евклида
    public static int gcdExtended(int a, int b, int[] x, int[] y, List<int[]> table) {
        if (a == 0) {
            x[0] = 0;
            y[0] = 1;
            table.add(new int[]{a, b, x[0], y[0], b}); // Сохраняем промежуточное состояние в таблицу
            return b;
        }

        int[] xPrevious = new int[1];
        int[] yPrevious = new int[1];
        int gcd = gcdExtended(b % a, a, xPrevious, yPrevious, table);

        x[0] = yPrevious[0] - (b / a) * xPrevious[0];
        y[0] = xPrevious[0];

        table.add(new int[]{a, b, x[0], y[0], gcd}); // Сохраняем промежуточное состояние в таблицу

        return gcd;
    }

    // для вычисления обратного элемента
    public static int modInverse(int c, int m) {
        int[] x = new int[1];
        int[] y = new int[1];
        List<int[]> table = new ArrayList<>(); // Таблица для сохранения состояний
        int g = gcdExtended(c, m, x, y, table);
        if (g != 1) {
            System.out.println("Обратный элемент не существует");
            return -1;
        }

        // Вывод таблицы
        System.out.println("Таблица по расширенному алгоритму:");
        System.out.println("a\tb\tx\ty\tgcd");
        for (int[] row : table) {
            System.out.println(row[0] + "\t" + row[1] + "\t" + row[2] + "\t" + row[3] + "\t" + row[4]);
        }

        return (x[0] % m + m) % m;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("число c: ");
        int c = scanner.nextInt();
        System.out.print("модуль m: ");
        int m = scanner.nextInt();

        int d = modInverse(c, m);
        if (d != -1) {
            System.out.println("Обратный элемент d: " + d);
        }
    }
}
