#include "board.h"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(520, 400), "Tic Tac Toe", Style::Titlebar | Style::Close);
    Board board(&window);
    board.run();
}