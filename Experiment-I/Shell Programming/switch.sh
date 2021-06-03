#!/bin/sh

echo "Welcome to this OS Lab Program By Chiranjeet Under Dr. Deepa K."
read -p "Enter any single character :" ch

case $ch in
    [0-9]*)
        echo "Input is a digit!"
        ;;

    [a-z]*|[A-Z]*)
        echo "Input is a character!"
        ;;

    *)
        echo "Input is a non alphanumeric character"
        ;;
esac
