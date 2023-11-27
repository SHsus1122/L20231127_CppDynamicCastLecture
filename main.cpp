#include <iostream>
#include <vector>

using namespace std;

// 다이나믹캐스트의 전재는 반드시 상속이 되어있다는 것이 전재
class Parent
{
public:
	// virtual 는 사용 시 재정의 해서 사용하라는 의미
	virtual void Do() { cout << "Parent"; };
};

class Child1 : public Parent
{
public:
	// 재정의 하면...
	virtual void Do() override { cout << "Child1"; };
};

class Child2 : public Parent
{
public:
	// 재정의 하면...
	virtual void Do() override { cout << "Child2"; };
};



// 추상 클래스 (다른말로 인터페이스)
// 이 안의 함수를 직접 구현하는 것이 아닌 자식에서 구현을 강제하는 목적
class IItem
{
public:
	virtual void Use() = 0;
};

class Knife : public IItem
{
	// IItem을(를) 통해 상속됨
	void Use() override
	{
		cout << "찌른다" << endl;
	}
};

class Gun : public IItem
{
	// IItem을(를) 통해 상속됨
	void Use() override
	{
		cout << "쏜다" << endl;
	}
};

class Inventory
{
public:
	void Pickup(IItem* PickedupItem)
	{
		Data.push_back(PickedupItem);
	}

	IItem* operator[](int Index)
	{
		return Data[Index];
	}
private:
	vector<IItem*> Data;
};


//class AGun : public AActor, IItem
//{
//
//};


int main()
{
	Inventory I;
	I.Pickup(new Knife());
	I.Pickup(new Gun());
	I[0]->Use();
	I[1]->Use();

	/*
	// 이제 부모의 것이 아닌 자식의 것이 나오게 됩니다.
	Child1 Child;
	Child.Do();

	// 위 방식은 삭제할 때 마음대로 못 하기 때문에(메모리 영역의 문제입니다)
	// 그래서 new 연산자를 통해서 Heap 영역에 만들어 주도록 합니다.
	Child1* ChildOne = new Child1();
	cout << endl;

	// 
	// 위 관련해서 자동영역..? 이 가리키는 곳의 바이트는 8바이트(64비트) 32비트는 4바이트

	vector<Parent*> Parents;
	Parents.push_back(new Child1);
	Parents.push_back(new Child2);
	Parents.push_back(new Child1);
	for (int i = 0; i < Parents.size(); i++)
	{
		//Child1* NewTest = dynamic_cast<Child1*>(Parents[i]);
		//if (NewTest)
		//{
		//	NewTest->Do();
		//}
		Parents[i]->Do();
		cout << endl;
	}
	*/
	

	return 0;
}