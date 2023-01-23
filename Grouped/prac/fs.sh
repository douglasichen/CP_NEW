#!bin/bash
for ((t=0;;t++)); do
	printf "\r%d" $t
	./gen >data/inp.txt
	./A <data/inp.txt >data/A.txt || exit 1
	./B <data/inp.txt >data/B.txt || exit 2
	diff data/A.txt data/B.txt || exit 3
done