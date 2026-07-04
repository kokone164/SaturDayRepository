#pragma once
class Map
{
private:
	//The x position of object in the world
	float worldX;
	float worldY;
public:
	//===================================
	//コンストラクタ
	//===================================
	Map(float worldX, float worldY);
	//===================================
	//描画
	//===================================
	void Draw(float cameraX);
};