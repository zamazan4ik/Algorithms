@echo off
del test.txt
for %%i in (1 2 3) do call one.bat %1 %%i