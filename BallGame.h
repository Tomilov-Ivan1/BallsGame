#ifndef BALL_GAME_H
#define BALL_GAME_H

#include "DoublyLinkedList.h"

class BallGame {
private:
    DoublyLinkedList balls_;

public:
    void InputFromConsole();
    void GenerateRandom(int count);
    void ReadFromFile(const std::string& filename);

    void PrintBalls() const;

    int CountDestroyedBalls();
};

#endif