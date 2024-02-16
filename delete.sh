#!/bin/zsh

# Find and delete all executable files
# Be sure to review the list of files before running the delete command
# find . -type f -executable -exec rm -f {} \;

# find . -type f -executable -print

# find . -type f -name "*.exe" -print

find . -type f -name "*.exe" -exec rm -f {} \;

echo "Executable files have been deleted."
