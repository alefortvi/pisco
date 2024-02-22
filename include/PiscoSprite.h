#ifndef PISCO_SPRITE_H
#define PISCO_SPRITE_H

#include <map>
#include <string>
#include "PiscoDraw.h"



	class PiscoSprite {
	public:
		void addSprite(const std::string& key, PiscoDraw& sprite);
		void setActiveSprite(const std::string& key);
		PiscoDraw& getActivatedSprite();
		std::string getActivatedKey() const;
		
	private:
		std::map<std::string, PiscoDraw> sprites;
		std::string activeSpriteKey;
	};

#endif // PISCO_SPRITE_H
