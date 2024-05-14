/*#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

// Функция для хеширования пароля с помощью SHA-256
std::string hashPassword(const std::string& password) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, password.c_str(), password.length());
    SHA256_Final(digest, &ctx);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return ss.str();
}

int main() {
    // Ваш пароль
    std::string password = "mypassword";

    // Получаем хеш пароля
    std::string hashedPassword = hashPassword(password);

    // Выводим хеш пароля
    std::cout << "Hashed password: " << hashedPassword << std::endl;

    return 0;
}
*/