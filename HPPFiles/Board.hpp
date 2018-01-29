#ifndef BOARD_HPP
#define BOARD_HPP

using namespace std;

#include <string>

using namespace std;

class Board
{
    private:
      int numberOfRows;
      int numberOfColumns;
      int row[17];
      int column[5];

    public:
        Board();
        void Build();
        void Draw();
        void Erase();
        string board[5][17];
};
#endif
