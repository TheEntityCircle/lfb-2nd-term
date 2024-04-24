#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Картинку, которую мы обрабатываем, будем хранить в глобальных переменных.

// Размеры. 
uint32_t width;
uint32_t height;

// Вспомогательная структура.
struct pixel {
    uint32_t r, g, b;
};

// Сама картинка.
std::vector<std::vector<pixel>> pict;


// Функция сортировки вектора пикселей - простая обертка над стандартной.
void sort(std::vector<pixel>& str)
{
    std::sort(str.begin(), str.end(), [](const pixel& a, const pixel& b) { return (a.r + a.g + a.b) > (b.r + b.g + b.b); });
}

int main()
{
    // Считываем файл, который сгенерировали при помощи 07_basic_ppm.cpp
    std::ifstream in("pic.ppm");
    std::string stmp;
    in >> stmp;
    in >> width >> height;
    in >> stmp;

    pict.resize(height);
    for (auto &s : pict)
        s.resize(width);

    for(uint32_t i = 0; i < height; i++)
        for(uint32_t j = 0; j < width; j++)
        {
            in >> pict[i][j].r >> pict[i][j].g >> pict[i][j].b;
        }


    // Обработка.
    for(uint32_t i = 0; i < height; i++)
        sort(pict[i]);


    // Вывод результата в другую картинку. Она должна отразиться справа налево.
    std::ofstream out("pic_sorted.ppm");
    out << "P3" << std::endl;
    out << width << " " << height << std::endl;
    out << "255" << std::endl;

    for(uint32_t i = 0; i < height; i++)
        for(uint32_t j = 0; j < width; j++)
        {
            out << pict[i][j].r << " " << pict[i][j].g << " " << pict[i][j].b << " ";
        } 

    return 0;
}

