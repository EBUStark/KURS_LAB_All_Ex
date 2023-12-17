#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "EX1_HOSPITAL.h"
#include "RECTANGLE.h"


void GLOBAL_menu() {
    char choice;
    do {
        std::cout << "Виберіть опцію:\n";
        std::cout << "1. Робота з палатами та лікарями\n";
        std::cout << "2. Робота з прямокутниками\n";
        std::cout << "0. Вийти з програми\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            Hospital().run();
            break;
        case '2':
            Rectangle().main1();  // Викликати main1 при виборі опції "2"
            break;
        case '0':
            std::cout << "Дякуємо за використання програми. Програма завершується.\n";
            break;
        default:
            std::cout << "Некоректний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != '0');

    return;
}

int main() {
    GLOBAL_menu();
    return 0;
}
