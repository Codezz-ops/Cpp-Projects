#include <iostream>

int Encryption()
{
    std::string c, m;
    std::cin >> m;
    c = m + 2 * 2;
    std::cout << c << std::endl;
    return 0;
}

int Decryption()
{
    std::string c, m;
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
