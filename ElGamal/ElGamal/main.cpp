#include "elgamal.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


int main() {
    int prime_p = 2087;
    std::vector<int> alice_keys = generate_keys(prime_p);
    std::vector<int> bob_keys = generate_keys(prime_p);
    
    
    
    std::ifstream inputFile("/Users/ivanmerzov/Desktop/ElGamal/ElGamal/file.txt"); 
        if (!inputFile.is_open()) {
            std::cerr << "Не удалось открыть файл!" << std::endl;
            return 1;
        }

        std::string alice_message;
        std::getline(inputFile, alice_message);

        inputFile.close();
    
    
    
    
    
    std::cout << "Исходное сообщение Алисы: " << alice_message << std::endl;

    auto encrypted_message = encrypt(alice_message, bob_keys);
    std::cout << "Зашифрованное сообщение для Боба: ";
    for (int num : encrypted_message.second) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::string bob_decrypted_message = decrypt(encrypted_message, bob_keys);
    std::cout << "Боб расшифровал сообщение: " << bob_decrypted_message << std::endl;

    return 0;
    
    
    
}

