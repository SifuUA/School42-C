cd test_invalid_tetriminos
for dir in `find * -maxdepth 0 -type d`
do
../fillit $dir/task.txt > $dir/usr-answer.txt
if (! cmp $dir/usr-answer.txt $dir/answer.txt)
then echo "Test $dir: Error"
else echo "Test $dir: Ok"
fi
done
