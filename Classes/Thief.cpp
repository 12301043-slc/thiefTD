//
//  Thief.cpp
//  thiefTD
//
//  Created by cocos2d-x on 14-4-28.
//
//

#include "Thief.h"


bool Thief::init()
{
	if (!Sprite3D::init())
	{
		return false;
	}
    setRunSpeed(25);
    setVaule(10);
	sprite = Sprite3D::create("orc.c3b");
    this->addChild(sprite);
	sprite->setScale(2.0);
	sprite->setAnchorPoint(Vec2(0,0));
	
	auto animation = Animation3D::create("orc.c3b");
    if (animation)
    {
        auto animate = Animate3D::create(animation);
        bool inverse = (std::rand() % 3 == 0);

        int rand2 = std::rand();
        float speed = 1.0f;
        if(rand2 % 3 == 1)
        {
            speed = animate->getSpeed() + CCRANDOM_0_1();
        }
        else if(rand2 % 3 == 2)
        {
            speed = animate->getSpeed() - 0.5 * CCRANDOM_0_1();
        }
        animate->setSpeed(inverse ? -speed : speed);

        sprite->runAction(RepeatForever::create(animate));
    }
	
    
    createAndSetHpBar();
	schedule(schedule_selector(EnemyBase::changeDirection), 0);
	return true;
}

Thief* Thief::createThief(Vector<Node*> points, int hp)
{
    Thief *pRet = new Thief();
    if (pRet && pRet->init())
    {
        pRet->setPointsVector(points);
		pRet->setMaxHp(hp);
		pRet->setCurrHp(hp);
        pRet->runFllowPoint();
        
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

void Thief::changeDirection(float dt)
{
	hpBgSprite->setPosition(Point(sprite->getContentSize().width / 2, sprite->getContentSize().height +15 )+sprite->getPosition());
    auto curr = currPoint();
    if( curr == NULL )
	{
		return;
	}
    if(curr->getPositionX() > sprite->getPosition().x )
    {
		sprite->setRotation3D(Vec3(0,-90,0));
    }else{
		sprite->setRotation3D(Vec3(0,90,0));
    }
}
void Thief::enemyExpload()
{
    hpBgSprite->setVisible(false);
    sprite->stopAllActions();
    unschedule(schedule_selector(Thief::changeDirection));
    sprite->setAnchorPoint(Point(0.5f, 0.25f));
	sprite->removeFromParent();
}


bool Pirate::init()
{
	if (!Sprite3D::init())
	{
		return false;
	}
    setRunSpeed(50);
    setVaule(20);
    sprite = Sprite3D::create("orc.c3b");
	sprite->setAnchorPoint(Vec2(0,0));
	sprite->setScale(2.0);
    this->addChild(sprite);
    animationRight = createAnimation("enemyRight2", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationRight, "runright2");
    animationLeft = createAnimation("enemyLeft2", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationLeft, "runleft2");
    animationExplode= createAnimation("explode2", 6, 0.15f);
	AnimationCache::getInstance()->addAnimation(animationExplode, "explode2");
    
    createAndSetHpBar();
	schedule(schedule_selector(Pirate::changeDirection), 0);
	return true;
}

Pirate* Pirate::createPirate(Vector<Node*> points, int hp)
{
    Pirate *pRet = new Pirate();
    if (pRet && pRet->init())
    {
        pRet->setPointsVector(points);
		pRet->setMaxHp(hp);
		pRet->setCurrHp(hp);
        pRet->runFllowPoint();
        
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
void Pirate::changeDirection(float dt)
{
	hpBgSprite->setPosition(Point(sprite->getContentSize().width / 2, sprite->getContentSize().height +15 )+sprite->getPosition());
    auto curr = currPoint();
    if( curr == NULL )
	{
		return;
	}
    if(curr->getPositionX() > sprite->getPosition().x )
    {
		sprite->setRotation3D(Vec3(0,-90,0));
    }else{
		sprite->setRotation3D(Vec3(0,90,0));
    }
}
void Pirate::enemyExpload()
{
    hpBgSprite->setVisible(false);
    sprite->stopAllActions();
    unschedule(schedule_selector(Pirate::changeDirection));
    sprite->setAnchorPoint(Point(0.5f, 0.25f));
	sprite->removeFromParent();
}


bool Bandit::init()
{
	if (!Sprite3D::init())
	{
		return false;
	}
    setRunSpeed(70);
    setVaule(30);
    sprite = Sprite3D::create("orc.c3b");
	sprite->setColor(Color3B(255,255,0));
	sprite->setAnchorPoint(Vec2(0,0));
    this->addChild(sprite);
	sprite->setScale(2.0);
    animationRight = createAnimation("enemyRight3", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationRight, "runright3");
    animationLeft = createAnimation("enemyLeft3", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationLeft, "runleft3");
    animationExplode= createAnimation("explode3", 6, 0.15f);
	AnimationCache::getInstance()->addAnimation(animationExplode, "explode3");
    
    createAndSetHpBar();
	schedule(schedule_selector(Bandit::changeDirection), 0);
	return true;
}

Bandit* Bandit::createBandit(Vector<Node*> points, int hp)
{
    Bandit *pRet = new Bandit();
    if (pRet && pRet->init())
    {
        pRet->setPointsVector(points);
		pRet->setMaxHp(hp);
		pRet->setCurrHp(hp);
        pRet->runFllowPoint();
        
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
void Bandit::changeDirection(float dt)
{
	hpBgSprite->setPosition(Point(sprite->getContentSize().width / 2, sprite->getContentSize().height +15 )+sprite->getPosition());
    auto curr = currPoint();
    if( curr == NULL )
	{
		return;
	}
    if(curr->getPositionX() > sprite->getPosition().x )
    {
		sprite->setRotation3D(Vec3(0,-90,0));
    }else{
		sprite->setRotation3D(Vec3(0,90,0));
    }
}
void Bandit::enemyExpload()
{
    hpBgSprite->setVisible(false);
    sprite->stopAllActions();
    unschedule(schedule_selector(Bandit::changeDirection));
    sprite->setAnchorPoint(Point(0.5f, 0.25f));
	sprite->removeFromParent();
}

