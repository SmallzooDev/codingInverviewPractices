#!/bin/bash

problem_number=$1

if [ -z "$problem_number" ]; then
  echo "문제 번호를 입력하세요."
  exit 1
fi

problem_dir="problem_${problem_number}"

mkdir -p "problems/$problem_dir"

echo '#include "../../common/common_headers.h"
using namespace std;

int main() {
    // 여기에 문제 풀이 로직을 작성합니다.
    
    std::cout << "문제 '${problem_number}' 풀이 시작!" << std::endl;

}
' > "problems/$problem_dir/main.cpp"

echo "
# 문제 $problem_dir
$problem_dir: problems/$problem_dir/main.cpp
	g++ -std=c++17 -Icommon problems/$problem_dir/main.cpp -o $problem_dir
	./$problem_dir 
" >> Makefile

echo "문제 $problem_dir 디렉토리와 Makefile을 업데이트했습니다."
