#!/bin/sh

if [ $# -eq 0 ]
	then
		echo "No argument supplied"
else
		curl -s $1 | grep "href" | cut -d \" -f 2
fi
