#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "user.h"
#include "data.h"
#include "cell.h"
#include "setting.h"
#include "helper.h"

class Board
{
public:
    Board(sf::RenderWindow* _window);
    sf::RenderWindow* window;
    Cells cells;
    User* user_x;
    User* user_o;
    User* curr_user;

    sf::Font font;
    bool end;
    sf::Text status_text;

    void init();
    void draw();
    void run();
    void mouse_clicked(const sf::Vector2i& position);
    void cell_empty_clicked(int row, int column);
    void put_xo_in_cell(int row, int column);
    void check_end();
    void update_status_text();
};

#endif