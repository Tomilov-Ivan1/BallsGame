#include "BallGame.h"
#include "Exceptions.h"

#include <fstream>
#include <random>
#include <ctime>

void BallGame::InputFromConsole() {
    balls_.Clear();

    int n;
    std::cout << "Количество шариков: ";
    std::cin >> n;

    if (n <= 0) {
        throw InputException("Некорректное количество шариков.");
    }

    std::cout << "Введите цвета:\n";

    for (int i = 0; i < n; ++i) {
        int color;
        std::cin >> color;

        if (color < 0 || color > 9) {
            throw InputException("Цвет должен быть от 0 до 9.");
        }

        balls_.PushBack(color);
    }
}

void BallGame::GenerateRandom(int count) {
    balls_.Clear();

    std::mt19937 gen(static_cast<unsigned>(time(nullptr)));
    std::uniform_int_distribution<> dist(0, 9);

    for (int i = 0; i < count; ++i) {
        balls_.PushBack(dist(gen));
    }
}

void BallGame::ReadFromFile(const std::string& filename) {
    balls_.Clear();

    std::ifstream file(filename);

    if (!file.is_open()) {
        throw FileException("Не удалось открыть файл.");
    }

    int n;
    file >> n;

    for (int i = 0; i < n; ++i) {
        int color;
        file >> color;
        balls_.PushBack(color);
    }
}

void BallGame::PrintBalls() const {
    balls_.Print();
}

int BallGame::CountDestroyedBalls() {
    auto* start = balls_.Head();

    while (start) {
        auto* end = start;

        while (end->next &&
               end->next->color == start->color) {
            end = end->next;
        }

        int count = 1;

        auto* tmp = start;

        while (tmp != end) {
            ++count;
            tmp = tmp->next;
        }

        if (count >= 3) {
            int destroyed = count;

            auto* left = start->prev;
            auto* right = end->next;

            while (left && right &&
                   left->color == right->color) {

                int color = left->color;

                int leftCount = 0;
                int rightCount = 0;

                auto* l = left;
                auto* r = right;

                while (l && l->color == color) {
                    ++leftCount;
                    l = l->prev;
                }

                while (r && r->color == color) {
                    ++rightCount;
                    r = r->next;
                }

                if (leftCount + rightCount >= 3) {
                    destroyed += leftCount + rightCount;
                    left = l;
                    right = r;
                } else {
                    break;
                }
            }

            return destroyed;
        }

        start = end->next;
    }

    return 0;
}