/* ADT */
#include "../headers/map.h"

/* APP */
#include "../../app/headers/filereader.h"
#include "../../app/headers/parser.h"

int main()
{
    Map map;

    ReadMapConfig(&map);
    DisplayMatriks(TAB(map));
    START_INPUT();
    while(true)
    {
        if (IsInputEqual(MOVE_EAST_WORD))
        {

        }

        else if (IsInputEqual(MOVE_NORTH_WORD))
        {

        }

        else if (IsInputEqual(MOVE_SOUTH_WORD))
        {

        }

        else if (IsInputEqual(MOVE_WEST_WORD))
        {

        }

        else {
            break;
        }
    }

    
}