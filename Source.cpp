#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <vector>
#include <iostream>
#include <fstream>

const int SIZE = 7;
int arrows = 5;

int array[SIZE][SIZE];

std::random_device rd;
std::mt19937 eng(rd());
std::uniform_int_distribution<> distr(0, SIZE - 1);
std::vector <std::string> myVector;

bool checkUniqueness(int x, int y) {

	std::string s = std::to_string(x);
	std::string t = std::to_string(y);
	std::string u = s + t;

	bool result = true;

	for (int i = 0; i < myVector.size(); i++) {
		if (myVector[i] == u) {
			result = false;
		}

	}
	if (result==true) {
		myVector.push_back(u);
	}
	
	return result;

}


int main() {

	int startingRow = distr(eng);
	int startingCol = distr(eng);

	std::string s = std::to_string(startingRow);
	std::string t = std::to_string(startingCol);
	std::string u = s + t;

	myVector.push_back(u);

	int wumpusRow= distr(eng);
	int wumpusCol = distr(eng);

	while (checkUniqueness(wumpusRow, wumpusCol) == false) {
		wumpusRow = distr(eng);
		wumpusCol = distr(eng);
	}


	int bat1Row = distr(eng);
	int bat1Col = distr(eng);

	while (checkUniqueness(bat1Row, bat1Col) == false) {
		bat1Row = distr(eng);
		bat1Col = distr(eng);
	}
	
	int bat2Row = distr(eng);
	int bat2Col = distr(eng);

	while (checkUniqueness(bat2Row, bat2Col) == false) {
		bat2Row = distr(eng);
		bat2Col = distr(eng);
	}

	int pit1Row = distr(eng);
	int pit1Col = distr(eng);

	while (checkUniqueness(pit1Row, pit1Col) == false) {
		pit1Row = distr(eng);
		pit1Col = distr(eng);
	}

	int pit2Row = distr(eng);
	int pit2Col = distr(eng);

	while (checkUniqueness(pit2Row, pit2Col) == false) {
		pit2Row = distr(eng);
		pit2Col = distr(eng);
	}

	int arrow1Row = distr(eng);
	int arrow1Col = distr(eng);

	while (checkUniqueness(arrow1Row, arrow1Col) == false) {
		arrow1Row = distr(eng);
		arrow1Col = distr(eng);
	}

	int arrow2Row = distr(eng);
	int arrow2Col = distr(eng);

	while (checkUniqueness(arrow2Row, arrow2Col) == false) {
		 arrow2Row = distr(eng);
		 arrow2Col = distr(eng);
	}


	std::string choice;

	do {
		//player
		if (startingRow < 0) {
			startingRow = 0;
		}
		if (startingRow > SIZE - 1) {
			startingRow = SIZE - 1;
		}
		if (startingCol < 0) {
			startingCol = 0;
		}
		if (startingCol > SIZE - 1) {
			startingCol = SIZE - 1;
		}
		//wumpus
		if (wumpusRow < 0) {
			wumpusRow = 0;
		}
		if (wumpusRow > SIZE - 1) {
			wumpusRow = SIZE - 1;
		}
		if (wumpusCol < 0) {
			wumpusCol = 0;
		}
		if (wumpusCol > SIZE - 1) {
			wumpusCol = SIZE - 1;
		}

		std::string message;
		if (arrows<1 && arrow1Row==-1 && arrow2Row==-1) {
			std::cout << "GAME OVER, you don't have anymore arrows! \n";
			break;
		}

		if (startingRow == wumpusRow && startingCol == wumpusCol) {
			
			std::cout << "GAME OVER, the wumpus ate you! \n";
			break;

		}
		else if ((startingRow == pit1Row && startingCol == pit1Col) || (startingRow == pit2Row && startingCol == pit2Col)) {
			
			std::cout << "GAME OVER, you fell into a pit! \n";
			break;

		}
		else if (startingRow == arrow1Row && startingCol == arrow1Col) {

			message = "You found a magical Wumpus - Killing arrow! \n";
			arrow1Row = -1;
			arrow1Col = -1;
			arrows++;

		}
		else if (startingRow == arrow2Row && startingCol == arrow2Col) {

			message = "You found a magical Wumpus - Killing arrow! \n";
			arrow2Row = -1;
			arrow2Col = -1;
			arrows++;

		}
		else if ((startingRow == bat1Row && startingCol == bat1Col) || (startingRow == bat2Row && startingCol == bat2Col)) {

			startingRow = distr(eng);
			startingCol = distr(eng);
			std::cout << "A bat just carried you away! \n";
			continue;
			
		}

		else if ((startingCol == wumpusCol && (startingRow + 1 == wumpusRow || startingRow - 1 == wumpusRow)) ||
			(startingRow == wumpusRow && (startingCol + 1 == wumpusCol || startingCol - 1 == wumpusCol))
			) {
			message = "You smell a foul stench nearby \n";
		}
		else if ((startingCol == bat1Col && (startingRow + 1 == bat1Row || startingRow - 1 == bat1Row)) ||
			(startingRow == bat1Row && (startingCol + 1 == bat1Col || startingCol - 1 == bat1Col))
			) {
			message = "You hear flapping nearby \n";
		}
		else if ((startingCol == bat2Col && (startingRow + 1 == bat2Row || startingRow - 1 == bat2Row)) ||
			(startingRow == bat2Row && (startingCol + 1 == bat2Col || startingCol - 1 == bat2Col))
			) {
			message = "You hear flapping nearby \n";
		}
		else if ((startingCol == pit1Col && (startingRow + 1 == pit1Row || startingRow - 1 == pit1Row)) ||
			(startingRow == pit1Row && (startingCol + 1 == pit1Col || startingCol - 1 == pit1Col))
			) {
			message = "You feel a breeze nearby \n";
		}
		else if ((startingCol == pit2Col && (startingRow + 1 == pit2Row || startingRow - 1 == pit2Row)) ||
			(startingRow == pit2Row && (startingCol + 1 == pit2Col || startingCol - 1 == pit2Col))
			) {
			message = "You feel a breeze nearby \n";
		}
		else {
		}

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				
				if (i == startingRow && j == startingCol) {
					std::cout << "[ * ]" << " ";
				}

				/*
				else if (i == wumpusRow && j == wumpusCol) {
					std::cout << "[ W ]" << " ";
				}
				else if (i == bat1Row && j == bat1Col) {
					std::cout << "[ B ]" << " ";
				}
				else if (i == bat2Row && j == bat2Col) {
					std::cout << "[ B ]" << " ";
				}
				else if (i == pit1Row && j == pit1Col) {
					std::cout << "[ P ]" << " ";
				}
				else if (i == pit2Row && j == pit2Col) {
					std::cout << "[ P ]" << " ";
				}
				else if (i == arrow1Row && j == arrow1Col) {
					std::cout << "[ A ]" << " ";
				}
				else if (i == arrow2Row && j == arrow2Col) {
					std::cout << "[ A ]" << " ";
				}

				*/

				else {
					std::cout << "[   ]" << " ";
				}
				
				
			}
			std::cout << "\n \n";

		}

		std::cout << "Arrows left: " << arrows << std::endl;

		std::cout << "Controls: u=up, d=down, r=right, l=left, su=shoot up, sd=shoot down, sr=shoot right, sl=shoot left, "

			<< "s=save, ld=load game, n=new game, q=quit. Press Enter to make the move. \n \n";

		std::cout << message;

		std::cin >> choice;
		
		system("cls");

		if (choice == "d") {
			startingRow++;
		
		}
		else if (choice=="u") {
			startingRow--;
		}
		else if (choice=="r") {
			startingCol++;
		}
		else if (choice=="l") {
			startingCol--;

		}
		else if (choice == "su") { //shooting up
			if (arrows>0) {
				arrows--;
				if ((startingCol==wumpusCol && startingRow-1==wumpusRow) || (startingCol == wumpusCol && startingRow - 2 == wumpusRow) ||
					(startingCol == wumpusCol && startingRow - 3 == wumpusRow)) {
					std::cout << "CONGRATULATIONS, you killed the wumpus! \n";
					break;
				}
				else {
					std::uniform_int_distribution<> distr(1, 4);
					int rand= distr(eng);
					if (rand == 1) {
						wumpusCol++;
					}
					else if (rand==2) {
						wumpusCol--;
					}
					else if (rand==3) {
						wumpusRow++;
					}
					else {
						wumpusRow--;
					}
					continue;
				}
			}
			

		}
		//shooting down
		else if (choice == "sd") { 
			if (arrows>0) {
				arrows--;
				if ((startingCol == wumpusCol && startingRow + 1 == wumpusRow) || (startingCol == wumpusCol && startingRow + 2 == wumpusRow) ||
					(startingCol == wumpusCol && startingRow + 3 == wumpusRow)) {
					std::cout << "CONGRATULATIONS, you killed the wumpus! \n";
					break;
				}
				else {
					std::uniform_int_distribution<> distr(1, 4);
					int rand = distr(eng);
					if (rand == 1) {
						wumpusCol++;
					}
					else if (rand == 2) {
						wumpusCol--;
					}
					else if (rand == 3) {
						wumpusRow++;
					}
					else {
						wumpusRow--;
					}
					continue;
				}
			}


		}

		//shooting right
		else if (choice == "sr") { 
			if (arrows>0) {
				arrows--;
				if ((startingRow == wumpusRow && startingCol + 1 == wumpusCol) || (startingRow == wumpusRow && startingCol + 2 == wumpusCol) ||
					(startingRow == wumpusRow && startingCol + 3 == wumpusCol)) {
					std::cout << "CONGRATULATIONS, you killed the wumpus! \n";
					break;
				}
				else {
					std::uniform_int_distribution<> distr(1, 4);
					int rand = distr(eng);
					if (rand == 1) {
						wumpusCol++;
					}
					else if (rand == 2) {
						wumpusCol--;
					}
					else if (rand == 3) {
						wumpusRow++;
					}
					else {
						wumpusRow--;
					}
					continue;
				}
			}


		}

		//shooting left
		else if (choice == "sl") {
			if (arrows>0) {
				arrows--;
				if ((startingRow == wumpusRow && startingCol - 1 == wumpusCol) || (startingRow == wumpusRow && startingCol - 2 == wumpusCol) ||
					(startingRow == wumpusRow && startingCol - 3 == wumpusCol)) {
					std::cout << "CONGRATULATIONS, you killed the wumpus! \n";
					break;
				}
				else {
					std::uniform_int_distribution<> distr(1, 4);
					int rand = distr(eng);
					if (rand == 1) {
						wumpusCol++;
					}
					else if (rand == 2) {
						wumpusCol--;
					}
					else if (rand == 3) {
						wumpusRow++;
					}
					else {
						wumpusRow--;
					}
					continue;
				}
			}


		}
		else if (choice == "n") {
			main();
		}
		else if (choice == "s") {
			std::ofstream myFile;
			myFile.open("save.txt");
			//saving all variable values
			myFile << arrows << "\n" << arrow1Row << arrow1Col << "\n" << arrow2Row << arrow2Col << "\n" << startingRow
				<< startingCol << "\n" << wumpusRow << wumpusCol << "\n" << bat1Row << bat1Col << "\n" << bat2Row << bat2Col <<
				"\n" << pit1Row << pit1Col << "\n" << pit2Row << pit2Col ;
			myFile.close();
		}

		else if (choice == "ld") {
			std::string line;
			std::ifstream myfile("save.txt");

			if (myfile.is_open()) {
				int counter = 0;
				while (!myfile.eof()) {
					getline(myfile, line);
					if (counter==0) {
						arrows = line[0] - 48;
					}
					else if(counter==1) {
						arrow1Row= line[0] - 48;
						arrow1Col = line[1] - 48;
					}
					else if(counter == 2) {
						arrow2Row = line[0] - 48;
						arrow2Col = line[1] - 48;
					}
					else if(counter == 3) {
						startingRow = line[0] - 48;
						startingCol = line[1] - 48;
					}
					else if(counter == 4) {
						wumpusRow = line[0] - 48;
						wumpusCol = line[1] - 48;
					}
					else if(counter == 5) {
						bat1Row = line[0] - 48;
						bat1Col = line[1] - 48;
					}
					else if (counter == 6) {
						bat2Row = line[0] - 48;
						bat2Col = line[1] - 48;
					}
					else if (counter == 7) {
						pit1Row = line[0] - 48;
						pit1Col = line[1] - 48;
					}
					else {
						pit2Row = line[0] - 48;
						pit2Col = line[1] - 48;
					}
					counter++;

				}
				myfile.close();
			}

			else {
				std::cout << "Unable to open file" << std::endl;
			}
			continue;

		}

		else {
			break;
		}

	} while (choice !="q");

	std::string choice2;
	std::cout << "Type n for new game and to see more options \n";

	std::cin >> choice2;

	if (choice2=="n") {
		system("cls");
		main();
	}


}