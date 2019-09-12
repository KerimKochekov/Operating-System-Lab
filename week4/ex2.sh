#!/bin/bash
gcc ex2.c
./a.out &
for i in {1..5} ; do
	pstree
	sleep 5
done
