make -C ../
rm ../tests/test_print.txt
./filler_vm -f ./maps/map00 -p1 ../gvannest.filler -p2 players/carli.filler | less
cat ../tests/test_print.txt


