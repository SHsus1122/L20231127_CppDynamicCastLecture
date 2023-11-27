#include <iostream>
#include <vector>

using namespace std;

// ���̳���ĳ��Ʈ�� ����� �ݵ�� ����� �Ǿ��ִٴ� ���� ����
class Parent
{
public:
	// virtual �� ��� �� ������ �ؼ� ����϶�� �ǹ�
	virtual void Do() { cout << "Parent"; };
};

class Child1 : public Parent
{
public:
	// ������ �ϸ�...
	virtual void Do() override { cout << "Child1"; };
};

class Child2 : public Parent
{
public:
	// ������ �ϸ�...
	virtual void Do() override { cout << "Child2"; };
};



// �߻� Ŭ���� (�ٸ����� �������̽�)
// �� ���� �Լ��� ���� �����ϴ� ���� �ƴ� �ڽĿ��� ������ �����ϴ� ����
class IItem
{
public:
	virtual void Use() = 0;
};

class Knife : public IItem
{
	// IItem��(��) ���� ��ӵ�
	void Use() override
	{
		cout << "���" << endl;
	}
};

class Gun : public IItem
{
	// IItem��(��) ���� ��ӵ�
	void Use() override
	{
		cout << "���" << endl;
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
	// ���� �θ��� ���� �ƴ� �ڽ��� ���� ������ �˴ϴ�.
	Child1 Child;
	Child.Do();

	// �� ����� ������ �� ������� �� �ϱ� ������(�޸� ������ �����Դϴ�)
	// �׷��� new �����ڸ� ���ؼ� Heap ������ ����� �ֵ��� �մϴ�.
	Child1* ChildOne = new Child1();
	cout << endl;

	// 
	// �� �����ؼ� �ڵ�����..? �� ����Ű�� ���� ����Ʈ�� 8����Ʈ(64��Ʈ) 32��Ʈ�� 4����Ʈ

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