/*
 * Texture.cpp
 *
 *  Created on: 28 мая 2022 г.
 *      Author: Семён
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdexcept>
#include <memory>

#include "Texture.h"

Texture::Texture(const char *filename)
{
	auto _image1 = std::shared_ptr<SDL_Surface>(
			IMG_Load(filename),
			SDL_FreeSurface);

	if (_image1 == nullptr)
		throw std::runtime_error(
				std::string(" Не могу загрузить текстуру_1! ") +
				std::string(SDL_GetError()));

	auto _image2 = std::shared_ptr<SDL_Surface>(
				SDL_CreateRGBSurface(
						0, _image1->w, _image1->h, 32,
						0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000),
				SDL_FreeSurface);

	SDL_UpperBlit(_image1.get(), nullptr, _image2.get(), nullptr);

	glGenTextures(1, &_tex);
	glBindTexture(GL_TEXTURE_2D, _tex);
	gluBuild2DMipmaps(
			GL_TEXTURE_2D, GL_RGBA,
			_image2->w, _image2->h,
			GL_RGBA, GL_UNSIGNED_BYTE, _image2->pixels
			);
	glTexParameteri(
			GL_TEXTURE_2D,
			GL_TEXTURE_MAG_FILTER,
			GL_LINEAR_MIPMAP_LINEAR
			);
	glTexParameteri(
				GL_TEXTURE_2D,
				GL_TEXTURE_MIN_FILTER,
				GL_LINEAR_MIPMAP_LINEAR
				);
}

Texture::~Texture()
{
	glDeleteTextures(1, &_tex);
}

void Texture::bind()
		{
			glBindTexture(GL_TEXTURE_2D, _tex);
		}
