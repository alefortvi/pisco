
#include "../include/PiscoSprite.h"
#include "../include/PiscoDraw.h"


	void PiscoSprite::addSprite(const std::string& key, PiscoDraw& sprite) {
		sprites[key] = sprite;
		activeSpriteKey = key; // Establecer el sprite activo como el último agregado
	}
	
	void PiscoSprite::setActiveSprite(const std::string& key) {
		auto it = sprites.find(key);
		if (it != sprites.end()) {
			activeSpriteKey = key;
		} else {
			throw std::invalid_argument("Sprite with key '" + key + "' does not exist.");
		}
	}
	
	
	PiscoDraw& PiscoSprite::getActivatedSprite(){
		auto it = sprites.find(activeSpriteKey);
		if (it != sprites.end()) {
			return it->second;
		} else {
			throw std::invalid_argument("Active sprite does not exist.");
		}
	}
	
	std::string PiscoSprite::getActivatedKey() const {
		return activeSpriteKey;
	}

