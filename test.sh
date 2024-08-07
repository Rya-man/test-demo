cd $1

i=1
mkdir partA
cd partA
while [ $i -le 7 ]
do
	mkdir 'pgrm'$i
	cp  $2 'pgrm'$i/$i.cpp
	i=$(($i + 1))
done
cd ../
mkdir partB
cd partB

i=1
while [ $i -le 6 ]
do
	mkdir 'pgrm'$i
	cp  $2 'pgrm'$i/$i.cpp
	i=$(($i + 1))
done
