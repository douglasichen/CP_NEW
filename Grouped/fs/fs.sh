#!/bin/bash
for ((t=0;;t++)); do
	printf "\r%d" $t
	./gen >input.txt
	./solve <input.txt >slow.txt || exit 1
	./main <input.txt >fast.txt || exit 2
	diff slow.txt fast.txt || exit 3
done