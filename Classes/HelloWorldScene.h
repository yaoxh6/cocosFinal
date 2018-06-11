#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
        
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	cocos2d::Sprite* player;
	cocos2d::Vector<SpriteFrame*> attack;
	cocos2d::Vector<SpriteFrame*> dead;
	cocos2d::Vector<SpriteFrame*> run;
	cocos2d::Vector<SpriteFrame*> idle;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Label* time;
	int dtime;
	cocos2d::ProgressTimer* pT;

	//判断是否在播放动作
	bool isAnimating;
	//攻击
	void attackCallback(Ref* pSender);
	//死亡
	void deadCallback(Ref* pSender);
	//重写update，实现倒计时
	void update(float time)override;

	//下面是新加的变量
	//用来显示打倒的敌人数
	cocos2d::Label* score;
	//判断是否在攻击
	bool isAttack = false;
	//判断是否在死亡
	bool isDead = false;
	//停止所有动作
	void stop(float time);


	void addKeyboardListener();
	void onKeyPressed(EventKeyboard::KeyCode code, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode code, Event* event);
	bool isMove;
	char movekey;
	void movePlayer(char c);
	void updateMove(float time);
	void attackA();
	Vec2 tileCoordForPosition(const Vec2& position);
	Vec2 positionForTileCoord(const Vec2& tileCoord);
	cocos2d::TMXTiledMap* tmx;
	Size mapSize;
	Size tileSize;
	std::vector<Vec2> skill1(Vec2 temp);
	void setColor(std::vector<Vec2> inputArea,Color3B inputColor);
	cocos2d::TMXLayer* backGroundLayer;
};
