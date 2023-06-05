#!/bin/bash

echo "Enter a number:"
read number

isPrime=true

if [ $number -eq 1 ]; then
    isPrime=false
fi

for ((i=2; i<=$number/2; i++))
do
    if [ $((number%i)) -eq 0 ]; then
        isPrime=false
        break
    fi
done

if $isPrime; then
    echo "$number is a prime number."
else
    echo "$number is not a prime number."
fi
