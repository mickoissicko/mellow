BUILD_SCRIPT := './build.sh'

all:
	@echo 'no targets specified'

sh:
	@echo 'building...'
	@$(BUILD_SCRIPT)

clean:
	@echo 'cleaning up'
	rm -rf obj/*.o
	rm -rf build/mellow

