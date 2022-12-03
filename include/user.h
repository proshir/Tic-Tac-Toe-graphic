#ifndef USER_H
#define USER_H

#include "data.h"
#include "cell.h"

class User
{
public:
    User(Id id);
    Id id;
    bool check_win(Cells &cells);
    bool is_cell_for_you(Cell &cell);
};

#endif