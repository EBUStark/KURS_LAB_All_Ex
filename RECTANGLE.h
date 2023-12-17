#pragma once



#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class Rectangle {
private:
    int x;
    int y;
    int width;
    int height;
    std::string color;

private:
    std::string generateRandomColor();
  
public:
    

    Rectangle();
    Rectangle(int x, int y, int width, int height, std::string color);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    std::string getColor();

    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setColor(std::string color);
    void main1();
    int area();
    void print();

    friend Rectangle operator>(Rectangle r1, Rectangle r2);
};


