# compile and test all *.in and *.ans
g++ -g -O2 -std=gnu++17 -static prog.cpp
for i in *.in; do
	f=${i%.in}
	./a.exe < $i > "$f.out"
	diff -b -q "$f.ans" "$f.out"
done
