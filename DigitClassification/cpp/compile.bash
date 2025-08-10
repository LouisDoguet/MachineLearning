#!/bin/bash

CXX=g++
CXXFLAGS="-std=c++17 -Wall -Wextra -O2" 

INCLUDES="-Icommon"
SOURCES="src"

SRC=$(find common src -name "*.cpp")

$CXX $CXXFLAGS $INCLUDES $SRC -o prog 
