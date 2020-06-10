echo Single Digit
./test_stream.exe < testcase0.txt
echo
echo - UNLOCKED FASTIO
time ./test_notebook.exe < testcase0.txt
echo - STD STREAMS
time ./test_stream.exe < testcase0.txt
echo - FASTIO STREAMS
time ./test_stream_fast.exe < testcase0.txt
echo - SCANF
time ./test_scanf.exe < testcase0.txt
echo - GETCHAR/PUTCHAR
time ./test_locked.exe < testcase0.txt
echo - BUFFERED
time ./test_buffer.exe < testcase0.txt

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
echo - SCANF
time ./test_scanf.exe < testcase1.txt
echo - GETCHAR/PUTCHAR
time ./test_locked.exe < testcase1.txt
echo - BUFFERED
time ./test_buffer.exe < testcase1.txt
