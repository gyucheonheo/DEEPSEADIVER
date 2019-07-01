#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]; then
    echo "Usage"
    echo "The first argument is a program you want to analyze."
    echo "The second argument is the name of your svg file."
    echo "The thrid argument is the frequnecy ex) 99 == 99Hz, 1024 == 1KHz"
else
    if [ ! -f ./$1 ]; then
	echo "ERROR: $1 does not exist in the directory"
    else
	perf record -F $3 -g "./$1"
	perf script | ../FlameGraph/stackcollapse-perf.pl > out.folded-data
	../FlameGraph/flamegraph.pl out.folded-data > "$2.svg"
    fi
fi
