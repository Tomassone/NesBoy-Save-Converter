
objs = main.o pkmn_gb.o pkmn_nes.o ui.o 

vpath %.h header_files
vpath %.c source_files

nesboy : $(objs)
	gcc -o nesboy $(objs)
	
main.o : main.c
	gcc -c main.c

pkmn_gb.o : pkmn_gb.c pkmn_gb.h
	gcc -c pkmn_gb.c
	
pkmn_nes.o : pkmn_nes.c pkmn_nes.h
	gcc -c pkmn_nes.c
	
ui.o : ui.c ui.h
	gcc -c ui.c
	
clean :
	rm edit $(objs)
