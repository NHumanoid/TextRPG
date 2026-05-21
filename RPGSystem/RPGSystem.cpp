#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item
{
	string name = "";
	int price = 30;

	void PrintItemInfo()const
	{
		cout << "아이템 이름: " << name << endl;
		cout << "가격: " << price << "골드" << endl;
	}
};

vector<Item> inventory;

vector<string> potionRecipes = {
	"HP포션: 허브 + 물",
	"스태미나포션: 허브 + 베리",
	"공격력포션: 용의 심장 + 물",
	"방어력포션: 거인의 뼈 + 물"
};

class Player
{

public :

	Player(string name, string job, int level, int hp, int mp, int power, int defense) : name(name), job(job), level(level), hp(hp), mp(mp), power(power), defense(defense) 
	{
	}	

	void setHp(int hp)
	{
		this->hp = hp;
	}
	void setMp(int mp)
	{
		this->mp = mp;
	}
	void setPower(int power)
	{
		this->power = power;
	}
	void setDefense(int defense)
	{
		this->defense = defense;
	}

	void printPlayerStatus(string name, int hp, int mp, int power, int defense)
	{
		cout << "=====================" << endl;
		cout << "닉네임:" << name << " 직업:" << job << "level:" << level << endl;
		cout << "HP:" << hp << " MP:" << mp << "공격력:" << power << " 방어력:" << defense << endl;
		cout << "=====================" << endl;
	}
	int getHp()
	{
		return hp;
	}
	int getMp()
	{
		return mp;
	}

	string getjob()
	{
		return job;
	}
	int getAttack()
	{
		return power;
	}

	int getPower()
	{
		return power;
	}

	int getDefense()
	{
		return defense;
	}

	string getName()
	{
		return name;
	}

	virtual void atteck() = 0;
	virtual ~Player() {};

protected :

	string name;
	string job;

	int level;
	int hp;
	int mp;
	int power;
	int defense;

};

class Warrior : public Player
{
public:

	Warrior(string name, int hp, int mp, int power, int defense) : Player(name, "전사", 1, hp, mp, power, defense) 
	{
	}

	void atteck() override
	{
		cout << "검객난무를 시도한다!" << endl;

	}
};

class Wizard : public Player
{
public:
	Wizard(string name, int hp, int mp, int power, int defense) : Player(name, "마법사", 1, hp, mp, power, defense)
	{
	};

	void atteck() override
	{
		cout << "파이어볼을 발사한다!" << endl;

	}
};

class Thief : public Player
{
public:

	Thief(string name, int hp, int mp, int power, int defense) : Player(name, "도적", 1, hp, mp, power, defense)
	{
	};

	void atteck() override
	{
		cout << "백스텝을 시도한다!" << endl;

	}
};

class Archer : public Player
{
public:

	Archer(string name, int hp, int mp, int power, int defense) : Player(name, "궁수", 1, hp, mp, power, defense) 
	{
	};

	void atteck() override
	{
		cout << "멀티샷을 시도한다!" << endl;

	}
};

class Monster
{
public:

	void setHp(int hp)
	{
		this->hp = hp;
	}

	string getName()
	{
		return name;
	}

	int getdefense()
	{
		return defense;
	}

	int getAttack()
	{
		return power;
	}

	int getHp()
	{
		return hp;
	}

	string getDropItemName()
	{
		return dropItemName;
	}

private:

	string name = "슬라임";
	string dropItemName = "끈적한 젤리";

	int hp = 30;
	int power = 20;
	int defense = 10; 
	int dropItemPrice = 10;

};

