#include "board.h"
#include "iostream"
Board::Board(sf::RenderWindow* _window) : window(_window)
{
    this->user_o = new User(O);
    this->user_x = new User(X);
   // this->window->setTitle("Tic Tac Toe");
    this->window->setFramerateLimit(60);
}

void Board::init()
{
    end = false;
    this->cells.resize(3);
    for (int row = 0; row < 3; row++)
    {
        this->cells[row].resize(3);
        for (int column = 0; column < 3; column++)
        {
            this->cells[row][column].rect.setSize(sf::Vector2f(setting::cell_size, setting::cell_size));
            this->cells[row][column].rect.setFillColor(setting::cell_color);
            this->cells[row][column].rect.setPosition(get_cell_position(row, column));
        }
    }
    this->curr_user = this->user_x;
    font.loadFromFile("resources/fonts/roboto.ttf");
    status_text.setFont(font);
    status_text.setCharacterSize(30);
    status_text.setStyle(sf::Text::Regular);
    status_text.setFillColor(sf::Color::Black);
    status_text.setPosition(400.f, 80.f);
    this->update_status_text();
}

void Board::draw()
{
    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++)
        {
            this->window->draw(this->cells[row][column].rect);
            if (this->cells[row][column].cell_status == OCCUPIED)
                this->window->draw(this->cells[row][column].xo->sprite);
        }
    this->window->draw(this->status_text);
}

void Board::run()
{
    this->init();
    string s;
    bool d = false; 
    this->window->display();
    while (this->window->isOpen()) {
        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
            else if (!this->end)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    this->mouse_clicked(sf::Mouse::getPosition(*(this->window)));
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                s = sf::Clipboard::getString();
                cout<<s<<endl;
            }
        }
        this->window->clear(sf::Color(150, 150, 150));
        this->update_status_text();
        this->draw();
        this->window->display();
    }
}

void Board::mouse_clicked(const sf::Vector2i& position)
{   
    int row = get_cell_index(position.y), column = get_cell_index(position.x);
    if (row == -1 || column == -1)
        return;
    if (this->cells[row][column].cell_status == EMPTY)
        this->cell_empty_clicked(row, column);
}

void Board::cell_empty_clicked(int row, int column)
{
    put_xo_in_cell(row, column);
    this->end = this->curr_user->check_win(this->cells);
    if (this->end)
        return;
    this->curr_user = this->curr_user->id == X ? this->user_o : this->user_x;
}

void Board::put_xo_in_cell(int row, int column)
{
    XO* xo = new XO(this->curr_user->id);
    xo->sprite.setPosition(this->cells[row][column].rect.getPosition());
    this->cells[row][column].xo = xo;
    this->cells[row][column].cell_status = OCCUPIED;
}

void Board::update_status_text()
{
    if (this->end)
        status_text.setString(get_name_of_id(this->curr_user->id) + " Wins!");
    else
        status_text.setString(get_name_of_id(this->curr_user->id) + " Turn");
}