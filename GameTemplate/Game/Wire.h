#pragma once
class Wire :public IGameObject
{
public :

	Wire();
	~Wire();


	bool Start();

	void Update()override;

	CVector3 Set_Wire_Position(CVector3 pos) {
		wire_position = pos;

		return wire_position;
	}


	CVector3 Set_Wire_Speed(CVector3 speed) {
		wire_Speed = speed;

		return wire_Speed;
	}



	void Set_wire_number(int num) {

		wire_number = num;
			
	}
	//スケールを設定する。
	void SetScale(const CVector3& scale) {
		m_scale = scale;
	}



	void  Set_position(CVector3 pos) {

		wire_position = pos;
	
	}




private:


	CVector3 wire_position = CVector3::Zero;
	                       

	CVector3  wire_Speed = CVector3::Zero;

	CVector3 m_scale = CVector3::One;		//スケール。


	prefab::CSkinModelRender* m_skin_wire = nullptr;


	int wire_number;

	int m_timer = 0;
};

