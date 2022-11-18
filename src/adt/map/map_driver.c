/* ADT */
#include "map.h"

/* APP */
#include "../../app/filereader/filereader.h"
#include "../../app/parser/parser.h"

int main()
{
    Map map;
    Point currentPoint;

    ReadMapConfig(&map);
    DisplayMap(map);
    printf("ASUMSI INPUT MOVE VALID TANPA PERLU VALIDASI\n");
    STARTWORD();

    while(true)
    {
        currentPoint = S(map);

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

        else{
            break;
        }

        DisplayMap(map);
        ADVWORD();

    }

    
}