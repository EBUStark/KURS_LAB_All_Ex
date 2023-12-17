#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class Ward {
public:
    Ward() = default;
    Ward(int totalBeds, const std::string& doctorLastName, int availableBeds)
        : totalBeds_(totalBeds), doctorLastName_(doctorLastName), availableBeds_(availableBeds) {}

    std::string getDoctorLastName() const {
        return doctorLastName_;
    }

    int getTotalBeds() const {
        return totalBeds_;
    }

    int getAvailableBeds() const {
        return availableBeds_;
    }

    void displayInfo() const {
        std::cout << "Лікар: " << doctorLastName_ << "\n";
        std::cout << "Загальна кількість ліжок: " << totalBeds_ << "\n";
        std::cout << "Доступні ліжка: " << availableBeds_ << "\n";
    }

private:
    int totalBeds_;
    std::string doctorLastName_;
    int availableBeds_;
};

class Hospital {
public:
    Hospital() : maxWardCount(10) {}

    void displayMenu();
    void enterWardData();
    void displayInfoAndCreateReport();
    void displayTotalAvailableBeds();
    void displayDoctorsWithAvailableBeds();
    void run();

private:
    const int maxWardCount;
    Ward wards[10];
    int wardCount = 0;
};
