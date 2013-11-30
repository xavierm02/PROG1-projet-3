/**
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SCREEN_H
#define __SCREEN_H

#include <string>
#include "SDL.h"

#include "image.hpp"

namespace rt {

	/**
	 * The screen class inherites from the image class in order
	 * to draw something on the screen. It also wraps the SDL
	 * initialization calls. Only one screen should be created.
	 * If a second screen instance is created, it gets attached
	 * to the first one and the width and height are ignored.
	 */
	class screen : public image
	{
		private:
			static int initialized; /*!< Indicates how many instances of screen exist. */
			static SDL_Surface* buffer; /*!< Pointer to the screen's buffer. */

		public:
			/**
			 * Main constructor, uses width and height.
			 */
			screen(int width, int height);

			/**
			 * Destructor. Decrements the initialized
			 * counter and closes the screen only if it goes to 0.
			 */
			virtual ~screen();

			/**
			 * Flushes the buffer to the screen, listen to event.
			 * Returns false if a QUIT event (^C for exemple) has
			 * been received.
			 */
			virtual bool update();
	};

}
#endif
