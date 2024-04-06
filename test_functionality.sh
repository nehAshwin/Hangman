# Create a file with a test input
echo t >> win_input.txt
echo h >> win_input.txt
echo e >> win_input.txt
echo q >> win_input.txt
echo u >> win_input.txt
echo i >> win_input.txt
echo c >> win_input.txt
echo k >> win_input.txt
echo b >> win_input.txt
echo r >> win_input.txt
echo o >> win_input.txt
echo w >> win_input.txt
echo n >> win_input.txt
echo f >> win_input.txt
echo x >> win_input.txt
echo j >> win_input.txt
echo m >> win_input.txt
echo p >> win_input.txt
echo s >> win_input.txt
echo v >> win_input.txt
echo l >> win_input.txt
echo a >> win_input.txt
echo z >> win_input.txt
echo y >> win_input.txt
echo d >> win_input.txt
echo g >> win_input.txt

# Run your binary with the test input and redirect the output and errors to a separate file
./hangman zyxwvutsrqponmlkjihgfedcba < win_input.txt > win_output.txt 
my_returncode=$?

# Compare what was printed to stdout
diff win_output.txt win.txt
if [ $? -eq 0 ]; then
    echo "standard out doesn't match!"
    rm win_output.txt
    rm win_input.txt
    exit 1
fi

# Compare the return codes.
if [ 0 -ne $my_returncode ] ; then
    echo "Return codes don't match!"
    rm win_output.txt
    rm win_input.txt
    exit 1
fi

# Everything matches as expected!
echo "Working Correctly"
rm win_output.txt
rm win_input.txt
exit 0
