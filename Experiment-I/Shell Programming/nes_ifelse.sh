    #! /bin/bash

    echo "Welcome to this OS Lab Program By Chiranjeet Under Dr. Deepa K."
    echo "You are supposed to Enter 3 unequal numbers!"
    read -p "Enter a: " a
    read -p "Enter b: " b
    read -p "Enter c: " c
    $ans; $var
    if (( $a > $b ))
    then
        if (( $a > $c ))
        then
            ans=$a
            var=a
        else
            ans=$c
            var=c
        fi
    else
        if (( $b > $c ))
        then
            ans=$b
            var=b
        else
            ans=$c
            var=c
        fi
    fi

    echo "Greatest number is $var: $ans"