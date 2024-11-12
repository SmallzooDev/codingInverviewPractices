# coding interview practices

## 00. init

```bash
chmod +x init.sh
chmod +x .git/hooks/pre-commit
chmod +x remove_executables.sh
./init.sh <문제 번호>
```

```bash
make problem_${문제번호}
```
위 커맨드와 함께 문제 번호를 입력하면 해당 문제의 디렉토리와 파일이 생성되고, makefile이 업데이트 됩니다.

이후 실행에서는 루트디렉토리에 생성된 executable을 실행하면 됩니다.(코드 변경이 없을 때)

```bash
./problem_${문제번호}
```

pre-commit 훅에는 remove_executables.sh가 등록되어 있습니다. 커밋 전에 실행되어 루트 디렉토리에 생성된 executable을 삭제합니다.
