cd $1

i=0
while [ $i -le 12 ]
do
	rm -rf 'pgrm'$i
	i=$(($i + 1))
done

