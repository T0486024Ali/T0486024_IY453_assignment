#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // for rand()
#include <ctime>   // for seeding rand

using namespace std;

// Item class
class Item {
public:
    string name;
    string type; // weapon, armor, food
    int value;

    Item(string n, string t, int v) {
        name = n;
        type = t;
        value = v;
    }
};

// Player class
class Player {
public:
    string name;
    int health;
    int attack;
    int defense;
    int score;
    vector<Item> inventory;

    Player(string n) {
        name = n;
        health = 20;
        attack = 5;
        defense = 2;
        score = 0;
    }

    void showStats() {
        cout << "\n--- " << name << "'s Stats ---\n";
        cout << "Health: " << health << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Score: " << score << endl;
        cout << "Inventory: ";
        if (inventory.empty()) cout << "None";
        for (Item item : inventory) cout << item.name << " ";
        cout << "\n--------------------\n";
    }
};

// Combat function
void Combat(Player &player, string enemyname, int enemypower) {
    cout << "\nCombat! " << enemyname << " appears!\n";
    int playerroll = player.attack + (rand() % 6 + 1);
    int enemyroll = enemypower + (rand() % 6 + 1);

    cout << "Your combat score: " << playerroll << endl;
    cout << enemyname << "'s combat score: " << enemyroll << endl;

    if (playerroll >= enemyroll) {
        cout << "You defeated the " << enemyname << "!\n";
        player.score += 10;
    } else {
        cout << "You were injured by the " << enemyname << "!\n";
        player.health -= 5;
    }
}

// Puzzle function
void Puzzle(Player &player) {
    cout << "\nPuzzle Time!\n";
    cout << "What is 7 + 5? ";
    int answer;
    cin >> answer;
    if (answer == 12) {
        cout << "Correct! You gain 5 points.\n";
        player.score += 5;
    } else {
        cout << "Wrong! You lose 3 health.\n";
        player.health -= 3;
    }
}

// Function to pick an item
void findItem(Player &player) {
    cout << "\nYou found a sword!\n";
    Item sword("Sword", "weapon", 3);
    player.inventory.push_back(sword);
    player.attack += sword.value;
    cout << "Your attack increased by " << sword.value << "!\n";
}

// Example scene function
bool Scene1(Player &player) {
    cout << "\nScene 1: You enter a dark cave.\n";
    cout << "1) Cross the rickety bridge\n";
    cout << "2) Swim in the shallow pool\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player, "Cave Troll", 8);
    } else if (choice == 2) {
        cout << "You get bitten by leeches! Lose 1 health.\n";
        player.health -= 1;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene1(player);
    }
    return true;
}

bool Scene2(Player &player) {
    cout << "\nScene 2: You find a treasure chest.\n";
    cout << "1) Open it\n";
    cout << "2) Ignore it\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        findItem(player);
    } else if (choice == 2) {
        cout << "You walk past the chest.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene2(player);
    }
    return true;
}

bool Scene3(Player &player) {
    cout << "\nScene 3: You face a locked door with a riddle.\n";
    Puzzle(player);
    return true;
}

bool Scene4(Player &player) {
    cout << "\nScene 4: You had a really big problem.\n";
    Puzzle(player);
    return true;
}

bool Scene5(Player &player) {
    cout << "\nScene 5: You go .\n";
    cout << "1) Cross the rickety bridge\n";
    cout << "2) Swim in the shallow pool\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player, "Cave Troll", 8);
    } else if (choice == 2) {
        cout << "You get bitten by leaches! Lose 1 health.\n";
        player.health -= 1;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene1(player);
    }
    return true;
}

