/* ADT */
#include "../headers/map.h"

/* APP */
#include "../../app/headers/filereader.h"
#include "../../app/headers/parser.h"

int main()
{
    Map map;
    Point currentPoint;

    ReadMapConfig(&map);
    START_INPUT();
    while(true)
    {
        currentPoint = S(map);

        DisplayMap(map);
        if (IsInputEqual(MOVE_EAST_WORD))
        {
            MovePointEast(&currentPoint);
            MoveSimulator(&map, currentPoint);
        }

        else if (IsInputEqual(MOVE_NORTH_WORD))
        {
            MovePointNorth(&currentPoint);
            MoveSimulator(&map, currentPoint);
        }

        else if (IsInputEqual(MOVE_SOUTH_WORD))
        {
            MovePointSouth(&currentPoint);
            MoveSimulator(&map, currentPoint);
        }

        else if (IsInputEqual(MOVE_WEST_WORD))
        {
            MovePointSouth(&currentPoint);
            MoveSimulator(&map, currentPoint);
        }

        else {
            break;
        }
    }

    
}