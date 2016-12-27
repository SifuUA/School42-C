cd time-test
for dir in `find * -maxdepth 0 -type d`
do
	time ../fillit $dir/task.txt > $dir/usr-answer.txt
	if (! cmp $dir/usr-answer.txt $dir/answer.txt)
		then echo "Test $dir: Error"
		else echo "Test $dir: Ok"
	fi
done
