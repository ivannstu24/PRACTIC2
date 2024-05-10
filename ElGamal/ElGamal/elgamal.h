#ifndef ELGAMAL_H
#define ELGAMAL_H

#include <string>
#include <vector>

int mod_pow(int base, int exp, int mod);
int mod_inverse(int a, int m);
std::vector<int> generate_keys(int p);
std::pair<int, std::vector<int>> encrypt(const std::string& plain_text, const std::vector<int>& public_key);
std::string decrypt(const std::pair<int, std::vector<int>>& ciphertext, const std::vector<int>& private_key);

#endif 

