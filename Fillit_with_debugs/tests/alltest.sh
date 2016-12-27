make

echo "Tests for invaid input:"
sh test_invalid_tetriminos.sh

echo "\nTests for valid input: "
sh test.sh

echo "\nTests for big time:"
sh time-test.sh

echo "\nOther tests:"
./fillit 
echo "\n must be 'usage: fillit input_file'\n"

./fillit test/00/task.txt test/01/task.txt
echo "\n must be 'usage: fillit input_file'\n"

./fillit not-existing-file
echo "\n must be 'error'\n"
