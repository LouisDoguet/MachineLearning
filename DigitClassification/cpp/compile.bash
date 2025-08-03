#!/bin/bash

CXX=g++
CXXFLAGS="-std=c++17 -Wall" 

INCLUDES="-Icommon"
SOURCES="src"



SRC=$SOURCES/main.cpp


$CXX $CXXFLAGS $INCLUDES $SRC -o prog 
