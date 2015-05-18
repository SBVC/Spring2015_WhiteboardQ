#!/bin/bash

mkdir -p ./bin
g++ ./src/main.cpp ./src/Student.cpp -o ./bin/whiteboard -lsqlite3
