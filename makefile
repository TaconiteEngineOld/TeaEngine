make:
	nelua main.nelua --cflags="-L ." -o ./bin/out && ./bin/out

clean:
	rm ./bin/out
