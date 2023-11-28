#include <iostream>

class Monster {
private:
	std::string name, attackType;
	int HP, attack, defense, speed;
public:
	Monster(std::string name, std::string attackType, int HP, int attack, int defense, int speed)
		: name(name), attackType(attackType), HP(HP), attack(attack), defense(defense), speed(speed) {}

	void printMonster() {
		std::cout << "MONSTER: " << name << std::endl;
		std::cout << "Attack type: " << attackType << std::endl;
		std::cout << "STATS: " << std::endl;
		std::cout << "HP: " << HP << ", attack: " << attack << ", defense: " << defense << ", speed: " << speed << std::endl;
	}
};

class Skeleton : public Monster {
public:
	Skeleton(std::string name, std::string attackType, int HP, int attack, int defense, int speed)
		: Monster(name, attackType, HP, attack, defense, speed) {}

	void printSkeleton() {
		printMonster();
		std::cout << std::endl;
	}
};

class WalkingDead : public Monster {
private:
	std::string abilities;
	int diseaseDamage;
public:
	WalkingDead(std::string name, std::string attackType, int HP, int attack, int defense, int speed, std::string abilities, int diseaseDamage)
		: Monster(name, attackType, HP, attack, defense, speed), abilities(abilities), diseaseDamage(diseaseDamage) {}

	void printWalkingDead() {
		printMonster();
		std::cout << "Special ability: " << abilities << std::endl;
		std::cout << "The ability causes a loss of " << diseaseDamage << " HP up to 5 times" << std::endl;
		std::cout << std::endl;
	}
};

class Vampire : public Monster {
private:
	std::string attackBuff;
public:
	Vampire(std::string name, std::string attackType, int HP, int attack, int defense, int speed, std::string attackBuff)
		: Monster(name, attackType, HP, attack, defense, speed), attackBuff(attackBuff) {}

	void printVampire() {
		printMonster();
		std::cout << "Attack buff when dealing damage to humans: " << attackBuff << std::endl;
		std::cout << std::endl;
	}
};

class Lich : public Monster {
private:
	int magicAttack;
public:
	Lich(std::string name, std::string attackType, int HP, int attack, int defense, int speed, int magicAttack)
		: Monster(name, attackType, HP, attack, defense, speed), magicAttack(magicAttack) {}

	void printLich() {
		printMonster();
		std::cout << "Can cast a spell that deals " << magicAttack << " points of damage" << std::endl;
		std::cout << std::endl;
	}
};

class BlackKnight : public Monster {
private:
	std::string attackBuff;
	std::string defenseBuff;
public:
	BlackKnight(std::string name, std::string attackType, int HP, int attack, int defense, int speed, std::string defenseBuff, std::string attackBuff)
		: Monster(name, attackType, HP, attack, defense, speed), defenseBuff(defenseBuff), attackBuff(attackBuff) {}

	void printBlackKnight() {
		printMonster();
		std::cout << "Defense buff against humans and mages: " << defenseBuff << std::endl;
		std::cout << "Attack buff against dwarves, elves, and mages: " << attackBuff << std::endl;
		std::cout << std::endl;
	}
};

template<typename T>
class MonsterTemplate {
private:
	std::string name, attackType;
	int HP, attack, defense, speed;
public:
	MonsterTemplate(std::string name, std::string attackType, int HP, int attack, int defense, int speed)
		: name(name), attackType(attackType), HP(HP), attack(attack), defense(defense), speed(speed) {}

	void printMonsterTemplate() {
		std::cout << "MONSTER: " << name << std::endl;
		std::cout << "Attack type: " << attackType << std::endl;
		std::cout << "STATS: " << std::endl;
		std::cout << "HP: " << HP << ", attack: " << attack << ", defense: " << defense << ", speed: " << speed << std::endl;
	}
};

class BoneDragon : public MonsterTemplate<BoneDragon> {
private:
	std::string attackBuff;
	std::string abilities;
public:
	BoneDragon(std::string name, std::string attackType, int HP, int attack, int defense, int speed, std::string attackBuff, std::string abilities)
		: MonsterTemplate(name, attackType, HP, attack, defense, speed), attackBuff(attackBuff), abilities(abilities) {}

	void printBoneDragon() {
		printMonsterTemplate();
		std::cout << "Attack buff against humans, dwarves, elves, and mages: " << attackBuff << std::endl;
		std::cout << "Special ability: " << abilities << std::endl;
		std::cout << std::endl;
	}
};

int main() {
	auto skeleton = Skeleton("Skeleton", "Melee", 6, 5, 4, 4);
	auto walkingDead = WalkingDead("Walking dead", "Melee", 15, 5, 5, 3, "20% chance to cause disease in creatures they attack", 1);
	auto vampire = Vampire("Vampire", "Melee", 30, 10, 9, 6, "+5");
	auto lich = Lich("Lich", "Ranged", 30, 13, 10, 6, 20);
	auto blackKnight = BlackKnight("Black knight", "Melee", 120, 16, 16, 7, "+4", "+3");
	auto boneDragon = BoneDragon("Bone dragon", "Melee", 150, 17, 15, 9, "+5", "20% chance of aging their targets");
	decltype(Skeleton("", "", 0, 0, 0, 0)) skeletonWarrior("Skeleton warrior", "Melee", 6, 6, 6, 5);
	decltype(WalkingDead("", "", 0, 0, 0, 0, "", 0)) zombie("Zombie", "Melee", 15, 5, 5, 3, "30% chance to poison the creatures they attack", 2);
	decltype(Vampire("", "", 0, 0, 0, 0, "")) vampireLord("Vampire lord", "Melee", 40, 10, 10, 9, "+5");
	decltype(Lich("", "", 0, 0, 0, 0, 0)) powerLich("Power lich", "Ranged", 40, 13, 10, 7, 25);
	decltype(BlackKnight("", "", 0, 0, 0, 0, "", "")) dreadKnight("Dread knight", "Melee", 120, 18, 18, 9, "+4", "+4");
	decltype(BoneDragon("", "", 0, 0, 0, 0, "", "")) ghostDragon("Ghost dragon", "Melee", 200, 19, 17, 14, "+5", "30% chance of aging their targets");

	std::cout << "< Monsters of the Necropolis faction >" << std::endl;
	std::cout << std::endl;
	skeleton.printSkeleton();
	walkingDead.printWalkingDead();
	vampire.printVampire();
	lich.printLich();
	blackKnight.printBlackKnight();
	boneDragon.printBoneDragon();
	std::cout << "< Upgraded monsters of the Necropolis faction >" << std::endl;
	std::cout << std::endl;
	skeletonWarrior.printSkeleton();
	zombie.printWalkingDead();
	vampireLord.printVampire();
	powerLich.printLich();
	dreadKnight.printBlackKnight();
	ghostDragon.printBoneDragon();

	return 0;
}