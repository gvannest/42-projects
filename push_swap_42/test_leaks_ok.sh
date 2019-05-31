#!/bin/bash

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`


echo "\n${green}Starting 5 tests in range -15 to -5${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (-15..-5).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range 7 to 22${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (7..22).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range -50 to 50${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker $ARG >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range -50 to 50 for checker only with KO${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./checker $ARG >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range -50 to 50 for push_swap only${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range -50 to 50 with /dev/null as input for both push_swap and checker${reset}"
for i in {1..5}
do
	echo "Test $i"
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap /dev/null | ./checker /dev/null >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range -50 to 50 with /dev/null as input for push_swap and ARG as input for checker${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap /dev/null | ./checker $ARG >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range -50 to 50 with /dev/null as input for checker and ARG as input for push_swap${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker /dev/null >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done

echo "\n${green}Starting 5 tests in range -50 to 50 with /dev/urandom as input for both push_swap and checker${reset}"
for i in {1..5}
do
	echo "Test $i"
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap /dev/urandom | ./checker /dev/urandom >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range -50 to 50 with /dev/urandom as input for push_swap and ARG as input for checker${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap /dev/urandom | ./checker $ARG >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done


echo "\n${green}Starting 5 tests in range -50 to 50 with /dev/urandom as input for checker and ARG as input for push_swap${reset}"
for i in {1..5}
do
	echo "Test $i"
	ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="test.txt" ./push_swap $ARG | ./checker /dev/urandom >/dev/null && cat test.txt | grep "definitely lost"
	rm test.txt
done