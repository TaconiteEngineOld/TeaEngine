make:
	nelua main.nelua --cc "zig cc" --cflags="-L ." -o ./out/bin && ./out/bin

docs:
	nelua --scripts gen-docs

clean:
	rm ./bin/*
