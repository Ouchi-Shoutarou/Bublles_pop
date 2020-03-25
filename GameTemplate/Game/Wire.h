#pragma once
class Wire :public IGameObject
{
public :

	Wire();
	~Wire();


	bool Start();

	void UpDate();

	CVector3 Set_Wire_Position(CVector3 pos) {
		wire_position = pos;
	}


	CVector3 Set_Wire_Speed(CVector3 speed) {
		wire_Speed = speed;
	}


protected:


	CVector3 wire_position = CVector3::Zero;
	                       

	CVector3  wire_Speed=CVector3::Zero;


	prefab::CSkinModelRender* m_skin_wire;

};

