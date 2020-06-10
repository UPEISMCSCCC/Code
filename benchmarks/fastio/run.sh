>&2 echo ============
>&2 echo Single Digit
>&2 echo ============
./test_stream.exe < testcase0.txt
>&2 echo
>&2 echo - UNLOCKED FASTIO
time ./test_notebook.exe < testcase0.txt
>&2 echo
>&2 echo - STD STREAMS
time ./test_stream.exe < testcase0.txt
>&2 echo
>&2 echo - FASTIO STREAMS
time ./test_stream_fast.exe < testcase0.txt
>&2 echo
>&2 echo - SCANF
time ./test_scanf.exe < testcase0.txt
>&2 echo
>&2 echo - GETCHAR/PUTCHAR
time ./test_locked.exe < testcase0.txt
>&2 echo
>&2 echo - BUFFERED
time ./test_buffer.exe < testcase0.txt

>&2 echo

>&2 echo ===========
>&2 echo Many Digits
>&2 echo ===========
./test_stream.exe < testcase1.txt
>&2 echo
>&2 echo - UNLOCKED FASTIO
time ./test_notebook.exe < testcase1.txt
>&2 echo
>&2 echo - STD STREAMS
time ./test_stream.exe < testcase1.txt
>&2 echo
>&2 echo - FASTIO STREAMS
time ./test_stream_fast.exe < testcase1.txt
>&2 echo
>&2 echo - SCANF
time ./test_scanf.exe < testcase1.txt
>&2 echo
>&2 echo - GETCHAR/PUTCHAR
time ./test_locked.exe < testcase1.txt
>&2 echo
>&2 echo - BUFFERED
time ./test_buffer.exe < testcase1.txt
