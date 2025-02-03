i=1
while [ $i -le 12 ]
do
    mkdir program$i
    cd program$i
    touch Main.java
    cd ..
    i=$(($i+1))
done