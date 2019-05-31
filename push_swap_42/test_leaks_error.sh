#!/bin/bash

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`


echo "\n${green}1 test with duplicates push_swap${reset}"
ARG="9 4 6 8 2 6 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG > /dev/null && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with duplicates checker${reset}"
ARG="9 4 6 8 2 6 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with duplicates both${reset}"
ARG="9 4 6 8 2 6 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt




echo "\n${green}1 test with = INT_MAX push_swap${reset}"
ARG="9 4 6 8 2 2147483647 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG /dev/null && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with = INT_MAX checker${reset}"
ARG="9 4 6 8 2 2147483647 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with = INT_MAX both${reset}"
ARG="9 4 6 8 2 2147483647 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with > INT_MAX push_swap${reset}"
ARG="9 4 6 8 2 2147483648 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG /dev/null && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with > INT_MAX checker${reset}"
ARG="9 4 6 8 2 2147483648 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with > INT_MAX both${reset}"
ARG="9 4 6 8 2 2147483648 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt



echo "\n${green}1 test with = INT_MIN push_swap${reset}"
ARG="9 4 6 8 2 -2147483648 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG /dev/null && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with = INT_MIN checker${reset}"
ARG="9 4 6 8 2 -2147483648 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with = INT_MIN both${reset}"
ARG="9 4 6 8 2 -2147483648 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with < INT_MIN push_swap${reset}"
ARG="9 4 6 8 2 -2147483649 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG /dev/null && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with < INT_MIN checker${reset}"
ARG="9 4 6 8 2 -2147483649 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with < INT_MIN both${reset}"
ARG="9 4 6 8 2 -2147483649 5"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt



echo "\n${green}1 test with nothing push_swap${reset}"
ARG=""
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG /dev/null && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with nothing checker${reset}"
ARG=""
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with nothing both${reset}"
ARG=""
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt



echo "\n${green}1 test with invalid input push_swap${reset}"
ARG="5 6 1 7 4 gf 9"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG /dev/null && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with invalid input checker${reset}"
ARG="5 6 1 7 4 gf 9"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt

echo "\n${green}1 test with invalid input both${reset}"
ARG="5 6 1 7 4 gf 9"
echo "ARG = $ARG"
valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG && cat test.txt | grep "definitely lost"
rm test.txt