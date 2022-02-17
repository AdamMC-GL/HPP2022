#include <iostream>
#include <vector>
using namespace std;

class Game
{
public:
    string name;
    int releaseYear;
    float price;
    float currentPrice;

    Game();
    Game(string name, int releaseYear, float price );
    double current_price();
};


class Persoon{
public:
    string naam;
    float budget;
    vector<Game> owned_games;

    Persoon();
    Persoon(string naam, float budget);
    string koop(Game game);
    string verkoop(Game game, Persoon & koper);
    string toString();
};


