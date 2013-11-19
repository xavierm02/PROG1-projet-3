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

#ifndef __IMAGE_H
#define __IMAGE_H

#include "SDL.h"

#include "rect.hpp"
#include "color.hpp"

namespace rt {

	/**
	 * The image class wraps a SDL_Surface structure
	 * to offer object-oriented access to its data.
	 * It represents an in-memory image.
	 */
	class image
	{
		protected:
			SDL_Surface* data; /*!< Wrapped SDL surface */

			/**
			 * Default constructor is protected and can be used
			 * only by inheriting classes. It is forbidden to
			 * build an image without at least its dimensions.
			 */
			image();

		public:

			/**
			 * Main constructor. Builds an image from its dimensions.
			 */
			image(int width, int height);

			/**
			 * Copy constructor.
			 * Warning: this does not copy the actual data, so
			 * any modification to the copy will impact the original.
			 * To build a hard copy, use the copy member function.
			 */
			image(const image& img);

			/**
			 * Destructor. Will decrease the reference counter
			 * of the wrapped data and free it if it goes to 0.
			 */
			virtual ~image();

			/**
			 * Returns the width of the image.
			 */
			virtual inline int width() const
			{
				return data->w;
			}

			/**
			 * Returns the height of the image.
			 */
			virtual inline int height() const
			{
				return data->h;
			}

			/**
			 * Returns a hard copy of the image.
			 */
			virtual image copy() const;

			/**
			 * Returns the color of a pixel.
			 */
			virtual color get_pixel(int x, int y) const;

			/**
			 * Sets a pixel to a given color.
			 */
			virtual void set_pixel(int x, int y, const color& c);

			/**
			 * Copy/Past the image's source rectangle to a given destiation
			 * at given coordinates.
			 */
			virtual void blit(image& dst, const rect& srcrect, int dstx, int dsty) const;

			/**
			 * Copy/Past time entire image to a given destiation
			 * at given coordinates.
			 */
			virtual void blit(image& dst, int dstx, int dsty) const;

			/**
			 * Draws a line from (x1,y1) to (x2,y2) of a given color.
			 */
			virtual void draw_line(int x1, int y1, int x2, int y2, const color& c);

			/**
			 * Draws a rectangle (uses draw_line) of a given color.
			 */
			virtual void draw_rect(int x1, int y1, int x2, int y2, const color& c);

			/**
			 * Draws a filled rectangle of a given color.
			 */
			virtual void fill_rect(int x1, int y1, int x2, int y2, const color& c);
	};

}
#endif