void Fight(Player* player)
{
    Monster monster;
    cout << "\n[전투 시작] " << player->getName() << " vs " << monster.getName() << endl;

    while (player->getHp() > 0 && monster.getHp() > 0)
    {
        // --- 플레이어 턴 ---
        int damage = player->getAttack() - monster.getdefense();
        if (damage <= 0) damage = 1; // 방어력이 높아도 최소 1의 데미지는 입힘

        int prevMonsterHp = monster.getHp();
        monster.setHp(prevMonsterHp - damage);

        cout << " --- 플레이어 턴 --- " << endl;
        player->atteck();
        cout << monster.getName() << "에게 " << damage << " 데미지!" << endl;
        cout << monster.getName() << " HP: " << prevMonsterHp << " -> " << (monster.getHp() < 0 ? 0 : monster.getHp()) << endl;

        if (monster.getHp() <= 0) break; // 몬스터가 죽으면 즉시 종료

        // --- 몬스터 턴 ---
        int monsterDamage = monster.getAttack() - player->getDefense();
        if (monsterDamage <= 0) monsterDamage = 1; // 최소 데미지 보정

        int prevPlayerHp = player->getHp();
        player->setHp(prevPlayerHp - monsterDamage);

        cout << " --- 몬스터 턴 --- " << endl;
        cout << monster.getName() << "의 공격!" << endl;
        cout << player->getName() << "에게 " << monsterDamage << " 데미지!" << endl;
        cout << player->getName() << " HP: " << prevPlayerHp << " -> " << (player->getHp() < 0 ? 0 : player->getHp()) << endl;
    }

    if (player->getHp() <= 0)
    {
        cout << "\n[결과] 전투 패배... " << player->getName() << "이(가) 쓰러졌습니다." << endl;
    }
    else
    {
        cout << "\n[결과] 전투 승리!" << endl;
        cout << monster.getName() << "의 " << monster.getDropItemName() << "를 획득했습니다!" << endl;

        Item item;
        item.name = monster.getDropItemName();
        inventory.push_back(item);
    }
}

void event()
{
}

void printStatus(string name, int stat[])
{
	cout << "=====================" << endl;
	cout << name << " 현재의 능력치" << endl;
	cout << "=====================" << endl;
	cout << "HP:" << stat[0] << " MP:" << stat[1] << endl;
	cout << "공격력:" << stat[2] << " 방어력:" << stat[3] << endl;
	cout << "=====================" << endl;
}

