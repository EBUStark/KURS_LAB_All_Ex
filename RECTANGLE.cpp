#include "RECTANGLE.h"



std::string Rectangle::generateRandomColor() {
    std::string color = "";
    for (int i = 0; i < 6; i++) {
        int digit = rand() % 16;
        char hexDigit = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        color += hexDigit;
    }
    return color;
}

Rectangle::Rectangle() {
    srand(time(0));

    x = rand() % 100;
    y = rand() % 100;
    width = rand() % 50 + 1;
    height = rand() % 50 + 1;

    color = generateRandomColor();
}

Rectangle::Rectangle(int x, int y, int width, int height, std::string color) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
}

int Rectangle::getX() {
    return x;
}

int Rectangle::getY() {
    return y;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

std::string Rectangle::getColor() {
    return color;
}

void Rectangle::setX(int x) {
    this->x = x;
}

void Rectangle::setY(int y) {
    this->y = y;
}

void Rectangle::setWidth(int width) {
    this->width = width;
}

void Rectangle::setHeight(int height) {
    this->height = height;
}

void Rectangle::setColor(std::string color) {
    this->color = color;
}

int Rectangle::area() {
    return width * height;
}

void Rectangle::print() {
    std::cout << "Прямокутник з координатами (" << x << ", " << y << "), розмірами " << width << "x" << height << " і кольором " << color << std::endl;
}

Rectangle operator>(Rectangle r1, Rectangle r2) {
    int x3 = (r1.getX() + r2.getX()) / 2;
    int y3 = (r1.getY() + r2.getY()) / 2;

    Rectangle r3(x3, y3, 0, 0, "");

    r3.setWidth(r1.getWidth() + r2.getWidth());
    r3.setHeight(r1.getHeight() + r2.getHeight());

    std::string color1 = r1.getColor();
    std::string color2 = r2.getColor();
    std::string color3 = "";
    for (int i = 0; i < 6; i += 2) {
        std::string c1 = color1.substr(i, 2);
        std::string c2 = color2.substr(i, 2);

        int n1 = std::stoi(c1, nullptr, 16);
        int n2 = std::stoi(c2, nullptr, 16);

        int n3 = (n1 + n2) % 256;

        std::stringstream ss;
        ss << std::hex << n3;
        std::string c3 = ss.str();

        if (c3.length() == 1) {
            c3 = "0" + c3;
        }

        color3 += c3;
    }
    r3.setColor(color3);

    return r3;
}

void Rectangle::main1() {
    srand(time(0));
    int x1 = rand() % 100;
    int y1 = rand() % 100;
    int w1 = rand() % 50 + 1;
    int h1 = rand() % 50 + 1;
    std::string c1 = "";
    for (int i = 0; i < 6; i++) {
        int digit = rand() % 16;
        char hexDigit = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        c1 += hexDigit;
    }

    int x2 = rand() % 100;
    int y2 = rand() % 100;
    int w2 = rand() % 50 + 1;
    int h2 = rand() % 50 + 1;
    std::string c2 = "";
    for (int i = 0; i < 6; i++) {
        int digit = rand() % 16;
        char hexDigit = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        c2 += hexDigit;
    }

    Rectangle r1(x1, y1, w1, h1, c1);
    Rectangle r2(x2, y2, w2, h2, c2);

    std::cout << "Перший прямокутник:" << std::endl;
    r1.print();
    std::cout << "Другий прямокутник:" << std::endl;
    r2.print();

    Rectangle r3 = r1 > r2;

    std::cout << "Новий прямокутник, який утворився в результаті операції >:" << std::endl;
    r3.print();

    return ;
}
