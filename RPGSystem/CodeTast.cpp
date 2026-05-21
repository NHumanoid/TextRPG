#include <iostream>
#include <string>

//네임 스페이스는 std로 설정		
using namespace std;

class charater // 캐릭터 클래스
{

public:

protected:

	string name = "";
	int HP = 0;
	int MP = 0;
	int ACK = 0;

};

class BOB : public charater // BOB 클래스는 charater 클래스를 상속받음
{

public:

	BOB() 
	{
		name = "BOB";
		HP = 120;
		MP = 30;
		ACK = 25;
	}

	void BOBprintStatus()
	{
		cout << "=====================" << endl;
		cout << name << " 현재의 능력치" << endl;
		cout << "=====================" << endl;
		cout << "HP:" << HP << " MP:" << MP << endl;
		cout << "공격력:" << ACK << endl;
		cout << "=====================" << endl;
	} // BOB의 상태 출력 함수
	

private:

	string SpacialMove = "Lightning Strike"; // BOB의 특수 공격
	string NormalMove = "Sword Slash"; // BOB의 일반 공격

};

class Ross :public charater // Ross 클래스는 charater 클래스를 상속받음
{
public:

	Ross() 
	{
		name = "Ross";
		HP = 100;
		MP = 50;
		ACK = 20;

	}
	void ROSSprintStatus() 
	{
		cout << "=====================" << endl;
		cout << name << " 현재의 능력치" << endl;
		cout << "=====================" << endl;
		cout << "HP:" << HP << " MP:" << MP << endl;
		cout << "공격력:" << ACK << endl;
		cout << "=====================" << endl;
	}

private:

	string SpacialMove = "Fireball"; // Ross의 특수 공격

};

// 함수 오버로딩 예시

/*int Mau(int a, int b)
{
	return a + b;
}
int Mau(int a, int b, int c)
{
	return a + b + c;
}
int Mau(int a, int b, int c, int d)
{
	return a + b + c + d;
}*/

int main() 
{
	Ross ross; // Ross 객체 생성
	BOB bob; // BOB 객체 생성

	bob.BOBprintStatus(); // BOB의 상태 출력
	ross.ROSSprintStatus(); // Ross의 상태 출력

	return 0;
}
