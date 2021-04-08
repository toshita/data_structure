#!/bin/bash
make clean;
make;
valgrind --tool=memcheck --leak-check=yes ./list_main 
