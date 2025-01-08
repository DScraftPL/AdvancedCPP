.PHONY: run

run:
	@g++ -std=c++17 ./*.cpp -I./googletest/googletest/include/ -I./googletest/googlemock/include/ -L./googletest/build/lib/ -lgmock -lgtest -pthread
	@./a.out
