ASM=ca65
LINK=ld65
TYPE=cx16
INC=src/include/
TESTS=tests/

hello:
	$(ASM) -t $(TYPE) -I $(INC) -l $(TESTS)/text/kernal-print.lst $(TESTS)/text/kernal-print.asm
	$(LINK) -t $(TYPE) -o $(TESTS)/text/KERNAL-PRINT.PRG $(TESTS)/text/kernal-print.o cx16.lib

petscii:
	$(ASM) -t $(TYPE) -I $(INC) -l $(TESTS)/text/kernal-pestcii.lst $(TESTS)/text/kernal-petscii.asm
	$(LINK) -t $(TYPE) -o $(TESTS)/text/KERNAL-PETSCII.PRG $(TESTS)/text/kernal-petscii.o cx16.lib