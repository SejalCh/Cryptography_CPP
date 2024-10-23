#!/bin/bash

# Compile the C++ program
g++ crypto.cpp -o crypto_tool

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Running the program..."
    
    # Run the C++ executable
    ./crypto_tool
else
    echo "Compilation failed!"
fi

