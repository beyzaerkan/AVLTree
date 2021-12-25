all: compile link run
compile:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -I "./include" -c ./src/DogruKuyrugu.cpp -o ./lib/DogruKuyrugu.o
	g++ -I "./include" -c ./src/AgacDugum.cpp -o ./lib/AgacDugum.o
	g++ -I "./include" -c ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
link:
	g++ -o ./bin/program ./lib/Dugum.o ./lib/DogruKuyrugu.o ./lib/AgacDugum.o ./lib/AVLAgaci.o ./lib/main.o
run:
	./bin/program