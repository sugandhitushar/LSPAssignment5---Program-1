pipeDemo: program.c program.h
	gcc -o pipeDemo program.c

.PHONY: clean run
clean:
	rm pipeDemo
usage:
	@echo make
	@echo make run
