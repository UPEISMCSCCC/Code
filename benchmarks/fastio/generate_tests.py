from random import randint

f = open("testcase0.txt", "w")
for i in range(0, 10000000):
	f.write(str(randint(0, 9)) + '\n')
f.close()

f = open("testcase1.txt", "w")
for i in range(0, 10000000):
	f.write(str(randint(10000000, 99999999)) + '\n')
f.close()