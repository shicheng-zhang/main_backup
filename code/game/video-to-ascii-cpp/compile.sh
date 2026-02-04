#!/bin/bash
g++ -std=c++17 convert_ascii_image.c++ -o convert_ascii_image $(pkg-config --cflags --libs opencv4)
./convert_ascii_image
