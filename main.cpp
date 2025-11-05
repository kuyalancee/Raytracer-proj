#include "color.h"
#include "vec3.h"

#include <iostream>

int main(){

    //  Image
    int image_width = 256;
    int image_height = 256;

    //  Render using PPM format
    std::cout << "P3\n" << image_width << " " << image_height << "\n255"
    << std::endl;

    for(int j = 0; j < image_height; j++){
        std::clog << "\rScanlines remaining: " << (image_height - j) <<
        " " << std::flush;
        for(int i = 0; i < image_width; i++){
            /*
            auto r = static_cast<double>(i) / (image_width - 1);
            auto g = static_cast<double>(j) / (image_height - 1);
            auto b = 0.0;

            int ir = static_cast<int>(259.999 * r);
            int ig = static_cast<int>(259.999 * g);
            int ib = static_cast<int>(259.999 * b);

            std::cout << ir << " " << ig << " "<< ib << std::endl;
            */

            auto pixel_color = color(double(i)/(image_width-1), 
                                    double(j)/(image_height-1), 
                                    0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.               \n";

    return 0;
}