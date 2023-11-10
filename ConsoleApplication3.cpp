#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using namespace sf;

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    RenderWindow mainWindow(VideoMode(600, 700, 32), "Gierka");

    Vector2f platformSize(50, 5), deltaMovePlatform(10, 0), deltaBallMove(2, 2);
    unsigned int ballR = 5, deltaAngle = 45;

    RectangleShape platform(platformSize);
    platform.setPosition(275, 600);
    platform.setFillColor(Color::White);

    CircleShape ball(ballR);
    ball.setPosition(300 - ballR, 500 - ballR);
    ball.setFillColor(Color::White);

    // Ramka o szerokości 1 px
    //RectangleShape frame(Vector2f(mainWindow.getSize().x - 2, mainWindow.getSize().y - 2));
    //frame.setOutlineThickness(1);
    //frame.setOutlineColor(Color::White);
    //frame.setPosition(1, 1);

    while (mainWindow.isOpen()) {
        Event action;

        while (mainWindow.pollEvent(action)) {

            if (action.type == Event::KeyPressed) {

                //Zamykanie..
                if (action.key.code == Keyboard::Escape) {
                    mainWindow.close();
                    return EXIT_SUCCESS;
                }

                //Strerowaie..
                if (action.key.code == Keyboard::Left) {
                    if (platform.getPosition().x - deltaMovePlatform.x > 0)
                        platform.move(-deltaMovePlatform);
                }
                else if (action.key.code == Keyboard::Right) {
                    if (platform.getPosition().x + platformSize.x + deltaMovePlatform.x < mainWindow.getSize().x)
                        platform.move(deltaMovePlatform);
                }
            }
            else if (action.type == Event::Closed) {//Kolejne zamykanie..
                mainWindow.close();
                return EXIT_SUCCESS;
            }

        }

        // Ruch obiektu ball
        ball.move(deltaBallMove);

        // Parametry ruchu piłki


        mainWindow.clear(Color(48, 25, 52));

        // Rysowanie ramki
        //mainWindow.draw(frame);

        // Rysowanie obiektu platform i ball
        mainWindow.draw(platform);
        mainWindow.draw(ball);

        mainWindow.display();
    }

    return 0;
}
