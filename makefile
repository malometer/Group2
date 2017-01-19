Lageneric: lageneric.o boundaries.o methods.o
	g++ -o Lageneric lageneric.o boundaries.o methods.o
	chmod 777 *

*.o: *.cpp
	g++ -o *.o *.cpp

.Phony:
clean:
	
	rm *.o
	rm Lageneric
	
	

