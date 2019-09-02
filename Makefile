all:
	mkdir -p bin/
	gcc src/main.c -o bin/sgets -ldl

install:
	cp bin/sgets ~/.local/bin/

uninstall:
	rm -f ~/.local/bin/sgets

clean:
	rm -rf bin/
