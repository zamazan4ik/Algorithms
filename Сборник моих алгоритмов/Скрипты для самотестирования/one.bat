@echo off
del input.txt
del output.txt
copy %2.in input.txt
%1 < input.txt >output.txt
fc.exe %2.out output.txt >> test.txt