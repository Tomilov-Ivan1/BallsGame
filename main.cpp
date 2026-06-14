#include "BallGame.h"
#include "Exceptions.h"

#include <iostream>

void PrintMenu() {
    std::cout << "\n===== МЕНЮ =====\n";
    std::cout << "1. Ввод с клавиатуры\n";
    std::cout << "2. Случайная генерация\n";
    std::cout << "3. Загрузка из файла\n";
    std::cout << "4. Показать шарики\n";
    std::cout << "5. Подсчитать уничтоженные\n";
    std::cout << "0. Выход\n";
    std::cout << "Ваш выбор: ";
}

int main() {
    BallGame game;

    while (true) {
        try {
            PrintMenu();

            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1:
                game.InputFromConsole();
                break;

            case 2: {
                int n;
                std::cout << "Количество шариков: ";
                std::cin >> n;

                game.GenerateRandom(n);
                break;
            }

            case 3:
                game.ReadFromFile("colors.txt");
                break;

            case 4:
                game.PrintBalls();
                break;

            case 5:
                std::cout
                    << "Будет уничтожено: "
                    << game.CountDestroyedBalls()
                    << "\n";
                break;

            case 0:
                return 0;

            default:
                std::cout << "Неверный пункт меню\n";
            }
        }
        catch (const std::exception& ex) {
            std::cout << "Ошибка: "
                      << ex.what()
                      << "\n";
        }
    }
}