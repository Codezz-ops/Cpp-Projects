#include <iostream>
#include <cmath>

void Halflife()
{   
    float N, N_o, halflife, val, ans;
    std::cout << "Enter ending value: ";
    std::cin >> N;
    std::cout << "Enter starting value: ";
    std::cin >> N_o;
    std::cout << "Enter halflife: ";
    std::cin >> halflife;
    val = N/N_o;
    ans = halflife * log(val)/log(.5);
    std::cout << "It will take " << ans << " cents, years, weeks, days, mins, secs, millsecs... amount of time to decay this isotope";
}

int main()
{
    Halflife();
    return 0;
}
