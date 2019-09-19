#!/bin/bash
if [ ! -f ex2.txt ]; then
	echo 0 > ex2.txt
fi
for i in {1..100}
do
	n=$(tail -n 1 ex2.txt)
	n=$((n + 1))
	echo $n >> ex2.txt
done
