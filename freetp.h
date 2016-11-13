#ifndef FREETP_H
#define FREETP_H

#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <string>
#include <stdexcept>

namespace freetype {
// В этом пространстве, даем себе возможность написать только "vector" вместо "std::vector"
    using std::vector;
    // тоже самое для строки.
    using std::string;
    // Здесь мы храним всю информацию о FreeType шрифте, который мы хотим создать
    struct font_data {
      float h;                    // Высота
      GLuint * textures;          // Идентификатор
      GLuint list_base;           // Содержит указатель на список отображения
      void init(const char * fname, unsigned int h);
      // Освобождаем ресурсы связанные со шрифт
      void clean();
    };
    void print(const font_data &ft_font, float x, float y, const char *fmt, ...);
}
#endif // FREETP_H
