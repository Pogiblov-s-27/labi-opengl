/*
 * Texture.h
 *
 *  Created on: 28 мая 2022 г.
 *      Author: Семён
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <GL/glu.h>

class Texture final
{
	private:
		GLuint _tex { 0 };

	public:
		Texture(const char * filename);
		~Texture();

		void bind();
};

#endif /* TEXTURE_H_ */
