cd $1

i=0
while [ $i -le 12 ]
do
	mkdir 'pgrm'$i
	cp  $2 'pgrm'$i/$i.cpp
	i=$(($i + 1))
done

