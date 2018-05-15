.PHONY: all dram_init debug siscope scan clean

all: dram_init

dram_init: clean
	make -f main.mk MK_DRAM_INIT=1

debug: clean
	make -f main.mk MK_DEBUG=1

siscope: clean
	make -f main.mk MK_SISCOPE=1

scan: clean
	make -f main.mk MK_SCAN=1

clean:
	make -f main.mk clean

