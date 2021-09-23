#include <iostream>
#include "engine/RandomDice.h"

#include "games/clifford/YourSolver.h"

/////////////////////////////////////////////
// Paste a proper name e.g. "0&code=000000000000";
const char* yourName = "0&code=000000000000";
/////////////////////////////////////////////

#include "engine/WebClient.h"

int main(int argc, char** argv) {
	int EXITCODE = 0;

	RandomDice* rd = new RandomDice();

	DirectionSolver* dds = new YourSolver(rd);

	WebClient wcl(dds);
	try {
		wcl.run("ws://localhost:8080/codenjoy-contest/ws", yourName);
	}
	catch (const std::runtime_error& ex) {
		std::cout << "Runtime error happened: " << ex.what() << std::endl;
		EXITCODE = 1;
	}
	catch (const std::invalid_argument& iarex) {
		std::cout << "Invalid argument: " << iarex.what() << std::endl;
		EXITCODE = 2;
	}
	catch (websocketpp::lib::error_code e) {
		std::cout << e.message() << std::endl;
	}
	catch (...) {
		std::cout << "Something's definitely not right..." << std::endl;
		EXITCODE = 3;
	}
	std::cout << "Done";
	std::cin.get();

	delete dds;
	delete rd;

	return EXITCODE;
}
