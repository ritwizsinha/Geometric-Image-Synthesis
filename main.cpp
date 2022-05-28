#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shapes/Rectangle.h"
#include <stdlib.h>
#include <climits>

double CalculateError(sf::Image &img1, sf::Image &img2, Shape* s) {
    uint w = img1.getSize().x;
    uint h = img1.getSize().y;
    double e = 0;
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            sf::Color c1;
            if (s->Inside(i, j)) c1 = s->GetPixel(img1, i, j);
            else c1 = img1.getPixel(i, j);

            sf::Color c2 = img2.getPixel(i, j);
            float total = std::abs(c2.r - c1.r)/255.f + std::abs(c2.g - c1.g)/255.f + std::abs(c2.b - c1.b)/255.f;
            e += total;
        }
    }


    return e;
 }

int main(int argc, char ** argv)
{
    // Create the main window
    int iterations = 2000;
    int screen_width = 800, screen_height = 600;
    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "SFML window");

    double prev_error = 1.0 * INT_MAX;
    std::string img_path = "images/img_1.jpg";
    sf::Image actual;
    if (!actual.loadFromFile(img_path)){
        std::cout<<"Error in loading actual image";
        return EXIT_FAILURE;
    }

    sf::Image buffer;
    buffer.create(screen_width, screen_height, sf::Color::White);

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
            Rectangle r(screen_height, screen_width);
            r.CreateRandDimensions();

            // Check if this shape reduces the error
            double error = CalculateError(buffer, actual, &r);

            // If it doesn't create continue
            if (error < prev_error) {
                count++;
                prev_error = error;
                std::cout<<count<<". "<<error<<std::endl;
                r.FillWithColor(buffer);
                sf::Texture t;
                t.loadFromImage(buffer);
                sf::Sprite sp;
                sp.setTexture(t);
                window.clear();
                window.draw(sp);
                window.display();
            }
        }

        // If it does then add it to the image and clear the screen to redraw the image

        // Do these steps at max ITERATIONS number of times
    }
    return EXIT_SUCCESS;

}