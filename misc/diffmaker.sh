#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ] || [ -z "$4" ]; then
    echo "Usage"
    echo "The first argument is a program to be compared."
    echo "The second argument is another program to be compared."
    echo "The thrid argument is the frequnecy e.g) 99 == 99Hz, 1024 == 1KHz"
    echo "The fourth argument is the name of output"
else
    if [ ! -f ./$1 ] || [ ! -f ./$2 ]; then
	echo "ERROR: $1 does not exist in the directory"
    else
	perf record -F $3 -g "./$1"
	perf script | ../FlameGraph/stackcollapse-perf.pl > out.folded1
	
	perf record -F $3 -g "./$2"
	perf script | ../FlameGraph/stackcollapse-perf.pl > out.folded2

	../FlameGraph/difffolded.pl out.folded1 out.folded2 | ../FlameGraph/flamegraph.pl > "$4.svg"
    fi
fi
