//
//  LineSprite.cpp
//  LittleKnight
//
//  Created by JinTongyao on 1/27/15.
//
//

#include "LineSprite.h"

bool LineSprite::init() {
    if(!Sprite::init()) {
        return false;
    }
    return true;
}

LineSprite* LineSprite::createLine(TileSprite* beginTile, TileSprite* endTile) {
    LineSprite* line = new LineSprite();
    if(line && line->init()) {
        line->autorelease();
        line->setBeginTile(beginTile);
        line->setEndTile(endTile);
        line->draw(beginTile, endTile);
        return line;
    }
    CC_SAFE_DELETE(line);
    return NULL;
}

void LineSprite::draw(TileSprite* beginTile, TileSprite* endTile) {
    DrawNode* drawNode = DrawNode::create();
    drawNode->drawSegment(Vec2(beginTile->getPosX() + (beginTile->getWidth() / 2), beginTile->getPosY() + (beginTile->getHeight() / 2)),
                          Vec2(endTile->getPosX() + (endTile->getWidth() / 2), endTile->getPosY() + (endTile->getHeight() / 2)),
                          6, Color4F(111, 0, 0, 50));
    this->addChild(drawNode, 20);
}

TileSprite* LineSprite::getBeginTile() {
    return this->beginTile;
}

void LineSprite::setBeginTile(TileSprite* beginTile) {
    this->beginTile = beginTile;
}

TileSprite* LineSprite::getEndTile() {
    return this->endTile;
}

void LineSprite::setEndTile(TileSprite* endTile) {
    this->endTile = endTile;
}