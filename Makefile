make:
	nelua main.nelua --cflags="-L ." --print-code | tee out/main.c
	nelua main.nelua --cflags="-L ." --print-ast | tee out/main.ast
	nelua main.nelua --cflags="-L ." -o ./out/bin && ./out/bin

clean:
	rm ./bin/*
