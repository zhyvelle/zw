#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		
		auto menu = this->getChildByID("bottom-menu");

		// gay
		bool gay = Mod::get()->getSettingValue<bool>("enable");

		if (gay) {
			auto spr = CCSprite::create("gay.png"_spr);
			auto zw = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyMenuLayer::onZw));
			zw->setID("zw"_spr);
			menu->addChild(zw);
		}

		// not gay

		bool notGay = Mod::get()->getSettingValue<bool>("good");

		if (notGay) {
			auto goodSpr = CCSprite::create("good.png"_spr);
			auto good = CCMenuItemSpriteExtra::create(goodSpr, this, menu_selector(MyMenuLayer::onGood));
			good->setID("good"_spr);
			menu->addChild(good);
		}

		//bad
		bool bift = Mod::get()->getSettingValue<bool>("bad");

		if (bift) {
			auto badSpr = CCSprite::create("bad.png"_spr);
			auto bad = CCMenuItemSpriteExtra::create(badSpr, this, menu_selector(MyMenuLayer::onBad));
			bad->setID("bad"_spr);
			menu->addChild(bad);
		}
		menu->updateLayout();

		return true;
	}

	void onZw(CCObject*) {
		FLAlertLayer::create("message", "im gay", "ok")->show();
	}

	void onGood(CCObject*) {
		FLAlertLayer::create("messgae", "not  gay", "ok")->show();
	}

	void onBad(CCObject*) {
		FLAlertLayer::create("message", "im bad\ni also dont know how to make image fit", "ok")->show();
	}
};