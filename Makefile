make:
	nelua main.nelua --cc "zig cc" --cflags="-L ." --print-code | tee out/main.c
	nelua main.nelua --cc "zig cc" --cflags="-L ." --print-ast | tee out/main.ast
	nelua main.nelua --cc "zig cc" --cflags="-L ." -o ./out/bin && ./out/bin

docs:
	nelua --scripts gen-docs

clean:
	rm ./bin/*
