#!/bin/bash

# Compile the C++ program
g++ if_leap_year.cpp -o a.out

# Array of test years
echo "----Leap year-----"
a=(1968 2004 2012 1200 1600 2000)

for i in "${a[@]}"; do
    output=$(echo "$i" | ./a.out)
    if [[ $output == *"Leap Year"* ]]; then
        echo ">>$i: OK"
    else
        echo ">>$i: KO"
    fi
done
echo "--Not Leap year---"

a2=(1971 2006 2010 1700 1800 1900)

for i in "${a2[@]}";
do
	output=$(echo $i | ./a.out)
	if [[ $output == *"Not Leap Year"* ]]; then
		echo ">>$i: OK"
	else
		echo ">>$i: KO"
	fi
done