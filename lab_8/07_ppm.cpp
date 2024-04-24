#include <iostream>
#include <fstream>

int main()
{
    unsigned int const width  = 1920u;
    unsigned int const height = 1080u;

    std::ofstream out("pic.ppm");
    out << "P3" << std::endl;
    out << width << " " << height << std::endl;
    out << "255" << std::endl;

    for(auto i = 0u; i < height; ++i)
    for(auto j = 0u; j <  width; ++j)
    {
        double const x = double(j) / double(width );
        double const y = double(i) / double(height);
        unsigned int const r = x * 255.;
        unsigned int const g = y * 255.;
        unsigned int const b = 80u;
        out << r << " " << g << " " << b << " ";
    }
}

