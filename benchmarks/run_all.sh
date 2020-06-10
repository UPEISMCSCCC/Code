cd fastio
python generate_tests.py
./prerun.sh
./run.sh 2> ../benchmark_fastio.txt
cd ..
