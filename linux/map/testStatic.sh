#!/bin/bash

./buildStatic.sh test.jl
STATUS="$?"
if [ $STATUS -ne 0 ]; then
	break
fi

rm test.jl
