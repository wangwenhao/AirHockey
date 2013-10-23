#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#define GOAL_WIDTH 400

#include "cocos2d.h"
#include "GameSprite.h"

using namespace cocos2d;

class GameLayer : public cocos2d::CCLayer
{
    GameSprite *_player1;
    GameSprite *_player2;
    GameSprite *_ball;
    
    CCArray *_players;
    CCLabelTTF *_player1ScoreLabel;
    CCLabelTTF *_player2ScoreLabel;
    
    CCSize _screenSize;
    
    int _player1Score;
    int _player2Score;
    
    void playerScore(int player);
    
public:
    
    ~GameLayer();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static CCScene* scene();
    
    // a selector callback
    //void menuCloseCallback(CCObject* pSender);
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *event);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *event);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *event);
    
    void update(float dt);
    
    // implement the "static node()" method manually
    CREATE_FUNC(GameLayer);
    
    };

#endif // __GAMELAYER_H__
