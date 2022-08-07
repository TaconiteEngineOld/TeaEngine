make:
	nelua main.nelua --cc "zig cc" --cflags="-L ." -o ../binaries/bin && ../binaries/bin

docs:
	nelua --scripts gen-docs

clean:
	rm ./bin/*
