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

ItemSprite* ItemSprite::create(ItemType itemType) {
    ItemSprite *item = new ItemSprite();
    if (item && item->init()) {
        switch (itemType) {
            case ItemType::sword:
                item->initWithSpriteFrameName("sword.png");
                item->setItemType(ItemType::sword);
                break;
            case ItemType::health:
                item->initWithSpriteFrameName("health.png");
                item->setItemType(ItemType::health);
                break;
            case ItemType::mana:
                item->initWithSpriteFrameName("magic.png");
                item->setItemType(ItemType::mana);
                break;
            case ItemType::conis:
                item->initWithSpriteFrameName("coins.png");
                item->setItemType(ItemType::conis);
                break;
            case ItemType::shield:
                item->initWithSpriteFrameName("shield.png");
                item->setItemType(ItemType::shield);
                break;
            case ItemType::monster1:
                item->initWithSpriteFrameName("monster.png");
                item->setItemType(ItemType::monster1);
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
