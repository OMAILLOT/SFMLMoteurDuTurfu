#pragma once
#include <iostream>
namespace LeTurfu {

class AComponent
{
protected:
public:
	int ID;
	AComponent();
	~AComponent();
	virtual void Awake();
	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void LateUpdate();
	virtual void GenerateID();
	virtual void Draw();
};

}
