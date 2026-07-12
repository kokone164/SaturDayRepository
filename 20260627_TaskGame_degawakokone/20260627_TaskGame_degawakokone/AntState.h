#pragma once
class Ant;
//状態インターフェース
class IAntState//I＝インターフェース
{
public:
	virtual void Update(Ant& ant, float dt) = 0;
	virtual void Draw(Ant& ant, int normalImage, int hitImage);
	virtual bool OnClick(Ant& ant, int mx, int my) = 0;
};

//各状態
//非表示
class HiddenState : public IAntState//“ : public インターフェース名”で使えるようになる
{
public:
	void Update(Ant& ant, float dt)override;//override＝上書き
	void Draw(Ant& ant, int, int)override;
	bool OnClick(Ant& ant, int, int)override;
};
//表示
class VisibleState : public IAntState
{
public:
	void Update(Ant& ant, float dt)override;
	void Draw(Ant& ant, int normalImage, int)override;
	bool OnClick(Ant& ant, int mx, int my)override;
};
//Hit
class HitState : public IAntState
{
public:
	void Update(Ant& ant, float dt)override;
	void Draw(Ant& ant, int, int hitImage)override;
	bool OnClick(Ant& ant, int mx, int my)override;
};

//共有インスタンス
extern HiddenState g_HiddenState;
extern VisibleState g_VisibleState;
extern HitState g_HitState;

