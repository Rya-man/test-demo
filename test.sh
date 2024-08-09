cd $1

i=1
mkdir partA
cd partA
while [ $i -le 7 ]
do
	cp  $2 $i.cpp
	i=$(($i + 1))
done
cd ../
mkdir partB
cd partB

i=1
while [ $i -le 6 ]
do
	cp  $2 $i.cpp
	i=$(($i + 1))
done
