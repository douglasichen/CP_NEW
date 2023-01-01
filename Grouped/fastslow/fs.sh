#!/bin/bash
# g++ -o A A.cpp
# g++ -o B B.cpp
# g++ -o gen gen.cpp
for ((t=0;;t++)); do
	printf "\r%d" $t
	./gen >inp.txt
	./A <A.txt >A.txt || exit 1
	./B <B.txt >B.txt || exit 2
	diff A.txt B.txt || exit 3
done