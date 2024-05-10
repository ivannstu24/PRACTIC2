import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class ElGamal {

    // Вспомогательная функция для возведения числа в степень по модулю
    public static int modPow(int base, int exp, int mod) {
        int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // Функция для нахождения обратного элемента в кольце вычетов по модулю m
    public static int modInverse(int a, int m) {
        int m0 = m, y = 0, x = 1;
        if (m == 1) return 0;
        while (a > 1) {
            int q = a / m;
            int t = m;
            m = a % m; a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0) x += m0;
        return x;
    }

    // Функция для генерации ключей
    public static List<Integer> generateKeys(int p) {
        Random rng = new Random();
        int g = 2; // Первообразный корень для больших простых чисел, можно использовать другие методы нахождения
        int x = rng.nextInt(p - 1) + 1;
        int y = modPow(g, x, p);
        return List.of(g, p, y, x);
    }

    // Функция для шифрования
    public static AbstractMap.SimpleEntry<Integer, List<Integer>> encrypt(String plainText, List<Integer> publicKey) {
        int g = publicKey.get(0), p = publicKey.get(1), y = publicKey.get(2);
        Random rng = new Random();
        int k = rng.nextInt(p - 2) + 1; // Выбор случайного числа k
        int c1 = modPow(g, k, p);
        List<Integer> c2 = new ArrayList<>();

        for (char ch : plainText.toCharArray()) {
            int m = (int) ch;
            int c2Val = (m * modPow(y, k, p)) % p;
            c2.add(c2Val);
        }

        return new AbstractMap.SimpleEntry<>(c1, c2);
    }

    // Функция для дешифрования
    public static String decrypt(AbstractMap.SimpleEntry<Integer, List<Integer>> ciphertext, List<Integer> privateKey) {
        int c1 = ciphertext.getKey();
        List<Integer> c2 = ciphertext.getValue();
        int p = privateKey.get(1), x = privateKey.get(3);
        StringBuilder decryptedText = new StringBuilder();

        int s = modPow(c1, x, p);
        int sInverse = modInverse(s, p);

        for (int encChar : c2) {
            int m = (encChar * sInverse) % p;
            decryptedText.append((char) m);
        }

        return decryptedText.toString();
    }

    public static void main(String[] args) {
        int primeP = 2087; // Большее простое число для демонстрации
        List<Integer> aliceKeys = generateKeys(primeP);
        List<Integer> bobKeys = generateKeys(primeP);

        String aliceMessage = "Hello Bob"; // Сообщение от Алисы к Бобу
        System.out.println("Исходное сообщение Алисы: " + aliceMessage);

        AbstractMap.SimpleEntry<Integer, List<Integer>> encryptedMessage = encrypt(aliceMessage, bobKeys); // Алиса шифрует сообщение для Боба
        System.out.print("Зашифрованное сообщение для Боба: ");
        for (int num : encryptedMessage.getValue()) {
            System.out.print(num + " ");
        }
        System.out.println();

        String bobDecryptedMessage = decrypt(encryptedMessage, bobKeys); // Боб расшифровывает сообщение
        System.out.println("Боб расшифровал сообщение: " + bobDecryptedMessage);
    }
}
