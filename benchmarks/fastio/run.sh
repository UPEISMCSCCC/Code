echo NOTEBOOK FASTIO
time ./test_notebook.exe < testcase0.txt
time ./test_notebook.exe < testcase1.txt

echo STD STREAMS
time ./test_stream.exe < testcase0.txt
time ./test_stream.exe < testcase1.txt