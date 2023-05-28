#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <random>
#include <chrono>

#include "sources/Team2.hpp"
#include "sources/smartTeam.hpp"

using namespace std;
using namespace ariel;

//use in student demo

//<--------------------Helper Functions-------------------->
// https://www.geeksforgeeks.org/generate-a-random-float-number-in-cpp/
int random_int(int min = -100, int max = 100) {
	std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

double random_float(double min = -100, double max = 100) {
	std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
	std::uniform_real_distribution<double> distribution(min, max);

	return distribution(generator);
}

auto random_name = [](int type = 0) {
	static int c = 1, yn = 1, tn = 1, on = 1;
	stringstream ss;

	if (type == 0)
		ss << "Cowboy" << " " << c++;

	else if (type == 1)
		ss << "Young Ninja" << " " << yn++;

	else if (type == 2)
		ss << "Trained Ninja" << " " << tn++;

	else
		ss << "Old Ninja" << " " << on++;

	return ss.str();
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
	return new Cowboy{random_name(0), Point{x, y}};
};

auto create_yninja = [](double x = random_float(), double y = random_float()) {
	return new YoungNinja{random_name(1), Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
	return new TrainedNinja{random_name(2), Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
	return new OldNinja{random_name(3), Point{x, y}};
};

auto random_char(double x = random_float(), double y = random_float()) -> Character * {
	int flag = static_cast<int>(random_float()) % 4;

	if (flag == 0)
		return create_cowboy(x, y);

	if (flag == 1)
		return create_yninja(x, y);

	if (flag == 2)
		return create_tninja(x, y);

	return create_oninja(x, y);
}

auto simulate_battle = [](Team &team, Team &team2) {
	int i = 0;

	int rounds = 1;

	while (team.stillAlive() && team2.stillAlive())
	{
		cout << "Round " << rounds++ << ":" << endl;

		cout << "Team 1:" << endl;
		team.print();

		cout << "Team 2:" << endl;
		team2.print();

		if (i % 2 == 0)
		{
			cout << "Team 1 attacks Team 2:" << endl;
			team.attack(&team2);
		}

		else
		{
			cout << "Team 2 attacks Team 1:" << endl;
			team2.attack(&team);
		}

		i++;
	}

	cout << "Team " << (team.stillAlive() ? "1" : "2") << " won!" << endl;
	cout << "Total rounds: " << rounds << endl;
};

auto simulate_battle_steps = [](Team &team, Team &team2) {
	int i = 0;
	int rounds = 1;

	while (team.stillAlive() && team2.stillAlive())
	{
		cout << "Round " << rounds++ << ":" << endl;

		cout << "Team 1:" << endl;
		team.print();

		cout << "Team 2:" << endl;
		team2.print();

		if (i % 2 == 0)
		{
			cout << "Team 1 attacks Team 2:" << endl;
			team.attack(&team2);
		}

		else
		{
			cout << "Team 2 attacks Team 1:" << endl;
			team2.attack(&team);

			cout << "Press Enter to continue." << endl;
			cin.ignore(100000, '\n');
		}

		i++;
	}

	cout << "Team " << (team.stillAlive() ? "1" : "2") << " won!" << endl;
	cout << "Total rounds: " << rounds << endl;
};
//<-------------------------------------------------->

int main(void) {
	char battle_choice = '\0', team_choice = '\0';
	int team1_size = 0, team2_size = 0;

	cout << "Choose a battle mode:" << endl;
	cout << "1. Normal" << endl;
	cout << "2. Step by step" << endl;
	cin >> battle_choice;

	if (battle_choice != '1' && battle_choice != '2')
	{
		cout << "Invalid choice." << endl;
		return 1;
	}

	cout << "Choose a team type:" << endl;
	cout << "1. Team" << endl;
	cout << "2. Team2" << endl;
	cout << "3. SmartTeam" << endl;
	cout << "4. Random Mixed" << endl;
	cin >> team_choice;

	if (team_choice != '1' && team_choice != '2' && team_choice != '3' && team_choice != '4')
	{
		cout << "Invalid choice." << endl;
		return 1;
	}

	cout << "Choose team sizes (1-10):" << endl;
	cout << "Team 1: ";
	cin >> team1_size;

	cout << "Team 2: ";
	cin >> team2_size;

	if (team1_size < 1 || team2_size < 1 || team1_size > 10 || team2_size > 10)
	{
		cout << "Invalid team size." << endl;
		return 1;
	}

	cout << "Creating characters..." << endl;

	// Create characters
	vector<Character *> team1_members;
	vector<Character *> team2_members;

	team1_members.reserve((size_t)team1_size);
	team2_members.reserve((size_t)team2_size);

	for (int i = 0; i < team1_size; i++)
		team1_members.push_back(random_char());

	for (int i = 0; i < team2_size; i++)
		team2_members.push_back(random_char());

	cout << "Creating teams..." << endl;

	switch (team_choice)
	{
		case '1':
		{
			Team team1{team1_members.back()}, team2{team2_members.back()};
			team1_members.pop_back();
			team2_members.pop_back();

			for (auto member : team1_members)
				team1.add(member);

			for (auto member : team2_members)
				team2.add(member);

			if (battle_choice == '1')
				simulate_battle(team1, team2);

			else
				simulate_battle_steps(team1, team2);

			break;
		}

		case '2':
		{
			Team2 team1{team1_members.back()}, team2{team2_members.back()};
			team1_members.pop_back();
			team2_members.pop_back();

			for (auto member : team1_members)
				team1.add(member);

			for (auto member : team2_members)
				team2.add(member);

			if (battle_choice == '1')
				simulate_battle(team1, team2);

			else
				simulate_battle_steps(team1, team2);

			break;
		}

		case '3':
		{
			SmartTeam team1{team1_members.back()}, team2{team2_members.back()};
			team1_members.pop_back();
			team2_members.pop_back();

			for (auto member : team1_members)
				team1.add(member);

			for (auto member : team2_members)
				team2.add(member);

			if (battle_choice == '1')
				simulate_battle(team1, team2);

			else
				simulate_battle_steps(team1, team2);

			break;
		}

		case '4':
		{
			auto number = random_int(1, 9);

			switch (number)
			{
				case 1:
				{
					cout << "Team 1: Team, Team 2: Team" << endl;

					Team team1{team1_members.back()}, team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);

					if (battle_choice == '1')
						simulate_battle(team1, team2);

					else
						simulate_battle_steps(team1, team2);

					break;
				}

				case 2:
				{
					cout << "Team 1: Team, Team 2: Team2" << endl;

					Team team1{team1_members.back()};
					Team2 team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);

					if (battle_choice == '1')
						simulate_battle(team1, team2);

					else
						simulate_battle_steps(team1, team2);

					break;
				}

				case 3:
				{
					cout << "Team 1: Team, Team 2: SmartTeam" << endl;

					Team team1{team1_members.back()};
					SmartTeam team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);

					if (battle_choice == '1')
						simulate_battle(team1, team2);

					else
						simulate_battle_steps(team1, team2);

					break;
				}

				case 4:
				{
					cout << "Team 1: Team2, Team 2: Team" << endl;

					Team2 team1{team1_members.back()};
					Team team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);

					if (battle_choice == '1')
						simulate_battle(team1, team2);

					else
						simulate_battle_steps(team1, team2);

					break;
				}

				case 5:
				{
					cout << "Team 1: Team2, Team 2: Team2" << endl;

					Team2 team1{team1_members.back()}, team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);

					if (battle_choice == '1')
						simulate_battle(team1, team2);

					else
						simulate_battle_steps(team1, team2);

					break;
				}

				case 6:
				{
					cout << "Team 1: Team2, Team 2: SmartTeam" << endl;

					Team2 team1{team1_members.back()};
					SmartTeam team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);

					if (battle_choice == '1')
						simulate_battle(team1, team2);

					else
						simulate_battle_steps(team1, team2);

					break;
				}

				case 7:
				{
					cout << "Team 1: SmartTeam, Team 2: Team" << endl;

					SmartTeam team1{team1_members.back()};
					Team team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);

					if (battle_choice == '1')
						simulate_battle(team1, team2);

					else
						simulate_battle_steps(team1, team2);

					break;		
				}

				case 8:
				{
					cout << "Team 1: SmartTeam, Team 2: Team2" << endl;

					SmartTeam team1{team1_members.back()};
					Team2 team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);

					if (battle_choice == '1')
						simulate_battle(team1, team2);
					
					else
						simulate_battle_steps(team1, team2);

					break;
				}

				case 9:
				{
					cout << "Team 1: SmartTeam, Team 2: SmartTeam" << endl;

					SmartTeam team1{team1_members.back()}, team2{team2_members.back()};
					team1_members.pop_back();
					team2_members.pop_back();

					for (auto member : team1_members)
						team1.add(member);

					for (auto member : team2_members)
						team2.add(member);
					
					if (battle_choice == '1')
						simulate_battle(team1, team2);

					else
						simulate_battle_steps(team1, team2);
					
					break;
				}
			}

			break;
		}
	}

	return 0;
}