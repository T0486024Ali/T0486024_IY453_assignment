#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // for rand().
#include <ctime>   // for seeding rand.
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;

// Item class
class Item {
private:
    string name;
    string type; // weapon, armor, food.
    int value;
public:
 string GetName() {
	return name;
 }
 string GetType() {
	return type;
 }
 int GetValue() {
	return value;
 }
 Item(string n, string t, int v) {
    name = n;
    type = t;
    value = v;
 }
};

// Player class
class Player {
private:
    string name;
    int health;
    int attack;
    int defense;
    int score;
    vector<Item> inventory;
public:
 string GetName() {
	return name;
 }
 int GetHealth() {
	return health;
 }
 int GetAttack() {
	return attack;
 }
 int GetDefense() {
	return defense;
 }
 int GetScore() {
	return score;
 }
 void SetAttack(int attack){
	this->attack = attack;
 }
 void SetScore(int score){
	this->score = score;
 }void SetHealth(int health){
	this->health = health;
 }
 // Function to add an item.
 void FindItem(Player &player) {
	 cout << "\nYou found a sword!\n";
 	bool hassword = false;
 	for (Item item : inventory) {
 		if (item.GetName() == "Sword") {
 			hassword = true;
 		}
 	}
 	Item sword("Sword", "weapon", 3);
 	if (!hassword) {
 		inventory.push_back(sword);
 	}
 	else{
 		int attack = player.GetAttack();
 		attack += sword.GetValue();
 		player.SetAttack(attack);
 		player.GetAttack();
 		cout << "Your attack increased by " << sword.GetValue() << "!\n";
 	}
 }
 Player(string n) {
  name = n;
  health = 20;
  attack = 5;
  defense = 2;
  score = 0;
  }
  void ShowStats() {
   cout << "\n--- " << name << "'s Stats ---\n";
   cout << "Health: " << health << endl;
   cout << "Attack: " << attack << endl;
   cout << "Defense: " <<defense << endl;
   cout << "Score: " << score << endl;
   cout << "Inventory: ";
   if (inventory.empty()) cout << "None";
    	for (Item item : inventory) cout << item.GetName() << " ";
        cout << "\n--------------------\n";
   }

   // Writing to a file.
   bool WriteToFile(int currentscene) {
    fstream fs("savegame.txt", ios::out);

    if (!fs.is_open())
    {
        cout << "Error: Could not open save file.\n";
        return false;
    }

    // Write player information
    fs << name << endl;
    fs << health << endl;
    fs << attack << endl;
    fs << defense << endl;
    fs << score << endl;

    // Write current scene
    fs << currentscene << endl;

    // Write inventory size.
    fs << inventory.size() << endl;

    // Write items
    for ( Item item : inventory)
    {
        fs << item.GetName() << ","
           << item.GetType() << ","
           << item.GetValue() << endl;
    }

    if (fs.fail())
    {
        cout << "Error: Failed while writing save file.\n";
        return false;
    }

    fs.close();
    return true;
}

  // Reading from a file.
  bool LoadGame(int currentscene) {
    ifstream fs("savegame.txt");

    if (!fs.is_open())
    {
        cout << "Error: Save file not found.\n";
        return false;
    }

    string name;
    int health, attack, defense, score;
    int inventorysize;

    // Read player data
    if (!(fs >> name >> health >> attack >> defense >> score >> currentscene))
    {
        cout << "Error: Save file corrupted.\n";
        return false;
    }

    // Read inventory size
    if (!(fs >> inventorysize))
    {
        cout << "Error reading inventory size.\n";
        return false;
    }

    string line;
    getline(fs, line); // clear newline

    for (int i = 0; i < inventorysize; i++)
    {
        if (!getline(fs, line))
        {
            cout << "Error reading inventory item.\n";
            return false;
        }

        stringstream ss(line);

        string itemName, itemType, valueStr;

        if (!getline(ss, itemName, ',') ||
            !getline(ss, itemType, ',') ||
            !getline(ss, valueStr))
        {
            cout << "Error parsing inventory item.\n";
            return false;
        }
        int value = stoi(valueStr);
    }

    fs.close();

    cout << "Game loaded successfully!\n";
    return true;
}
};

// Combat scenario class.
class Combat{
public:
 // Combat function
 void CombatScenario(Player &player, string enemy_name, int enemy_power) {
    cout << "\nCombat! " << enemy_name << " appears!\n";
	int attack = player.GetAttack();
    int playerroll = attack + (rand() % 6 + 1);
    int enemyroll = enemy_power + (rand() % 6 + 1);
	player.SetAttack(playerroll);
    cout << "Your combat score: " << playerroll << endl;
    cout << enemy_name << "'s combat score: " << enemyroll << endl;
	int score = player.GetScore();
	int health = player.GetHealth();
    if (playerroll >= enemyroll) {
        cout << "You defeated the " << enemy_name << "!\n";
        score += 10;
		player.SetScore(score);
    } else {
        cout << "You were injured by the " << enemy_name << "!\n";
        health -= 5;
		player.SetHealth(health);
    }
 }
};

