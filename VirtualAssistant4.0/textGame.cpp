#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base People Class
class People {
public:
    string name;
    int health;
    People(string n, int h) : name(n), health(h) {}
    virtual void speak() = 0;
};

// Superhero class
class Superhero : public People {
public:
    int power;

    Superhero(string n) : People(n, 100), power(25) {}

    void speak() override {
        cout << name << ": I'm on a quest to find the Golden Taco!" << endl;
    }

    void attack(class Monster& m);
};

// Monster class
class Monster {
public:
    string type;
    int health;

    Monster(string t, int h) : type(t), health(h) {}

    void roar() {
        cout << type << " roars menacingly!" << endl;
    }
};

// BankAccount class
class BankAccount {
public:
    int balance;

    BankAccount() : balance(0) {}

    void deposit(int amount) {
        balance += amount;
        cout << "You deposited " << amount << " coins. Total: " << balance << endl;
    }
};

// Taco class (Heals player)
class Taco {
public:
    int healthBoost = 20;

    void eat(Superhero& hero) {
        hero.health += healthBoost;
        cout << "You ate a taco and gained " << healthBoost << " health! Current health: " << hero.health << endl;
    }
};

// Virtual Pet class
class VirtualPet {
public:
    string name;

    VirtualPet(string n) : name(n) {}

    void help() {
        cout << name << " found hidden coins! +30 coins!" << endl;
    }
};

// Game logic
class Game {
    Superhero player;
    BankAccount bank;
    VirtualPet pet;
    Taco taco;

public:
    Game(string playerName, string petName) : player(playerName), pet(petName) {}

    void start() {
        player.speak();
        int choice;

        while (true) {
            cout << "\n--- What would you like to do? ---" << endl;
            cout << "1. Explore Forest" << endl;
            cout << "2. Visit Taco Temple" << endl;
            cout << "3. Visit Fast Food Shop" << endl;
            cout << "4. Check Bank" << endl;
            cout << "5. Eat a Taco" << endl;
            cout << "6. Exit Game" << endl;
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    exploreForest();
                    break;
                case 2:
                    tacoTemple();
                    break;
                case 3:
                    shop();
                    break;
                case 4:
                    cout << "Bank Balance: " << bank.balance << " coins" << endl;
                    break;
                case 5:
                    taco.eat(player);
                    break;
                case 6:
                    cout << "Thanks for playing!" << endl;
                    return;
                default:
                    cout << "Invalid choice!" << endl;
            }
        }
    }

    void exploreForest() {
        cout << "\nYou explore the forest..." << endl;
        Monster m("Forest Troll", 50);
        m.roar();
        battle(m);
    }

    void tacoTemple() {
        cout << "\nYou enter the ancient Taco Temple..." << endl;
        cout << "You found the Golden Taco and earned 100 coins!" << endl;
        bank.deposit(100);
    }

    void shop() {
        cout << "\nWelcome to the Fast Food Shop!" << endl;
        cout << "An employee greets you and gives you 50 coins for helping clean up!" << endl;
        bank.deposit(50);
    }

    void battle(Monster& m) {
        srand(time(0));
        while (m.health > 0 && player.health > 0) {
            cout << "You hit the monster for " << player.power << " damage!" << endl;
            m.health -= player.power;
            if (m.health <= 0) {
                cout << "You defeated the monster!" << endl;
                pet.help();
                bank.deposit(30);
                break;
            }

            int monsterHit = rand() % 15 + 5;
            cout << "The monster hits you for " << monsterHit << " damage!" << endl;
            player.health -= monsterHit;
            if (player.health <= 0) {
                cout << "You were defeated... Game Over!" << endl;
                exit(0);
            }

            cout << "Your health: " << player.health << " | Monster's health: " << m.health << endl;
        }
    }
};

void runGame() {
    string playerName, petName;
    cout << "Enter your superhero name: ";
    getline(cin, playerName);
    cout << "Name your virtual pet: ";
    getline(cin, petName);

    Game game(playerName, petName);
    game.start();
}
