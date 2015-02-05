//
//  TileSprite.cpp
//  LittleKnight
//
//  Created by JinTongyao on 1/19/15.
//
//

#include "TileSprite.h"

TileSprite* TileSprite::createTile(float posX, float posY, float width, float height) {
    TileSprite *tile = new TileSprite();
    if (tile && tile->init()) {
        tile->setPosX(posX);
        tile->setPosY(posY);
        tile->setWidth(width);
        tile->setHeight(height);
        
        tile->setAnchorPoint(Vec2(0, 0));
        tile->setContentSize(Size(Vec2(tile->getWidth(), tile->getHeight())));
        tile->setPosition(Vec2(tile->getPosX(), tile->getPosY()));
        
        tile->autorelease();
        return tile;
    }
    CC_SAFE_DELETE(tile);
    return NULL;
}

bool TileSprite::init() {
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 60))) {
        return false;
    }
    return true;
}

int TileSprite::getArrayX() {
    return this->arrayX;
}

void TileSprite::setArrayX(int arrayX) {
    this->arrayX = arrayX;
}

int TileSprite::getArrayY() {
    return this->arrayY;
}

void TileSprite::setArrayY(int arrayY) {
    this->arrayY = arrayY;
}


float TileSprite::getPosX() {
    return this->posX;
}

void TileSprite::setPosX(float posX) {
    this->posX = posX;
}

void TileSprite::setPosY(float posY) {
    this->posY = posY;
}

float TileSprite::getPosY() {
    return this->posY;
}

float TileSprite::getWidth() {
    return this->width;
}

void TileSprite::setWidth(float width) {
    this->width = width;
}

float TileSprite::getHeight() {
    return this->height;
}

void TileSprite::setHeight(float height) {
    this->height = height;
}

ItemSprite* TileSprite::getItem() {
    return this->item;
}

void TileSprite::setItem(ItemSprite* item) {
    if (item == NULL) {
        this->item = NULL;
    }else {
        float scale = ((float)TILE_SIDE_LENGTH / TEXTURE_SIDE_LENGTH) * SCALE_RATE;
        this->item = item;
        this->item->setAnchorPoint(Point(0.5, 0.5));
        this->item->setPosition(Vec2(this->getWidth() / 2, this->getHeight() / 2));
        this->item->setScale(scale, scale);
    }
}