#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shapes/Rectangle.h"
#include "Shapes/RegularPolygon.h"
#include <stdlib.h>
#include <chrono>

double CalculateError(sf::Uint8 *img1, const sf::Uint8 *img2, Shape* s, int w, int h) {
    double e = 0;
    for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int index = 4*(i * w + j);
            sf::Color c1;
            if (s->Inside(Point{j, i})) c1 = s->GetPixel(img1, j, i);
            else {
                c1.r = img1[index];
                c1.g = img1[index + 1];
                c1.b = img1[index + 2];
            }
            sf::Color c2;
            c2.r = img2[index], c2.g = img2[index + 1], c2.b = img2[index + 2];
            float total = (std::abs(c2.r - c1.r) + std::abs(c2.g - c1.g) + std::abs(c2.b - c1.b)) / 255.f;
            e += total;
        }
    }

    return e / (w * h * 3);
 }

int main(int argc, char ** argv)
{
    srand(time(0));
    // Create the main window
    auto start = std::chrono::high_resolution_clock::now();
    int iterations = 1000;
    int screen_width = 800, screen_height = 600;
    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "SFML window");

    double prev_error = 1.0;
    std::string img_path = "images/img_1.jpg";
    sf::Image actual;
    if (!actual.loadFromFile(img_path)){
        std::cout<<"Error in loading actual image";
        return EXIT_FAILURE;
    }
    int totalPixels = screen_width * screen_height;
    sf::Uint8 *buffer = new sf::Uint8[totalPixels * 4];
    for (int i = 0; i < 4 * totalPixels; i++) buffer[i] = 255;
     const sf::Uint8 *actualImgPtr = actual.getPixelsPtr();
//    sf::Image buffer;

    // Start the game loop
    int count  = 0;
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Create a random shape
        if (count < iterations) {
            RegularPolygon r(screen_width, screen_height);
            r.CreateRandDimensions();

            // Check if this shape reduces the error
            double error = CalculateError(buffer, actualImgPtr, &r, screen_width, screen_height);

//             If it doesn't create continue
            if (error < prev_error) {
                count++;
                prev_error = error;
                std::cout<<"Count: "<<count<<" Accuracy: "<<(1 - prev_error) * 100 <<"%"<<std::endl;
                r.FillWithColor(buffer);
                sf::Image img;
                img.create(screen_width, screen_height, buffer);
                sf::Texture t;
                t.loadFromImage(img);
                sf::Sprite sp;
                sp.setTexture(t);
                window.clear();
                window.draw(sp);
                window.display();
            }

            if (count == iterations) {
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
                std::cout<<"Time taken is "<<duration.count()<<"s"<<std::endl;
            }
        }

        // If it does then add it to the image and clear the screen to redraw the image

        // Do these steps at max ITERATIONS number of times
    }
    return EXIT_SUCCESS;

}