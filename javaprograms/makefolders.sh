i=1
while [ $i -le 6 ]
do
    mkdir program$i
    cd program$i
    touch Main.java
    cd ..
    i=$(($i+1))
done