@echo off
echo Compiling...
gcc src/main.c src/adt/charmachine/charmachine.c src/adt/eltype/eltype.c src/adt/listdin/listdin.c src/adt/listdineltype/listdineltype.c src/adt/liststatik/liststatik.c src/adt/makanan/makanan.c src/adt/map/map.c src/adt/matriks/matriks.c src/adt/point/point.c src/adt/prioqueue/prioqueue.c src/adt/set/set.c src/adt/simulator/simulator.c src/adt/stack/stack.c src/adt/tree/tree.c src/adt/waktu/waktu.c src/adt/wordmachine/wordmachine.c src/app/commands/commands.c src/app/display/display.c src/app/filereader/filereader.c src/app/parser/parser.c -o main
echo Compilation done!
main
pause
