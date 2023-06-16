#include <iostream>
#include <fstream>

void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key)
{
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    char keyByte = key[0];
    char inputByte;

    while (inFile.read(&inputByte, sizeof(inputByte))) {
        char encryptedByte = inputByte ^ keyByte;
        outFile.write(&encryptedByte, sizeof(encryptedByte));
    }

    outFile.close();
    inFile.close();

    std::cout << "Encryption completed. Encrypted file: " << outputFile << std::endl;
}

void decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key)
{
    encryptFile(inputFile, outputFile, key); // XOR encryption and decryption are the same

    std::cout << "Decryption completed. Decrypted file: " << outputFile << std::endl;
}

int main()
{
    std::string inputFile = "input.txt";
    std::string encryptedFile = "encrypted.bin";
    std::string decryptedFile = "decrypted.txt";
    std::string key = "secretkey";

    encryptFile(inputFile, encryptedFile, key);
    decryptFile(encryptedFile, decryptedFile, key);

    return 0;
}