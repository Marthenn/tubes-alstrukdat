@echo off
echo Compiling...
gcc src/main.c src/adt/implementasi/*.c src/app/implementasi/*.c -o main
echo Compilation done!
main
pause
