	#!/bin/bash
for ((t=0;;t++)); do
	printf "\r%d" $t
	./gen >data/inp.txt
	./B <data/inp.txt >data/B.txt || exit 1
	./A <data/inp.txt >data/A.txt || exit 2
	diff data/B.txt data/A.txt || exit 3
done