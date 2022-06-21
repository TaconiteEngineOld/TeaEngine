make:
	nelua main.nelua --cflags="-L ." -o ./bin/out && ./bin/out

ast:
	nelua main.nelua --cflags="-L ." --print-ast

clean:
	rm ./bin/out
