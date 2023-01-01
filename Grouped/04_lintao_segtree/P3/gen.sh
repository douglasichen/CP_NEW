#!/bin/sh
echo "Number of Test Cases to Generate:"
read T

echo "Max 'N' and Max 'Val':"
read N

echo 'Seed:'
read SEED

echo 'Folder Name:'
read FOLDER

if [ ! -d $FOLDER ]; then 
	mkdir $FOLDER
fi

RANDOM=$SEED
i=1
while [ $i -le $T ]; do
	./gen $T $N $RANDOM > "$FOLDER/data.$i.in"
	i=$((i+1))
done