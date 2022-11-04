@echo off
set /p "file=Enter ADT/APP name (e.g. eltype): "
IF EXIST src/adt/%file% (
	echo Compiling...
	gcc src/adt/%file%/%file%_driver.c src/adt/charmachine/charmachine.c src/adt/eltype/eltype.c src/adt/listdin/listdin.c src/adt/listdineltype/listdineltype.c src/adt/liststatik/liststatik.c src/adt/makanan/makanan.c src/adt/map/map.c src/adt/matriks/matriks.c src/adt/point/point.c src/adt/prioqueue/prioqueue.c src/adt/set/set.c src/adt/simulator/simulator.c src/adt/stack/stack.c src/adt/tree/tree.c src/adt/waktu/waktu.c src/adt/wordmachine/wordmachine.c src/app/commands/commands.c src/app/display/display.c src/app/filereader/filereader.c src/app/parser/parser.c -o driver
	echo Compilation done!
	driver
) ELSE IF EXIST src/app/%file% (
	echo Compiling...
	gcc src/app/%file%/%file%_driver.c src/adt/charmachine/charmachine.c src/adt/eltype/eltype.c src/adt/listdin/listdin.c src/adt/listdineltype/listdineltype.c src/adt/liststatik/liststatik.c src/adt/makanan/makanan.c src/adt/map/map.c src/adt/matriks/matriks.c src/adt/point/point.c src/adt/prioqueue/prioqueue.c src/adt/set/set.c src/adt/simulator/simulator.c src/adt/stack/stack.c src/adt/tree/tree.c src/adt/waktu/waktu.c src/adt/wordmachine/wordmachine.c src/app/commands/commands.c src/app/display/display.c src/app/filereader/filereader.c src/app/parser/parser.c -o driver
	echo Compilation done!
	driver
) ELSE (
	echo No ADT/APP named %file%.
)

pause