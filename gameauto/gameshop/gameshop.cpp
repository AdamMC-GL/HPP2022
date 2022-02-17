#include <string>
#include "gameshop.hpp"
using namespace std;

Game::Game()
{

}

Game::Game(string name, int releaseYear, float price)
{
    this->name = name;
    this->releaseYear = releaseYear;
    this->price = price;
    currentPrice = price;

}

double Game::current_price(){
    currentPrice = price;
    for(unsigned int i = releaseYear; i < 2022; i++){
        currentPrice = currentPrice - (currentPrice / 100 * 30);
    }
    return currentPrice;
}

Persoon::Persoon()
{
    owned_games = { };
}
Persoon::Persoon(string naam, float budget)
{
    this->naam = naam;
    this->budget = budget;

}

string Persoon::koop(Game game){
    for(unsigned int i = 0; i < owned_games.size(); i++){
        if (game.name == owned_games[i].name){
            return "niet gelukt";
        }
    }
    if(game.current_price() > budget){
        return "niet gelukt";
    }

    budget = budget - (game.current_price());
    owned_games.push_back(game);
    return "gelukt";
}

string Persoon::verkoop(Game game, Persoon & koper){

    for(unsigned int j = 0; j < koper.owned_games.size(); j++){
        if (game.name == koper.owned_games[j].name){
            return "niet gelukt";
        }
    }
    if(game.current_price() > koper.budget){
        return "niet gelukt";
    }
    for(signed int i = 0; i < owned_games.size(); i++){
        if (game.name == owned_games[i].name){
            koper.budget = koper.budget - game.current_price();
            budget = budget + game.current_price();
            koper.owned_games.push_back(game);
            owned_games.erase(owned_games.begin() + i);
            return "gelukt";
        }
    }
    return "niet gelukt";
}

string Persoon::toString(){
    string str = naam + " heeft een budget van " + to_string(budget).substr(0,5) + ",- en bezit de volgende games: \n";
    for(unsigned int i = 0; i < owned_games.size(); i++){
        str += owned_games[i].name + ", uitgegeven in " + to_string(owned_games[i].releaseYear) + " nieuwprijs: " + to_string(owned_games[i].price).substr(0,5) + ",- nu voor: " + to_string(owned_games[i].current_price()).substr(0,5)+",- \n";
    }
    return str;
}



