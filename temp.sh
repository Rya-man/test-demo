cd $1

i=1
while [ $i -le 10 ]
do
	touch 'pgrm'$i'.c'
	i=$(($i + 1))
done

