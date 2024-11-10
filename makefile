CC = g++
CFLAGS = -std=c++17 -Icommon




# 문제 problem_1-A
problem_1-A: problems/problem_1-A/main.cpp
	g++ -std=c++17 -Icommon problems/problem_1-A/main.cpp -o problem_1-A


# 문제 problem_1-B
problem_1-B: problems/problem_1-B/main.cpp
	g++ -std=c++17 -Icommon problems/problem_1-B/main.cpp -o problem_1-B
	./problem_1-B 

