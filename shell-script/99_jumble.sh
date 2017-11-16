#!/bin/bash

# unscramble

wordlib="/usr/lib/games/long-words.txt"
randomquote="$HOME/bin/randomquote"

scrambleword()
{
	match="$($randomquote $wordlib)"
	echo "Picked out a word!"
	len=$(echo $match | wc -c | sed 's/[^[:digit:]]//g')
	scrambled=""; lastval=1
	for((val=1; $val < $len; ))
	do
		if [$(perl -e "print int rand(2)") -eq 1]; then
			scrambled=$scrambled$(echo $match | cut -c$val)
		else
			scrambled=$(echo $match | cut -c$val)$scrambled
		fi
		val=$(( $val + 1 ))
	done
}
	

