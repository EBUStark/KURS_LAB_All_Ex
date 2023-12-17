#include "EX1_HOSPITAL.h"

void Hospital::displayMenu() {
    std::cout << "Виберіть опцію:\n";
    std::cout << "1. Ввести дані про палати та лікарів\n";
    std::cout << "2. Вивести інформацію про всі палати та створити текстовий звіт\n";
    std::cout << "3. Вивести загальну кількість вільних ліжок у всіх палатах\n";
    std::cout << "4. Вивести лікарів із вільними ліжками\n";
    std::cout << "0. Вийти з програми\n";
}

void Hospital::enterWardData() {
    std::cout << "Введіть кількість палат (не більше " << maxWardCount << "): ";

    while (!(std::cin >> wardCount) || wardCount > maxWardCount || wardCount <= 0) {
        std::cerr << "Некоректна кількість палат. Будь ласка, введіть правильні дані.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < wardCount; ++i) {
        int totalBeds, availableBeds;
        std::string doctorLastName;

        std::cout << "Введіть дані для палати " << i + 1 << ":\n";
        std::cout << "Загальна кількість ліжок: ";
        while (!(std::cin >> totalBeds) || totalBeds <= 0) {
            std::cerr << "Некоректна кількість ліжок. Будь ласка, введіть правильні дані.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Прізвище лікаря: ";
        std::cin >> doctorLastName;

        std::cout << "Кількість вільних ліжок: ";
        while (!(std::cin >> availableBeds) || availableBeds < 0 || availableBeds > totalBeds) {
            std::cerr << "Некоректна кількість вільних ліжок. Будь ласка, введіть правильні дані.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        wards[i] = Ward(totalBeds, doctorLastName, availableBeds);
    }
}

void Hospital::displayInfoAndCreateReport() {
    std::ofstream reportFile("report.txt");
    if (!reportFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису звіту.\n";
        return;
    }

    for (int i = 0; i < wardCount; ++i) {
        wards[i].displayInfo();
        reportFile << "Лікар: " << wards[i].getDoctorLastName() << "\n";
        reportFile << "Загальна кількість ліжок: " << wards[i].getTotalBeds() << "\n";
        reportFile << "Доступні ліжка: " << wards[i].getAvailableBeds() << "\n\n";
    }

    int totalAvailableBeds = 0;
    for (int i = 0; i < wardCount; ++i) {
        totalAvailableBeds += wards[i].getAvailableBeds();
    }

    std::cout << "Загальна кількість вільних ліжок у всіх палатах: " << totalAvailableBeds << "\n";
    reportFile << "Загальна кількість вільних ліжок у всіх палатах: " << totalAvailableBeds << "\n";

    char choice;
    std::cout << "Бажаєте переглянути лікарів із вільними ліжками? (Y/N): ";
    std::cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        std::cout << "Лікарі у палатах з вільними ліжками:\n";
        reportFile << "Лікарі у палатах з вільними ліжками:\n";
        for (int i = 0; i < wardCount; ++i) {
            if (wards[i].getAvailableBeds() > 0) {
                std::cout << wards[i].getDoctorLastName() << "\n";
                reportFile << wards[i].getDoctorLastName() << "\n";
            }
        }
    }

    reportFile.close();
}

void Hospital::displayTotalAvailableBeds() {
    int totalAvailableBeds = 0;
    for (int i = 0; i < wardCount; ++i) {
        totalAvailableBeds += wards[i].getAvailableBeds();
    }

    std::cout << "Загальна кількість вільних ліжок у всіх палатах: " << totalAvailableBeds << "\n";
}

void Hospital::displayDoctorsWithAvailableBeds() {
    std::cout << "Лікарі у палатах з вільними ліжками:\n";
    for (int i = 0; i < wardCount; ++i) {
        if (wards[i].getAvailableBeds() > 0) {
            std::cout << wards[i].getDoctorLastName() << "\n";
        }
    }
}

void Hospital::run() {
    int choice;
    do {
        displayMenu();
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            enterWardData();
            break;
        case 2:
            displayInfoAndCreateReport();
            break;
        case 3:
            displayTotalAvailableBeds();
            break;
        case 4:
            displayDoctorsWithAvailableBeds();
            break;
        case 0:
            std::cout << "Дякуємо за використання програми. Програма завершується.\n";
            break;
        default:
            std::cout << "Некоректний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);
}