int main()
{
	int stat[4] = { 0 };
	string name;

	cout << "=====================" << endl;
	cout << "던전 탈출 택스트 RPG" << endl;
	cout << "=====================" << endl;
	cout << "용사의 이름을 입력해주세요:";
	cin >> name;
	cout << "=====================" << endl;

	// P2
	while (true)
	{
		cout << "HP와 MP를 입력하세요:";
		cin >> stat[0];
		cin >> stat[1];
		if (stat[0] <= 50 || stat[1] <= 50)
		{
			cout << "HP나 MP가 너무 낮습니다. 다시 입력해주세요." << endl;
		}
			break;
	}
	while (true)
	{
		cout << "공격력과 방어력을 입력하세요:";
		cin >> stat[2];
		cin >> stat[3];
		if (stat[2] <= 50 || stat[3] <= 50)
		{
			cout << "공격력이나 방어력이 너무 낮습니다. 다시 입력해주세요." << endl;
		}
		else
			break;
	}

	void printStatus(string name, int stat[]);

	// P3
	int HPPotion = 5;
	int MPPotion = 5;
	int choice;
	bool isgameStart = false;

	cout << "HP 포션" << HPPotion << "개, MP 포션" << MPPotion << "개가 기본지급 되었습니다." << endl;
	cout << "=====================" << endl;
	cout << "캐릭터 강화" << endl;
	cout << "1.HP up 2.MP up 3.Attack x2 4.Defense x2 5.Show Stats 0.Game Start" << endl;
	cout << "=====================" << endl;

	while (!isgameStart)
	{
		cout << "번호를 선택해 주세요: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "게임을 시작합니다." << endl;
			isgameStart = true;
			break;
		case 1:
			if (HPPotion > 0)
			{
				stat[0] += 20;
			}

			HPPotion--;
			if (HPPotion < 0)
			{
				cout << "HP 포션이 부족합니다." << endl;
				HPPotion = 0; // 포션 개수를 0으로 유지
				break;
			}
			cout << "HP가 20 증가했습니다. (HP 포션차감	: 남은포션 " << HPPotion << ")" << endl;
			break;
		case 2:
			if (MPPotion > 0)
			{
				stat[1] += 20;
			}
			MPPotion--;
			if (MPPotion < 0)
			{
				cout << "MP 포션이 부족합니다." << endl;
				MPPotion = 0; // 포션 개수를 0으로 유지
				break;
			}
			cout << "MP가 20 증가했습니다. (MP 포션차감	: 남은포션 " << MPPotion << ")" << endl;
			break;
		case 3:
			stat[2] *= 2;
			cout << "공격력이 2배 증가했습니다." << endl;
			break;
		case 4:
			stat[3] *= 2;
			cout << "방어력이 2배 증가했습니다." << endl;
			break;
		case 5:
			printStatus(name, stat);
			break;
		}
	}

	cout << name << "님, 직업을 선택해주세요" << endl;
	cout << "1.전사 2.마법사 3.도적 4.궁수" << endl;
	cin >> choice;

	Player* player = nullptr;

	switch (choice)
	{
	case 1:
		cout << "전사를 선택하셨습니다. (HP+30)" << endl;
		player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
		player->setHp(player->getHp() + 30);
		break;
	case 2:
		cout << "마법사를 선택하셨습니다. (MP+30)" << endl;
		player = new Wizard(name, stat[0], stat[1], stat[2], stat[3]);
		player->setMp(player->getMp() + 30);
		break;
	case 3:
		cout << "도적을 선택하셨습니다. (POWERx2)" << endl;
		player = new Thief(name, stat[0], stat[1],stat[2], stat[3]);
		player->setPower(player->getPower() * 2);
		break;
	case 4:
		cout << "궁수를 선택하셨습니다. (DEFENCEx2)" << endl;
		player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
		player->setDefense(player->getDefense() * 2);
		break;
	}
	player->atteck();
	player->printPlayerStatus(player->getName(), player->getHp(), player->getMp(), player->getPower(), player->getDefense());

	isgameStart = false;
	int recipeCount = 0;

	Fight(player);

	while (!isgameStart)
	{
		cout << "=== 메인 메뉴 ===" << endl;
		cout << "1.던전 입장" << endl;
		cout << "2.인벤토리 확인" << endl;
		cout << "3.포션 제작소" << endl;
		cout << "0.게임 종료" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "던전에 입장합니다..." << endl;
			Fight(player);
			break;

		case 2:
			cout << "인벤토리:" << endl;
			for (const auto& item : inventory)
			{
				item.PrintItemInfo();
				cout << "---------------------" << endl;
			}
			cout << "---------------------" << endl;

		case 3:
			int potionChoice;

			cout << "=== 포션 제작소 ===" << endl;
			cout << "1.전체 레시피 보기" << endl;
			cout << "2.포션 이름으로 검색" << endl;
			cout << "3.재료로 검색" << endl;
			cout << "0.메인 메뉴로 돌아가기" << endl;

			cin >> potionChoice;

			switch (potionChoice)
			{
			case 1:
				cout << "전체 레시피:" << endl;
				for (const auto& recipe : potionRecipes)
				{
					cout << recipe << endl;
				}
				break;

			case 2:
			{
				string searchName;
				cout << "포션 이름을 입력하세요: ";
				cin >> searchName;
				bool found = false;
				for (const auto& recipe : potionRecipes)
				{
					if (recipe.find(searchName) != string::npos)
					{
						cout << "레시피: " << recipe << endl;
						found = true;
					}
				}
				if (!found)
				{
					cout << "해당 포션 레시피를 찾을 수 없습니다." << endl;
				}
				break;
			}
			case 3:
			{
				string searchIngredient;
				cout << "재료 이름을 입력하세요: ";
				cin >> searchIngredient;
				bool found = false;
				for (const auto& recipe : potionRecipes)
				{
					if (recipe.find(searchIngredient) != string::npos)
					{
						cout << "레시피: " << recipe << endl;
						found = true;

						recipeCount++;
					}
				}
				cout << "총 " << recipeCount << "개의 레시피를 찾았습니다." << endl;
				if (!found)
				{
					cout << "해당 재료를 포함하는 포션 레시피를 찾을 수 없습니다." << endl;
				}
			}
			case 0:
				cout << "메인 메뉴로 돌아갑니다." << endl;
				break;
			}
			break;
		case 0:
			cout << "게임을 종료합니다." << endl;
			isgameStart = true;
			break;
		}
	}

	delete player;
}