bool Scene6(Player &player) {
    cout << "\nScene 6: You find strange berries.\n";
    cout << "1) Eat them\n";
    cout << "2) Leave them\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "They were poisonous! Lose 2 health.\n";
        player.health -= 2;
    } else if (choice == 2) {
        cout << "You stay safe.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene6(player);
    }
    return true;
}
bool Scene7(Player &player) {
    cout << "\nScene 7: A guard challenges you.\n";
    cout << "1) Accept the fight\n";
    cout << "2) Decline\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player, "Guard", 9);
    } else if (choice == 2) {
        cout << "The guard allows you to pass.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene7(player);
    }
    return true;
}
bool Scene8(Player &player) {
    cout << "\nScene 8: You see a healing fountain.\n";
    cout << "1) Drink from it\n";
    cout << "2) Ignore it\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You regain 3 health.\n";
        player.health += 3;
    } else if (choice == 2) {
        cout << "You move on.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene8(player);
    }
    return true;
}
bool Scene9(Player &player) {
    cout << "\nScene 9: A locked door blocks your way.\n";
    cout << "1) Solve a puzzle\n";
    cout << "2) Force the door\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You solve the puzzle successfully.\n";
    } else if (choice == 2) {
        cout << "You hurt yourself. Lose 2 health.\n";
        player.health -= 2;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene9(player);
    }
    return true;
}
bool Scene10(Player &player) {
    cout << "\nScene 10: A giant spider descends.\n";
    cout << "1) Fight\n";
    cout << "2) Dodge it\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player, "Giant Spider", 8);
    } else if (choice == 2) {
        cout << "You dodge successfully.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene10(player);
    }
    return true;
}

bool Scene11(Player &player) {
    cout << "\nScene 11: A wild wolf appears.\n";
    cout << "1) Fight the wolf\n";
    cout << "2) Try to scare it away\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player,"Hulk",7);
    } else if (choice == 2) {
        cout << "The wolf scratches you. Lose 2 health.\n";
        player.health -= 2;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene11(player);
    }
    return true;
}

bool Scene12(Player &player) {
    cout << "\nScene 12: You find an old bridge.\n";
    cout << "1) Cross it carefully\n";
    cout << "2) Run across it\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You cross safely.\n";
    } else if (choice == 2) {
        cout << "The bridge shakes! Lose 3 health.\n";
        player.health -= 3;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene12(player);
    }
    return true;
}

bool Scene13(Player &player) {
    cout << "\nScene 13: A bandit blocks your path.\n";
    cout << "1) Fight the bandit\n";
    cout << "2) Give him food\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player,"Spider", 8);
    } else if (choice == 2) {
        cout << "The bandit leaves you alone.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene13(player);
    }
    return true;
}

bool Scene14(Player &player) {
    cout << "\nScene 14: A dark tunnel lies ahead.\n";
    cout << "1) Enter the tunnel\n";
    cout << "2) Take the long way around\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You trip in the dark. Lose 2 health.\n";
        player.health -= 2;
    } else if (choice == 2) {
        cout << "You stay safe but feel tired.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene14(player);
    }
    return true;
}

bool Scene15(Player &player) {
    cout << "\nScene 15: You find a healing fountain.\n";
    cout << "1) Drink from it\n";
    cout << "2) Ignore it\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You recover 3 health.\n";
        player.health += 3;
    } else if (choice == 2) {
        cout << "You walk away.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene15(player);
    }
    return true;
}

bool Scene16(Player &player) {
    cout << "\nScene 16: A snake blocks the road.\n";
    cout << "1) Attack it\n";
    cout << "2) Slowly back away\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player,"Batman", 6);
    } else if (choice == 2) {
        cout << "The snake bites you. Lose 1 health.\n";
        player.health -= 1;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene16(player);
    }
    return true;
}

bool Scene17(Player &player) {
    cout << "\nScene 17: You reach a cliff.\n";
    cout << "1) Climb down\n";
    cout << "2) Look for another path\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You slip. Lose 3 health.\n";
        player.health -= 3;
    } else if (choice == 2) {
        cout << "You find a safer route.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene17(player);
    }
    return true;
}

bool Scene18(Player &player) {
    cout << "\nScene 18: A strange puzzle is carved on a wall.\n";
    cout << "1) Solve it\n";
    cout << "2) Ignore it\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Puzzle(player);
    } else if (choice == 2) {
        cout << "You move on.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene18(player);
    }
    return true;
}

bool Scene19(Player &player) {
    cout << "\nScene 19: You hear footsteps behind you.\n";
    cout << "1) Turn around\n";
    cout << "2) Run forward\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player, "Hero",7);
    } else if (choice == 2) {
        cout << "You escape but lose stamina. Lose 2 health.\n";
        player.health -= 2;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene19(player);
    }
    return true;
}

bool Scene20(Player &player) {
    cout << "\nScene 20: A calm campfire awaits.\n";
    cout << "1) Rest\n";
    cout << "2) Keep moving\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You rest and gain 2 health.\n";
        player.health += 2;
    } else if (choice == 2) {
        cout << "You continue onward.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene20(player);
    }
    return true;
}

/* Scenes 21–30 follow SAME pattern */

