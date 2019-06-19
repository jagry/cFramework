#!/bin/bash

SOURCES=( "byteMap.c" "byteMapIterator.c" "byteMapNode.c" )

if [[ $# -ne 1 ]];
	then
		echo need 1 argument
		exit 1
	fi

OBJECTS=""
for SOURCE in "${SOURCES[@]}"
	do
		OBJECT=$SOURCE.o
		echo Compiling $SOURCE
		gcc -c -DDEBUG -o $OBJECT ../../source/map/$SOURCE -I../../include
		STATUS="$?"
		if [ $STATUS -ne 0 ]; then

			break
		fi
		OBJECTS="$OBJECTS $OBJECT"
	done
echo Status: $STATUS
if [ $STATUS -eq 0 ]; then
	$(ar -r $1 $(echo $OBJECTS))
fi
rm *.o
