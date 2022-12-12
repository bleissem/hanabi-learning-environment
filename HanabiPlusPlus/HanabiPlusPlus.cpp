// HanabiPlusPlus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../hanabi_learning_environment/hanabi_lib/hanabi_game.h"
#include "../hanabi_learning_environment/hanabi_lib/hanabi_state.h"
#include "../hanabi_learning_environment/hanabi_lib/hanabi_observation.h"

using namespace hanabi_learning_env;

const int CHANCE_PLAYER_ID = -1;


/// <summary>
/// eines der Ziele: Entscheidungsprozess für ein Zug
/// </summary>
/// <param name="state"></param>
/// <param name="currentPlayer"></param>
/// <returns></returns>
HanabiMove* GetRandomMove(HanabiState& state, int currentPlayer)
{
    std::vector<HanabiMove> moves = state.LegalMoves(currentPlayer);
    std::vector<HanabiMove>::iterator randIt = moves.begin();
    std::advance(randIt, std::rand() % moves.size());
    HanabiMove move = *randIt;
    return &move;
}

int main()
{
    std::cout << "Hello World!\n";    
    
    std::unordered_map<std::string, std::string> gameParameter;
    gameParameter.insert({ "players", "2" });
    gameParameter.insert({ "random_start_player", "true" });
    // gameParameter.insert({ "observation_type", "2" });

    HanabiGame game(gameParameter);

    HanabiState state(&game);
    
    // Deal(state);

    while (!state.IsTerminal())
    {
        int currentPlayer = state.CurPlayer();
        if (currentPlayer == CHANCE_PLAYER_ID)
        {
            state.ApplyRandomChance();
            continue;
        }

        // aktuelle Spieler gesetzt

        HanabiObservation observation(state, currentPlayer);
        /*
        Agent* currentAgent;
        if (currentPlayer == 1)
        {
            currentAgent = agent1;
        }
        else
        {
            currentAgent = agent2;
        }

        int move = currentAgent->Act(&observation);

        HanabiMove hanabiMove = game.GetMove(move);        

        int last_score = state.Score();

        state.ApplyMove(hanabiMove);

        while (currentPlayer == CHANCE_PLAYER_ID)
        {
            state.ApplyRandomChance();
            continue;
        }

        
        int reward = state.Score() - last_score;
        */
    }
    std::cout <<  state.Score();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
