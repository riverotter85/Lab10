@echo off
cls

g++ -I.\ -I.\Lab10Files -I.\Lab10Files\CSC2110 -c HybridDriver.cpp
g++ -L.\Lab10Files\CSC2110 -o Hybrid HybridDriver.o -lCSC2110
