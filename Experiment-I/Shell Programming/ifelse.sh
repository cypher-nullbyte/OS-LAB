#! /bin/bash

echo "Welcome to this OS Lab Program By Chiranjeet Under Dr. Deepa K."
read -p "Enter number: " number
if [ $number -eq 10 ]
then
    echo "Equal to 10"
elif  (($number > 10))                
then 
    echo "Greater than 10"
else
    echo "Smaller than 10"
fi