//
//  ItemSprite.cpp
//  LittleKnight
//
//  Created by JinTongyao on 1/22/15.
//
//

#include "ItemSprite.h"

bool ItemSprite::init() {
    if (!Sprite::init()) {
        return false;
    }
    return true;
}

ItemSprite* ItemSprite::createBasicItem(BasicItemType itemType) {
    ItemSprite *item = new ItemSprite();
    if (item && item->init()) {
        switch (itemType) {
            case BasicItemType::sword1:
                item->initWithSpriteFrameName("sword-1.png");
                item->setItemType(BasicItemType::sword1);
                break;
            case BasicItemType::health:
                item->initWithSpriteFrameName("health.png");
                item->setItemType(BasicItemType::health);
                break;
            case BasicItemType::mana:
                item->initWithSpriteFrameName("magic.png");
                item->setItemType(BasicItemType::mana);
                break;
            case BasicItemType::conis:
                item->initWithSpriteFrameName("coins.png");
                item->setItemType(BasicItemType::conis);
                break;
            case BasicItemType::shield:
                item->initWithSpriteFrameName("shield.png");
                item->setItemType(BasicItemType::shield);
                break;
            case BasicItemType::enemy2:
                item->initWithSpriteFrameName("enemy-2.png");
                item->setItemType(BasicItemType::enemy2);
                break;
            case BasicItemType::enemy3:
                item->initWithSpriteFrameName("enemy-3.png");
                item->setItemType(BasicItemType::enemy3);
                break;
            case BasicItemType::enemy4:
                item->initWithSpriteFrameName("enemy-4.png");
                item->setItemType(BasicItemType::enemy4);
                break;
        }
        item->autorelease();
        return item;
    }
    CC_SAFE_DELETE(item);
    return NULL;
}

ItemSprite* ItemSprite::createBossItem(BossItemType itemType) {
    ItemSprite *item = new ItemSprite();
    if (item && item->init()) {
        switch (itemType) {
            case BossItemType::boss1:
                item->initWithSpriteFrameName("boss-1.png");
                item->setItemType(BossItemType::boss1);
                break;
            case BossItemType::boss2:
                item->initWithSpriteFrameName("boss-2.png");
                item->setItemType(BossItemType::boss2);
                break;
            case BossItemType::boss3:
                item->initWithSpriteFrameName("boss-3.png");
                item->setItemType(BossItemType::boss3);
                break;
        }
        item->autorelease();
        return item;
    }
    CC_SAFE_DELETE(item);
    return NULL;
}



int ItemSprite::getItemType() {
    return this->itemType;
}

void ItemSprite::setItemType(int itemType) {
    this->itemType = itemType;
}
