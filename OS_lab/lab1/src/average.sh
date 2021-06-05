sum=0
count=0 
for i in $@
do
let sum=sum+$i
let count=count+1
done

if [ $count -eq 0 ]
then
echo Arguments are empty set
else
echo Count $count
echo Sum $sum
let avg=sum/count
echo Average $avg
fi