#!/bin/bash
cnt=0
dabao(){
	echo $1 $2
	tar -czvf "$2"/"$1".tar.gz -C "$2" "$1"
}
day(){
	for i in "$1"/*
	do
		name="$(basename "$i")"
		if [[ $i != *.gz ]]; then
			dabao "$name" "$1"
			rm -rf "$i"
		else
			echo "$i"
			cnt=$((cnt+1))
		fi
	done
}

month(){
	for i in "$1"/*
	do
		day $i
	done
}

for file in /mnt/z/MyData/小秘密/爬C站/*
do
	if [ -d $file ]; then
		echo "nian"
		echo $file
		
		for file_a in "$file"/*
		do
			month $file_a
		done
	fi
done
echo "cnt" $cnt
