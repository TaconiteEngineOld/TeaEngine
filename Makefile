make:
	nelua main.nelua --cc "zig cc" --cflags="-L ." --print-code | tee out/main.c
	nelua main.nelua --cc "zig cc" --cflags="-L ." --print-ast | tee out/main.ast
	nelua main.nelua --cc "zig cc" --cflags="-L ." -o ./out/bin && ./out/bin

clean:
	rm ./bin/*
