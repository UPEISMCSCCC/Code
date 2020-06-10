echo Single Digit
./test_stream.exe < testcase0.txt
echo
echo - UNLOCKED FASTIO
time ./test_notebook.exe < testcase0.txt
echo - STD STREAMS
time ./test_stream.exe < testcase0.txt
echo - FASTIO STREAMS
time ./test_stream_fast.exe < testcase0.txt

echo

echo Many Digits
./test_stream.exe < testcase1.txt
echo
echo - UNLOCKED FASTIO
time ./test_notebook.exe < testcase1.txt
echo - STD STREAMS
time ./test_stream.exe < testcase1.txt
echo - FASTIO STREAMS
time ./test_stream_fast.exe < testcase1.txt