#!/bin/bash



i=0
temp=0
initial=$(./tempRead)
check=$?
if [ $check -eq 1 ]; then
	echo "No temperature sensor detected"
fi
diff=0


while [ $i -lt 4 ]; do
	gpio mode $i out
	gpio write $i 0
	let i=i+1
	
done


for (( ; ; )); do

	sleep .5
	temp=$(./tempRead)
	check=$?
	if [ $check -eq 1 ]; then
		echo "No temperature sensor detected"
	else
		
		temp=$(./tempRead)
                diff=$(($temp-$initial))
                diff=$(($diff/1000))
                i=$(($diff))

                for(( ; i < 4; i++)); do
                        i=$(($i+1))
                        gpio write $i 0
                done
                
                i=$(($diff))
                for(( ; i > 0; i-- )); do
                        i=$(($i-1))
                        gpio write $i 1
                done

	fi
	
done
