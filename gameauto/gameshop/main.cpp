#include "gameshop.hpp"

using namespace std;
int main()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t); //http://cplusplus.com/forum/beginner/32329/

    int releaseJaar1 = timePtr->tm_year + 1900 - 1;
    int releaseJaar2 = timePtr->tm_year + 1900 - 2;

    Game g1 = {"Just Cause 3", releaseJaar1, 49.98};
    Game g2 = {"Need for Speed: Rivals", releaseJaar2, 45.99};
    Game g3 = {"Need for Speed: Rivals", releaseJaar2, 45.99};

    Persoon p1 = {"Eric", 200};
    Persoon p2 = {"Hans", 55};
    Persoon p3 = {"Arno", 185};

    cout << p1.koop(g1) << "\n";
    cout << p1.koop(g2) << "\n";
    cout << p1.koop(g3) << "\n";
    cout << p2.koop(g2) << "\n";
    cout << p2.koop(g1) << "\n";
    cout << p3.koop(g3) << "\n";
    cout << "\n";

    cout << p1.toString() << "\n";
    cout << p2.toString() << "\n";
    cout << p3.toString() << "\n";

    cout << p1.verkoop(g1, p3) << "\n";
    cout << p2.verkoop(g2, p3) << "\n";
    cout << p2.verkoop(g1, p1) << "\n";
    cout << "\n";

    cout << p1.toString() << "\n";
    cout << p2.toString() << "\n";
    cout << p3.toString() << "\n";
}