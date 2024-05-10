// Вариант Эль-Гамаля
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

// Вспомогательная функция для возведения числа в степень по модулю
int mod_pow(int base, int exp, int mod) {
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
int mod_inverse(int a, int m) {
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

// Функция для генерации ключей
vector<int> generate_keys(int p) {
    mt19937 rng(time(NULL));
    int g = 2;
    int x = rng() % (p - 1) + 1;
    int y = mod_pow(g, x, p);
    return vector<int>{g, p, y, x};
}

// Функция для шифрования
pair<int, vector<int>> encrypt(const string& plain_text, const vector<int>& public_key) {
    int g = public_key[0], p = public_key[1], y = public_key[2];
    mt19937 rng(time(NULL));
    int k = rng() % (p - 2) + 1; // Выбор случайного числа k
    int c1 = mod_pow(g, k, p);
    vector<int> c2;

    for (char ch : plain_text) {
        int m = static_cast<int>(ch); //  UNICOD
        int c2_val = (m * mod_pow(y, k, p)) % p;
        c2.push_back(c2_val);
    }

    return make_pair(c1, c2); // части шифротекста
}

// Функция для дешифрования
string decrypt(const pair<int, vector<int>>& ciphertext, const vector<int>& private_key) {
    int c1 = ciphertext.first;
    const vector<int>& c2 = ciphertext.second;
    int p = private_key[1], x = private_key[3];
    string decrypted_text;

    int s = mod_pow(c1, x, p);
    int s_inverse = mod_inverse(s, p);

    for (int enc_char : c2) {
        int m = (enc_char * s_inverse) % p;
        decrypted_text.push_back(static_cast<char>(m));
    }

    return decrypted_text;
}

int main() {
    int prime_p = 2087; // Большее простое число для демонстрации
    vector<int> alice_keys = generate_keys(prime_p);
    vector<int> bob_keys = generate_keys(prime_p);

    string alice_message = "Русский"; // Сообщение от Алисы к Бобу
    cout << "Исходное сообщение Алисы: " << alice_message << endl;

    auto encrypted_message = encrypt(alice_message, bob_keys); // Алиса шифрует сообщение для Боба
    cout << "Зашифрованное сообщение для Боба: ";
    for (int num : encrypted_message.second) {
        cout << num << " ";
    }
    cout << endl;

    string bob_decrypted_message = decrypt(encrypted_message, bob_keys); // Боб расшифровывает сообщение
    cout << "Боб расшифровал сообщение: " << bob_decrypted_message << endl;

    return 0;
}
