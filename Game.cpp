//
// Created by krisv816 on 2019-12-11.
//

#include "Game.h"
Game::Game(std::string filepath)
:PS{filepath}, gameMode{1}
{}

void Game::run() {

    sf::RenderWindow window{sf::VideoMode(1920,1080), "TANK DUELS!", sf::Style::Fullscreen};
    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);

    window.setMouseCursorVisible(false);

    Menu menu(window.getSize().x, window.getSize().y);
    main_menu(window, menu);

    sf::Font font;
    if(!font.loadFromFile("fonts/pixelfont.otf"))
    {
        std::cerr << "Failed to load fonts/pixelfont.otf" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setPosition(window.getSize().x/2, window.getSize().y/2);

    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);

    sf::Clock clock;

    PS.make_arena();


        while (window.isOpen()) {
            sf::Time time = clock.getElapsedTime();
            sf::Event event{};

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    goToMenu(window, menu);

                }

            }

            PS.update(event,time);

            clock.restart();
            window.clear();
            PS.draw(window);
            PS.draw_scoreboard(window);
            window.display();


            PS.isRoundOver();

            if(PS.hasWon())
            {

                text.setString(PS.getWinner());

                window.clear();
                window.draw(text);
                window.display();
                sf::sleep(sf::seconds(4));

                goToMenu(window, menu);

            }
        }
}

//This function handles what has been written in the Menu class and uses it to present a main menu for the user.
void Game::main_menu(sf::RenderWindow &window, Menu & menu)
{
    sf::Font font;
    if(!font.loadFromFile("fonts/pixelfont.otf"))
    {
        std::cerr << "Failed to load fonts/pixelfont.otf" << std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("1v1");
    text.setPosition(100, 1000);
    bool playPressed{false};
    while (window.isOpen()) {
        sf::Event event{};
        if(playPressed)
        {
            break;
        }
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    playPressed = true;
                                    break;

                                case 1:
                                    gameMode = 2;
                                    changeGameMode();
                                    break;

                                case 2:
                                    gameMode = 1;
                                    changeGameMode();
                                    break;

                                case 3:
                                    window.close();
                                    break;
                            }
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }

        }
        if(gameMode == 1)
        {
            text.setString("1v1");
        }
        else if(gameMode == 2)
        {
            text.setString("2v2");
        }

        window.clear();
        window.draw(text);
        menu.draw(window);
        window.display();
    }
}

void Game::goToMenu(sf::RenderWindow &window, Menu & menu)
{
    PS.emptyBoard();
    PS.resetScore();
    main_menu(window, menu);
    PS.make_arena();

}

void Game::changeGameMode() {
    if(gameMode == 1)
    {
        PS.setFilepath("arenas/banacj.txt");
    }
    else if(gameMode == 2)
    {
        PS.setFilepath("arenas/arena2v2.txt");
    }
}

