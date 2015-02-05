//
//  MainMenuScene.cpp
//  LittleKnight
//
//  Created by JinTongyao on 1/19/15.
//
//

#include "MainMenuScene.h"

Scene* MainMenuScene::createScene() {
    auto scene = Scene::create();
    auto layer = MainMenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainMenuScene::init() {
    if(!Layer::init()) {
        return false;
    }
    
    Size visiableSize = Director::getInstance()->getVisibleSize();
    
    // background layer
    auto backgroundLayer = LayerColor::create(Color4B(238, 222, 170, 255));
    this->addChild(backgroundLayer);

    // normal mode menu
    auto nomrmalModeLable = MenuItemLabel::create(LabelTTF::create("Normal Mode", "Futura.ttf", 32), CC_CALLBACK_1(MainMenuScene::menuNormalModeCallback, this));
    nomrmalModeLable->setTag(0);
    nomrmalModeLable->setAnchorPoint(Point(0, 0));
    nomrmalModeLable->setPosition(Point(visiableSize.width / 2 - 80, visiableSize.height / 2 + 90));
    auto normalModeMenu = Menu::create(nomrmalModeLable, NULL);
    normalModeMenu->setPosition(0, 0);
    this->addChild(normalModeMenu);
    
    return true;
}

void MainMenuScene::menuNormalModeCallback(Ref *sender) {
    MenuItem* selectedMenu = (MenuItem*) sender;
    int tag = selectedMenu->getTag();
    Scene* normalModeScene = NormalModeScene::createScene(tag);
    TransitionFlipX *transition = TransitionFlipX::create(1.2, normalModeScene);
    Director::getInstance()->replaceScene(transition);
}