CC = sdcc

SDCC_INCLUDE = "/usr/share/sdcc/include/"

CXXFLAGS = -mmcs51 -I$(SDCC_INCLUDE)

CXXMAIN = main.c

SRCFILES = $(wildcard *.c)
OBJFILES = $(filter-out main.rel, $(SRCFILES:.c=.rel))

main.ihx: $(OBJFILES)
	$(CC) $(CXXFLAGS) $(CXXMAIN) $^

%.rel: %.c
	$(CC) $(CXXFLAGS) -c $<

clean:
	@echo "cleaning files..."
	@rm -f *.asm *.ihx *.lk *.lst *.map *.mem *.rel *.rst *.sym *.cod
	@echo "clean done! :D"