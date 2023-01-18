#include <iostream>

int Encryption()
{
    char c;
    char m;
    std::cin >> m;
    c = m + 2 * 2;
    std::cout << c << std::endl;
    return 0;
}

int Decryption()
{
    char c;
    char m;
    std::cin >> c;
    m = c - 2 * 2;
    std::cout << m << std::endl;  
    return 0; 
}

int main()
{
    Encryption();
    Decryption();
    return 0;
}