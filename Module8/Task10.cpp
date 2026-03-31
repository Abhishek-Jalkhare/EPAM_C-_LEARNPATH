//
// Created by AbhishekJalkhare on 26-03-2026.
//
#include <iostream>
#include <map>
using namespace std;

struct PlayerStats {
    std::string playerId;
    std::string playerName;
    int score;
};


struct  PlayerRankComparator {
    bool operator() (const PlayerStats& p1, const PlayerStats& p2)const {
        if (p1.score != p2.score ) return p1.score > p2.score;
        if (p1.playerName != p2.playerName) return p1.playerName<p2.playerName;
        return p1.playerId < p2.playerId;
    }
};


int main(int argc, char* argv[]) {
    std::map<PlayerStats, bool, PlayerRankComparator> leaderboard = {
        {PlayerStats("P001", "Alice", 1500), true},
        {PlayerStats("P003", "Charlie", 1200), true},
        {PlayerStats("P002", "Bob", 1500), true},
        {PlayerStats("P005", "David", 1800), true},
        {PlayerStats("P004", "Alice", 1000), true},
        {PlayerStats("P007", "Emily", 1200), true},
        {PlayerStats("P006", "Bob", 1500), true}
        };

    int rank = 1;
    for (const auto&[ player ,  val]  : leaderboard) {
        std::cout<<"Rank: "<<rank << ", ID: " <<player.playerId
          << ", Name: " << player.playerName
          << ", Score: " << player.score<< "\n";
        rank++;
    }
}
