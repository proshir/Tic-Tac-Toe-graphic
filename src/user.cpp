#include "user.h"

User::User(Id _id) : id(_id) {}

bool User::check_win(Cells &cells)
{
    if ((is_cell_for_you(cells[0][0])) && 
        ((is_cell_for_you(cells[0][1]) && is_cell_for_you(cells[0][2])) ||
         (is_cell_for_you(cells[1][0]) && is_cell_for_you(cells[2][0])) ||
         (is_cell_for_you(cells[1][1]) && is_cell_for_you(cells[2][2]))))
            return true;
    if ((is_cell_for_you(cells[1][1])) &&
        ((is_cell_for_you(cells[1][0]) && is_cell_for_you(cells[1][2])) ||
         (is_cell_for_you(cells[0][1]) && is_cell_for_you(cells[2][1])) ||
         (is_cell_for_you(cells[0][2]) && is_cell_for_you(cells[2][0]))))
            return true;
    if ((is_cell_for_you(cells[2][2])) && 
        ((is_cell_for_you(cells[2][1]) && is_cell_for_you(cells[2][0]))||
         (is_cell_for_you(cells[1][2]) && is_cell_for_you(cells[0][2]))))
            return true;
    return false;
}

bool User::is_cell_for_you(Cell &cell)
{
    return cell.xo && cell.xo->id == this->id;
}