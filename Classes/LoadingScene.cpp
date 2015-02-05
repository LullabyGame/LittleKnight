//
//  LoadingScene.cpp
//  LittleKnight
//
//  Created by JinTongyao on 1/19/15.
//
//

#include "LoadingScene.h"

Scene* LoadingScene::createScene() {
    auto scene = Scene::create();
    auto layer = LoadingScene::create();
    scene->addChild(layer);
    return scene;
}


bool LoadingScene::init() {
    if(!Layer::init()) {
        return false;
    }
    
    // add logo to current scene
    auto *logo = Sprite::create("img/lullaby.jpg");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    logo->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
    this->addChild(logo);
    
    // preload sound and music
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/Ka-Ching.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/got.mp3");
    
    // init sprite cache texture and change scene =>
    Director::getInstance()->getTextureCache()->addImageAsync("img/LittleKnight.png", CC_CALLBACK_1(LoadingScene::loadingCallBack, this));
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("img/LittleKnight.plist");

    return true;
}


void LoadingScene::loadingCallBack(Texture2D *texture) {
    auto scene = MainMenuScene::createScene();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}