bool Scene21(Player &player) {
    cout << "\nScene 21: A shadow attacks you.\n";
    cout << "1) Fight\n";
    cout << "2) Dodge\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player,"Attacker", 8);
    } else if (choice == 2) {
        cout << "You dodge but lose balance. Lose 1 health.\n";
        player.health -= 1;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene21(player);
    }
    return true;
}

bool Scene22(Player &player) {
    cout << "\nScene 22: A narrow hallway.\n";
    cout << "1) Walk slowly\n";
    cout << "2) Sprint through\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You pass safely.\n";
    } else if (choice == 2) {
        cout << "You hit a trap! Lose 3 health.\n";
        player.health -= 3;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene22(player);
    }
    return true;
}

bool Scene23(Player &player) {
    cout << "\nScene 23: A final guardian appears.\n";
    cout << "1) Fight bravely\n";
    cout << "2) Try to negotiate\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player,"Monster", 9);
    } else if (choice == 2) {
        cout << "The guardian attacks anyway. Lose 2 health.\n";
        player.health -= 2;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene23(player);
    }
    return true;
}

bool Scene24(Player &player) {
    cout << "\nScene 24: A quiet corridor.\n";
    cout << "1) Search it\n";
    cout << "2) Ignore it\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You find nothing.\n";
    } else if (choice == 2) {
        cout << "You move on.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene24(player);
    }
    return true;
}

bool Scene25(Player &player) {
    cout << "\nScene 25: A monster ambushes you.\n";
    cout << "1) Fight\n";
    cout << "2) Run\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player,"Zombie", 8);
    } else if (choice == 2) {
        cout << "You escape but lose 2 health.\n";
        player.health -= 2;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene25(player);
    }
    return true;
}

bool Scene26(Player &player) {
    cout << "\nScene 26: You reach a staircase.\n";
    cout << "1) Go up\n";
    cout << "2) Go down\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The stairs collapse! Lose 2 health.\n";
        player.health -= 2;
    } else if (choice == 2) {
        cout << "You descend safely.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene26(player);
    }
    return true;
}

bool Scene27(Player &player) {
    cout << "\nScene 27: A locked chest.\n";
    cout << "1) Open it\n";
    cout << "2) Ignore it\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Puzzle(player);
    } else if (choice == 2) {
        cout << "You walk past.\n";
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene27(player);
    }
    return true;
}

bool Scene28(Player &player) {
    cout << "\nScene 28: A cold wind blows.\n";
    cout << "1) Push forward\n";
    cout << "2) Rest\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You endure the cold.\n";
    } else if (choice == 2) {
        cout << "You lose time and energy. Lose 1 health.\n";
        player.health -= 1;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene28(player);
    }
    return true;
}

bool Scene29(Player &player) {
    cout << "\nScene 29: The final door stands before you.\n";
    cout << "1) Open it\n";
    cout << "2) Turn back\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You step forward bravely.\n";
    } else if (choice == 2) {
        cout << "You hesitate. Lose 1 health.\n";
        player.health -= 1;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene29(player);
    }
    return true;
}

bool Scene30(Player &player) {
    cout << "\nScene 30: The final challenge!\n";
    cout << "1) Fight\n";
    cout << "2) Use all your strength\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Combat(player,"Giant", 10);
    } else if (choice == 2) {
        cout << "You survive but lose 2 health.\n";
        player.health -= 2;
    } else {
        cout << "Invalid choice. Try again.\n";
        return Scene30(player);
    }
    return true;
}

// Main game loop
int main() {
    srand(time(0));
    cout << "Enter your player name: ";
    string playerName;
    getline(cin,playerName);

    Player player(playerName);

    cout << "\nWelcome, " << player.name << "! Your adventure begins!\n";

    // The game with the 30 scenes
    Scene1(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene2(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene3(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }
    Scene4(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene5(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene6(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }
    Scene7(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene8(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene9(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }
    Scene10(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene10(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene11(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }
    Scene12(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene13(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene14(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }
    Scene15(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene16(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene17(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }
    Scene18(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene19(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene20(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }
    Scene21(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene22(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene23(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }
    Scene24(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene25(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene26(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene27(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene28(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene29(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    Scene30(player);
    if (player.health <= 0) { cout << "Game Over!\n"; return 0; }

    cout << "\nCongratulations! You completed the adventure.\n";
    player.showStats();

    return 0;
}