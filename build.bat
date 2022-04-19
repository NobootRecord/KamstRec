@echo off
tcc -o kamstrec32.exe -mwindows -m32 -lgdi32 -luser32 -lkernel32 main.c
tcc -o kamstrec64.exe -mwindows -m32 -lgdi32 -luser32 -lkernel32 main.c
pause