// Puzzle scenario class.
class Puzzle{
public:
 // Puzzle function.
 // Puzzle 1.
 void PuzzleScenario1(Player &player) {
    cout << "\nPuzzle Time!\n";
    cout << "What is 7 + 5? ";
    int answer;
    while (!(cin >> answer)) {
        cout << "Invalid input!\n";
        cout << "Please enter a valid input: \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	int score = player.GetScore();
	int health = player.GetHealth();
    if (answer == 12) {
        cout << "Correct! You gain 5 points.\n";
        score += 5;
		player.SetScore(score);
    } else {
        cout << "Wrong! You lose 3 health.\n";
        health -= 3;
		player.SetHealth(health);
    }
 }
	// Puzzle 2.
	void PuzzleScenario2(Player &player) {
 	cout << "\nPuzzle Time!\n";
 	cout << "What is 12 + 20? ";
 	int answer;
 	while (!(cin >> answer)) {
        cout << "Invalid input!\n";
        cout << "Please enter a valid input: \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
 	int score = player.GetScore();
 	int health = player.GetHealth();
 	if (answer == 32) {
 		cout << "Correct! You gain 5 points.\n";
 		score += 5;
 		player.SetScore(score);
 	} else {
 		cout << "Wrong! You lose 3 health.\n";
 		health -= 3;
 		player.SetHealth(health);
 	}
 }
};

// Scene class.
class Scene{
public:
 // Scenes functions.
 // Combat scene.
 bool Scene1(Player &player) {
    cout << "\nScene 1: You enter a dark cave.\n";
    cout << "1) Cross the rickety bridge\n";
    cout << "2) Swim in the shallow pool\n";
    int choice;
    while (!(cin >> choice)) {
        cout << "Invalid input!\n";
        cout << "Please enter a valid input: \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	int health = player.GetHealth();
	Combat combat = Combat();
    if (choice == 1) {
        combat.CombatScenario(player, "Cave Troll", 8);
    } else if (choice == 2) {
        cout << "You get bitten by leeches! Lose 1 health.\n";
        health -= 1;
		player.SetHealth(health);
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene1(player);
    }
    return true;
 }
 //	Item collection secne.
 bool Scene2(Player &player) {
    cout << "\nScene 2: You find a treasure chest.\n";
    cout << "1) Open it\n";
    cout << "2) Ignore it\n";
    int choice;
    while (!(cin >> choice)) {
        cout << "Invalid input!\n";
        cout << "Please enter a valid input: \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	int health = player.GetHealth();
    if (choice == 1) {
        player.FindItem(player);
    } else if (choice == 2) {
         cout << "You walk past the chest.\n";
         health -= 1;
		 player.SetHealth(health);
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene2(player);
    }
    return true;
 }
 // Puzzle scene 1.
 bool Scene3(Player &player) {
    cout << "\nScene 3: You had a really big problem.\n";
	Puzzle puzzle = Puzzle();
    puzzle.PuzzleScenario1(player);
    return true;
 }
 // puzzle scene 2.
 bool Scene4(Player &player) {
 	cout << "\nScene 4: You are stuck in a really embarrassing situation .\n";
 	Puzzle puzzle = Puzzle();
 	puzzle.PuzzleScenario2(player);
 	return true;
 }
};

// Main game loop.
int main() {
    srand(time(0));
    cout << "Enter your player name: ";
    string player_name;
	while (!getline(cin, player_name)) {
		cout << "Input error. Try again.\n";
	}
    Player player(player_name);
	Scene scene = Scene();
    cout << "\nWelcome, " << player.GetName() << "! Your adventure begins!\n";
	 int scenariocount = 0;
     // Game has 30 scenarios to call.
      while (scenariocount < 30 && player.GetHealth() > 0) {

        int randomScene = rand() % 4 + 1;

        if (randomScene == 1) {
            scene.Scene1(player);
        }
        else if (randomScene == 2) {
            scene.Scene2(player);
        }
        else if (randomScene == 3) {
            scene.Scene3(player);
        }
        else if (randomScene == 4) {
        	scene.Scene4(player);
        }
        scenariocount++;
	    player.WriteToFile(scenariocount);
		player.LoadGame(scenariocount);
        if (player.GetHealth() <= 0) {
            cout << "\nYou have no health left.\n";
            cout << "Game Over!\n";
            return 0;
        }
      }
	cout << "\nScenario " << scenariocount << " completed!\n";
    cout << "\nCongratulations! You completed the adventure.\n";
    cout << "Final Score: " << player.GetScore() << endl;
    player.ShowStats();
    return 0;
}