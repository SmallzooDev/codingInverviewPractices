#!/bin/bash

root_dir=$(git rev-parse --show-toplevel)

echo "루트 디렉토리에서 실행 파일을 삭제합니다..."
find "$root_dir" -maxdepth 1 -type f -name "problem_*" -exec rm -f {} \;

echo "루트 디렉토리에서 실행 파일을 삭제했습니다."
